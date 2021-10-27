<% 

Dim ArraySort,aux

ArraySort = Array(11,1,13,6,2,9,7,3,4,5,10,12,8)

for i = 0 to Ubound(ArraySort)
	for j = 0 to Ubound(ArraySort)-i-1
		if ArraySort(j) > ArraySort(j+1) then
			aux = ArraySort(j+1)
			ArraySort(j+1) = ArraySort(j)
			ArraySort(j) = aux
		end if 
	next
next
for each x in ArraySort
	response.write x&"<br>"
next

%>
