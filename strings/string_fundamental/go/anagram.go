package main
import "fmt"

func main() {
    var t int
    fmt.Scan(&t)
    for i := 0; i < t; i++ {
        var word string
        fmt.Scanln(&word)
        if len(word) % 2 != 0 {
            fmt.Println(-1)
            continue
        }
        
        counts := make(map[uint8]int)
        for j := 0; j < len(word)/2; j++ {
            counts[word[j]]++
        }
        for k := len(word)/2; k < len(word); k++ {
            counts[word[k]]--
        }
        
        sum := 0
        for char := range counts {
            if c := counts[char]; c > 0 {
                sum += c
            }
        }
        fmt.Println(sum)
    }
}
