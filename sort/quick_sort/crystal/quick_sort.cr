require "spec"

def quick_sort(arr)
	if arr.size <= 1
		return arr
	else	
		pivot = arr[0]
		left, right = Array(Int32).new, Array(Int32).new
		arr[1..arr.size].each do |a|
			if a > pivot
				right << a
			else
				left << a
			end
		end
		return quick_sort(left) + [pivot] + quick_sort(right)
	end
end

sorted = quick_sort( [1,90,34,7,16,85,66,99,12] )
sorted.each do |s|
	puts s
end

describe "Sorting" do
	describe "#size" do
		it "correctly reports the number of elements in the sorted array" do
			quick_sort( [1,90,34,7,16,85,66,99,12] ).size.should eq 9
		end
	end

	describe "#type" do
		it "correclty reports the type" do
			typeof(quick_sort( [1,90,34,7,16,85,66,99,12] )).should eq Array(Int32)
		end
	end

	describe "#sorted" do
		it "correctly reports that the Array is sorted" do
			quick_sort([1,90,34,7,16,85,66,99,12]).should eq [1,7,12,16,34,66,85,90,99]
		end
	end
end
