// The Decorator Design Pattern :  The DrawingBoard object is wrapped by
// the DrawHouse,DrawTree,DrawRiver objects.A call to Picdescription()
// function unwraps bottom up from the DrawingBoard to the DrawRiver object.


import java.util.*;

public class DrawingBoard {
	
	public DrawingBoard()
	{
		
	}
	
	public String Picdescription()
	{
		return "This is a picture on the Drawing Board";
	}
	
	public static void main(String[] args)
	{
		
		DrawingBoard d1 = new DrawingBoard();
		
		d1 = new DrawHouse(d1);
		
		d1 = new DrawTree(d1);
		
		d1 = new DrawRiver(d1);
		
		System.out.println(d1.Picdescription());
	}

}

 abstract class DrawingBoardAdapter extends DrawingBoard
{
	public abstract String Picdescription() ;
	
}
 
 class DrawTree extends DrawingBoardAdapter
 {
	 DrawingBoard drawingboard;
	 
	 public DrawTree(DrawingBoard d)
	 {
		 drawingboard  = d;
	 }
 
	 public String Picdescription()
	 {
		 return (drawingboard.Picdescription()  + " with a Mangoo Tree");
	 }
 
 }
 
 
 class DrawHouse extends DrawingBoardAdapter
 {
	 DrawingBoard drawingboard;
	 
	 public DrawHouse (DrawingBoard d)
	 {
		 drawingboard  = d;
	 }
 
	 public String Picdescription()
	 {
		 return (drawingboard.Picdescription()  + " of a small house");
	 }
 
 }
 
 
 class DrawRiver extends DrawingBoardAdapter
 {
	 DrawingBoard drawingboard;
	 
	 public DrawRiver (DrawingBoard d)
	 {
		 drawingboard  = d;
	 }
 
	 public String Picdescription()
	 {
		 return (drawingboard.Picdescription()  + " and flowing river.");
	 }
 
 
 }
