 
                //Simple pyramid pattern printing in cpp//
 /*
  Pattern 1:
---------------
* 
* * 
* * * 
* * * * 
* * * * * 
---------------
*/

//Code:

#include <iostream> 
using namespace std; 
// Function to demonstrate printing pattern 
void pypart(int n) 
{ 
 // outer loop to handle number of rows(n) 
    for (int i=0; i<n; i++) 
    { 
        //  inner loop to handle number of columns 
        //  values changing acc. to outer loop 
        for(int j=0; j<=i; j++ ) 
        { 
            // printing stars 
            cout << "* "; 
        } 
  
        // ending line after each row 
        cout << endl; 
    } 
} 
  
// Main
int main() 
{ 
    int n = 5; 
    pypart(n); 
    return 0; 
} 

/*Pattern 2 : After 180 degrees rotation
-----------------
        * 
      * * 
    * * * 
  * * * * 
* * * * * 
---------------- */
//Code:
#include <iostream> 
using namespace std; 
  void pypart2(int n) 
{ 
    // number of spaces 
    int k = 2*n - 2; 
  
    // outer loop to handle number of rows(n)
    for (int i=0; i<n; i++) 
    { 
  
        // inner loop to handle number spaces 
        // values changing acc. to requirement 
        for (int j=0; j<k; j++) 
            cout <<" "; 
  
        // decrementing k after each loop 
        k = k - 2; 
  
        //  inner loop to handle number of columns 
        //  values changing acc. to outer loop 
        for (int j=0; j<=i; j++ ) 
        { 
           cout << "* "; } 
  
        // ending line after each row 
        cout << endl; 
    } 
} 
  
//Main
int main() 
{ 
    int n = 5; 
    pypart2(n); 
    return 0; 
}

/* Pattern 3: Triangle
----------
    * 
   * * 
  * * * 
 * * * * 
* * * * * 
---------
*/
//Code:

#include <iostream> 
using namespace std; 

void triangle(int n) 
{ 
    // number of spaces 
    int k = 2*n - 2; 
  
    // outer loop to handle number of rows (n)
    for (int i=0; i<n; i++) 
    { 
        // inner loop to handle number spaces 
        // values changing acc. to requirement 
        for (int j=0; j<k; j++) 
            cout <<" "; 
  
        // decrementing k after each loop 
        k = k - 1; 
  
        //  inner loop to handle number of columns 
        //  values changing acc. to outer loop 
        for (int j=0; j<=i; j++ ) 
        { 
            cout << "* ";  } 
  
        // ending line after each row 
        cout << endl; 
    } 
} 
  
//Main
int main() 
{ 
    int n = 5; 
    triangle(n); 
    return 0; 
} 

