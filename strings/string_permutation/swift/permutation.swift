func permute<T>(_ a: [T], _ n: Int) {
    if n == 0 {
        print(a)
    } else {
        var a = a //to convert let  
        permute(a, n - 1)
        for i in 0..<n {
            a.swapAt(i, n)
            permute(a, n - 1)
            a.swapAt(i, n)
        }
    }
}

let xyz = "🐶😀🐮"
print("permutations \(xyz):")
permute(Array(xyz), xyz.count - 1)
