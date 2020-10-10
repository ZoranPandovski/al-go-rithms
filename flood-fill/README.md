# Flood Fill

> Flood fill, also called seed fill, is an algorithm that determines the area connected to a given node in a multi-dimensional array. It is used in the "bucket" fill tool of paint programs to fill connected, similarly-colored areas with a different color, and in games such as Go and Minesweeper for determining which pieces are cleared.

## Algorithm

> The flood-fill algorithm takes three parameters: a start node, a target color, and a replacement color. The algorithm looks for all nodes in the array that are connected to the start node by a path of the target color and changes them to the replacement color. There are many ways in which the flood-fill algorithm can be structured, but they all make use of a queue or stack data structure, explicitly or implicitly.

In this variant, we will take an additional parameter which corresponds to a 2-dimensional array to operates on.

## Resources

- [FloodFill (Wikipedia)](https://en.wikipedia.org/wiki/Flood_fill)
- [Queue (Wikipedia)](<https://en.wikipedia.org/wiki/Queue_(abstract_data_type)>)
