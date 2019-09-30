<?php
    /**
     * @param Array  $array
     * 
     * returns a sorted array after applying insertion sort
     */
    function insertion_sort($array){
        for($i=1;$i<count($array); $i++){
            for($j=$i;$j >=1;$j--){
                if($array[$j] < $array[$j-1]){
                    $temp = $array[$j-1];
                    $array[$j-1] = $array[$j];
                    $array[$j] = $temp;
                } else{
                    break;
                }
            }
        }

        return $array;
    }

    //test
    function test(){
        $array = [19,138,1,6,5,41,2,2,12];
        $sorted = insertion_sort( $array);
        print_r($sorted);
    }

    test();