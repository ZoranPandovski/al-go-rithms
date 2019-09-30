
// LINEAR SEARCH - Tutorial

/* Linear search is the most basic search algorithm you can think of.
It progressively checks for the searched element in each position of the array searched
and stops when the element contained in the current position examined is equal to the 
searched element. 

This type of search is applicable to any kind of data storage like lists and structures.

Consider n to be the number of comparisons needed to find the target. 
The cost of this search algorithm is an O(n) in the worst case scenario.
If the element to be searched for is the first element of the list then the
cost is a O(1) (equal to an if-then-else operation).

This means that for very large data structures a linear search algorithm can be faster than, 
for example, which has a cost of O(log n) and thus of lower performance when n is high provided
the elements are sorted in order of most likelihood to be searched.
*

// In this example!

/* This example shows a very simple implementatio of a linear search algorithm to search for
a target element of datatype integer in a standard vector of integers. This example is easily modifiable by
the reader to produce examples using different datatypes and data structures more complex than simple
vectors. */



// Headers - only the standard c++ library is needed
#include "iostream"
#include "stdlib.h"
#include "vector"
#include "stdexcept"
#include "cstdlib"

// Function LinearSearch performs the search of target in the array
/*
*@param target : searched integer
*@param array : vector to be searched
*/
void LinearSearch(int target, std::vector<int> array)
{
    /* A local boolean is the best way to deal with the issue of not finding the value. 
    Using a different return int (like a -1) imposes that the user is not searching for a negative value, when that
    might happen the function would return an insucces despite having found the element. The boolean approach is, in
    my opinion, the best fail-proof design. */
    bool is_target_found = false;

    /* Search for the element */
    for (unsigned int i = 0; i<array.size(); ++i) // this loops cycles every position in the vector
    {
        if (array[i] == target) // Condition to satisfy
        { 
            // The code below is executed only when the element is found
            std::cout << "Element found at postion " << i << "!" << std::endl;
            is_target_found = true;
        }
    } 

    /* Stop method */
    if (is_target_found == false)
    {    
        std::cout << "The searched element (" << target << ") is not present in the array!" << std::endl;
        throw std::runtime_error("Error detected! It's important to stop the program if the searched element is mandatory further along the road!");
    }        
}

int main()
{
    /* Request user input for vector size*/
    int n_elements;
    std::cout << "Please insert the number of elements and press enter..." << std::endl;
    std::cin >> n_elements;
    std::cout << std::endl;
    std::vector<int> user_defined_array(n_elements);

    /* Request values to fill the vector */
    for (int i = 0; i<user_defined_array.size(); ++i)
    {
        std::cout << "Insert element in position " << i << " and press enter:" << std::endl;
        std::cin >> user_defined_array[i];
        std::cout << std::endl;
    }

    /* Request value to be searched */
    int target_value;
    std::cout << "Plese insert the element you are looking for and press enter..." << std::endl;
    std::cin >> target_value;
    std::cout << std::endl;

    /* Call LinearSearch algorithm */
    try 
    {
        LinearSearch(target_value, user_defined_array);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }    

    return EXIT_SUCCESS;

}
