import numpy as np
import torch
import torch.nn as nn
import matplotlib.pyplot as plt
from torch.utils.data import DataLoader
from torchvision import datasets, transforms
from torchvision import models
train_file = datasets.MNIST(
    root='./dataset/',
    train=True,
    download=False
)
print((train_file))