function move( n, src, dest, temp ) {

	if (n >= 1) {
		move(n - 1, src, temp, dest);
		console.log(`Moving ${src} -> ${dest}`);
		move(n - 1, temp, dest, src);
    }
}

move(3,1,3,2);
