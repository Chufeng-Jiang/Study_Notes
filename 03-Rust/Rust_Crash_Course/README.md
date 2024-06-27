# Rust中的模块化

- Package 包
- Create 箱
- Module 模块

## Package用于管理一个或多个Create。创建一个Package的方式是使用cargo new


# 可见性

## Rust模块中内部代码，结构体，函数等默认都是私有的，但是可以通过pub关键字来改变可见性

### 常见的pub有三种写法

- pub 成员对模块可见
- pub(self) 成员对模块内的子模块可见
- pub(create) 成员对整个create可见

# 使用super和self简化模块路径

- super 代表上层模块
- self 代表当前模块

当前模块和上层模块有相同名称的成员时，可以使用super、self来消除歧义。

# 将模块映射到文件

mod <路径> 语法将一个Rust源码文件作为模块内引入

# 将模块映射到文件夹

文件夹必须包含mod.rs这个文件


# 泛型

数据的类型作为一个参数传入到函数或者结构体等

