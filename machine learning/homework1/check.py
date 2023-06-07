import numpy as np
train_x=np.load('train_x.npy').T
train_y=np.load('train_y.npy')
test_x=np.load('test_x.npy').T
test_y=np.load('test_y.npy')
final_x=np.load('final_x.npy').T


print(train_x.shape,train_y.shape,test_x.shape,test_y.shape,final_x.shape)