import numpy as np
import matplotlib.pyplot as plt

np.random.seed(42)

X1 = 2*np.random.rand(10, 1)
print("X1:\n", X1)
X2 = 3*np.random.rand(10, 1)
print("\nX2:\n", X2)
# 这里要模拟出来的数据y是代表真实的数据，所以也就是y_hat+error
y = 5 + 4*X1 + 3*X2 + np.random.randn(10, 1)
print("\ny:\n", y)

# 绘图进行展示真实的数据点和我们预测用的模型
plt.figure(figsize=(12, 10))

# 绘制 X1 vs y 的散点图
plt.subplot(2, 2, 1)
plt.scatter(X1, y, color='blue', label='Data points')
plt.xlabel('X1')
plt.ylabel('y')
plt.title('X1 vs y')
plt.legend()

# 绘制 X2 vs y 的散点图
plt.subplot(2, 2, 2)
plt.scatter(X2, y, color='green', label='Data points')
plt.xlabel('X2')
plt.ylabel('y')
plt.title('X2 vs y')
plt.legend()

# 为了去求解W0截距项，我们给X矩阵一开始加上一列全为1的X0
# X_b是经过扩展后的特征矩阵，它包含了一个常数列（通常是全为 1 的列）以及原始特征X1和X2。这样做是为了包括截距项在线性回归模型中。
X_b = np.c_[np.ones((10, 1)), X1, X2]
print("\nX_b:\n", X_b)

# 实现解析解的公式来求解θ
θ = np.linalg.inv(X_b.T.dot(X_b)).dot(X_b.T).dot(y)
print("\nθ:\n", θ)

# 使用模型去做预测
X_new = np.array([[0, 0],
                  [2, 3]])

X_new_b = np.c_[np.ones((2, 1)), X_new]

print("\nX_new_b:\n",X_new_b)

y_predict = X_new_b.dot(θ)
print("\ny_predict:\n",y_predict)

# 绘图进行展示真实的数据点和我们预测用的模型
plt.subplot(2, 2, 3)
# 绘制X_new第一列和y
plt.plot(X_new[:, 0], y_predict, 'r-')
# 绘制X1和y
plt.plot(X1, y, 'b.')
plt.axis([0, 2, 0, 25])
plt.title('X_new1 vs y_predict')
plt.savefig('multi_LR_model_prediction.png')
plt.show()
