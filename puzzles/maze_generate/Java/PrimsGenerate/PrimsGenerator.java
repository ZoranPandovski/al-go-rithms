import java.util.ArrayList;
import java.io.PrintWriter;
import java.io.IOException;
 
public class PrimsGenerator{
    private int row, col;
    public Square[][] maze;
    private ArrayList<Coordinate[]> frontiers;
     
    public PrimsGenerator(int r, int c) throws IOException{
        row = r;
        col = c;
        maze = new Square[row][col];
        frontiers = new ArrayList<Coordinate[]>();
        fillWithWall();
        generate();
        addSE();
        //writeToFile();
    }
     
    private void fillWithWall(){
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                maze[r][c] = new Square("#");
            }
        }
    }
     
    private void generate(){
        Coordinate start = randomSquare();
        frontiers.add(new Coordinate[]{start, start});
         
         
        while (!frontiers.isEmpty()){
            int randF = (int)(Math.random() * frontiers.size());
            Coordinate[] fSq = frontiers.remove(randF);
            // for (Coordinate c : fSq){
                // System.out.println(c);
            // }
             
            int r1 = fSq[0].getX();
            int c1 = fSq[0].getY();
            int r2 = fSq[1].getX();
            int c2 = fSq[1].getY();
             
            if (maze[r2][c2].getType().equals("#")){
                maze[r1][c1] = new Square(" ");
                maze[r2][c2] = new Square(" ");
                 
 
                if (c2 > 1 && maze[r2][c2 - 2].getType().equals("#")){
                    Coordinate cor1 = new Coordinate(r2, c2 - 1);
                    Coordinate cor2 = new Coordinate(r2, c2 - 2);
                    frontiers.add(new Coordinate[]{cor1, cor2});
                }
                if (r2 > 1 && maze[r2 - 2][c2].getType().equals("#")){
                    Coordinate cor1 = new Coordinate(r2 - 1, c2);
                    Coordinate cor2 = new Coordinate(r2 - 2, c2);
                    frontiers.add(new Coordinate[]{cor1, cor2});
                }
                if (c2 < (col - 2) && maze[r2][c2 + 2].getType().equals("#")){
                    Coordinate cor1 = new Coordinate(r2, c2 + 1);
                    Coordinate cor2 = new Coordinate(r2, c2 + 2);
                    frontiers.add(new Coordinate[]{cor1, cor2});
                }
                if (r2 < (row - 2) && maze[r2 + 2][c2].getType().equals("#")){
                    Coordinate cor1 = new Coordinate(r2 + 1, c2);
                    Coordinate cor2 = new Coordinate(r2 + 2, c2);
                    frontiers.add(new Coordinate[]{cor1, cor2});
                }               
            }
        }
    }
     
    // returns coordinates of random square within borders
    private Coordinate randomSquare(){
        int x = (int)(Math.random() * (row - 2)) + 1;   // excludes border squares
        int y = (int)(Math.random() * (col - 2)) + 1;
        return new Coordinate(x, y);
    }
     
    private void addSE(){
        boolean check = false;
        for (int r = 0; r < row; r++){
            if (check)
                break;
            for (int c = 0; c < col; c++){
                if (maze[r][c].getType().equals(" ")){
                    maze[r][c] = new Square("S");
                    check = true;
                    break;
                }
            }
        }
         
        check = false;
        for (int r = row - 1; r >= 0; r--){
            if (check)
                break;
            for (int c = col - 1; c >= 0; c--){
                if (maze[r][c].getType().equals(" ")){
                    maze[r][c] = new Square("E");
                    check = true;
                    break;
                }
            }
        }       
    }
    /* 
    private void writeToFile() throws IOException{
        try {
                PrintWriter writer = new PrintWriter("Mazes/primsgeneratedfile.dat", "UTF-8");
                writer.println(this.toString());
                writer.close();
        }
        catch (IOException e){
            throw new IOException("unable to write to file");
        }
    }
     */
    private static String removeDoubleWalls(String content){
        // check and remove double top wall
        int width = widthString(content);
        int iS = indexS(content);
        if (iS > (widthString(content) * 2)){    // double wall on top
            // System.out.println("removed totopp wall");
            content = content.substring(width + 1);
        }
         
        // check and remove double left wall
        iS = indexS(content);
        width = widthString(content);
        if (iS == width + 3){   // double wall on left
            // System.out.println("removed lefleftt wall");
            for (int i = 0; i < content.length(); i += width){
                content = content.substring(0, i) + content.substring(i + 1);
            }
        }
         
        // check and remove double right wall
        int iE = indexE(content);
        width = widthString(content);
        if (content.substring(iE + 3, iE + 4).equals("\n")){    // double wall on right
            // System.out.println("removed right wall");
            for (int i = width - 1; i < content.length(); i += width){
                content = content.substring(0, i) + content.substring(i + 1);
            }           
        }
         
        // check and remove double bottom wall
        iE = indexE(content);
        width = widthString(content);
        if (iE < content.length() - (width * 2)){    // double wall on bottom
            // System.out.println("removed bottom wall");       
            content = content.substring(0, content.length() - width);
        }
 
        return content;
    }
     
    private static int indexS(String s){
        return s.indexOf("S");
    }
     
    private static int indexE(String s){
        return s.indexOf("E");
    }   
     
    private static int widthString(String s){
        return s.indexOf("\n");
    }
     
    private static int heightString(String s){
        int height = 1;
        String search = s;
        while (search.indexOf("\n") != -1){
            height++;
            search = search.substring(search.indexOf("\n") + 1);
        }
        return height;
    }
     
    public String toString(){
        String output = "";
         
        int c = col + 2;
        while (c > 0){
            output += "#";
            c--;
        }
        output += "\n";
         
        for (Square[] row : maze){
            output += "#";
            for (Square s : row){
                output += s.getType();
            }
            output += "#\n";
        }
         
        c = col + 2;
        while (c > 0){
            output += "#";
            c--;
        }
 
        output = removeDoubleWalls(output);
         
        if (output.substring(output.length() - 1).equals("\n"))
            output = output.substring(0, output.length() - 1);
             
        return output;
    }
     
    public static void main(String[] args) throws IOException{
        PrimsGenerator pg = new PrimsGenerator(100, 200);
        System.out.print(pg);
    }
}
