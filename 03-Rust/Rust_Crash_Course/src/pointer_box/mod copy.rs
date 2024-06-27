use std::{cell::RefCell, rc::Rc};

// 智能指针 Box
//

pub fn pointer_box() -> Result<(), Box<dyn std::error::Error>> {
    println!("-------------智能指针Box------------------");
    // 智能指针两层意思：
    // - 允许一个值放在堆上，而不是栈上 在Rust里面使用的值，默认是放在栈上面的
    // 甚至，在Rust创建一个数组，数组里面的内容，也是放在栈上的，而不是堆上
    // 如果想放到堆上面，就需要智能指针，而留在栈上的是指向堆的指针
    // - 在适当的时机，自动把引用的数据销毁掉，释放占用的内存
    // 当这个Box的生命周期到了之后，Box指向堆的内存就会被释放
    //
    //

    let a = Box::new(5 /*需要放上堆的数据*/);
    println!("a = {}", a);

    // 在以下三种情况，使用Box比正常的分配更实用、更好：
    // - 当有一个在编译是未知大小的类型，而又想要在确切类型大小的上下文中使用这个类型值的时候

    // Rust需要在编译时知道一个类型占用多少空间
    // 但是有一种类型无法在编译时知道占用空间大小的：递归类型
    // 这个类型值的一部分可以使相同的另一个值
    // 我们可以在递归类型里面插入Box，就可以创建递归类型了
    // ConsList 它的每一项都包含两个元素：当前项和下一项，以及结束时包含结束项
    // ConsList(0,ConsList(1,ConsList(2,Nil)))

    #[derive(Debug)]
    enum List {
        Cons(i32, Box<List>), // 不直接包含List而是存储指向List的地址
        Nil,
    }

    fn cbox(x: List) -> Box<List> {
        return Box::new(x);
    }

    // 应用场景很广泛，比如二叉树，字典树，都是递归结构，链表
    // let list = List::Cons(
    //     0,
    //     Box::new(List::Cons(1, Box::new(List::Cons(2, Box::new(List::Nil))))),
    // );

    let list = List::Cons(0, cbox(List::Cons(1, cbox(List::Cons(2, cbox(List::Nil))))));

    // let mut list: Box<List>;
    // for i in 0..3 {
    //     list = cbox(i,);
    // }

    println!("{:?}", list);

    #[derive(Debug)]
    struct Link {
        next: Option<Box<Link>>,
        content: String,
    }

    // impl Link {
    //     fn new(next: Option<Box<Link>>, content: String) -> Link {
    //         Link { next, content }
    //     }
    // }

    let mut root = Link {
        next: None,
        content: String::from("0"),
    };

    let next = Option::Some(Box::new(Link {
        next: None,
        content: String::from("1"),
    }));

    root.next = next;

    // 简化了match操作
    if let Some(ref mut x) = root.next {
        let next = Option::Some(Box::new(Link {
            next: None,
            content: String::from("2"),
        }));
        x.next = next;
    }

    println!("{:?}", root);

    // impl Default for Link {
    //     fn default() -> Self {
    //         return Link{end: false,next: unimplemented!(),content: String::new()};
    //         // todo!()
    //     }
    // }

    // - 当有大量数据并希望在确保数据不被拷贝的情况下转移所有权

    // 在Rust中定义所有权时，默认是存在栈里面的，如果存在栈里面的数据非常多，这样进行转移所有权的时候就会出现数据拷贝，
    // 如果不希望拷贝的话，可以放到Box里面，这样在所有权转移的时候，转移的是地址
    // 地址 指向堆里的数据是不会移动的

    let arr = [0; 1024]; // 这个声明的数组成员是存储在栈上面的，Rust的栈是有限额的

    let box_arr = Box::new(arr); // arr这个数据已经放到堆上面了，这个放到堆上面的动作一定会发生内存拷贝的

    // - 当希望拥有一个值并只关心它的类型是否实现了特定trait而不是具体类型
    // 一般main函数会返回Result<(),Box<dyn std::error::Error>>

    // 只关心是否实现了特定的trait，类似golang的interface和java里面的接口

    println!("-------------高级的智能指针Rc------------------");
    // 带引用计数的智能指针
    // 一般情况下，Rust中，哪个变量拥有哪个值是十分明确的
    // 但是有些情况下，一个值会有多个所有者
    // 0 -> 1 \
    //         | -> 4 // 4是共享的,被1和3共同所有
    // 2 -> 3 /

    #[derive(Debug)]
    enum ListM {
        Cons(i32, Rc<ListM>),
        Nil,
    }

    let n4 = Rc::new(ListM::Cons(4, Rc::new(ListM::Nil)));

    let n0 = Rc::new(ListM::Cons(
        0,
        Rc::new(ListM::Cons(
            1,
            Rc::clone(&n4), /*引用计数会加1的*/
        )), // 可以使用n4.clone()，但是容易引起误解，一般用这个Rc::clone(&n4)
    ));

    let n2 = Rc::new(ListM::Cons(2, Rc::new(ListM::Cons(3, n4.clone()))));

    println!("{:?}", n0);
    println!("{:?}", n2);

    #[derive(Debug)]
    struct Node {
        children: Rc<RefCell<Vec<Rc<RefCell<Node>>>>>,
        tag: String,
    }

    let mut n1 = Node {
        children: Rc::new(RefCell::new(vec![])),
        tag: String::from("div"),
    };
    let n2 = Node {
        children: Rc::new(RefCell::new(vec![])),
        tag: String::from("span"),
    };
    let n3 = Node {
        children: Rc::new(RefCell::new(vec![])),
        tag: String::from("img"),
    };
    let stack: Rc<RefCell<Vec<Rc<RefCell<Node>>>>> = Rc::new(RefCell::new(vec![]));
    let rc_n2 = Rc::new(RefCell::new(n2));
    n1.children.borrow_mut().push(rc_n2.clone());
    stack.borrow_mut().push(rc_n2.clone());

    let mut stack1: Vec<Rc<RefCell<Node>>> = vec![Rc::new(RefCell::new(n3))];
    let res = stack1.pop().ok_or("err")?;
    let temp = res.borrow_mut();
    temp.children.borrow_mut().push(rc_n2.clone());

    println!("stack: {:?}", stack.to_owned());
    println!("n1: {:?}", n1);
    println!("n1: {:?}", res);

    Ok(())
}
