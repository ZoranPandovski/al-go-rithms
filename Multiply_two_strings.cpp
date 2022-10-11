
#include<bits/stdc++.h>
using namespace std;
#include<string>

class Solution{
  public:
    string multiplyStrings(string s1, string s2) {
    if(s1.equals("0") || s2.equals("0")){
           return "0";
       }
       int aLen=s1.length();
       int bLen=s2.length();
       boolean minus=false;
       
       if(s1.charAt(0)=='-' && s2.charAt(0)=='-'){
           s1=s1.substring(1);
           aLen--;
           s2=s2.substring(1);
           bLen--;
       }
       else if(s1.charAt(0)=='-'){
            s1=s1.substring(1);
           aLen--;
           minus true;
       }
       else if(s2.charAt(0)=='-'){
          s2=s2.substring(1);
           bLen--;
           minus true;
       }
       int len=aLen+bLen+1;
       int res[]=new int[len];
       int carry=0;
       for(int i=0; i<bLen; i++){
           int x=Integer.parseInt(s2.substring(bLen-1-i,bLen-i));
           for(int j=0; j<aLen; j++){
              int y=Integer.parseInt(s1.substring(aLen-1-j,aLen-j));
              res[len-1-i-j] += x*y + carry;
              carry= res[len-1-i-j]/10;
               res[len-1-i-j]%=10;
           }
           if(carry!=0){
                res[len-1-i-aLen]=carry;
                carry=0;
           }
       }
       string op="";
       if(minus)
           op="-";
       for(int i=0; i<len; i++){
           op=+res[i];
       
       }
       return op;
   
    
    }


};
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
