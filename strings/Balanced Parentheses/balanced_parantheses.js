function is_balanced(bracket_string){
    let bracket_match_dict = {')':'(','}':'{', ']':'['}; //bracket match key-value pairs
    let len = bracket_string.length; //length of the given string
    let stk = []; //empty stack

    //if length of the string is not even then it is definitely not balanced so return false
    if (len%2!=0) return false; 

    //checking if a even length string is balanced
    for(let i=0;i<len;i++){
        let ch = bracket_string[i];
        if(ch == '(' || ch =='{' || ch == '[')
        {
            stk.push(ch); //push all opening brackets into stack
        }

        else 
        {
            let match_string = bracket_match_dict[ch]; //match closing bracket to opening bracket
            let top_stk = stk[stk.length-1]; //store top element in stack
            if (match_string!=top_stk) return false;  //if top and match element are not same return false
            stk.pop();  // pop() if top and match element are same
        }
         
    }

    //if the stack is still empty then string is balanced otherwise it is not
    if(stk.length==0) return true; 
    return false;

}

function print_output(output, bracket_string){
    if(output) console.log(bracket_string + " is balanced.");
    else console.log(bracket_string+ " is not balanced.");
}


//driver code
 let test1 = "[((()))]" ;
 let test2 = "[(({}))]" ;
 let test3 = "[{((){})}]"; 
 let fail1 = "[[[]]";
 let fail2 = "[[[]])";
 let fail3 = "[[]{}[)]])";

print_output(is_balanced(test1), test1);
print_output(is_balanced(test2), test2);
print_output(is_balanced(test3), test3);
print_output(is_balanced(fail1), fail1);
print_output(is_balanced(fail2), fail2);
print_output(is_balanced(fail3), fail3);
