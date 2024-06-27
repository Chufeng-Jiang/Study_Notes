use std::fmt::Debug;

// 某一种数据可能含有一些共同的行为，例如它们能被显示在屏幕上，或者能相互之间比较大小
// 我们将这些行为称做Traits 非常像接口这个行为
// 我们用标准库 std::fmt::Display这个traits举例
// 这个traits实现了在formatter中使用空白格式{}的功能

struct Point<T> {
    x: T,
    y: T,
}

impl<T: std::fmt::Display> std::fmt::Display for Point<T> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "({},{})", self.x, self.y)
    }
}

fn show<T: std::fmt::Display>(a: T) {
    // 不关心参数类型是什么，只关心是否实现了 display这个trait
    println!("show: {}", a);
}

// 语法糖
fn show_sugar(a: impl std::fmt::Display) {
    // 不关心参数类型是什么，只关心是否实现了 display这个trait
    println!("show: {}", a);
}

pub fn traits() {
    println!("-------------traits------------------");
    let point = Point { x: 10, y: 20 };
    println!("{}", point);

    // 我们实现一个函数，接收一个参数，但是这个函数不关心这个参数具体类型，
    // 只关心这个参数有没有实现具体方法，可以用traits实现
    // 使用traits来作为函数的参数类型

    // show(point);
    show_sugar(point);

    // 自动派生
    println!("-------------自动派生------------------");
    // 自动派生是由编译器做的，没有运行时开销
    // 前提是这个结构体里面的字段都已经实现了traits
    #[derive(Debug, PartialEq, Default)] // Debug允许去使用{:?}这种形式进行结构化的输出
                                         // PartialEq 比较两个结构体是否相等
                                         // Default 为这个结构体提供一个Default方法取得一个结构体，里面的字段都是默认值
    struct PointS<T> {
        x: T,
        y: T,
    }
    let pp = PointS { x: 100, y: 200 };
    let pp2 = PointS { x: 100, y: 200 };
    if pp == pp2 {
        println!("pp == pp2");
    }
    println!("{:?}", pp);
    let pp3 = PointS::<i32>::default();
    println!("{:?}", pp3);

    println!("-------------所有权------------------");
    // Rust语言里面最核心的概念 内存安全就建立在所有权之上
    // C语言内存管理模型就是malloc和free
    // 而有些语言采用了垃圾回收技术GC 开发者只需要去申请内存，不需要去释放内存
    // 垃圾回收器会自动检测，某块内存是否在使用
    // 如果不再使用，GC就会去释放内存
    // 任何使用GC的语言几乎都不可能编写底层程序，比如操作系统等
    // Rust采用RAII方式来管理内存
    // 它兼容GC的一用性和安全性，同时又有极高的性能

    // 栈：一种先进先出的结构，栈内的元素都有不同大小，通常是机器的位宽。
    // 比如我们用的是64位机器，那么所有程序运行的栈的位宽就是64位
    // 正好是一个寄存器的大小

    // 如果我们要放置一个对象，则会放置在堆中
    // 在堆上分配一个对象时，先想操作系统请求给定的内存数量，
    // 操作系统会在堆中找到一个空闲的位置，标记这个位置已经占用，并返回指向该存储位置的指针（内存地址）
    // 因此堆的组织性会比较差，但是处理动态结构的唯一方法

    // 一般来说（可以这么理解），当存储一个结构体时，栈中保存的是结构体的的地址，堆中保存的是结构体内容
    // 通常来说，保存在栈里面的是值类型，保存在堆中的是引用类型
    //

    // 所有权 实际规则
    // - Rust中每个值都绑定有一个变量，称为该值的所有者
    // - 每个值只有一个所有者，而且每个值都有它的作用域
    // - 一旦这个值离开作用域，这个值占用的内存将被回收

    // 例子：

    /*
    {
        这就是一个作用域
    }
    */
    let value = 1;
    println!("{}", value);
    {
        let value2 = 2;
    }
    // println!("{}", value2); // 会报错

    // String 是存储在堆中的
    let s1 = String::from("Hello s1");
    let s2 = s1; // s1把字符串的所有权转移给了s2
    println!("s2: {}", s2);
    // println!("s1: {}",s1); // 此时s1没有了字符串的所有权

    let s3: String; // 空字符串

    {
        let s5 = String::from("Hello s5");
        s3 = s5; // 字符串所有权转移到父作用域中的变量了，当前子作用域结束后，字符串内容不会回收
    }

    println!("s3: {}", s3);

    println!("-------------借用------------------");

    // 借用
    // 一个值只能有一个所有者
    // 但是有时候我们希望使用一个值，而不拥有这个值，这种需求在函数调用时十分常见
    //

    // 第一种
    // fn echo<T: std::fmt::Display>(s: T) {
    //     println!("{}", s);
    // }

    // let ss = String::from("hello this is a String");
    // // echo(ss);
    // // println!("{}", ss); // 提示ss已经没有所有权

    // echo(&ss); // 借用
    // println!("{}", ss);

    // #[derive(Debug)]
    // struct Person<T,U> {
    //     name: T,
    //     age: U,
    // }

    // impl<T: std::fmt::Display, U: std::fmt::Display> std::fmt::Display for Person<T, U> {
    //     fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
    //         write!(f, "({},{})", self.name, self.age)
    //     }
    // }

    // let jack = Person{name: String::from("Jack"), age: 20};
    // echo(&jack);
    // println!("{:?}", jack);

    // 第二种

    fn echo<T: Debug>(s: T) {
        println!("{:?}", s);
    }

    let ss = String::from("hello this is a String");
    // echo(ss); // 把字符串的所有权已经转移到函数体中去了
    // println!("{}", ss); // 提示ss已经没有所有权

    echo(&ss); // 借用
    println!("{}", ss);

    #[derive(Debug)]
    struct Person<T, U> {
        name: T,
        age: U,
    }

    let mut jack: Person<String, u32> = Person {
        name: String::from("Jack"),
        age: 20,
    };

    echo(&jack);
    println!("{:?}", jack);

    fn change_content(s: &mut Person<String, u32>) {
        // s.name.insert_str(s.name.len(), "哈哈");
        s.name.push_str("哈哈");
        println!("change: {:?}", s);
    }
    change_content(&mut jack); // 借用值并修改
    println!("change: {:?}", jack);

    // 引用可变引用 不可变引用
    // 同一时间内至多只能有一个可变引用

    // 不会有问题
    let s_ref1 = &jack;
    let s_ref2 = &jack;

    // 会有问题 原因：同一时间内至多只能有一个可变引用 
    // 为了防止数据竞争，尤其是多线程中，直接禁止同一时间存在多个可变引用
    // let s_ref3 = &mut jack;
    // let s_ref4 = &mut jack;
    // println!("{:?}", s_ref3);
    // println!("{:?}", s_ref4);




}
