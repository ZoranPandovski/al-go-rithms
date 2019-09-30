//Performs the fast exponentiation algorithm by repeated squaring operations
fn fast_exponentiation(base: u64, exponent: u64) -> u64 {
	if exponent == 0 {
		return 1;
	}

	if exponent == 1 {
		return base;
	}

	if exponent % 2 == 0 {
		return fast_exponentiation(base*base, exponent/2);
	} else {
		return base * fast_exponentiation(base*base, (exponent-1)/2);
	}
}


fn main() {
    println!("fast_exp({}, {}) = {} equals pow({},{}) = {}", 10, 1, fast_exponentiation(10, 1), 10, 1, 10_u64.pow(1));
    println!("fast_exp({}, {}) = {} equals pow({},{}) = {}", 10, 0, fast_exponentiation(10, 0), 10, 0, 10_u64.pow(0));
    println!("fast_exp({}, {}) = {} equals pow({},{}) = {}", 20, 3, fast_exponentiation(20, 3), 20, 3, 20_u64.pow(3));
    println!("fast_exp({}, {}) = {} equals pow({},{}) = {}", 4, 20, fast_exponentiation(4, 20), 4, 20, 4_u64.pow(20));
}