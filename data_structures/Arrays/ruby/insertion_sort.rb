def insertion_sort(array)
  farr = []
  farr << array.shift 
    for i in array
      fi = 0
      while fi < farr.length 
        if i <= farr[fi] 
          farr.insert(fi, i) 
          break  
        elsif fi == farr.length-1 
          farr.insert(fi + 1, i) 
          break
        end
        final_index += 1   
      end
    end
  return farr
end
