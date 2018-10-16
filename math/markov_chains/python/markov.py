#USAGE
#python3 markov.py textFile.txt
#generates random text using textFile.txt
#
#program will use the article below if file doesn't exist or specified
sampleArticle = """\
Kung Fury
From Wikipedia, the free encyclopedia

Sometime in the early 1980s, Miami-Dade Police Department detective Kung Fury and his partner Dragon apprehend a red ninja in a back alley, but Dragon is sliced in half by the ninja while Kung Fury is suddenly struck by lightning and bitten by a cobra, giving him extraordinary kung fu powers that enable him to defeat his foe. Years later in 1985, after defeating a rogue arcade machine robot, Kung Fury quits the force when he is assigned to partner with Triceracop, fearing that he would lose another partner in the line of duty. Meanwhile, Adolf Hitler, a.k.a. "Kung Führer", enters the timeline and remotely guns down the police chief and attacks the precinct through a mobile phone. Intent to avenge the chief, Kung Fury has computer whiz Hackerman send him back in time to kill Hitler in Nazi Germany. A glitch in the system, however, sends him back into the Viking Age. After Kung Fury meets the Viking valkyries Barbarianna and Katana, the Norse god Thor sends him to Nazi Germany for him to finish his job.

Upon his arrival, Kung Fury singlehandedly mows down dozens of Nazi soldiers with his kung fu skills, but is gunned down by Hitler using a Gatling-type gun from inside his podium. Suddenly, Thor, Hackerman, Triceracop, the Viking Babes, and a tyrannosaurus hack into the timeline and kill the rest of the Nazi army while the tyrannosaurus squares off against Hitler's robotic Reichsadler. After being revived by Hackerman, Kung Fury gives Hitler an uppercut to the testicles before Thor drops his hammer on the Nazi leader and his robotic eagle. Seeing his mission as accomplished, Kung Fury returns to his timeline.

Back in 1985 Miami, Kung Fury once again battles and defeats the arcade machine robot, but notices a Swastika on the robot's body while Hitler and his Reichsadler enter the timeline, vowing revenge on Kung Fury. """
import sys
from random import choice

try:
	with open(sys.argv[1]) as f:
		text=f.read()
except FileNotFoundError:
	print("!!! File named "+sys.arhv[1]+" is not found. Using internal sample article !!!\n")
	text=sampleArticle
except IndexError:
	print("!!! No file specified. Using internal sample article !!!\n")
	text=sampleArticle

matrix = {}
step=2  # how long is one chain?
length=400  #length of generated text

for i in range(step,len(text),step):
	try:
		key=text[i-step:i]
		r=text[i:i+step]
	except IndexError:
		break
	if key in matrix:
		matrix[key].append(r)
	else:
		matrix[key] = [ r ]


b=choice(list(matrix.keys()))
out=b

while len(out)<length:
	b=choice(matrix[b])
	out+=b

print(out)
