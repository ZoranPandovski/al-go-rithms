def move( n, src, dest, temp ):

	if n >= 1 : 
		move( n - 1, src, temp, dest )
	
		print( "Moving %d -> %d" % (src, dest))

		move( n - 1, temp, dest, src )


def main():
	move(3,1,3,2)
	
if __name__ == "__main__":
	main()
