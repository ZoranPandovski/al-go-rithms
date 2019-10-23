
import 'dart:math';
/**
 * Merge sort Algorithm from introduction to algorithm
 */

mergeSort(List lst,int start,int end){
  //divide and conquer
  if(start < end){
    int mid = (start+end)~/2;
    mergeSort(lst,start,mid);
    mergeSort(lst,mid+1,end);
    merge(lst,start,mid,end);
  }
}


merge(List lst,int start, int mid, int end){
    int pivot1 = mid - start + 1;
    int pivot2 = end - mid;

    List lower = List(pivot1+1);
    List upper = List(pivot2+1);
    //We have to fill with a dummy value, here infinite number.
    int intMax = pow(2,63-1);
    lower.fillRange(0, pivot1+1,intMax);
    upper.fillRange(0, pivot2+1,intMax);

    int i;
    int j;

    for(i = 1; i < pivot1+1;i++){
      lower[i-1] = lst[(start + i)-1];
    }
    for(j = 1; j < pivot2+1;j++){
      upper[j-1] = lst[mid + j];
    }

    i = 0;
    j = 0;

    for(int k = start; k < end;k++){
      if(lower[i] <= upper[j]) {
        lst[k] = lower[i];
        i++;
      }else {
        lst[k] = upper[j];
        j++;
      }
    }
}


main(){
  
  var rng = new Random();
  List test_lst = new List<int>.generate(12, (int index) => (index+1) * rng.nextInt(100));

  print(test_lst);

  mergeSort(test_lst, 0, test_lst.length-1);

  print(test_lst);

}