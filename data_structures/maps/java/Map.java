import java.util.*; 
  
// Main class 
class Map { 

    public static void main(String args[]) 
    { 
        HashMap<String, Integer> hm 
            = new HashMap<String, Integer>(); 
  
        hm.put("A", 10); 
        hm.put("B", 20); 
        hm.put("C", 30); 
        hm.put("D", 30); 
  
        for (HashMap.Entry<String, Integer> me : 
             hm.entrySet()) { 
  
            // Printing Key and value pairs
            System.out.print(me.getKey() + ":"); 
            System.out.println(me.getValue()); 
        } 
    } 
}