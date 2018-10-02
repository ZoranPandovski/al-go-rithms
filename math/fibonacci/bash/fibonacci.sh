#!/bin/bash -e

if ! [[ "$1" =~ ^[0-9]+$ ]]; then
  echo "This script expects a number as the first parameter." >&2
  exit 1
fi

if [ "$1" = "0" ]; then
  echo "We start count the fibonacci positions at 1." >&2
  exit 1
fi

f() {
  test $1 -le 2 && echo 1 || ( echo "$(f $(($1-1))) + $(f $(($1-2)))" | bc )
}

f $1
