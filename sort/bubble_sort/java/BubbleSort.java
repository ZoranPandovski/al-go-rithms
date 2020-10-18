public static void bubbleSort(int[] ranNum){
        for (int i=0; i<ranNum.length-1; i++){
            for (int j=0; j<ranNum.length-1-i; j++){
                if(ranNum[j]>ranNum[j+1]){
                    int temp = ranNum[j+1];
                    ranNum[j+1] = ranNum[j];
                    ranNum[j] = temp;
                }
            }
        }
        System.out.println(Arrays.toString(ranNum)); 
}
