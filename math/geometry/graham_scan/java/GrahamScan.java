
// This algorithm solve the convex hull problem  of UVA using Graham Scan algorithm
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1019
import java.util.*;


public class GrahamScan {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int qtyNumbers = scanner.nextInt();

		while (qtyNumbers != 0) {
			final ArrayList<Point> points = new ArrayList<>();

			for (int i = 0; i < qtyNumbers; i++) {
				int numX = scanner.nextInt();
				int numY = scanner.nextInt();
				points.add(new Point(numX, numY));
			}

			// say if the points are convex
			System.out.println(isConvex(points));

			qtyNumbers = scanner.nextInt();

		}

		scanner.close();

	}

	public static double crossProduct(Point p1, Point p2, Point p3) {
		return (p2.getY() - p1.getY()) * (p3.getX() - p2.getX()) - (p2.getX() - p1.getX()) * (p3.getY() - p2.getY());
	}

	static String isConvex(ArrayList<Point> points) {

		// Sort by most left Y, if there are 2 points with the same Y, X will by
		// tested
		Collections.sort(points, new Comparator<Point>() {
			public int compare(Point p1, Point p2) {
				// Check if Y of Point 1 is > or < Y of Point 2
				int result = Integer.valueOf(p1.getY()).compareTo(p2.getY());

				if (result == 0) {
					// If Y are equal, check X
					return Integer.valueOf(p1.getX()).compareTo(p2.getX());
				} else {
					// IF Point1 Y is lower than Point2 Y, return -1, else 1
					return result;
				}
			}
		});

		// Choose the most left point
		final Point leftPoint = points.remove(0);
		// ordena pelos angulos (do menor pro maior)
		// Sort by angles (smaller to bigger)
		Collections.sort(points, new Comparator<Point>() {

			public int compare(Point p1, Point p2) {
				// if left angle
				double angle1 = Math.atan2(p1.getY() - leftPoint.getY(), p1.getX() - leftPoint.getX());
				double angle2 = Math.atan2(p2.getY() - leftPoint.getY(), p2.getX() - leftPoint.getX());
				// point with smaller angle comes first
				return Double.valueOf(angle1).compareTo(angle2);
			}
		});

		// Add the most left point to start the convex hull
		points.add(0, leftPoint);

		Stack<Point> stack = new Stack<Point>();
		Point pivot = points.get(0);
		Point p2 = points.get(1);

		stack.push(pivot);
		stack.push(p2);

		/*
		 * Graham Scan algorithm: Find pivot P; Sort Points by angle (resolve
		 * ties in favor of point farther from P);
		 * 
		 * # Points[1] is the pivot Stack.push(Points[1]);
		 * Stack.push(Points[2]); FOR i = 3 TO Points.length o <-
		 * Cross_product(Stack.second, Stack.top, Points[i]); IF o == 0 THEN
		 * Stack.pop; Stack.push(Points[i]); ELSEIF o > 0 THEN
		 * Stack.push(Points[i]); ELSE WHILE o <= 0 and Stack.length > 2
		 * Stack.pop; o <- Cross_product(Stack.second, Stack.top, Points[i]);
		 * ENDWHILE Stack.push(Points[i]); ENDIF NEXT i
		 */

		for (int i = 2; i < points.size(); i++) {
			Point ptI = points.get(i);
			Point ptTop = stack.pop();
			Point ptSecond = stack.peek();

			double crossProduct = crossProduct(ptSecond, ptTop, ptI);

			if (crossProduct == 0) {
				stack.push(ptI);
			} else if (crossProduct < 0) {
				stack.push(ptTop);
				stack.push(ptI);
			}

		}
		// Results are stored in stack
		if (stack.size() != points.size()) {
			return "Yes";
		} else {
			return "No";
		}

	}

	static class Point {

		private int x;
		private int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int getX() {
			return this.x;
		}

		public int getY() {
			return this.y;
		}

	}
}
