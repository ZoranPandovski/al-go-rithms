# watchdog process
#mainpid=$$
#(sleep 30; kill $mainpid) &
#watchdogpid=$!

#possible timer, wont use
#timeout() {
#
#    time=$1
#
#    # start the command in a subshell to avoid problem with pipes
#    # (spawn accepts one command)
#    command="/bin/sh -c \"$2\""
#
#    expect -c "set echo \"-noecho\"; set timeout $time; spawn -noecho $command; expect timeout { exit 1 } eof { exit 0 }"    
#
#    if [ $? = 1 ] ; then
#        echo "Timeout after ${time} seconds"
#    fi

#}

#rest of driver

#compile program
javac KnightBoard.java

#run
for x in $(seq 5 50)
do
    if [ $x -eq 41 ]
    then
	echo "41 by 41 doesn't work"
	continue
    else
	echo $x $x $LOL
	#timeout 10 "java ${KnightBoard $x $x}"
	time java KnightBoard $x $x
    fi
done
#kill $watchdogpid


