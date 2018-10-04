/**
*	Recursive linear search implemented in scala
*	unnecessarily complex
*/	
def linear_search(lst:Array[Int],idx:Int,key:Int):Int={
	if(lst.length == 0 ) return -1 else
		if(lst(idx) == key) return idx else
			return linear_search(lst,idx+1,key) 
}

def test(){

	val l = Array(12,3,4,5,6,7)

	assert(linear_search(l,0,4) == 2)
}