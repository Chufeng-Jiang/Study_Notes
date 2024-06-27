pub fn avg(a: u32, b: u32) -> u32 {
    // 求平均数
    // 主要是处理整数溢出
    let c = (a & b)/*按位与*/ + ((a ^ b)/*求异或*/ >> 1);
    return c;
}
