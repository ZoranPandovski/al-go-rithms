function approximatePi(iterations = 10000) {
	let a = 0;
	for(let k = 0; k < iterations; k++) {
		a += Math.pow(-1, k) / (2 * k + 1);
	}
	return 4 * a;
}

approximatePi(1)         // 4                  with a difference of -0.8584073464102069
approximatePi(10)        // 3.0418396189294032 with a difference of  0.09975303466038987
approximatePi(100)       // 3.1315929035585537 with a difference of  0.00999975003123943
approximatePi(1000)      // 3.140592653839794  with a difference of  0.000999999749998981
approximatePi(10000)     // 3.1414926535900345 with a difference of  0.0000999999997586265
approximatePi(100000)    // 3.1415826535897198 with a difference of  0.000010000000073340232
approximatePi(1000000)   // 3.1415916535897743 with a difference of  0.0000010000000187915248
approximatePi(10000000)  // 3.1415925535897915 with a difference of  0.00000010000000161269895
approximatePi(100000000) // 3.141592643589326  with a difference of  0.000000010000467121074053
Math.PI                  // 3.141592653589793
