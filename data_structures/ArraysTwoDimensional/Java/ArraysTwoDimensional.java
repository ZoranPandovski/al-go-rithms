package arrays;

/**
 * @author Jose Chavarría
 * @license MIT
 * @link https://chavarria.cr/post/array-bidimensional
 */
public class ArraysTwoDimensional {

    /**
     * @param args the command line arguments
     */
    static Integer[][] num = new Integer[6][6];

    static void Insertion() {
        System.out.println("Insertion...");
        int count = 0;
        for (int i = 0; i < num.length; i++) {
            for (int j = 0; j < num.length; j++) {
                System.out.println(num[i][j] = count++);
            }
        }
    }

    static void Traverse() {
        System.out.println("\nTraverse...");
        for (Integer[] aux : num) {
            for (Integer i : aux) {
                System.out.print(i + "\t");
            }
            System.out.println("\n");
        }
    }

    static void Search(int var) {
        System.out.println("\nSerch: " + var);
        for (int i = 0; i < num.length; i++) {
            for (int j = 0; j < num.length; j++) {
                if (num[i][j] == var) {
                    System.out.println("row: " + i + " colum: " + j);
                }
            }
        }
    }

    static void Update(int past, int var) {
        System.out.println("\nUpdate: " + past + " to " + var);
        for (int i = 0; i < num.length; i++) {
            for (int j = 0; j < num.length; j++) {
                if (num[i][j] == past) {
                    num[i][j] = var;
                    System.out.println("Row: " + i + " colum: " + num[i][j]);
                }
            }
        }
    }

    static void Deletion(int var) {
        System.out.println("\nDeletion: " + var);
        for (int i = 0; i < num.length; i++) {
            for (int j = 0, count = 0; j < num.length; j++) {
                if (num[i][j] == var) {
                    num[i][count++] = null;
                    System.out.println("Row: " + i + " colum: " + num[i][j]);
                }
            }
        }
    }

    static void rotateClockWise() {
          int length = num.length-1;
           
          for (int i = 0; i <= (length)/2; i++) {
              for (int j = i; j < length-i; j++) {
                
               //Coordinate 1
               int p1 = num[i][j];
                
               //Coordinate 2
               int p2 = num[j][length-i];
                
               //Coordinate 3
               int p3 = num[length-i][length-j];
                
               //Coordinate 4
               int p4 = num[length-j][i];
                
               //Swap values of 4 coordinates.
               num[j][length-i] = p1;
               num[length-i][length-j] = p2;
               num[length-j][i] = p3;
               num[i][j] = p4;
              }
          }
    }

    public static void main(String[] args) {
        Insertion();
        Traverse();
        Search(3);
        Update(3, 100);
        Traverse();
        Deletion(100);
        Traverse();
    }
}
