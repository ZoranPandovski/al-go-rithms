def to_map array
    keys = array.uniq
    Hash[*keys.map{|k| [k,array.count{|i|i==k}]}.flatten]
end


gets.to_i.times{

    str = [*gets.chars][0..-2]
    
    if str.length%2 == 1
        p -1
        next
    end
    
    a = to_map str[0..str.length/ 2-1]
    b = to_map str[str.length/ 2..-1]
    
    p a.inject(0){|sum,h|sum + (b[h[0]] ? ((h[1]>b[h[0]]) ? h[1] - b[h[0]] : 0) : h[1])}
}
