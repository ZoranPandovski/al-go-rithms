def tower_of_hanoi(num, from, to, aux)
    if num >= 1
        tower_of_hanoi(num - 1, from, aux, to)
        puts "Move #{num} from #{from} to #{to}"
        tower_of_hanoi(num - 1, aux, to, from)
    end
end

tower_of_hanoi(5, 'A', 'B', 'C')
