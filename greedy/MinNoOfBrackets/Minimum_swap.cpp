// minimum number of swaps required to balance the brackets using c++

#include <iostream>
using namespace std;

class bracket {
    public:
        void display(string S){
            for(int i=0; i<S.length(); i++) {
                cout << S[i];
            }
            cout << endl;
        }
    
        //  O(n)
        int swapCount(string S) {    
            // Stores total number of Left and Right brackets encountered
            int countLeft = 0, countRight = 0;
            int toatl_swap = 0 , imbalance = 0;
            
            for(int i = 0; i < S.length(); i++) {
                if (S[i] == '[') {
                    // Increment count of Left bracket
                    countLeft++;
                    
                    if (imbalance > 0) {
                        swap(S[i], S[i-imbalance]);
                        toatl_swap++; 
                        
                        cout << "Swap " << toatl_swap << " :";
                        display(S);
                        // imbalance -1 becoz one bracket is solved..
                        imbalance--;    
                    }
                }
                else if(S[i] == ']' ) {
                    countRight++;
                    
                    // imabalance is different between right-left
                    imbalance = (countRight - countLeft);
                }
            }

            if(countLeft != countRight) {
                return -1;
            }
            return toatl_swap;
        }
};

int main() {
    // string s = "]]][[[";   [][][]
    string s;
    int out;
    cout << "Enter string : ";
    getline(cin, s);

    bracket obj;
    out = obj.swapCount(s);
    if(out == -1) {
        cout << "\nBracket balancing is not possible for such combinations..";
    } else{
        cout << "\nTotal Number of Swaps = " << out << endl;
    }

    return 0;
}

// end
