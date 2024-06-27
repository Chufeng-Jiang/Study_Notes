// 切片类型  是对数组（包括固定大小数组、动态数组）部分引用的工具 不需要拷贝数组和数组中的内容
// 有利于安全有效的访问数组中的一部分
// 切片在编译时长度是未知的，本质上就是一个保存着两个usize成员
// 第一个usize成员指向起始位置，第二个usize成员表示切片的长度

pub fn slice() {
    println!("-------------slice------------------");
    let mut arr = [1, 2, 3, 4, 5];
    let part1 = &arr[0..3]; // ..是Rust里面的Range 语法。 &是引用符号
    println!("part1:");
    for item in part1 {
        println!("part1 {} length {}", item, part1.len())
    }
    // 取数组最后两个元素
    let arr_len = arr.len();
    let start = arr_len - 3;
    let end = arr_len - 1;
    let part2 = &arr[start..end];
    println!("part2:");
    for item in part2 {
        println!("part2 {:?} length {}", item, part2.len())
    }

    // 切片内置函数
    println!(
        "arr.len() = {} ,arr.is_empty() = {}",
        arr.len(),
        arr.is_empty()
    );

    // 创建一个可变的切片
    let mut_slice = &mut arr[..]; // 把可变数组切出一部分，这部分本身就是可变的

    let mut_a = &mut_slice[..];

    println!("mut_a:");
    for mut i in mut_a {
        if *i == 2 {
            i = &200; // 这里修改了，后面打印没有变
        }
        println!("mut_a {}",i);
    }

    for i in mut_a {
        println!("mut_a {}",i);
    }

    mut_slice[0] = 100;
    

    // 如果去修改了一个可变切片引用的元素，则原数组也会改变 这里可以看出，slice就是对原数组的引用
    println!("arr[0] = {}", arr[0]);
    println!("arr[1] = {}", arr[1]);
}
