//
//  main.cpp
//
//  Created by Mehmet Sahin on 10/2/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#include <iostream>
#include "Stack.cpp"
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    Stack<int> s1;
    
    s1.Push(10);
    s1.Push(15);
    s1.Push(20);
    cout << s1.Top() << endl;
    s1.Pop();
    s1.Pop();
    cout << s1.Top() << endl;
    
    cout << s1.IsEmpty() << endl;
    s1.MakeEmpty();
    cout << s1.IsEmpty() << endl;
    return 0;
}
