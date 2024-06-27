fn function() {
    println!("function");
}

mod mod_test {
    pub fn function() {
        super::function();
    }
}


pub fn super_self() {
    println!("-------------super_self------------------");
    mod_test::function();
}