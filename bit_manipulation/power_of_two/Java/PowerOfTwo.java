public class PowerOfTwo {

    public static void main(String[] args) {
	    System.out.println("3 Power of Two? " + isPowerOfTow(3));
        System.out.println("2 Power of Two? " + isPowerOfTow(2));
        System.out.println("365 Power of Two? " + isPowerOfTow(365));
        System.out.println("512 Power of Two? " + isPowerOfTow(512));
        System.out.println("1024 Power of Two? " + isPowerOfTow(1024));
        System.out.println("1738362 Power of Two? " + isPowerOfTow(1738362));
        System.out.println("0 Power of Two? " + isPowerOfTow(0));
    }

    private static boolean isPowerOfTow(int x) {
        return (x & (x-1)) == 0;
    }
}
