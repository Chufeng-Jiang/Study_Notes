// 流程控制
// Rust是一个基于表达式的语言
// 表达式总是会返回一个值，而语句不会
// 1 + 1; // 表达式
// let a = 1; // 语句
// Rust大多数代码都会有一个返回值，除了一下语法：

// 1.变量声明
// 2.模块声明
// 3.函数声明
// 4.结构体声明
// 5.枚举声明
// ...
// if else 也是表达式
pub fn my_expressions() {
    println!("-------------expressions------------------");
    let flag = true;
    // if else 非常像三元表达式
    let a = if flag { 10 } else { 20 };
    println!("a = {}", a);

    // loop
    let mut s = 0;
    let mut n = 10;

    // 从0加到10
    let c = loop {
        if n < 0 {
            break s;
        }
        s += n;
        n -= 1;
    };

    println!("c = {}", c);

    println!("-------------if else------------------");
    // 必须保证if else所有分支的返回值类型相同

    let n = 10;
    let res = if n < 0 {
        "负数"
    } else if n > 0 {
        "正数"
    } else {
        "0"
    };

    println!("n是{}", res);

    println!("-------------loop------------------");

    // loop表示无限循环
    // 相当于别的语言的while(true)
    // break 退出循环
    // continue 跳过其余代码并开始下一次循环

    // 计算 1 + 2 + ... + 100

    let mut start = 1;
    let end = 100;
    let mut sum = 0;
    sum = loop {
        sum += start;
        start += 1;
        if start > end {
            break sum;
        }
    };

    println!("1 + 2 + ... + 100 = {}", sum);

    println!("-------------while------------------");

    // 本质上就是一个带循环条件的loop
    // 条件为假时结束循环

    let mut s = 1;
    while s <= 100 {
        if s % 15 == 0 {
            println!("FizzBuzz");
        } else if s % 3 == 0 {
            println!("Fizz");
        } else if s % 5 == 0 {
            println!("Buzz");
        } else {
            // println!("{}",s);
        }
        s += 1;
    }

    println!("-------------for range------------------");
    // for ... in ...可以遍历一个迭代器
    // 有多种方法创建一个迭代器
    // 1.a..b 创建一个包含a不包含b，步长为1的迭代器
    // 2.a..=b 创建一个包含且包含b，步长为1的迭代器

    for i in 0..5 {
        println!("0..5 {}", i);
    }

    for i in 0..=5 {
        println!("0..=5 {}", i);
    }

    // 遍历数组，前提是将数组转换成迭代器 可以使用数组的 .iter() 或 .iter_mut() 方法实现 区别是后者是可变的

    let mut color = [String::from("红"), String::from("蓝"), String::from("绿")];
    for item in color.iter() {
        println!("{}", item);
    }

    for item in color.iter_mut() {
        item.push('0');
        println!("{}", item);
    }

    println!("-------------match------------------");

    #[derive(Debug)]
    enum Alphabet {
        A,
        B,
    }
    let letter = Alphabet::A;
    match letter {
        Alphabet::A => {
            println!("A");
        }
        Alphabet::B => {
            println!("B");
        }
    }

    let op_code: u8 = 30;

    match op_code {
        30 => {
            println!("It is ok!");
        }
        _ => {}
    }

    println!("-------------if let 语法糖------------------");
    // if let 语法糖主要是简化了match操作
    // 仅仅想匹配某一个操作时，忽略其他操作时，
    // 黑可以匹配到枚举中参数

    enum Alphabet1 {
        A(char),
        B,
    }

    let letter = Alphabet::A;
    match letter {
        Alphabet::A => {
            println!("send msg!");
        }
        _ => {}
    }

    if let Alphabet::A = letter {
        println!("if let send msg!");
    }

    let letter = Alphabet1::A('A');

    if let Alphabet1::A(x) = letter {
        println!("{}", x);
    }

    println!("-------------while let 语法糖------------------");

    let lettera = Alphabet::A;
    let mut count = 0;

    while let Alphabet::A = lettera {
        // 当lettera == Alphabet::A 时，循环会一直执行下去
        println!("{:?}", lettera);
        count += 1;
        if count > 10 {
            break;
        }
    }
}
