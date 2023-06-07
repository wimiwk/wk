import torch
import numpy as np
import torch.nn as nn
from torchvision import models, transforms
from PIL import Image
from torch.utils.data import DataLoader
path = 'test_x.npy'
data = np.load(path).T
data_ = np.zeros((5000,28,28), dtype=np.float32)
for i in range(5000):
    m=0
    for x in range(28):
        for y in range(28):
            data_[i][x][y]=data[i][m]
            m+=1
transform = transforms.Compose([transforms.Resize((224, 224))])
image = np.zeros((5000,3, 224, 224), dtype=np.float32)
for i in range(5000):
    image[i] =np.stack((transform(Image.fromarray(data_[i].astype(np.uint8))),)*3, axis=-1).transpose(2, 0, 1)
#img=[Image.fromarray((image[i] * 255).astype(np.uint8).transpose(1, 2, 0)) for i in range(5000)]
img=[transforms.ToTensor()(Image.fromarray((image[i] * 255).astype(np.uint8).transpose(1, 2, 0))) for i in range(5000)]
# 加载模型
model = models.resnet18(pretrained=True)
in_features = model.fc.in_features
model.fc = nn.Linear(in_features, 10)
model.load_state_dict(torch.load('model.pth'))
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
model.to(device)

# 进行推理
model.eval()
predicted_=np.zeros((5000), dtype=np.float32)
with torch.no_grad():
    test_loader = DataLoader(img, batch_size=1, shuffle=False)
    m=0
    for images in test_loader:
        images = images.to(device)
        outputs = model(images)
        _, predicted = torch.max(outputs.data, 1)
        predicted_[m]=predicted.cpu().numpy()
        m+=1
# 保存结果
np.save('result.npy', predicted_)
