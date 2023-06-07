import cv2
import torch
import torchvision
from torchvision.models.detection import fasterrcnn_resnet50_fpn
from torchvision.transforms import ToTensor
from PIL import Image

# 加载预训练的Faster R-CNN模型
model = fasterrcnn_resnet50_fpn(pretrained=True)
# 检查是否有可用的GPU
if torch.cuda.is_available():
    device = torch.device("cuda")
else:
    device = torch.device("cpu")

# 将模型转移到GPU上
model.to(device)


# 将模型设置为评估模式
model.eval()

# 打开摄像头或视频文件
#cap = cv2.VideoCapture(0)  # 使用摄像头
cap = cv2.VideoCapture("hi.mp4")  # 使用视频文件

# 设置置信度阈值
confidence_threshold = 0.8

while True:
    # 读取一帧图像
    ret, frame = cap.read()
    if not ret:
        break

    # 将OpenCV图像转换为PIL图像
    pil_image = Image.fromarray(cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))

    # 对图片进行预处理
    transform = ToTensor()
    image_tensor = transform(pil_image)
    # 将输入数据转移到GPU上
    image_tensor = image_tensor.to(device)
    # 将图片输入模型进行预测
    with torch.no_grad():
        predictions = model([image_tensor])

    # 提取预测结果中的目标检测框
    detected_boxes = []
    for box, score, label in zip(predictions[0]["boxes"], predictions[0]["scores"], predictions[0]["labels"]):
        if score > confidence_threshold:
            detected_boxes.append((box, label))

    # 在原始图像上绘制检测框
    for box, label in detected_boxes:
        x1, y1, x2, y2 = box
        x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
        cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
        cv2.putText(frame, str(label), (x1, y1), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

    # 显示带有检测框的图像
    cv2.imshow("Video", frame)

    # 按'q'键退出循环
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 释放资源并关闭窗口
cap.release()
cv2.destroyAllWindows()