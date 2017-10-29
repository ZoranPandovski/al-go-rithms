 #!/bin/bash

#########################################
disks=$1
moves=0

margin=2
width=7

let "basewidht=$width * $disks + $margin"

let "disks1= $disks-1"
let "spaces1= $disks"
let "spaces2= 2 * $disks"

let "lastmove_t = $disks-1"

declare -a stacks1 stacks2 stacks3

#############VARIABLES###################

#########################################

function draw_space () {
local N

for (( N=0; N < $2; N++)); do
echo -n "$1"
done
}

function from (){
local stack summit weight sequence

while true; do
stack=$1
test ${stack/[^123]/} || break;

sequence=$(echo $(seq 0 $disks1 | tac))
for summit in $sequence; do
eval weight=\${stacks${stack}[$summit]}
test $weight -ne 0 && { echo "$stack $summit $weight"; return; }
done
done
}

function to (){

local stack first weight sequence

while true; do
stack=$2
test ${stack/[^123]} || continue

sequence=$(echo $(seq 0 $disks1 | tac))
for first in $sequence; do
eval weight=\${stacks${stack}[$first]}
test $weight -gt 0 && { (( first++ )); break; }
done
test $weight -gt $1 -o $first = 0 && { echo "$stack $first"; return; }
done
}

##################MOVES##################

function print {

local disk stack empty fill sp sequence

draw_space " " $spaces1
echo -n "|"
draw_space " " $spaces2
echo -n "|"
draw_space " " $spaces2
echo "|"

sequence=$(echo $(seq 0 $disks1 | tac))
for disk in $sequence; do
for stack in {1..3}; do
eval empty=$(( $disks - (stacks${stack}[$disk] / 2)))
eval fill=\${stacks${stack}[$disk]}
draw_space " " $empty
test $fill -gt 0 && draw_space "*" $fill "" || echo -n "|"
draw_space " " $empty
done
echo
done
draw_space "=" $basewidht
echo
}

display (){

echo
print

first=(`from $1`)
eval stacks${first[0]}[${first[1]}]=0

second=(`to ${first[2]} $2`)
eval stacks${second[0]}[${second[1]}]=${first[2]}

echo; echo; echo

if [ "${stacks3[lastmove_t]}" = 1 ]
then
echo "+ Final Position: $moves moves"; echo
print
fi
}
##################PRINT##################

#########################################
function hanoi (){
if [ "${1:-0}" -ne 0 ]
then
hanoi "$(($1-1))" $2 $4 $3

if [ "$moves" -ne 0 ]
then
echo "+ Position after move: $moves"
fi
((moves++))
echo -n " Next move will be: "
echo $2 "-->" $3
display $2 $3
hanoi "$(($1-1))" $4 $3 $2
fi
}

################ALGORITHM################

clear_array(){
local dim n elem

let "dim1 = $1-1"
elem=$dim1

for n in $(seq 0 $dim1)
do
let "stacks1[$elem] = 2 * $n +1"
stacks2[$n]=0
stacks3[$n]=0
((elem--))
done
}

###################MISC##################

clear_array $disks
echo; echo "+ Start Position"
disks=$1
hanoi $1 $2 $4 $3
exit
