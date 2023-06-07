import os
# import json
import numpy as np
import torch
from PIL import Image
from torchvision import transforms
import matplotlib.pyplot as plt
from network_files import FasterRCNN
from backbone import resnet50_fpn_backbone, MobileNetV2

def main():
    # get devices
    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
    print("using {} device.".format(device))

    # create model
    backbone = resnet50_fpn_backbone(norm_layer=torch.nn.BatchNorm2d)
    model = FasterRCNN(backbone=backbone, num_classes=6, rpn_score_thresh=0.5)

    train_weights = "./save_weights/resNetFpn-model-14.pth"
    assert os.path.exists(train_weights), "{} file dose not exist.".format(train_weights)
    model.load_state_dict(torch.load(train_weights, map_location=device)["model"])
    model.to(device)

    imagename = '4.jpg'
    original_img = Image.open("./others/"+ imagename)
    # from pil image to tensor, do not normalize image
    data_transform = transforms.Compose([transforms.ToTensor()])
    img = data_transform(original_img)
    # expand batch dimension
    img = torch.unsqueeze(img, dim=0)

    model.eval()

    with torch.no_grad():
        # Inference
        # predictions = model(img.to(device))[0]
        features = model.backbone.forward(img.to(device))
        features = list(features.values())

        for feature in features:
            feature = feature.detach().cpu().numpy()
            im = np.squeeze(feature)
            im = np.transpose(im, [1, 2, 0])
            plt.figure()
            for i in range (12):
                ax = plt.subplot(3, 4, i+1)
                plt.imshow(im[:, :, 1])
            plt.show()

if __name__ == '__main__':
    main()

