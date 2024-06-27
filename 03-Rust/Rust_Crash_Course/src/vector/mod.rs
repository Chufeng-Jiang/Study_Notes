pub fn vector() {
    println!("-------------向量------------------");
    // Vec是动态大小的数组，与切片一样，它们的大小在编译时是未知的
    // 但它们可以随时增长或收缩
    // Vec使用三个参数表示
    // - 指向数据的指针
    // - 长度
    // - 容量 预留的内存

    let mut v: Vec<i32> = Vec::new();
    for i in 0..10 {
        v.push(i);
    }
    println!("{:?}", v);

    let mut vv: Vec<i32> = vec![0, 1, 2, 3];
    println!("{:?} len = {} capacity = {}", vv, vv.len(), vv.capacity());

    // 向量迭代

    for i in 0..vv.len() {
        println!("{:?}", vv[i]);
    }

    for item in vv.iter() {
        println!("{:?}", item);
    }

    for item in vv.iter_mut() {
        *item *= 2;
        println!("{:?}", item);
    }

    println!("{:?} len = {} capacity = {}", vv, vv.len(), vv.capacity());
    // copy_from_slice()
    // last()
    
}
