void main() {
  test();
}

int linearSearch(List<int> data,int target){
  int targetIndex = -1;
  for(int i = 0;i < data.length;i++){
    if(data[i] == target){
      targetIndex = i;
    }
  }
  return targetIndex;
}

void test(){
  List<int> data = [20,14,6,11,39,9];
  int target = 14;
  int result;
  
  if((result = linearSearch(data,target)) != -1){
    print("$target found at $result");
  }
  else{
    print("$target not found");
  }
}