echo 'Program to reverse a string using stack'
read -p "Please enter your string : " str 
len=${#str}
i=0
until [ ! $i -lt $len ]
do
   stack[$i]=${str:i:1}
   i=`expr $i + 1`
done
top=`expr $i - 1`
revstr=''
until [ ! $top -gt -1 ]
do
   x=${stack[$top]}
   revstr=$revstr$x 
   top=`expr $top - 1`
done
echo "The reversed string is : $revstr"
