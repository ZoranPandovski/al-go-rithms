

/**
* Recursive binary search algorithm 
* @param lst the integer array which is being searched
* @param l lower value for partition
* @param r upper value for partition
* @param num number which is being searched for
* @return the index of the element that matches the search term, returns -1 if not found
*/
def binary_search(lst:Array[Int],l:Int,r:Int,num:Int):Int={

	if(l <= r){
		val mid = l+(r-1)/2

		if (lst(mid) == num) return mid else 
			if (lst(mid) <  num ) return binary_search(lst,mid+1,r,num) else
				return binary_search(lst,l,mid-1,num)
		
	}


	return -1
}

def test(){

	val l = Array(12,3,4,5,6,7)

	assert(binary_search(l,1,l.length,4) == 2)
}