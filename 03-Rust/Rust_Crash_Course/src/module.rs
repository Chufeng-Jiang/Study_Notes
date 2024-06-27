pub fn module() {
    // 模块可见性
    mod mod1 {
        pub const MSG: &str = "hello";
        pub mod mod2 {
            pub const MSG1: &str = "hello";
            pub fn hey() {
                println!("{}", super::MSG);
            }
        }
    }

    println!("-------------模块可见性------------------");
    println!("{}", mod1::mod2::MSG1);
    mod1::mod2::hey();
    // 结构体可见性
    println!("-------------结构体可见性------------------");
    // 结构体中的字段和方法默认是私有的，但是 与结构体同一个模块的代码可以自由访问结构体的字段和方法

    mod mod3 {
        #[derive(Debug)]
        pub struct Person {
            pub name: String,
            nick_name: String,
        }
        impl Person {
            pub fn new(name: &str) -> Self {
                Person {
                    name: name.to_string(),
                    nick_name: String::new(), // 创建空的string
                }
            }

            pub fn set_nick_name(&mut self, nick_name: &str) {
                self.nick_name = nick_name.to_string();
            }

            pub fn say(&self) {
                println!("{}",self.nick_name);
            }
        }
    }

    let mut p = mod3::Person::new("小明");
    println!("{}",p.name);
    p.set_nick_name("xiaoming");
    p.say();
    // println!("{}",p.nick_name);// 私有的字段，不能打印
}
