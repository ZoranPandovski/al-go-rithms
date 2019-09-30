public class Square{
    private String type;
    private int colorR, colorG, colorB;
    private static final String allTypes = "# SE*?.";
     
    // constructor
    public Square(String s){
    checkValidity(s);
    type = s;
    setColors();
    }
     
    // checks if maze block is one of: "# SE*"
    // # wall, _ empty space, S start, E end, * path
    private void checkValidity(String s) throws IllegalArgumentException{
    if ("# SE*?.".indexOf(s) == -1){
        throw new IllegalArgumentException("Maze content includes an invalid type: " + s);
    }
    }
     
    // SETTING COLOR OF SQUARE
    private void setColors(){
    colorR = setColorR();
    colorG = setColorG();
    colorB = setColorB();
    }
     
    private int setColorR(){
    int[] reds = {0, 255, 0, 255, 255,0,0};
    return reds[allTypes.indexOf(type)];
    }
     
    private int setColorG(){
    int[] greens = {0, 255, 255, 0, 165,255,0};
    return greens[allTypes.indexOf(type)];
    }
     
    private int setColorB(){
    int[] blues = {0, 255, 0, 0, 0,0,255};
    return blues[allTypes.indexOf(type)];
    }
     
 
     
    // ACCESSOR METHODS
    public String getType(){
    return type;
    }
     
     
    public int[] getColor(){ // returns int array of RGB colors
    int[] output = {colorR, colorG, colorB};
    return output;
    }
     
    // returns "Square type: ___...Color RGB: _,_,_"
    public String toString(){
    return "Square type: " + type + "\nColor RGB: [" + colorR + "," + colorG + "," + colorB + "]";
    }
}
