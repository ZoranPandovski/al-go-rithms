#include <iostream>
using namespace std;

#define Operand 1
#define Operator 2
#define Parenthesis 3

class stack{
    public:
        char stk[100000];
        int top=1;
        void Make_empty(){
            top=1;
        }
        bool Is_empty(){
            return top==1;
        }
        void push(char val){
            stk[top]=val;
            top++;
        }
        char Top(){
            if(Is_empty()){
                return '.';
            }
            else return stk[top-1];
        }
        char pop(){
            if(Is_empty())return '.';
            char val = stk[top-1];
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

int checker(token* arr, int n){
    int validity=1;
    for(int i=0;i<n-1;i++){
        if(arr[i].type==1){
            if((arr[i+1].type==3 && arr[i+1].value==1)||(arr[i+1].type==2 && arr[i+1].value==1) || (arr[i+1].type==1)){
                validity = 0;
            }
        }
        else if(arr[i].type==2){
            if(arr[i].value == 1){
            }
            else{
                if((arr[i+1].type == 3 && arr[i+1].value == -1) || (arr[i+1].type==2 && arr[i+1].value!=1)){
                    validity=0;
                }
            }
        }
        else{
            if(arr[i].value==1){
                if(arr[i+1].type==2 && arr[i+1].value!=1 || (arr[i+1].type == 3 && arr[i+1].value==-1)){
                    validity = 0;
                }
            }
            else{
                if(arr[i+1].type == 1){
                    validity = 0;
                }
                else if(arr[i+1].type == 2 && arr[i+1].value == 1){
                    validity = 0;
                }
                else if(arr[i+1].type == 3 && arr[i+1].value==1){
                    validity = 0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        if(arr[i].type==2 && arr[i].value == 1){
            if(arr[i-1].type == 1 || (arr[i-1].type == 3 && arr[i-1].value == 3)){
                validity=0;
            }
        }
    }
    if(arr[0].type == 2 && arr[0].value!=1){
        validity=0;
    }
    if(arr[n-1].type==2 || (arr[n-1].type==3 && arr[n-1].value==1)){
        validity=0;
    }
    return validity;
}

int balance(token* arr,int n){
    stack s;
    s.Make_empty();
    for(int i=0;i<n;i++){
        if(arr[i].type==3){
            if(arr[i].value==1){
                s.push('(');
            }
            else{
                if(!s.Is_empty() && s.Top()=='('){
                    char c = s.pop();
                }
                else s.push(')');
            }
        }
    }
    if(s.Is_empty()) return 1;
    else return 0;
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
            if(v[i]=='('){
                arr[pos].type = 3;
                arr[pos].value = 1;
                pos++;
            }
            else if(v[i]==')'){
                arr[pos].type = 3;
                arr[pos].value = -1;
                pos++;
            }
            else if(v[i]=='^'||v[i]=='/'||v[i]=='%'||v[i]=='*'||v[i]=='+'||v[i]=='-'){
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
        for(int i=0;i<n-1;i++){
            if(( arr[i].type==2 || (arr[i].type==3&&arr[i].value==1) ) && (arr[i+1].type==2 && arr[i+1].value==7)){
                arr[i+1].value=1;
            }
        }
        if((arr[0].type==2 && arr[0].value==7) && (arr[1].type==1)){
            arr[0].type=2;
            arr[0].value=1;
        }
        int valid = checker(arr,n);
        valid = valid & balance(arr,n);
        if(!valid){
            cout<<"INVALID"<<endl;
            continue;
        }
        stack s;
        s.Make_empty();
        pos=0;

        for(int i=0;i<n;i++){
            if(arr[i].type == 1){
                cout<< arr[i].value<<' ';
            }
            else if(arr[i].type==3 && arr[i].value==1){
                s.push('(');
            }
            else if(arr[i].type==3 && arr[i].value==-1){
                while(!s.Is_empty()){
                    char val = s.pop();
                    if(val=='(')break;
                    cout<<val<<' ';
                }
            }
            else{
                char current = operator_array[arr[i].value];
                int p1 = precedence(current);

                if(s.Is_empty()){
                    s.push(current);
                }
                else{
                    int p2 = precedence(s.Top());
                    if(p1>p2){
                        s.push(current);
                    }
                    else{
                        char val;
                        while(!s.Is_empty() && (p1<(precedence(s.Top())))){
                            val = s.pop();
                            cout<<val<<' ';
                        }
                        if(p1 == precedence(s.Top())){
                            if(current!='^'){
                                val = s.pop();
                                cout<<val<<' ';
                            }
                        }
                        s.push(current);
                    }
                }
            }
        }
        while(!s.Is_empty()){
            char val = s.pop();
            cout<<val<<' ';
        }
        cout<<endl;
    }
    return 0;
}
