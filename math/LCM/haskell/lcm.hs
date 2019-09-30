gcd_hs :: (Integral a) => a -> a -> a
gcd_hs x y = gcd_hs_ (abs x) (abs y)
  where
    gcd_hs_ a 0 = a
    gcd_hs_ a b = gcd_hs_ b (a `rem` b)

lcm_hs :: (Integral a) => a -> a -> a
lcm_hs _ 0 =  0
lcm_hs 0 _ =  0
lcm_hs x y =  abs ((x `quot` (gcd_hs x y)) * y)