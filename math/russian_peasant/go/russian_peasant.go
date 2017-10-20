package russian_peasant

func RussianPeasant(a int, b int) (sum int) {
  for b > 0 {
    if (a % 2 == 1) { sum += b }
    a = a >> 1
    b = b << 1
  }
  return
}
