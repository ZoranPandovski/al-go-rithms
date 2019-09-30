# Knight Tour

## KnightsTour.java

---

## KnightBoard.java
- purpose is work faster and on larger boards
- allows for user input
- has a tradition, simpler method you can change main to use
- To my knowledge:
  - going up from 0:
    - fails/ slow at 41, 52, 59, 60, 66, 74
    - stackoverflow past 75 (75 works)
    - I've noticed this vary by machine as well

### compile
- `javac KnightBoard.java`

### run
- `java KnightBoard $N`
  - where $N is the length of board for program
  - eg: `java KnightBoard 5`

## Driver-KnightBoard.sh
- purpose is to automate testing of KnightBoard.java
  - times each entry as well
- loop goes 5-50
  - skips 41

### run
- `. Driver-KnightBoard.sh`