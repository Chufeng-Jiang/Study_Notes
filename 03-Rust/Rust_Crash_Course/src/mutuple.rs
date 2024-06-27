// 元组
// 多个具有各种类型的值，组成一个复合类型，元组有固定的长度，一旦声明就不能增大或者缩小

pub fn mutuple() {
    println!("-------------mutuple------------------");
    let a: i32 = 10;
    let b: char = 'A';
    let mutuple = (a, b);
    // 使用模式匹配分解元组值
    let (c, d) = mutuple;
    println!("c = {} ,d = {}", c, d);

    println!("mutuple.0 = {} ,mutuple.1 = {}", mutuple.0, mutuple.1)
}
