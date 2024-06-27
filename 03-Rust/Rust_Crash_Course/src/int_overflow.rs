pub fn int_over_flow() {
    // let a: u32 = 4294967295; // 2^32 - 1
    // 这里处理是将字符串转为数字
    // unwrap是在parse过程中遇到任何问题，程序就崩溃退出
    // cargo build 默认是debug模式，运行时整形溢出会报错
    // 可以使用cargo build --release
    let a: u32 = "4294967295".parse::<u32>().unwrap(); // 2^32 - 1
    let b: u32 = 1;
    // let c: u32 = a + b;
    // println!("sum = {}", c);

    // 如果我们能预见，加法操作会溢出，那么推荐使用，如果不能预见不会溢出，则就认为会溢出，然后使用下面的方法
    let (c /*相加之后的结果*/, _is_overflow /*是否溢出*/) = a.overflowing_add(b); // 会返回一个元组
    println!("sum = {}， _is_overflow = {}", c, _is_overflow);
}
