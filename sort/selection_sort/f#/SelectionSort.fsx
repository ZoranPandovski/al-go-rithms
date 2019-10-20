let selectionSort (lst: 'a list) =
    let rec select acc (lst: 'a list) =
        match lst with
        | [] -> acc
        | h::t ->
            let mlst = List.fold (fun (acc: 'a list) elm ->
                if elm > acc.Head then elm::acc
                else acc.Head::elm::acc.Tail) [h] t
            select (mlst.Head::acc) mlst.Tail
    select [] lst
