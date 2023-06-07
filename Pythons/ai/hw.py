import numpy as np
from matplotlib import pyplot as plt
# generate dataset randomly
x_dim, y_dim = 2, 5
m = 3 
x = np.random.rand(x_dim, m) 
y = np.random.rand(y_dim, m)
L = 4 # num of layers
N = [x_dim, 4, 3, y_dim] # num of neurons of each layer
w = [np.random.rand(N[l+1], N[l]) for l in range(L-1)]

print("size of connections:")
for l, w_l in enumerate(w):
    print("size of w_{} is : {}".format(l, w_l.shape))
def sigmoid(z):
    return 1/(1+np.exp(-z))
def dfsigmoid(z):
    return sigmoid(z)*(1-sigmoid(z))

def forward(x, w, L, N):
    m = x.shape[1] # batch size
    z = [np.zeros((N[l], m)) for l in range(L)]
    a = [np.zeros_like(z_l) for z_l in z]
    
    a[0] = x # set input
    for l in range(0, L-1):
        
        ### Your code here ###
        z[l+1] = np.random.rand(z[l+1].shape[0], z[l+1].shape[1])
        a[l+1] = np.random.rand(a[l+1].shape[0], a[l+1].shape[1])
        z[l+1] = np.dot(w[l], a[l])
        a[l+1] = sigmoid(z[l+1])
        ### end of Your code ###
    
    return a, z

def cost(y, a):
    m = a.shape[1]
    return np.sum(np.square(y-a))/m/2

def backward(y, w, z, a):
    m = y.shape[1] # batch size
    L = len(a)
    
    delta = [np.zeros_like(z_l) for z_l in z]
    grad_w = [np.zeros_like(w_l) for w_l in w]
    
    
    # compute delta for the last layer
    delta[-1] = a[-1] - y
    
    # compute delta for the hidden layers
    for l in range(L-2, -1, -1):
        delta[l] = dfsigmoid(z[l]) * np.dot(w[l].T, delta[l+1])
    
    # compute gradients
    for l in range(L-2, -1, -1):
        grad_w[l] = np.dot(delta[l+1], a[l].T)
    
    for l in range(0, L-1):
        grad_w[l] += np.zeros_like(grad_w[l])
    
    return grad_w 

def numerical_grad(l, epsilon, x, w, L, N, y):
    grad = np.zeros_like(w[l])
    for i in range(N[l+1]):
        for j in range(N[l]):
            w_minus = [w_l.copy() for w_l in w]
            w_minus[l][i,j] = w_minus[l][i,j] - epsilon
            a_minus, _ = forward(x, w_minus, L, N)
            J_minus = cost(a_minus[-1], y)
            
            w_plus = [w_l.copy() for w_l in w]
            w_plus[l][i,j] = w_plus[l][i,j] + epsilon
            a_plus, _ = forward(x, w_plus, L, N)
            J_plus = cost(a_plus[-1], y)

            grad[i,j] = (J_plus - J_minus)/(2*epsilon)

    return grad

a, z = forward(x, w, L, N)
grad_w = backward(y, w, z, a)
epsilon = 1e-5

for l in range(0, L-1):
    num_grad = numerical_grad(l, epsilon, x, w, L, N, y)
    grad_diff = np.sqrt(np.square(grad_w[l] - num_grad).sum())
    
    check_str = "check.py grad success" if grad_diff < 1e-8 else "check.py grad failed"
    print("grad difference for w_{} is {}, {}".format(l, grad_diff, check_str))