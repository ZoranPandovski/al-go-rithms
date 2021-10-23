use std::time::Instant;

mod l0j0 {
    use std::cmp::PartialEq;
    use std::fmt::Debug;

    pub trait Hashable {
        fn hash(&self) -> usize;
    }

    impl Hashable for String {
        fn hash(&self) -> usize {
            let mut result: usize = 5381;
            for c in self.bytes() {
                result = ((result << 5).wrapping_add(result)).wrapping_add(c.into());
            }
            result
        }
    }

    impl Hashable for usize {
        fn hash(&self) -> usize {
            *self >> 27
        }
    }

    #[derive(Default, Clone)]
    struct HashCell<Key, Value> {
        key: Key,
        value: Value,
        taken: bool,
    }

    pub struct HashTable<Key, Value> {
        cells: Vec<HashCell<Key, Value>>,
        taken_count: usize,
    }

    impl<Key, Value> HashTable<Key, Value>
    where
        Key: Clone + Default + Debug + PartialEq + Hashable,
        Value: Clone + Default + Debug,
    {
        pub fn new() -> Self {
            const INITIAL_CAPACITY: usize = 50;
            Self {
                cells: vec![HashCell::<_, _>::default(); INITIAL_CAPACITY],
                taken_count: 0,
            }
        }

        pub fn extend(&mut self) {
            assert!(self.cells.len() > 0);
            let mut new_self = Self {
                cells: vec![HashCell::<_, _>::default(); self.cells.len() * self.cells.len() + 1],
                taken_count: 0,
            };

            for cell in self.cells.iter() {
                if cell.taken {
                    new_self.insert(cell.key.clone(), cell.value.clone());
                }
            }

            *self = new_self;
        }

        pub fn insert(&mut self, key: Key, new_value: Value) {
            if let Some(old_value) = self.get_mut(&key) {
                *old_value = new_value;
            } else {
                if self.taken_count >= self.cells.len() {
                    self.extend();
                }
                assert!(self.taken_count < self.cells.len());

                let mut index = key.hash() % self.cells.len();

                while self.cells[index].taken {
                    index = (index + 1) % self.cells.len();
                }

                self.cells[index].taken = true;
                self.cells[index].key = key;
                self.cells[index].value = new_value;
                self.taken_count += 1;
            }
        }

        fn get_index(&self, key: &Key) -> Option<usize> {
            let mut index = key.hash() % self.cells.len();
            for _ in 0..self.cells.len() {
                if !self.cells[index].taken {
                    break;
                }

                if self.cells[index].key == *key {
                    break;
                }

                index = (index + 1) % self.cells.len();
            }

            if self.cells[index].taken && self.cells[index].key == *key {
                Some(index)
            } else {
                None
            }
        }

        #[allow(dead_code)]
        pub fn get(&self, key: &Key) -> Option<&Value> {
            if let Some(index) = self.get_index(key) {
                Some(&self.cells[index].value)
            } else {
                None
            }
        }

        pub fn get_mut(&mut self, key: &Key) -> Option<&mut Value> {
            if let Some(index) = self.get_index(key) {
                Some(&mut self.cells[index].value)
            } else {
                None
            }
        }
    }
}

fn benchmark_our_version_table(n: usize) {
    use l0j0::*;
    let mut hash = HashTable::<usize, usize>::new();
    for _ in 0..n {
        let key = rand::random::<usize>();
        if let Some(value) = hash.get_mut(&key) {
            *value += 1;
        } else {
            hash.insert(key, 1);
        }
    }
}

fn benchmark_std_rust_table(n: usize) {
    use std::collections::HashMap;

    let mut hash = HashMap::<usize, usize>::new();
    for _ in 0..n {
        let key = rand::random::<usize>();
        if let Some(value) = hash.get_mut(&key) {
            *value += 1;
        } else {
            hash.insert(key, 1);
        }
    }
}

fn main() {
    const N: usize = 100_000;

    let begin = Instant::now();
    benchmark_our_version_table(N);
    println!("Our Virgin Table: {}", begin.elapsed().as_secs_f32());

    let begin = Instant::now();
    benchmark_std_rust_table(N);
    println!("std Chad Table: {}", begin.elapsed().as_secs_f32());
}
