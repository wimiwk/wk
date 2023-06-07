import numpy as np
# 训练集
with open('./minist_data/train-images.idx3-ubyte') as f:
    loaded = np.fromfile(file=f, dtype=np.uint8)
    train_data = loaded[16:60000 * 784 + 16].reshape((60000, 784))
with open('./minist_data/train-labels.idx1-ubyte') as f:
    loaded = np.fromfile(file=f, dtype=np.uint8)
    train_labels = loaded[8:60000 + 8].reshape(60000)
# 手写痕迹为1 背景为0
for i in range(60000):
    for n in range(784):
        if train_data[i][n] > 0:
            train_data[i][n] = 1
# 测试集
with open('./minist_data/t10k-images.idx3-ubyte') as f:
    loaded = np.fromfile(file=f, dtype=np.uint8)
    test_data = loaded[16:10000 * 784 + 16].reshape((10000, 784))
# 测试集标签
with open('./minist_data/t10k-labels.idx1-ubyte') as f:
    loaded = np.fromfile(file=f, dtype=np.uint8)
    test_labels = loaded[8:10000 + 8].reshape(10000)
# 手写痕迹为1 背景为0
for i in range(10000):
    for n in range(784):
        if test_data[i][n] > 0:
            test_data[i][n] = 1
np.save("./minist_data/train_data.npy", train_data)
np.save("./minist_data/train_labels.npy", train_labels)
np.save("./minist_data/test_data.npy", test_data)
np.save("./minist_data/test_labels.npy", test_labels)

# 偏置初始化
hidden_bias0 = np.random.randn(256)
hidden_bias1 = np.random.randn(100)
hidden_bias2 = np.random.randn(64)
output_bias = np.random.randn(10)
np.save("./minist_data/hidden_bias0.npy", hidden_bias0)
np.save("./minist_data/hidden_bias1.npy", hidden_bias1)
np.save("./minist_data/hidden_bias2.npy", hidden_bias2)
np.save("./minist_data/output_bias.npy", output_bias)

hidden_parameter0 = np.random.randn(784, 256) * (1.0 / np.sqrt(256))
hidden_parameter1 = np.random.randn(256, 100) * (1.0 / np.sqrt(100))
hidden_parameter2 = np.random.randn(100, 64) * (1.0 / np.sqrt(64))
output_parameter = np.random.randn(64, 10) * (1.0 / np.sqrt(10))
np.save("./minist_data/hidden_parameter0.npy", hidden_parameter0)
np.save("./minist_data/hidden_parameter1.npy", hidden_parameter1)
np.save("./minist_data/hidden_parameter2.npy", hidden_parameter2)
np.save("./minist_data/output_parameter.npy", output_parameter)

print("初始化完成")
