def Tower(height,fromP,toP,aux):
	if(height>=1):
		Tower(height-1,fromP,aux,toP)
		move(fromP,toP)
		Tower(height-1,aux,toP,fromP)
		
def move(fromP,toP):
	print("Moving Disk from pole "+fromP+" to pole "+toP)
	
Tower(3,"1","2","3")