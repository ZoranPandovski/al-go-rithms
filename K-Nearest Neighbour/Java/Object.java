import java.util.Comparator;

/**
 * Created by Darkkgreen on 12/17/2016.
 */

public class Object implements Comparable<Object>{
    private int buyingPrice;
    private int maintPrice;
    private int safety;
    private int doors;
    private int people;
    private int lug_boot;
    private String classification;
    private double dist;

    public String getClassification() {
        return classification;
    }

    public void setClassification(String classification) {
        this.classification = classification;
    }

    public int getBP() {
        return buyingPrice;
    }

    public int getMP() {
        return maintPrice;
    }

    public int getSafety() {
        return safety;
    }

    public int getDoors() {
        return doors;
    }

    public int getPeople() {
        return people;
    }

    public int getLug() {
        return lug_boot;
    }

    public double getDist(){
        return dist;
    }

    public void setDist(double dist)
    {
        this.dist = dist;
    }

    public String retornaValores(){
        return new String("["+this.buyingPrice+","+this.maintPrice+","+this.safety+","+this.doors+","+this.people+","+this.lug_boot+"]");
    }

    Object(int buyingPrice, int maintPrice, int safety, int doors, int people, int lug_boot){
        this.buyingPrice = buyingPrice;
        this.maintPrice = maintPrice;
        this.safety = safety;
        this.doors = doors;
        this.people = people;
        this.lug_boot = lug_boot;
    }

    Object(int buyingPrice, int maintPrice, int safety, int doors, int people, int lug_boot, String classi){
        this.buyingPrice = buyingPrice;
        this.maintPrice = maintPrice;
        this.safety = safety;
        this.doors = doors;
        this.people = people;
        this.lug_boot = lug_boot;
        this.classification = classi;
    }

    public double calcDist(Object aux){
        int distBuying = (int) Math.pow(this.buyingPrice - aux.getBP(),2);
        int distMaint = (int) Math.pow(this.maintPrice - aux.getMP(),2);
        int distSaf = (int) Math.pow(this.safety - aux.getSafety(), 2);
        int distDoor = (int) Math.pow(this.doors - aux.getDoors(),2);
        int distPeople = (int) Math.pow(this.people - aux.getPeople(),2);
        int distLug = (int) Math.pow(this.lug_boot - aux.getLug(),2);
        double distTotal = Math.sqrt(distBuying + distMaint + distSaf + distDoor + distPeople + distLug);
        this.dist = distTotal;

        return distTotal;
    }

    public int compareTo(Object aux){
        if(this.dist < aux.getDist()){
            return -1;
        }else if(this.dist > aux.getDist()){
            return 1;
        }else
            return 0;
    }
}
