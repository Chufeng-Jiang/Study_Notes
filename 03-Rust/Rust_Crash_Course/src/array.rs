// 数组 一系列类型相同的数据 且有序保存
// rust里面的数组有一个固定的长度，不能去修改 且有越界检查
pub fn array() {
    println!("-------------array------------------");
    let myarray: [u32;/*类型*/ 5/*大小*/] = [1, 2, 3, 4, 5];
    let mut index = 0;
    for item in myarray {
        println!("index = {} value = {}", index, item);
        index = index + 1;
    }

    // let i = 5;

    // 当parse失败时程序会崩溃
    // let j = "a".parse::<usize>();
    // println!("{}",j);

    // let i = "5".parse::<usize>().unwrap(); // 使用unwrap当parse失败时程序会崩溃

    // println!("{}", myarray[i]);

    // 如果数组成员有相同的值

    let mybuffer: [u32; 32 * 1024] = [0; 32 * 1024]; // 32 * 1024个0
    println!("{}", mybuffer[1024]);

    // 修改数组元素
    let mut change_array = [1, 2, 3, 4, 5];
    println!("before change_array[3] = {}", change_array[3]);
    change_array[3] = 100;
    println!("after change_array[3] = {}", change_array[3]);
}
