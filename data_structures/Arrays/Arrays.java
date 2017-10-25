package arrays;

/**
 * @author Jose Chavarría
 * @license MIT
 * @link https://chavarria.cr/post/arrays
 */
public class Arrays {

    /**
     * @param args the command line arguments
     */
    static int[] num = new int[5]; 

    static void Insertion() {
         System.out.println("Insert...");
        for (int i = 0; i < num.length; i++) {
            num[i] = i + 10;
             System.out.println(num[i] = i + 10);
        }
    }

    static void Traverse() {
        System.out.println("\nTraverse...");
        for (int i = 0; i < num.length; i++) {
            System.out.println("index: " + i + " element: " + num[i]);
        }
    }

    static void Search(int var) {
        System.out.println("\nSearch: " + var);
        for (int i = 0; i < num.length; i++) {
            if (num[i] == var) {
                System.out.println("index: " + i + " element: " + num[i]);
            }
        }
    }

    static void Update(int past, int item) {
         System.out.println("\nUpdate: " + past + " to " + item);
        for (int i = 0; i < num.length; i++) {
            if (num[i] == past) {
                num[i] = item;
                 System.out.println("index: " + i + " element: " + num[i]);
            }
        }
    }

    static void Deletion(int var) {
        System.out.println("\nDelete: " + var);
        int[] temp = new int[4];
        int count = 0, aux = 0;
        
        while (count < num.length) {
            if (num[count] != var) {
                temp[aux] = num[count];
                aux++;
            }
            count++;
        }
        num = temp;
    }

    public static void main(String[] args) {
        Insertion();
        Traverse();
        Search(10);
        Update(10, 100);
        Deletion(100);
        Traverse();
    }

}
