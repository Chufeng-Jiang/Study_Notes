// 枚举类型包含了所有的取值情况即所有取值的可能性
// 有多种枚举写法

pub fn my_enum() {
    println!("-------------enum------------------");

    // 无参数的枚举
    enum Fruit {
        Apple,
        Banana,
    }

    // 带枚举值的枚举
    enum Color {
        Red = 0xff0000,
        Green = 0x00ff00,
        Blue = 0x0000ff,
    }

    // 带参数的枚举
    enum IPAddr {
        IPv4(u8, u8, u8, u8),
        IPv6(
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
            u8,
        ),
    }

    // 模式匹配 枚举通常与match模式匹配一起使用

    let localhost: IPAddr = IPAddr::IPv4(127, 0, 0, 1);
    match localhost {
        // 把localhost解封装成 a,b,c,d四个变量
        IPAddr::IPv4(a, b, c, d) => {
            println!("{}.{}.{}.{}", a, b, c, d);
        }
        // 如果这个localhost不是IPv4类型，则会走到这个分支
        _ => {}
    }
}
