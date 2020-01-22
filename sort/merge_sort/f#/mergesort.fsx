let rec merge op (a:list<'T>) (b:list<'T>) =
  match a.Length, b.Length with
  | 0, _ -> b
  | _, 0 -> a
  | _ -> if op a.[0] b.[0] then
           a.[0]::(merge op a.[1..] b)
         else
           b.[0]::(merge op a b.[1..])

let rec mergeSort op (lst:list<'T>) =
  match lst.Length with
  | 1 -> lst
  | _ -> let mid = int (lst.Length/2);
         merge op (mergeSort op lst.[..mid-1]) (mergeSort op lst.[mid..])

let mergeSortAscending = mergeSort (<)
let mergeSortDescending = mergeSort (>)

printfn "%A" (mergeSortAscending [31;41;59;26;41;58])
printfn "%A" (mergeSortDescending [31;41;59;26;41;58])
