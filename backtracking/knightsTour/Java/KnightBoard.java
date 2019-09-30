import java.util.Arrays;
import java.util.Comparator;

public class KnightBoard{
    private int[][]board;
    int moves[][]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int sr;
    int sc;
    //helps with string
    boolean solver=false;
    
    public KnightBoard(int startingRows,int startingCols){
	sr=startingRows;
	sc=startingCols;
        board = new int[sr][sc];
	//checkingFill();
	//reorder(board);
    }
    /*
      public void checkingFill(){
      for(int r=0; r<sr;r++){
      for(int c=0;c<sc;c++){
      board[r][c]=1;
      }
      }
      for(int r=1; r<sr;r++){
      for(int c=0;c<sc;c++){
      board[r][c]=1000;
      }
      }
      for(int r=2; r<sr;r++){
      for(int c=0;c<sc;c++){
      board[r][c]=100;
      }
      }
      for(int r=3; r<sr;r++){
      for(int c=0;c<sc;c++){
      board[r][c]=10;
      }
      }
      }
    */
    public String toString(){
	String s="";
	for(int r=0; r<sr;r++){
	    for(int c=0;c<sc;c++){
		if(board[r][c]<10){
		    s+="   "+board[r][c]+" ";
		}
		if(!(board[r][c]<10)&&
		   board[r][c]<100){
		    s+="  "+board[r][c]+" ";
		}
	        if(!(board[r][c]<10||
		     board[r][c]<100)&&
		   board[r][c]<1000){
		    s+=" "+board[r][c]+" ";
		}
		if(!(board[r][c]<10||
		     board[r][c]<100||
		     board[r][c]<1000)&&
		   board[r][c]<10000){
		    s+=+board[r][c]+" ";
		}
		s+=((c==sc-1) ? "\n" : "");
	    }
	}
	return s;
    }
    //will become 'fast' once i get it to work
    public void solveFast(){
	solveH(0,0,1);
	if(!solver)
	    clear();
    }
    //from a old commit, i can prolly make this work if
    //im pruning the tree
    public boolean valid (int r, int c){
	return r >= 0 && r < sc && c >= 0 && c < sr && board[c][r] == 0;
    }
    //n is level because im free :')
    //helper method
    public boolean solveH(int r, int c, int n){
	board[c][r] = n;
	//base case
	if (n == sr * sc){
	    solver=true;
	    return true;
	}
	
	/*JUST NEED THE SMART PART NOW HAHA*/

	int tree[][]=new int[8][3];
	for (int i=0; i<8;i++){
	    tree[i][0] = 0;
	    tree[i][1] = r + moves[i][0];
	    tree[i][2] = c + moves[i][1];
	    if (valid (tree[i][1], tree[i][2]))
		for (int j=0;j<8;j++){
		    if (valid (tree[i][1] + moves[j][0],tree[i][2] + moves[j][1]))
			tree[i][0]++;
		}
	}
	//sorter(tree);
	//i KNOW i have to sort somewhere, but where
	//def not here tho^ sike
	//debugPrinter(tree);
	//System.out.println("==============");
	reorder(tree);
	//debugPrinter(tree);
	//System.out.print("\033[2J");
	//ngl following stackoverflow post
	for (int i=0;i<8;i++){
	    if (valid (tree[i][1], tree[i][2]) && solveH (tree[i][1], tree[i][2], n + 1)){
		solver=true;
		return true;
	    }
	}
	//failure
	board[c][r] = 0;
	return false;
    }
    //2d array sorter
    /*
      public void sorter(int a[][]){
      int[][]b=new int[a[0].length][a.length];
      for(int i=0; i<8;i++){
      b[i][0]=a[0][i];
      b[i][1]=a[1][i];
      b[i][2]=a[2][i];
      }
      Arrays.sort(b[0]);
      for(int i=0; i<8;i++){
      a[0][i]=b[i][0];
      a[1][i]=b[i][1];
      a[2][i]=b[i][2];
	    
      }
      }
    */
    /*debug printers
      public void debugPrinter(int a[][]){
      for (int r=0; r < a.length; r++){
      for (int c=0; c < a[r].length; c++)
      System.out.printf ("%6d ", a[r][c]);
      System.out.printf("\n");
      }
      }
      public void debugPrinter(){
      for (int r=0; r < sr; r++){
      for (int c=0; c < sc; c++)
      System.out.printf ("%6d ", board[r][c]);
      System.out.printf("\n");
      }
      }
    */
    //custom compareTo, might make a quick sort using this
    //im using c logic :') #flawless
    //sort by first column
    public static void reorder(int[][] a){
	Arrays.sort(a, new Comparator<int[]>() {
		@Override
		public int compare(final int[] a, final int[] b) {
		    Integer c = Integer.valueOf(a[0]);
		    Integer d = Integer.valueOf(b[0]);
		    return c.compareTo(d);
		}
	    });
    }
    //in case of failure of solveH
    private void clear(){
	for(int r=0; r<sr;r++){
	    for(int c=0; c<sc;c++)
		board[r][c]=0;
	}
    }
    /*
      public static void main(String args[]){
      int a= Integer.parseInt(args[0]);
      int b= Integer.parseInt(args[1]);
      KnightBoard c=new KnightBoard(a,b);
      c.solveFast();
      //c.solveH(0,0,1);
      //c.debugPrinter();
      System.out.print(c);
      }
    */

    //Going up from 0, mine fails at 41, 52, 59, 60, 66, 74 and stackoverflow past 75 (75 works) 　 
    public static void main(String[]args){
	KnightBoard a= new KnightBoard(Integer.parseInt(args[0]), Integer.parseInt(args[0]));
        a.solveFast();
	System.out.println(a);
    }
}
