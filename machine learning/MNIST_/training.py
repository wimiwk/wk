import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

train_data = np.load("./minist_data/train_data.npy")
train_labels = np.load("./minist_data/train_labels.npy")

hidden_parameter0 = np.load('./minist_data/hidden_parameter0.npy')
hidden_parameter1 = np.load('./minist_data/hidden_parameter1.npy')
hidden_parameter2 = np.load('./minist_data/hidden_parameter2.npy')
output_parameter = np.load('./minist_data/output_parameter.npy')

numbers = [[1, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
           [0, 0, 0, 1, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0, 1, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
           [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]]
# 随机梯度下降的数据集数量
random_number = 10
# 学习率
learning_rate = 0.001
# 随机梯度下降次数
for times in range(60001):
    random_train_data = np.empty((random_number, 784), dtype=np.float32)
    random_train_labels = np.empty((random_number, 10), dtype=np.float32)
    # 从0到60000之间随机选择random_number个整数
    the_number = np.random.randint(0, 60000, size=random_number)
    for m in range(random_number):
        random_train_data[m] = train_data[the_number[m]]
        #
        random_train_labels[m] = numbers[train_labels[the_number[m]]]

    J_hidden0_parameter_derivative = np.zeros((784, 256), dtype=np.float32)
    J_hidden1_parameter_derivative = np.zeros((256, 100), dtype=np.float32)
    J_hidden2_parameter_derivative = np.zeros((100, 64), dtype=np.float32)
    J_output_parameter_derivative = np.zeros((64, 10), dtype=np.float32)

    hidden_output0 = np.matmul(random_train_data, hidden_parameter0)
    hidden_output0 = sigmoid(hidden_output0)
    hidden_output0_derivative = hidden_output0 * (1 - hidden_output0)

    hidden_output1 = np.matmul(hidden_output0, hidden_parameter1)
    hidden_output1 = sigmoid(hidden_output1)
    hidden_output1_derivative = hidden_output1 * (1 - hidden_output1)

    hidden_output2 = np.matmul(hidden_output1, hidden_parameter2)
    hidden_output2 = sigmoid(hidden_output2)
    hidden_output2_derivative = hidden_output2 * (1 - hidden_output2)

    output_output = np.matmul(hidden_output2, output_parameter)
    output_output = sigmoid(output_output)
    output_output_derivative = output_output * (1 - output_output)

    error = output_output - random_train_labels

    J_output_output_derivative = error * output_output_derivative
    for m in range(random_number):
        for i in range(64):
            J_output_parameter_derivative[i] += hidden_output2[m][i] * J_output_output_derivative[m]

    J_hidden2_output_derivative = np.matmul(J_output_output_derivative, output_parameter.T) * hidden_output2_derivative
    for m in range(random_number):
        for i in range(100):
            J_hidden2_parameter_derivative[i] += hidden_output1[m][i] * J_hidden2_output_derivative[m]

    J_hidden1_output_derivative = np.matmul(J_hidden2_output_derivative, hidden_parameter2.T) * hidden_output1_derivative
    for m in range(random_number):
        for i in range(256):
            J_hidden1_parameter_derivative[i] += hidden_output0[m][i] * J_hidden1_output_derivative[m]

    J_hidden0_output_derivative = np.matmul(J_hidden1_output_derivative, hidden_parameter1.T) * hidden_output0_derivative
    for m in range(random_number):
        for i in range(784):
            J_hidden0_parameter_derivative[i] += random_train_data[m][i] * J_hidden0_output_derivative[m]


    output_parameter -= (learning_rate / random_number) * J_output_parameter_derivative
    hidden_parameter2 -= (learning_rate / random_number) * J_hidden2_parameter_derivative
    hidden_parameter1 -= (learning_rate / random_number) * J_hidden1_parameter_derivative
    hidden_parameter0 -= (learning_rate / random_number) * J_hidden0_parameter_derivative

    if times % 100 == 0:
        np.save("./minist_data/hidden_parameter0.npy", hidden_parameter0)
        np.save("./minist_data/hidden_parameter1.npy", hidden_parameter1)
        np.save("./minist_data/hidden_parameter2.npy", hidden_parameter2)
        np.save("./minist_data/output_parameter.npy", output_parameter)
        print(error.sum() / 10)
        print(times)
