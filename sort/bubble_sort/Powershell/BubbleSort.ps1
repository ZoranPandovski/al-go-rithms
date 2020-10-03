$Array = @(83, 57, 14, 44, 30, 26, 1, 58, 9, 12, 32, 29, 45, 3, 4)

function BubbleSort([array]$ArrayToSort) {
    $ArrayToSort = $ArrayToSort.Clone()
    for ($i = 0; $i -lt ($ArrayToSort.Count - 1); $i++) {
        for ($j = 0; $j -lt ($ArrayToSort.Count - 1 - $i); $j++) {
            if ($ArrayToSort[$j] -gt $ArrayToSort[$j + 1]) {
                $temp = $ArrayToSort[$j + 1];
                $ArrayToSort[$j + 1] = $ArrayToSort[$j];
                $ArrayToSort[$j] = $temp;
            }
        }
    }
    return $ArrayToSort
}

$SortedArray = BubbleSort($Array)

$BuiltInSortedArray = $Array | Sort-Object

if ($($SortedArray -join ",") -ne $($BuiltInSortedArray -join ",")) {
    exit 1
}

exit 0