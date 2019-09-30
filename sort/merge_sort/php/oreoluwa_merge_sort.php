<?php

    /**
     * @param array $array
     * 
     * returns a sorted array after performing merge sort on it
     */
    function merge_sort( $array ){
        if( count($array) < 2)
            return $array;
        $mid = floor( count($array) / 2);
        $left = array_slice($array, 0, $mid);
        $right = array_slice($array,$mid, count($array));

        return merge( merge_sort($left), merge_sort($right));
    }

    /**
     * @param array $left
     * @param array $right
     * 
     * returns a single array with both arrays merged to form it
    */
    function merge( $left, $right){
        $result = [];

        while( count($left) && count($right )){
            if( $left[0] <= $right[0]){
                array_push($result, array_shift($left));
            }else{
                array_push($result, array_shift($right));
            }
        }

        while( count($left))
            array_push( $result, array_shift($left) );
        
        while( count($right))
            array_push( $result, array_shift($right) );

        return $result;
    }

    function test(){
        $array = [19,8,1,6,5,41,3,2,12];
        $sorted = merge_sort( $array);
        print_r($sorted);
    }

    test();