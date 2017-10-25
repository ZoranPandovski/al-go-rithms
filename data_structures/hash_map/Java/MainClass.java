
import java.util.ArrayList;
import java.util.Random;

/*
	Performance analisys
 */
public class MainClass {

    public static void main(String[] args) {

        Random generator = new Random();

        ArrayList<Student> list = new ArrayList<Student>();
        for (int i = 0; i < 2000 + generator.nextInt(2000); i++) {
            list.add(new Student((char) ('a' + generator.nextInt(20)) + "d", generator.nextInt(21)));
        }
        MyHashMap<Student, Integer> students = new MyHashMapImpl<Student, Integer>(20);
        for (int i = 0; i < list.size(); i++) {
            students.put(list.get(i), 10);
        }
        long time = System.currentTimeMillis();
        int nrTests = 10000;
        for (int i = 0; i < nrTests; i++) {
            students.get(list.get(generator.nextInt(list.size())));
        }
        System.out.println("Time " + (System.currentTimeMillis() - time));

        /*
		 * Analiza pentru LazyStudent
         */
        ArrayList<LazyStudent> lazylist = new ArrayList<LazyStudent>();
        for (int i = 0; i < 2000 + generator.nextInt(2000); i++) {
            lazylist.add(new LazyStudent((char) ('a' + generator.nextInt(20)) + "", generator.nextInt(21)));
        }
        MyHashMap<LazyStudent, Integer> lazystudents = new MyHashMapImpl<LazyStudent, Integer>(20);
        for (int i = 0; i < lazylist.size(); i++) {
            lazystudents.put(lazylist.get(i), 10);
        }
        time = System.currentTimeMillis();

        for (int i = 0; i < nrTests; i++) {
            lazystudents.get(lazylist.get(generator.nextInt(lazylist.size())));
        }
        System.out.println("Time " + (System.currentTimeMillis() - time));

    }
}
