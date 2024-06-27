use std::collections::HashMap;

pub fn hash_map() {
    println!("-------------hash_map------------------");
    // Vector是把数据按照索引来存储的
    // HashMap是一种从key映射到value的数据结构
    // HashMap也是可以动态调整大小的，可以使用以下这些方法创建HashMap
    // 大多数数据类型都可以作为HashMap的key，只要实现了Eq和Hash traits
    // HashMap存储的数据是无序的
    let mut map = HashMap::new();
    map.insert("name", "小明");
    println!("{:?}", map);

    match map.get(&"name") {
        Some(data) => {
            println!("{}", data);
        }
        None => {
            println!("Not found");
        }
    }

    match map.get(&"a") {
        Some(data) => {
            println!("{}", data);
        }
        None => {
            println!("Not found");
        }
    }

    for (name, &value) in map.iter() {
        println!("{} {}", *name, value);
    }

    map.remove(&"name");

    match map.get(&"name") {
        Some(data) => {
            println!("{}", data);
        }
        None => {
            println!("Not found");
        }
    }
}
