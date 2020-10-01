


void main() {
  
var array=[];
  
  void insertion(int n){
  array.add(n);
}
  
  void deletion(int n){
    array.remove(n);
  }
  
  void display(){
    print(array);
  }
  
  void search(int n){
    if(array.contains(n))
      print(n.toString() + " is present at "+(array.indexOf(n)+1).toString()+"th position");
    else
      print(n.toString() + " is not Present in the Array");
  }
  
  void update(int old, int replace){
    array[array.indexOf(old)] = replace;
  }
  
  insertion(5);
  insertion(10);
  insertion(18);
  insertion(20);
  insertion(25);
  display();
  update(18,15);
  display();
  search(18);
  search(15);
  insertion(30);
  display();
  deletion(5);
 
  
  
  
  
}


