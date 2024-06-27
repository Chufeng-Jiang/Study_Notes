// std::cmp::PartialOrd 泛型里面的特征（trait）
// T是type的缩写
fn largest<T: std::cmp::PartialOrd>(a: T, b: T) -> T {
    if a > b {
        a
    } else {
        b
    }
}

pub fn generics() {
    println!("-------------函数泛型------------------");

    let res = largest(10, 20);
    println!("{}", res);
    let res = largest(10.0, 20.0);
    println!("{}", res);
    let a: f32 = 10.56;
    let b: f32 = 20.78;
    let res = largest(a, b);
    println!("{}", res);

    println!("-------------结构体泛型------------------");

    // 使用泛型语法定义结构体
    // 结构体的字段，就可以使用泛型类型参数

    // 点
    #[derive(Debug)]
    struct Point<T> {
        x: T,
        y: T,
    }

    #[derive(Debug)]
    struct PointM<T, U> {
        x: T,
        y: T,
        z: U,
    }

    let integer = Point { x: 5, y: 10 };
    let float = Point { x: 10.5, y: 20.6 };
    println!("integer: {:?}", integer);
    println!("float: {:?}", float);

    let integer_m = PointM { x: 3, y: 5, z: 3.7 };
    let float_m = PointM {
        x: 10.5,
        y: 20.6,
        z: 5.7,
    };
    println!("integer_m: {:?}", integer_m);
    println!("float_m: {:?}", float_m);

    // 复杂泛型定义

    // 线段
    // 结构体泛型嵌套的写法
    #[derive(Debug)]
    struct Line<T> {
        x: Point<T>,
        y: Point<T>,
    }

    let p1 = Point { x: 0, y: 0 };
    let p2 = Point { x: 2, y: 0 };
    let l = Line { x: p1, y: p2 };
    println!("{:?}", l);

    // 为泛型结构体实现一些泛型方法
    // 和普通结构体实现方法，差别不大
    // 只需要注意在定义中加上泛型类型

    // 为泛型结构体实现方法
    impl<T: std::cmp::PartialOrd + Copy> Point<T> {
        fn largest(&self) -> T {
            if self.x > self.y {
                self.x
            } else {
                self.y
            }
        }
    }

    impl<T: std::cmp::PartialOrd + Clone> Point<T> {
        fn smeller(&self) -> T {
            if self.x < self.y {
                self.x.clone()
            } else {
                self.y.clone()
            }
        }
    }

    // 为泛型中某种固定类型实现方法
    impl Point<f32> {
        // 必须使用f32才能调用这个方法
        fn distance_from_origin(&self) -> f32 {
            (self.x.powi(2) + self.y.powi(2)).sqrt()
        }
    }

    let p3 = Point { x: 3, y: 5 };
    println!("largest: {}", p3.largest());
    println!("smeller: {}", p3.smeller());

    let p5 = Point{x: 3.3,y: 5.6};

    println!("distance_from_origin: {}",p5.distance_from_origin());
}
