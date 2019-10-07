let bubble_sort (xs: 'a list) =
    let rec inner acc sorted (xs: 'a list) =
        match xs, sorted with
        | [], true -> acc |> List.rev
        | [], false -> acc |> List.rev |> inner [] true
        | x::y::t, _ when x > y -> inner (y::acc) false (x::t)
        | h::t, state -> inner (h::acc) state t
    inner [] false xs
