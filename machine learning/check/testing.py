import numpy as np
test_data = np.load("final_predictions_origin.npy")
test_labels = np.load("final_predictions.npy")
test_number = test_data.shape[0]
right_sum = 0
worse_sum = 0
for m in range(test_number):
    if test_labels[m] == test_data[m]:
        right_sum += 1
    else:
        worse_sum += 1
print(right_sum)
print(worse_sum)
print("机器学习与神经网络预测结果的重合度：", right_sum / (worse_sum + right_sum))
