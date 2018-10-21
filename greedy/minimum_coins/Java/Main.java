import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Vector;

public class Main {
	static class Obj {
		public int weight;
		public int price;

		public Obj() {
			weight = 0;
			price = 0;
		}
	};

	static class Task {
		public final static String INPUT_FILE = "in";
		public final static String OUTPUT_FILE = "out";

		int n, w;
        double value;
		Obj[] objs;

		private void readInput() {
			try {
				Scanner sc = new Scanner(new File(INPUT_FILE));
				n = sc.nextInt();
				w = sc.nextInt();
				objs = new Obj[n];
				for (int i = 0; i < n; i++) {
					objs[i] = new Obj();
					objs[i].weight = sc.nextInt();
					objs[i].price = sc.nextInt();
				}
				sc.close();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}

		private void writeOutput(double result) {
			try {
				PrintWriter pw = new PrintWriter(new File(OUTPUT_FILE));
				pw.printf("%.4f\n", result);
				pw.close();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}

		private double getResult() {
			Vector<Obj> objss = new Vector<Obj>();
			for(int i=0; i<objs.length;i++) {
				objss.add(objs[i]);
			}
			
			Comparator<Obj> comparator = new Comparator<Obj>() {

				@Override
				public int compare(Obj arg0, Obj arg1) {
					if (arg0.price /arg0.weight > arg1.price / arg1.weight)
						return -1;
					else if (arg0.price / arg0.weight < arg1.price / arg1.weight)
						return 1;
					else if (arg0.weight > arg1.weight)
						return -1;
					else if (arg0.weight < arg1.weight)
						return 1;
					return 0;
				}
			};
			Collections.sort(objss,comparator);
			for(Obj o: objss){
                if(w-o.weight>=0){
                    w-=o.weight;
                    value+=o.price;
                }
                else{
                	if(w-o.weight<0 && w!=0) {
                		value+=(double)w*o.price/(double)o.weight;
                		w=0;
                	}
                }
            }
			return value;
		}1

		public void solve() {
			readInput();
			writeOutput(getResult());
		}
	}

	public static void main(String[] args) {
		new Task().solve();
	}
}
