class Solution {
    public int nextGreaterElement(int n) {
        char[] str = (n+"").toCharArray();

        int deflectionPoint = str.length-1;

        while(deflectionPoint>0){
            if(str[deflectionPoint] > str[deflectionPoint-1]) {
                break;
            }
            deflectionPoint--;
        }
        if(deflectionPoint == 0){
            return -1;
        }

        int firstSwappingIndex = deflectionPoint -1;

        int secondSwappingIndex = str.length -1;
        while(secondSwappingIndex>=firstSwappingIndex){
            if(str[firstSwappingIndex] < str[secondSwappingIndex]) {
                break;
            }
            secondSwappingIndex--;
        }

        // swap

        char temp = str[firstSwappingIndex];
        str[firstSwappingIndex] = str[secondSwappingIndex];
        str[secondSwappingIndex] = temp;

        // swapping at the point of deflection

        reverseChar(str, deflectionPoint);
        String s=new String(str);
        try{
        int res=Integer.parseInt(s);
        return res;
        }
        catch(Exception e){
            return -1;
        }
    }

    private void reverseChar(char[] str, int i){
        int start = i;
        int end =str.length-1;
        while(end>=start){
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            end--;
            start++;

        }
    }


}
