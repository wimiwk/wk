import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import StandardScaler
# 读取训练数据
train_x = np.load('train_x.npy')
train_y = np.load('train_y.npy')
# 读取测试数据
test_x = (np.load('test_data.npy')).T
test_y = np.load('test_labels.npy')
print(train_x.shape,train_y.shape,test_x.shape,test_y.shape)
#缩放数据
scaler = StandardScaler()
train_x_scaled = scaler.fit_transform(train_x)
test_x_scaled = scaler.fit_transform(test_x)
# 创建逻辑回归模型
model = LogisticRegression(max_iter=5000)
# 训练模型
model.fit(train_x_scaled.T, train_y)
accuracy=model.score(test_x_scaled.T, test_y)
print("机器学习准确率：",accuracy)
# 读取最终数据
final_data = np.load('final_x.npy')
final_scaled = scaler.fit_transform(final_data)
# 使用模型进行最终数据的预测
final_predictions = model.predict(final_scaled.T)
# 保存预测结果为npy文件
np.save('final_predictions.npy', final_predictions)
