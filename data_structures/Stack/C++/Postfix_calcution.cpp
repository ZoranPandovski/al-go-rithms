#include <iostream>
using namespace std;

#define Operand 1
#define Operator 2
#define Parenthesis 3

class Intstack{
    public:
        int stk[100000];
        int top=1;
        void Make_empty(){
            top=1;
        }
        bool Is_empty(){
            return top==1;
        }
        void push(int val){
            stk[top]=val;
            top++;
        }
        int Top(){
            if(Is_empty()){
                return 0;
            }
            else return stk[top-1];
        }
        int pop(){
            if(Is_empty())return 0;
            int val = stk[top-1];
            top--;
            return val;
        }

};

struct token{
    int type=0;
    int value=0;
};

char operator_array[8] = {'.','~','^','/','%','*','+','-'};

int precedence(char c){

    if(c=='~') return 5;
    if(c=='^') return 4;
    if(c=='/') return 3;
    if(c=='%') return 3;
    if(c=='*') return 2;
    if(c=='+') return 1;
    if(c=='-') return 1;
    if(c=='(') return 0;
    if(c==')') return 0;
}

int exponential(int x,int y){
    int ans=1;
    for(int i=0;i<y;i++)ans*=x;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    int t;
    scanf("%d",&t);
    char c;
    scanf("%c",&c);
    while(t--){
        char v[1000000]={'.'};
        int pos=0;
        scanf("%c",&c);
        while(c!='\n' && ((c)!=EOF)){
            v[pos]=c;
            pos++;
            c = getchar();
        }
        int n =pos;
        token arr[n];
        pos=0;

        for(int i=0;i<n;i++){
            
            if(v[i]=='~'||v[i]=='^'||v[i]=='/'||v[i]=='%'||v[i]=='*'||v[i]=='+'||v[i]=='-'){
                arr[pos].type = 2;
                if(v[i]=='~') arr[pos].value = 1;
                else if(v[i]=='^') arr[pos].value = 2;
                else if(v[i]=='/') arr[pos].value = 3;
                else if(v[i]=='%') arr[pos].value = 4;
                else if(v[i]=='*') arr[pos].value = 5;
                else if(v[i]=='+') arr[pos].value = 6;
                else if(v[i]=='-') arr[pos].value = 7;
                pos++;
            }
            else if((v[i]-'0')>=0 && (v[i]-'0')<=9){
                arr[pos].type = 1;
                int multiplier=100000000;
                while(i<n && (((v[i]-'0')>=0 && (v[i]-'0')<=9))){
                    arr[pos].value += (multiplier*((int)(v[i]-'0')));
                    multiplier/=10;
                    i++;
                }
                multiplier*=10;
                arr[pos].value/=multiplier;
                i--;
                pos++;
            }
        }
        n = pos;
        Intstack s;
        s.Make_empty();
        int answer=0;
        for (int i = 0; i < n; ++i){
            if(arr[i].type==1){
                s.push(arr[i].value);
            }
            else{
                char current = operator_array[arr[i].value];
                int x,y;
                if(current=='~'){
                    x = s.pop();
                    x*=-1;
                    s.push(x);
                }
                else if(current=='+'){
                    x = s.pop();
                    y = s.pop();
                    s.push(x+y);
                }
                else if(current=='-'){
                    x = s.pop();
                    y = s.pop();
                    s.push(y-x);
                }
                else if(current=='*'){
                    x = s.pop();
                    y = s.pop();
                    s.push(x*y);
                }
                else if(current=='/'){
                    x = s.pop();
                    y = s.pop();
                    s.push(y/x);
                }
                else if(current=='%'){
                    x = s.pop();
                    y = s.pop();
                    s.push(y%x);
                }
                else if(current=='^'){
                    x = s.pop();
                    y = s.pop();
                    s.push(exponential(y,x));
                }
            }
        }
        answer = s.pop();
        cout<<answer<<endl;
    }
    return 0;
}
