public class AddBinaryNumbers {

  public String addBinary(String a, String b) {

    if (a == null || b == null) return null;

    int i = a.length() - 1;
    int j = b.length() - 1;
    int carryOn = 0;
    StringBuilder sb = new StringBuilder();

    while (i >= 0 || j >= 0) {
      int d1 = i >= 0 ? a.charAt(i) - '0' : 0;
      int d2 = j >= 0 ? b.charAt(j) - '0' : 0;
      int sum = d1 + d2 + carryOn;
      int newDigit = sum % 2;
      sb.append(newDigit);
      carryOn = sum / 2;
      i--;
      j--;
    }

    if (carryOn == 1) {
      sb.append(1);
    }

    return sb.reverse().toString();
  }
}
