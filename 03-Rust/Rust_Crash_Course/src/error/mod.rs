use core::panic;

// 对错误类型进行包装

#[derive(Debug)]
pub enum Error {
    IO(std::io::ErrorKind),
    Utf8Error(std::str::Utf8Error),
}

pub fn error() {
    println!("-------------错误处理------------------");
    // 错误和异常是不同的东西
    // 错误：一个开发者能解决的问题，并应该解决的问题
    // 异常：开发者处理不了的问题，遇到了异常一般就是代码写错了
    // 异常例子：数组长度是10，你要去取索引为11的值，这就是代码写错了导致的异常

    // Rust中异常被称为不可恢复的错误
    // 遇到了这种错误，程序直接崩溃掉
    // 还有一种可恢复错误
    // 当访问文件时，文件不存在，开发者有能力处理这个错误

    // 不可恢复错误，有很多种
    // - 最简单的是panic! 宏
    // panic!("error!");
    // - 断言也可以生成不可恢复错误
    // assert!(1 == 2);
    // assert_eq!(1,2);
    // - 未实现的代码 unimplemented这个宏
    // fn add(a: u32,b: u32) -> u32 {
    //     unimplemented!(); // 未实现
    // }
    // let res = add(1,2);
    // - 不应当被访问到的代码 如果这段代码被执行，那么程序一定会出现问题
    // unreachable
    fn divide_by_three(x: u32) -> u32 {
        // for i in 0.. {
        //     if 3 * i < i {
        //         panic!("u32 overflow!");
        //     }
        //     if x < 3 * i {
        //         return i - 1;
        //     }
        // }
        unreachable!();
    }
    // divide_by_three(20);

    // 可恢复的错误
    // 主要是用带泛型的枚举Result来处理
    // -
    let a: Result<u32, &'static str> = Result::Ok(1);
    println!("{:?}", a);

    let b: Result<u32, &'static str> = Result::Err("Error");
    println!("{:?}", b);

    // 一般作为返回值来使用
    // std::fs::read
    let r = std::fs::read("src/a.rs");
    match r {
        Ok(data) => {
            println!("{:?}", std::str::from_utf8(&data).unwrap());
        }
        Err(err) => {
            println!("{:?}", err);
        }
    }

    println!("-------------错误传递------------------");

    // 如果当前层遇到错误，现在不想处理，不仅仅希望获取错误，更希望错误可以在上下文中进行传递
    // 有一种简易的方式可以进行错误传递：使用问号表达式。
    // 当函数的错误类型与当前错误的类型相同时，使用?可以直接将错误传递到函数外部并终止函数执行
    // 尤其是在编写库的时候

    // Ok的类型可以不同 Err类型必须一样

    fn bar() -> Result<u32, &'static str> {
        Ok(0)
    }
    fn foo() -> Result<i32, &'static str> {
        match bar() {
            Ok(data) => {
                return Ok(data as i32);
            }
            Err(err) => return Err(err),
        }

        // 上下两种写法相同

        // let a = bar()?;
        // Ok(a as i32)
    }

    println!("{:?}", foo());

    // 对错误类型进行包装

    // 实现了from这个trait，这个trait里面有个叫from的函数
    impl From<std::io::Error> for Error {
        fn from(error: std::io::Error) -> Self {
            Error::IO(error.kind())
        }
    }

    impl From<std::str::Utf8Error> for Error {
        fn from(error: std::str::Utf8Error) -> Self {
            Error::Utf8Error(error)
        }
    }

    fn read_file1() -> Result<&'static str, Error> {
        let data = std::fs::read("src/main.rs")?;
        let content: &str = std::str::from_utf8(&data)?;
        // println!("read_file1_inner: {:?}", content); // 暂时注释
        Ok("ok")
    }

    fn file() -> String {
        let data = std::fs::read("src/main.rs");
        match data {
            Ok(data) => {
                return std::str::from_utf8(&data).unwrap().to_string();
            }
            // _=> {}
            Err(err) => {
                println!("{:?}", err);
                unimplemented!()
            }
        }
    }

    let files = file();
    // println!("files: {}", files); // 暂时注释

    fn file_error() -> Result<String, Error> {
        let data = std::fs::read("src/a.rs")?;
        let content = std::str::from_utf8(&data)?;
        Ok(content.to_string())
    }

    let file_content = file_error();
    println!("file_content: {:?}", file_content);

    match read_file1() {
        Ok(data) => {
            // println!("{:?}", data); // 暂时注释
        }

        Err(e) => {
            println!("{:?}", e)
        }
    }

    fn read_file() -> Result<() /*空类型*/, Error> {
        let data = std::fs::read("src/a.rs")?;
        let content = std::str::from_utf8(&data).unwrap();
        println!("{:?}", content);
        Ok(())
    }

    match read_file() {
        Ok(data) => {}
        Err(err) => {
            println!("{:?}", err);
        }
    }
}
