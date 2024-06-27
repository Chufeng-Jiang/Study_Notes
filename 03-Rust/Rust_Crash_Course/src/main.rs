// 创建变量关键字let rust中变量，默认是不可变的
// 常量使用const定义 可以在任何作用域中声明
// 常量和变量最大的区别是 常量是在编译期间求值的 而不可变变量通常是在运行期间求值的
// 隐藏 可以声明和前面变量同名的新变量
//

pub mod array;
pub mod average;
pub mod error;
pub mod expressions;
pub mod function;
pub mod generics;
pub mod guess_number;
pub mod hash_map;
pub mod int_overflow;
pub mod lifecycle;
pub mod module;
pub mod mutuple;
pub mod my_enum;
pub mod my_slice;
pub mod my_struct;
pub mod my_type_conversion;
pub mod pointer_box;
pub mod str_type;
pub mod super_self;
pub mod tiem;
pub mod traits;
pub mod use_key_words;
pub mod vector;

const COUNT: i32 = 10;

fn get_number() -> i32 {
    42
}

// main 函数可以后返回值
fn main() -> Result<(), error::Error> {
    test_main();
    test_avg();
    test_int_over_flow();
    test_mutuple();
    test_array();
    test_slice();
    test_my_struct();
    test_my_enum();
    test_my_type_conversion();
    test_my_expressions();
    test_function();
    // 猜数字游戏
    // test_guess_number();
    test_module();
    // 读取文件
    // test_use_key_words();
    test_super_self();
    test_generics();
    test_traits();
    test_lifecycle();
    test_error();
    test_pointer_box();
    test_vector();
    test_hash_map();
    test_str_type();
    test_tiem();
    Ok(())
}

fn test_main() {
    // let x = 6; // 默认不可变
    let mut x = 10; // 添加mut可变
                    // 宏是一个支持可变参数的函数
    println!("The value of x is {}", x); // 这是一个宏，宏与函数最大的区别是，宏调用需要在后面加上感叹号

    x = 6;

    let y = get_number(); // 不可变变量通常是运行期间求值
    println!("The value of x is {}", x);
    println!("The value of y is {}", y);
    print!("The value of COUNT is {}", COUNT);

    // 隐藏
    let a = 1;
    let a = a + 1;
    let a = a * 2;
    // 推荐这种写法
    // 隐藏这种操作，在大多数，不可变变量的语言中很常见
    // 新变量和前一个变量名称相同时，新变量会隐藏掉前面的变量
    println!("The value of a is {}", a);
}

fn test_avg() {
    assert_eq!(average::avg(4294967295, 4294967295), 4294967295);
    assert_eq!(average::avg(0, 0), 0);
    assert_eq!(average::avg(10, 20), 15);
    assert_eq!(average::avg(4294967295, 1), 2147483648);
    println!("passed");
}

fn test_int_over_flow() {
    int_overflow::int_over_flow()
}

fn test_mutuple() {
    mutuple::mutuple()
}

fn test_array() {
    array::array();
}

fn test_slice() {
    my_slice::slice();
}

fn test_my_struct() {
    my_struct::my_struct();
}

fn test_my_enum() {
    my_enum::my_enum();
}

fn test_my_type_conversion() {
    my_type_conversion::my_type_conversion();
}

fn test_my_expressions() {
    expressions::my_expressions();
}

fn test_function() {
    function::function();
}

// 猜数字游戏
fn test_guess_number() {
    guess_number::guess_number();
}

fn test_module() {
    module::module();
}

fn test_use_key_words() {
    use_key_words::use_key_words();
}

fn test_super_self() {
    super_self::super_self();
}

fn test_generics() {
    generics::generics();
}

fn test_traits() {
    traits::traits();
}

fn test_lifecycle() {
    lifecycle::lifecycle();
}

fn test_error() {
    error::error();
}

fn test_pointer_box() {
    pointer_box::pointer_box();
}

fn test_vector() {
    vector::vector();
}

fn test_hash_map() {
    hash_map::hash_map();
}

fn test_str_type() {
    str_type::str_type();
}

fn test_tiem() {
    tiem::tiem();
}
