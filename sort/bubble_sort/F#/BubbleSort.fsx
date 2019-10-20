let bubbleSort (lst: 'a list) =
    let rec bubble acc sorted (lst: 'a list) =
        match lst, sorted with
        | [], true -> acc |> List.rev
        | [], false -> acc |> List.rev |> bubble [] true
        | x::y::t, _ when x > y -> bubble (y::acc) false (x::t)
        | h::t, state -> bubble (h::acc) state t
    bubble [] false lst
