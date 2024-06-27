use std::fs::read as get_content;
use std::path::PathBuf;

pub fn use_key_words() {
    // use关键字 比如我想从文件中读取main.rs内容，然后打印到输出里面

    let mut config_path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    config_path.push("src");
    config_path.push("main.rs");
    println!("config file: {:?}", config_path);

    // let data = read("src/main.rs").unwrap();
    let data = get_content(config_path).unwrap();
    let content = String::from_utf8(data).unwrap();
    println!("{:?}",content);
}
