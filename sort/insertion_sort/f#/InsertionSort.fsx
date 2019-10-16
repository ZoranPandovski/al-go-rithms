let insertionSort (lst: 'a list) =
    let rec insert (lst: 'a list) elm =
        match lst with
        | [] -> [elm]
        | h::t when elm <= h -> elm :: lst
        | h::t -> h :: (insert t elm)
    List.fold insert [] lst
