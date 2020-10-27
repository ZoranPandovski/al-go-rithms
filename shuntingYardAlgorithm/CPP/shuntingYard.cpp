#include<bits/stdc++.h>
using namespace std;
int precedence(char op){
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

int applyOps(int v1, int v2, char c){
    // cout << c;
    switch (c)
    {
    case '+':
        return v1+v2;
        break;
    
    case '-':
        return v1-v2;
        break;

    case '*':
        return v1*v2;
        break;

    case '/':
        return v1/v2;
        break;

    default:
        cout << "error" << endl;
        break;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    string expression;
    getline(cin, expression);
    stack<int> number;
    stack<char> operation;
    for (int i = 0; i < (int)expression.size(); i++)
    {
        // cout << i;
        if(expression[i] == ' '){
            continue;
        }else if (expression[i] == '(')
        {
            operation.push(expression[i]);
        }else if (expression[i] == ')')
        {
            while ((!operation.empty()) && (operation.top() != '('))
            {
                int val2 = number.top();
                number.pop();
                int val1 = number.top();
                number.pop();
                char op = operation.top();
                operation.pop();
                number.push(applyOps(val1, val2, op));
            }
            if (!operation.empty())
            {
                operation.pop();
            }
        }else if (isdigit(expression[i]))
        {
            int val = 0;
            while ((i < (int)expression.size()) && (isdigit(expression[i])))
            {
                val = (val * 10) + (expression[i] - '0');
                ++i;
            }
            // cout << val << " ";
            number.push(val);
            --i;
        }else
        {
            // cout << "check";
            while ((!operation.empty()) && (precedence(operation.top()) >= precedence(expression[i])))
            {
                // cout << "check";

                int val2 = number.top();
                // cout << val2;
                number.pop();
                // cout << val2;
                int val1 = number.top();
                number.pop();
                char op = operation.top();
                operation.pop();
                // cout << val1 << " " << val2 << " " << op;
                number.push(applyOps(val1, val2, op));
            }
            operation.push(expression[i]);
            
        }
    }

    while (!operation.empty())
    {
        int val2 = number.top();
        // cout << val2;
        number.pop();
        // cout << val2;
        int val1 = number.top();
        number.pop();
        char op = operation.top();
        operation.pop();
        // cout << val1 << " " << val2 << " " << op;
        number.push(applyOps(val1, val2, op));
    }
    

    cout << number.top() << endl;    
    return 0;
}
