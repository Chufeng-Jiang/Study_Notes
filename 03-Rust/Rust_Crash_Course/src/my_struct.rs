// Rust 是多范式的编程，支持函数式、面向对象、面向过程
// 结构体不是对象
// 结构体是数据的集合 对象是数据和算法的集合
// 结构体与元组类似，区别是我们可以为每个结构成员体命名

// 可以使用struct关键字创建三种不同的结构
// 1.元组结构

struct A(i32, f32);

// 2.经典的C结构

// derive派生属性 是一个编译时的语法
#[derive(Debug)]
struct Person {
    name: String,
    age: u32,
}
// 2.无字段的单元结构
// 一般用于泛型
// 很少用到
struct Unit;

// 命名是有标准的 使用驼峰命名
pub fn my_struct() {
    println!("-------------struct------------------");
    let a = A(10, 5.6);
    println!("a.0 = {},a.1 = {}", a.0, a.1);
    let jack = Person {
        // name: "jack".to_string(),
        name: String::from("jack"),
        age: 20,
    };
    println!("jack.name = {}, jack.age = {}", jack.name, jack.age);
    println!("{:?}",jack);

    let unit = Unit;
}
