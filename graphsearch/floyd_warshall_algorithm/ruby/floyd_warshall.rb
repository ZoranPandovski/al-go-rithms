INF = 9999999

graph = [ [0,   INF, -2, INF],
          [4,   0,    3, INF],
          [INF, INF,  0, 2],
          [INF, -1, INF, 0] ]

def floyd_warshall(graph)
    no_of_vertices = graph.length
    distance_matrix = Marshal.load(Marshal.dump(graph)) #Deep Copy the Array
    (0..no_of_vertices-1).each do |k|
        (0..no_of_vertices-1).each do |i|
            (0..no_of_vertices-1).each do |j|
                if distance_matrix[i][j] > distance_matrix[i][k] + distance_matrix[k][j]
                    distance_matrix[i][j] = distance_matrix[i][k] + distance_matrix[k][j]
                end
            end
        end
    end
    distance_matrix
end

def pretty_print(matrix)
    puts 'Shortest Distance Between the Nodes are: '
    matrix.each { |row|
        puts row.join(" ")
    }
end

pretty_print floyd_warshall graph
