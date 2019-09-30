/**
 * Given an integer, write a function to determine if it is a power of three.
 */
public class power_of_three {

    /**
     * SOLUTION
     */
    public static boolean isPowerOfThree(int n) {
        if (n == 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }

    /**
     * SOLUTION
     * Because we have a 32 bit signed int, the choices are fairly short. Because we can't actually store numbers
     * larger than 3^19 in an int, we only have to check 3^0 to 3^19 numbers.
     */
    public static boolean isPowerOfThree2(int n) {
        return (n == 1) ||
                (n == 3) ||
                (n == 9) ||
                (n == 27) ||
                (n == 81) ||
                (n == 243) ||
                (n == 729) ||
                (n == 2187) ||
                (n == 6561) ||
                (n == 19683) ||
                (n == 59049) ||
                (n == 177147) ||
                (n == 531441) ||
                (n == 1594323) ||
                (n == 4782969) ||
                (n == 14348907) ||
                (n == 43046721) ||
                (n == 129140163) ||
                (n == 387420489) ||
                (n == 1162261467);
    }

    /**
     * SOLUTION
     * We keep 3^19, as its the largest power of three that can be stored in an 32bit int. Since the mod of 3^19 to any
     * power of 3 is 0, we check if thats the case. If it is and is not 0 (edge case) then it's a power of three.
     */
    public static boolean isPowerOfThree3(int n) {
        return (n > 0) && (1162261467 % n == 0);
    }


    public static void main(String[] args) {
        System.out.println(isPowerOfThree(387420489));
    }
}

