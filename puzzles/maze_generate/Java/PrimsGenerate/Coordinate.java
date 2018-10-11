public class Coordinate{
    private int xcor, ycor;
     
    public Coordinate(int x, int y){
        xcor = x;
        ycor = y;
    }
     
    // ACCESSOR METHODS
    public int getX(){
        return xcor;
    }
     
    public int getY(){
        return ycor;
    }
     
    // MODIFIERS
    public void setX(int x){
        xcor = x;
    }
     
    public void setY(int y){
        ycor = y;
    }
     
    public String toString(){
        return "(" + xcor + "," + ycor + ")";
    }
}
