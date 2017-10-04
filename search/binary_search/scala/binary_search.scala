


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