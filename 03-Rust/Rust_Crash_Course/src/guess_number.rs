use rand::Rng;
use std::io;

// 猜数字游戏
pub fn guess_number() {
    println!("-------------猜数字游戏------------------");
    println!("Guess the number!");
    // 随机生成一个1-100之间的整数
    let secret_number: u32 = rand::thread_rng().gen_range(1..101);

    loop {
        // 获取用户的输入
        println!("Please input your guess:");
        let mut input = String::new();
        // unwrap会在read_line返回error时立刻退出程序运行
        io::stdin().read_line(&mut input).unwrap(); // read_line会返回这个类型io::Result<usize>，如果正常情况会返回usize，错误情况会返回error

        // trim把回车符移除掉
        let gess_to_number: u32 = match input.trim().parse() {
            Ok(num) => num,
            Err(err) => continue,
        };

        println!("you guess is {}", gess_to_number);
        // 判断大小

        if gess_to_number > secret_number {
            println!("too big");
        } else if gess_to_number < secret_number {
            println!("too small");
        } else {
            // 如果正确程序退出
            println!("you win!");
            break;
        }
    }
}
