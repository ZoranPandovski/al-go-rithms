def lyric_99_bottles(num)
    if num == 99
        puts '99 bottles of beer on the wall, 99 bottles of beer.'
    elsif num == 1
        puts "Take one down and pass it around, #{num} bottle of beer on the wall."
        puts "#{num} bottle of beer on the wall, #{num} bottle of beer."
    elsif num == 0
        puts 'Take one down and pass it around, no more bottles of beer on the wall.'
        puts 'No more bottles of beer on the wall, no more bottles of beer.'
        puts 'Go to the store and buy some more, 99 bottles of beer on the wall.'
        return
    else
        puts "Take one down and pass it around, #{num} bottles of beer on the wall."
        puts "#{num} bottles of beer on the wall, #{num} bottles of beer."
    end
    lyric_99_bottles(num - 1)
end

lyric_99_bottles(99)
