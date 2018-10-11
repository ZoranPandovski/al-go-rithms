<?php

    function loop_replacing($start, $end, $items, $i) {
        // Replace elements
        $forward_is_lighter = $start < $end && $items[$start] > $items[$i];
        $backward_is_heavier = $start > $end && $items[$start] < $items[$i];

        if ($forward_is_lighter || $backward_is_heavier) {
            $temp = $items[$start];
            $items[$start] = $items[$i];
            $items[$i] = $temp;
            unset($temp);
        }
        return $items;
    }

    function shaker_sort($input) {
        $items = count($input) - 1;

        $start = 0;
        $end = $items;
        while ($start !== $end) {
            if ($start < $end) {
                // Loop forward
                for ($i = $start; $i <= $end; $i++) {
                    $input = loop_replacing($start, $end, $input, $i);
                }
                // Reduce next looping
                $start++;
            } else {
                // Loop backward
                for ($i = $start; $i >= $end; $i--) {
                    $input = loop_replacing($start, $end, $input, $i);
                }
                // Reduce next looping
                $start--;
            }
            
            // Switch start and end to revert moving through array
            $temp = $end;
            $end = $start;
            $start = $temp;
            unset($temp);

        }

        return $input;
    }