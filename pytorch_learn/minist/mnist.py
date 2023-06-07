import torch
import torch.nn as nn
import matplotlib.pyplot as plt
from torch.utils.data import DataLoader
from torchvision import datasets, transforms
from torchvision import models

# 预处理
my_transform = transforms.Compose([
        transforms.Resize((224, 224)),
        transforms.Grayscale(3),
        transforms.ToTensor(),
        transforms.Normalize((0.1307,0.1307,0.1307), (0.3081,0.3081,0.3081)),
    ])
# 训练集
train_file = datasets.MNIST(
    root='./dataset/',
    train=True,
    transform=my_transform,
    download=True
)
# 测试集
test_file = datasets.MNIST(
    root='./dataset/',
    train=False,
    transform=my_transform,
    download=True
)

model = models.resnet18(pretrained=True)
in_features = model.fc.in_features
model.fc = nn.Linear(in_features, 10)

# 定义损失函数和优化器
criterion = nn.CrossEntropyLoss()
optimizer = torch.optim.SGD(model.parameters(), lr=0.001, momentum=0.9)

# 定义训练循环的参数
num_epochs = 10
batch_size = 16
train_loader = DataLoader(train_file, batch_size=batch_size, shuffle=True)
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(device)
model.to(device)

accurancies=[0 for i in range(num_epochs)]
max_accurancies=0

# 训练模型
for epoch in range(num_epochs):
    for i, (images, labels) in enumerate(train_loader):
        images=images.to(device)
        labels=labels.to(device)
        outputs = model(images)
        loss = criterion(outputs, labels)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        if (i + 1) % 100 == 0:
            print('Epoch [{}/{}], Step [{}/{}], Loss: {:.4f}'
                  .format(epoch + 1, num_epochs, i + 1, len(train_loader), loss.item()))
    # 测试模型
    model.eval()
    with torch.no_grad():
        correct = 0
        total = 0
        test_loader = DataLoader(test_file, batch_size=batch_size, shuffle=False)
        for images, labels in test_loader:
            images=images.to(device)
            labels=labels.to(device)
            outputs = model(images)
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
        accurancies[epoch]=100 * correct / total
        print('Test Accuracy: {:.2f}%'.format(100 * correct / total))
    # 保存模型的状态字典
    if accurancies[epoch]>max_accurancies:
        max_accurancies=accurancies[epoch]
        torch.save(model.state_dict(), 'model_16.pth')