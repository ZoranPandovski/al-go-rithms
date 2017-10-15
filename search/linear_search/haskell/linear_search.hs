module LinearSearch where
    
    linear_search::[Integer]->Integer->Integer
    linear_search l x= search l x 0

    search::[Integer]->Integer->Integer->Integer
    search (x:xs) y n = if x == y then n
                                else search xs y (n + 1)
    search [] y n = -1
