let sort (arr:'a[]) = 
  let arr = arr |> Array.copy
  let swap i j = let tmp = arr.[i] in arr.[i] <- arr.[j]; arr.[j] <- tmp
  for i = arr.Length - 1 downto 0 do
    for j = 1 to i do
      if (arr.[j - 1] > arr.[j]) then swap (j-1) j
  arr