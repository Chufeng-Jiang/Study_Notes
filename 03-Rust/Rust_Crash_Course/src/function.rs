use std::thread;

#[derive(Debug)]
struct FIB {
    num: u64,
}

impl FIB {
    // 构造方法
    fn new(num: u64) -> FIB {
        FIB { num }
    }

    fn fib_iner(num: u64) -> u64 {
        if num < 2 {
            num
        } else {
            fib(num - 1) + fib(num - 2)
        }
    }

    // 修改成员变量
    fn set_num(&mut self, num: u64) {
        self.num = num;
    }

    fn fib(&self) -> u64 /*-> 返回值*/ {
        FIB::fib_iner(self.num)
    }
}

pub fn function() {
    println!("-------------function------------------");
    let res = fib(10);
    println!("{}", res);

    let mut ff = FIB::new(10);
    println!("{:?}", ff);
    // 修改成员变量
    ff.set_num(20);
    let res = ff.fib();
    println!("{:?}", ff);
    println!("{}", res);

    println!("-------------闭包------------------");
    // 闭包 Rust中的闭包是一种匿名函数
    // 它可以从上下文中捕获变量的值
    // 闭包使用|| -> 语法定义，闭包可以 被保存在变量中。

    let times = 2;
    let to_three_3x = |n: u32| -> u32 { n * times };

    println!("{}", to_three_3x(20));

    // 捕获运行时环境的值
    // move 将环境中的值，移到闭包内部
    // 使用多线程时，从主线程移动值到子线程
    // 多线程实例：
    let hello_message = "hello rust";

    // 子线程
    thread::spawn(move || {
        println!("{}", hello_message);
    })
    .join(); // join 除非子线程退出，不然主线程会一直去等待

    println!("-------------高阶函数------------------");

    // 高阶函数 这个函数可以接受一个或多个函数作为输入
    // 或者 输出一个函数

    type Method = fn(u32, u32) -> u32; // alias 别名

    fn calc(method: Method, a: u32, b: u32) -> u32 {
        method(a, b)
    }

    fn calc_str(method: &str) -> Method {
        match method {
            "add" => {
                add
            }
            "sub" => {
                sub
            }
            _=> {
                unimplemented!() // 不合法的 未实现的
            }
        }
    }

    fn add(a: u32, b: u32) -> u32 {
        a + b
    }

    fn sub(a: u32, b: u32) -> u32 {
        a - b
    }

    let a = 10;
    let b = 20;
    let res = calc(add, a, b);
    println!("{} + {} = {}", a, b, res);
    let res = calc(sub, b, a);
    println!("{} - {} = {}", b, a, res);

    let res = calc_str("add");
    println!("{} + {} = {}", a, b, res(a,b));

    println!("-------------发散函数------------------");

    // 发散函数 是一个永远不会返回的函数
    // 返回值标记为!，这是一个空类型

    // 与发散函数容易搞混的是空返回值的函数
    // 空返回的函数 是可以返回的
     fn no_return() {
         ()
     }

    // 发散函数的作用 永远不会返回 发散函数的类型起始是可以为任意类型
    // 发散函数最大的用处就是通过Rust的类型检查系统
    // 比如前面说了Rust的if else 必须返回相同类型，但是下面这段代码也是可以通过编译的

    fn forever_no_return() -> ! {
        panic!("This call never returns.");
    }

    let a = if true {
        10
    } else {
        forever_no_return()
    };
    println!("{}",a);
}

// 函数
fn fib(num: u64) -> u64 /*-> 返回值*/ {
    if num < 2 {
        num
    } else {
        fib(num - 1) + fib(num - 2)
    }
}
