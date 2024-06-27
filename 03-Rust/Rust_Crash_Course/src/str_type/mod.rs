fn echo(str: &str) {
    println!("{}", str);
}

#[derive(Debug)]
struct Student {
    name: String,
}

pub fn str_type() -> Result<(), Box<dyn std::error::Error>> {
    println!("-------------str_type------------------");
    // 放在函数的参数里面使用&str
    // 如果定义一个结构体，结构图里面的成员，是字符串类型，使用String
    // Rust的字符串表示有什么区别，如何去使用他们

    // "hello world"这一段数据是存储二进制文件中的
    // "hello world" 叫做字符串的字面量

    // 直接编译到二进制文件里面 被保存到数据段的地方（数据段、栈段、代码段）
    // 数据段是专门用来存储数据的地方，不会变的数据
    let s = "hello world"; // 在整个程序运行期间，都不会变
                           // s的真实类型是一个具有静态生命周期的引用
                           // let s:&'static str = "hello world";

    // 在Rust里面几乎不会用到str这个类型
    // 我们总会使用str的引用
    // str 代表的是存储在内存中的字符串数据
    // 如果我们使用这个数据，只能去使用这个引用
    // 内存是分段使用的，（数据段、代码段、堆、栈...）
    // &str可以引用数据段的内容
    // 也可以是堆里面的内容

    let mut t: String = String::from(s);
    // String类型，它拥有自己的数据，而上面说的变量s，不拥有自己的数据，是一个引用
    // 拥有自己的数据的好处是可以修改，
    // String 类型数存储在堆里面的 String类型的变量，存储的是堆中的地址
    t.push_str("haha");
    println!("{}", t);
    echo(s);
    echo(&t); // 传入String

    let zs = Student {
        name: String::from("张三"),
    };
    println!("{:?}", zs); // Rust自动实现了Debug，可以通过{:?}来打印

    let str = String::from("小明");
    for item in str.chars() {
        println!("{}", item);
    }

    let ss = "小明";
    println!("{:?}",ss.get(0..1));
    Ok(())
}
