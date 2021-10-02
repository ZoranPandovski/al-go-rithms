
class StackImpl{
    static final int MAX = 3;
    int top;
    int a[] = new int[MAX];
    
      StackImpl()
    {
        top = -1;
    }
    public boolean push(int data){
       
        if (top >= (MAX - 1)) {
            System.out.println("Stack Overflow");
            return false;
        }else{
            a[++top] = data;
            System.out.println(data+ "pushed into stack");
            return true;
        }
    }
    
     boolean isEmpty(){
        return (top < 0);
    }
    
    public int pop(){
        if(top>-1){
            int data = a[top];
            top--;
            return data;
        }else{
            System.out.println("stack underflow");
            return -1;
        }   
    }
    
    public static void main(String args[]){
        StackImpl stack = new StackImpl();
        stack.push(3);
        stack.push(4);
        stack.pop();
        stack.pop();
        stack.pop();//stack underflow
        stack.isEmpty();
     
    }
}
