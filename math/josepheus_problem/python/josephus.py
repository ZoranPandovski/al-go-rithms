from __future__ import print_function
def josephus(list_of_players, step):
	#skipdeadguy
	step -= 1 
	index = step
	while len(list_of_players) > 1:
		print("Player Died : " , list_of_players.pop(index))
		index = (index + step) % len(list_of_players)
	print('Player Survived : ', list_of_players[0])

def main():
	print("[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15], 5")
	josephus([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15], 5)

if __name__ == "__main__":
    main()
