use std::time::{Duration, SystemTime};

use std::thread::sleep;

pub fn tiem() {
    println!("-------------time------------------");
    // Rust时间处理，只实现了一些基础方法
    // 如果你要实现一些高级方法，日期之类的
    // 星期等 需要使用第三方库 chrono

    // 系统时间，不是真实世界的时间
    // 是Rust通过系统调用，操作系统返回给Rust的时间
    let now = SystemTime::now();
    println!("{:?}", now);

    // timestamp 是1970年1月1日到现在的秒数
    let time_stamp = now.duration_since(SystemTime::now() + Duration::from_secs(60));
    let res: Duration = match time_stamp {
        Ok(data) => {
            println!("{:?}", data);
            data
        }
        Err(err) => {
            println!("{:?}", err);
            Duration::from_secs(0) // 无法处理
                                   // unimplemented!()
                                   // todo!()
                                   // unreachable!()
        }
    };
    println!("{:?}", res);
    let time_stamp = now.duration_since(SystemTime::UNIX_EPOCH).unwrap();
    println!("time_stamp: {:?}", time_stamp);

    let start = SystemTime::now();
    let since_the_epoch = start
        .duration_since(SystemTime::UNIX_EPOCH)
        .expect("Time went backwards");
    println!("since_the_epoch: {:?}", since_the_epoch);

    let in_ms =
        since_the_epoch.as_millis();

    println!("in_ms: {:?}", in_ms);

    // sleep(Duration::from_secs(2));
    // ela 航运常见 一艘船从港口出发到上岸为止
    println!("after 2s {:?}", now.elapsed().unwrap());

    // 拿到当前时间，来取得一分钟后的时间和一小时后的时间
    let after_miut = now.checked_add(Duration::from_secs(60));
    println!("{:?}", after_miut);
}
