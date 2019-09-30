package russian_peasant

import (
  "fmt"
)

func ExampleByZero() {
  fmt.Println(RussianPeasant(0, 3))
  // Output: 0
}

func ExampleByOne() {
  fmt.Println(RussianPeasant(1, 7))
  // Output: 7
}

func ExampleRandomNumbers() {
  first := RussianPeasant(2, 3)
  second := RussianPeasant(9, 9)
  fmt.Println(first, second)
  // Output 6 81
}

func ExampleBigNumbers() {
  fmt.Println(RussianPeasant(123456, 7890))
  // Output: 974067840
}
