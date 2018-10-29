import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.util.*;

/**
 * Created by Darkkgreen on 12/17/2016.
 */

public class Main {
    private static int k_value = 5;

    public static void main( String []args ) {
        Object newObject;
        ArrayList<Object> objectList = null;
        Scanner scan = new Scanner(System.in);
        String entry = "-";
        String[] entryObj;
        String output = null;

        try{
            objectList = readTests();
        }catch(Exception e){
            System.out.println(e);
        }

        System.out.println("Please insert your info: ");

        while(entry != null){
            entry = scan.next();
            entryObj = entry.split(",");
            newObject = new Object(treatPrice(entryObj[0]), treatPrice(entryObj[1]), treatDoors(entryObj[2]), treatPeople(entryObj[3]), treatLug(entryObj[4]), treatSafety(entryObj[5]));

            output = classify(newObject, objectList);
            newObject.setClassification(output);

            System.out.println("Classified as " + output);

            objectList.add(newObject);
            output = "";
            newObject = null;
            entryObj = null;
            entry = "-";
        }
    }

    // This function is used to classify our new entries

    public static String classify(Object newObject, ArrayList<Object> objectList){
        ArrayList<Object> topK = new ArrayList<>();
        Iterator<Object> it = objectList.iterator();
        Hashtable<String, Integer> map = new Hashtable<String, Integer>();

        Integer auxiliar, highest = 0;
        Integer total = 0;
        String return_value = "";

        while(it.hasNext()){
            Object aux = it.next();
            aux.setDist(newObject.calcDist(aux));

            if(topK.size() < k_value){
                topK.add(aux);
            }else{
                if(topK.get(topK.size()-1).getDist() > aux.getDist()){
                    topK.remove(topK.size()-1);
                    topK.add(aux);
                }
            }

            Collections.sort(topK);
        }

        Collections.sort(objectList);
        printList(objectList);

        for(Object aux: topK){
            if(map.containsKey(aux.getClassification())){
                auxiliar = map.get(aux.getClassification());
                map.put(aux.getClassification(), auxiliar+1);
            }else{
                map.put(aux.getClassification(), 1);
            }
        }

        for(Object aux: topK){
            auxiliar = map.get(aux.getClassification());
            if(auxiliar > highest){
                highest = auxiliar;
                return_value = aux.getClassification();
            }
        }

        return return_value;
    }

    // Print the list with classifications

    public static void printList(ArrayList<Object> tree){
        Iterator<Object> it = tree.iterator();
        Object aux;

        while(it.hasNext()){
            aux = it.next();
            System.out.println(aux.getDist() + "( " + aux.getClassification() + " " + aux.retornaValores() + " ) ");
        }
    }

    // Using this next function, we're reading some classifications from our file

    public static ArrayList<Object> readTests() throws FileNotFoundException{
        ArrayList<Object> objectList = new ArrayList<Object>();
        Object newObject = null;

        // Here, you need to input your file location
        FileInputStream fis = new FileInputStream("tests.txt");
        Scanner reader = new Scanner(fis);

        String[] element;

        while(reader.hasNextLine()){
            element = reader.nextLine().split(",");
            newObject = new Object(treatPrice(element[0]), treatPrice(element[1]), treatDoors(element[2]), treatPeople(element[3]), treatLug(element[4]), treatSafety(element[5]), element[6]);
            objectList.add(newObject);
        }

        System.out.println("Lines read: " + objectList.size());
        System.out.println("Done loading archive!");

        return objectList;
    }

    // Those next functions 

    public static int treatPrice(String value){
        if(value.equals("vhigh")) {
            return 1;
        }else if(value.equals("high")) {
            return 2;
        }else if(value.equals("med")) {
            return 3;
        }else if(value.equals("low")) {
            return 4;
        }else
            return Integer.parseInt(value);
    }

    public static int treatDoors(String value){
        if(value.equals("5more")){
            return 5;
        }else
            return Integer.parseInt(value);
    }

    public static int treatPeople(String value){
        if(value.equals("more")){
            return 5;
        }else
            return Integer.parseInt(value);
    }

    public static int treatLug(String value) {
        if (value.equals("small")) {
            return 1;
        } else if (value.equals("med")) {
            return 2;
        } else if (value.equals("big")) {
            return 3;
        }

        return 0;
    }

    public static int treatSafety(String value){
        if (value.equals("low")) {
            return 1;
        } else if (value.equals("med")) {
            return 2;
        } else if (value.equals("high")) {
            return 3;
        }

        return 0;
    }
}
