class Palindrome{  
 public static void main(String args[]){  
  int a,sum=0,temp;    
  int n=454;  
  
  temp=n;    
  while(n>0){    
   a=n%10;  
   sum=(sum*10)+a;    
   n=n/10;    
  }    
  if(temp==sum)    
   System.out.println(" its a palindrome number ");    
  else    
   System.out.println("its not a palindrome");    
}  
}  
