# Hash Table
Not to be confused with a Hash Map. A hash table stores all values as their own key.

A hash table is a data structure that allows a user to store values and later retrieve them, just like an array.
The key difference is that a hash table will have O(1), or constant, lookup time on average. What this means is that the speed at which we can check whether a value exists within a table is not affected by how large the table grows. Compare this to a linked list that would require checking every element in order to see if a given value exists. That process's time to complete is proportional to how big a linked list grows.

To achieve a hash table, a few important concepts come into play
  - hashing
  - collisions
  - rehashing

# Hashing
The concept of hashing is simple. In order to achieve a constant lookup time, a hash table has a hash function that calculates the position that a element should be stored in. The generic hash function for a table of size n is simply 

>index = toInsert % n

As you can see, this will simply place a number into a table based on its remainder when divided by the table size, which will always result in a value that is an index in the table (with the assumption that we are working with positive integers).


# Collisions
What happens if two numbers give the same result from a hash function? This is called a collision, and resolving collisions is one of the areas of study in hash tables. There are multiple ways to resolve collisions, popular ones are simply simply adding 1 to the result until an open slot is found (called linear probing), hashing the number again using result of the number of collisions^2 (quadratic probing), and using a second hash function in conjunction with the first (double hashing). 

# Rehashing
Hash tables are only optimized when they can avoid collisions(or at least resolve them quickly) and rehashing. In order to keep this property true, we want a couple main properties to exist for our hash table:
 - its size is a prime number
 - its never more than half full

If either of these properties become false, rehashing the table is a good idea to keep it efficient. Rehashing is the process of creating a new table that is bigger (usually at least twice the size of the previous table) and re-adding all the previous values to it. So, the process goes something like
1. create temp array to hold the table
2. find the next largest prime number that is at least twice the size of our previous table
3. create a new table of that size
4. re-add all the elements from the temporary table

Specifically, step 4 is a slow process (linear time, but slow for something we may do often), and that is why we want to avoid rehashing. In order to be able to track when a table should rehash, a load variable is used to track how full the table is, and a MAX_LOAD is defined (usually 0.5) to indicate when a table should rehash. Every time a value is added to the table, the load is increased and the need for rehashing is evaluated.
