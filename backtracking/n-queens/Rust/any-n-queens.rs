const N: u64 = 8; // change me!
const WIDTH: u64 = ((N * N) + 63) / 64;

fn or(a: &Vec<u64>, b: &Vec<u64>) -> Vec<u64> {
    // bitwise OR over a vec of u64s
    a.iter().zip(b.iter()).map(|(aa, bb)| aa | bb).collect()
}

fn and(a: &Vec<u64>, b: &Vec<u64>) -> Vec<u64> {
    // bitwise AND over a vec of u64s
    a.iter().zip(b.iter()).map(|(aa, bb)| aa & bb).collect()
}

fn not(a: &Vec<u64>) -> Vec<u64> {
    // bitwise NOT on a vec of u64s
    a.iter().map(|aa| !aa).collect()
}

fn shl(a: &Vec<u64>, c: u64) -> Vec<u64> {
    // bitwise shl over a vec of u64s
    let mask = (1 << (64 - c)) - 1;
    let mut carry = 0_u64;
    a.iter()
        .map(|aa| {
            let v = ((aa & mask) << c) | carry;
            carry = (aa & !mask) >> (64 - c);
            v
        })
        .collect()
}

fn shr(a: &Vec<u64>, c: u64) -> Vec<u64> {
    // bitwise shr over a vec of u64s
    let mask = (1 << c) - 1;
    let mut carry = 0_u64;
    let mut ret = a
        .iter()
        .rev()
        .map(|aa| {
            let v = ((aa & !mask) >> c) | carry;
            carry = (aa & mask) << (64 - c);
            v
        })
        .collect::<Vec<u64>>();
    ret.reverse();
    ret
}

struct FreeIterator {
    b: Vec<u64>,
    i: usize,
}
impl Iterator for FreeIterator {
    // iterator to find the position of the 0s in a vec of u64s
    type Item = u64;
    fn next(&mut self) -> Option<Self::Item> {
        while self.b[self.i].count_ones() == 64 {
            self.i += 1;
            if self.i >= self.b.len() {
                return None;
            }
        }
        let sc = self.b[self.i].trailing_ones();
        self.b[self.i] |= 1_u64 << sc;

        let possible = (sc as u64 + self.i as u64 * 64) as u64;
        if possible >= N * N {
            return None;
        }
        Some(possible)
    }
}
fn neg_bits(board: Vec<u64>) -> FreeIterator {
    FreeIterator { b: board, i: 0 }
}

fn attsqs(bb: &Vec<u64>, leftfile: &Vec<u64>, rightfile: &Vec<u64>) -> Vec<u64> {
    // find squares being attacked by the given bitboard
    let mut infile = bb.clone();
    let mut inrank = bb.clone();
    let mut yx = bb.clone();
    let mut ynx = bb.clone();

    for _ in 1..N {
        infile = or(&infile, &shl(&infile, N));
        infile = or(&infile, &shr(&infile, N));
        inrank = or(&inrank, &and(&shl(&inrank, 1), &leftfile));
        inrank = or(&inrank, &and(&shr(&inrank, 1), &rightfile));

        yx = or(&yx, &and(&shl(&yx, N + 1), &leftfile));
        yx = or(&yx, &and(&shr(&yx, N + 1), &rightfile));
        ynx = or(&ynx, &and(&shl(&ynx, N - 1), &rightfile));
        ynx = or(&ynx, &and(&shr(&ynx, N - 1), &leftfile));
    }

    or(&or(&infile, &inrank), &or(&yx, &ynx))
}

fn display(board: &Vec<u64>) {
    // utility function to display a board
    for row in (0..N).rev() {
        for col in 0..N {
            let position = row * N + col;
            let int = board[(position / 64) as usize];
            if (int & (1 << (position % 64))) != 0 {
                print!("# ");
            } else {
                print!(". ");
            }
        }
        println!()
    }
}

fn solve(board: &mut Vec<u64>, prev: u64, toplace: u64, lf: &Vec<u64>, rf: &Vec<u64>) {
    // recursively solve the problem
    if toplace == 0 {
        display(&board);
        println!();
        return;
    }
    for pos in neg_bits(attsqs(&board, lf, rf)).filter(|x| *x >= prev) {
        board[(pos / 64) as usize] |= 1 << (pos % 64); // place queen
        solve(board, pos, toplace - 1, lf, rf);
        board[(pos / 64) as usize] &= !(1 << (pos % 64)); // del queen
    }
}

fn main() {
    let mut board = vec![0_u64; WIDTH as usize];

    let mut leftfile = vec![0_u64; WIDTH as usize];
    leftfile[0] = 1;
    let mut rightfile = vec![0_u64; WIDTH as usize];
    rightfile[0] = 1 << (N - 1);
    for _ in 1..N {
        leftfile = or(&leftfile, &shl(&leftfile, N));
        rightfile = or(&rightfile, &shl(&rightfile, N));
    }

    leftfile = not(&leftfile); // helpful for masking
    rightfile = not(&rightfile);

    solve(&mut board, 0, N, &leftfile, &rightfile);
}
