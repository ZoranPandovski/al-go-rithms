use List::{Item, Nil};

// linked list implementation in rust

fn main() {
    let mut list = List::new();
    list = list.prepend(1);
    list = list.prepend(2);
    list = list.prepend(3);
    list = list.prepend(4);

    println!("len of final linked list {}", list.len());
    println!("{}", list.stringify());
}

enum List {
    Item(u32, Box<List>),
    Nil,
}

impl List {
    fn new() -> List {
        Nil
    }
    fn prepend(self, elem: u32) -> List {
        Item(elem, Box::new(self))
    }
    fn len(&self) -> u32 {
        match *self {
            Item(_, ref tail) => 1 + tail.len(),
            Nil => 0
        }
    }
    fn stringify(&self) -> String {
        match *self {
            Item(head, ref tail) => {
                format!("{}, {}", head, tail.stringify())
            },
            Nil => {
                format!("Nil")
            }
        }
    }
}

