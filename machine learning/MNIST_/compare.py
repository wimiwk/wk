import numpy as np
import time
start = time.time()


def sigmoid(x):
    return 1 / (1 + np.exp(-x))


def softmax(x):
    e_x = np.exp(x)
    return e_x / e_x.sum()


# 测试集数量

test_data = (np.load("./minist_data/test_x.npy")).T
test_labels = np.load("./minist_data/test_y.npy")
test_number = test_data.shape[0]
for count in range(2):
    # 映射对应的矩阵
    numbers = [[1, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
               [0, 0, 0, 1, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
               [0, 0, 0, 0, 0, 0, 1, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
               [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]]
    # 隐藏层参数
    hidden_parameter0 = np.load('./minist_data/hidden_parameter0.npy')
    hidden_parameter1 = np.load('./minist_data/hidden_parameter1.npy')
    hidden_parameter2 = np.load('./minist_data/hidden_parameter2.npy')
    output_parameter = np.load('./minist_data/output_parameter.npy')

    hidden_output0 = np.matmul(test_data, hidden_parameter0)
    hidden_output0 = sigmoid(hidden_output0)
    hidden_output1 = np.matmul(hidden_output0, hidden_parameter1)
    hidden_output1 = sigmoid(hidden_output1)
    hidden_output2 = np.matmul(hidden_output1, hidden_parameter2)
    hidden_output2 = sigmoid(hidden_output2)
    output_output = np.matmul(hidden_output2, output_parameter)
    output_output = sigmoid(output_output)
    right = np.zeros(10, dtype=np.int16)
    worse = np.zeros(10, dtype=np.int16)

    right_sum = 0
    worse_sum = 0
    # 判断
    for m in range(test_number):
        # right[test_labels[m]] += 1
        if test_labels[m] == np.argmax(output_output[m]):
            right_sum += 1
            right[test_labels[m]] += 1
        else:
            worse_sum += 1
            worse[test_labels[m]] += 1
        if m % 1000 == 0:
            print(test_labels[m], softmax(output_output[m] * 7))
            # print(test_labels[m], output_output[m])

    print("识别正确数：",right_sum, right)
    print("识别失败数：",worse_sum, worse)
    print("一万例用时：", time.time() - start)
