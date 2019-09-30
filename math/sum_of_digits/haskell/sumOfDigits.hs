import Data.Maybe

char2Int c = fromJust (lookup c (zip ['0' .. '9'] [0..9] )) 
sumdigits n = sum([ char2Int i | i <- (show n)])
main = print (sumdigits 456)