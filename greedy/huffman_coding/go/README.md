# Overview

This is an implementation of Huffman's encryption in go, generating a compression codebook from a byte array.

## Build

Simply call

    make

## Run

Simply call

    ./huffman <some text>

The result will display the corresponding codebook.


## Example

    > huffman aaabccd
    98 b [0 0 1]
    100 d [0 0 0]
    97 a [1]
    99 c [0 1]

