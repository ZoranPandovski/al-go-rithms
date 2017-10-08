local search_test = require("linear_search")
local array = {14, 7, 8, 42, 99, 32, 76, 88, 1}

assert(search_test.linear_search(array, 42) == 4)
assert(search_test.linear_search(array, 101) == nil)

print("Tests passed")