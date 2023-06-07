import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader
from torchvision import datasets, transforms
import numpy as np
from PIL import Image
# 数据预处理
transform = transforms.Compose([
    transforms.ToTensor(),
    transforms.Normalize((0.5,), (0.5,))
])

# 加载数据集
#train_set = datasets.MNIST(root='x.npy', train=True, download=False, transform=transform)
path = 'x.npy'
data = np.load(path).T
data_ = np.zeros((5000,28,28), dtype=np.float32)
for i in range(5000):
    m=0
    for x in range(28):
        for y in range(28):
            data_[i][x][y]=data[i][m]
            m+=1
#transform = transforms.Compose([transforms.Resize((224, 224))])
image = np.zeros((5000,28, 28), dtype=np.float32)
for i in range(5000):
    image[i] =transform(Image.fromarray(data_[i].astype(np.uint8)))
train_loader = DataLoader(image, batch_size=128, shuffle=True)
# 定义自编码器模型
class Autoencoder(nn.Module):
    def __init__(self):
        super(Autoencoder, self).__init__()
        self.encoder = nn.Sequential(
            nn.Linear(28 * 28, 128),
            nn.ReLU(),
            nn.Linear(128, 64),
            nn.ReLU(),
            nn.Linear(64, 12),
            nn.ReLU(),
            nn.Linear(12, 3)
        )
        self.decoder = nn.Sequential(
            nn.Linear(3, 12),
            nn.ReLU(),
            nn.Linear(12, 64),
            nn.ReLU(),
            nn.Linear(64, 128),
            nn.ReLU(),
            nn.Linear(128, 28 * 28),
            nn.Tanh()
        )

    def forward(self, x):
        x = self.encoder(x)
        x = self.decoder(x)
        return x

# 实例化模型
model = Autoencoder()

# 定义损失函数和优化器
criterion = nn.MSELoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

# 训练模型
num_epochs = 60000
for epoch in range(num_epochs):
    for data in train_loader:
        #print(data)
        img= data
        img = img.view(img.size(0), -1)
        optimizer.zero_grad()
        outputs = model(img)
        loss = criterion(outputs, img)
        loss.backward()
        optimizer.step()
    print(f"Epoch [{epoch + 1}/{num_epochs}], Loss: {loss.item():.4f}")

# 评估模型性能
model.eval()
total_loss = 0
with torch.no_grad():
    for data in train_loader:
        img= data
        img = img.view(img.size(0), -1)
        outputs = model(img)
        loss = criterion(outputs, img)
        total_loss += loss.item()

print(f"Average reconstruction loss: {total_loss / len(train_loader):.4f}")