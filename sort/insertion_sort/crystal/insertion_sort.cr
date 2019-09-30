require "spec"

def insertion_sort(arr)
	temp = arr
	length = arr.size
	length.times do |i|
		j = i
		while (j > 0) && (temp[j - 1] > temp[j])
			temp[j], temp[j - 1] = temp[j - 1], temp[j]
			j = j - 1
		end
	end
	return temp
end

sorted = insertion_sort( [1,90,34,7,16,85,66,99,12] )
sorted.each do |s|
	puts s
end

describe "Sorting" do
	describe "#size" do
		it "correctly reports the number of elements in the Array" do
			insertion_sort( [1,90,34,7,16,85,66,99,12] ).size.should eq 9
		end
	end

	describe "#sorting" do
		it "correctly reports if the array is sorted" do
			insertion_sort( [1,90,34,7,16,85,66,99,12] ).should eq [1,7,12,16,34,66,85,90,99]
		end
	end
end
