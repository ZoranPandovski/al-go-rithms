import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {
	static class Task {
		public final static String INPUT_FILE = "in";
		public final static String OUTPUT_FILE = "out";

		int n, k;
		int[] solution ;
		int[] viz;
		ArrayList<Integer> domain = new ArrayList<Integer>();
		private void readInput() {
			try {
				Scanner sc = new Scanner(new File(INPUT_FILE));
				n = sc.nextInt();
				k = sc.nextInt();
				sc.close();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}

		private void writeOutput(ArrayList<ArrayList<Integer>> result) {
			try {
				PrintWriter pw = new PrintWriter(new File(OUTPUT_FILE));
				pw.printf("%d\n", result.size());
				for (ArrayList<Integer> arr : result) {
					for (int i = 0; i < arr.size(); i++) {
						pw.printf("%d%c", arr.get(i), i + 1 == arr.size() ?
								'\n' : ' ');
					}
				}
				pw.close();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}


		ArrayList<ArrayList<Integer>> back(int step, int[] solution, int stop, ArrayList<ArrayList<Integer>> all ){
			if (step == stop) {
					ArrayList<Integer> aux = new ArrayList<>();
					for(int i=0;i<k;i++)
						aux.add(solution[i]);
					all.add(aux);
                    return all;
				}
			for(int i =1; i<=n;i++)
				if(viz[i]==0){
					solution[step]=i;
					viz[i]=1;
					back(step+1, solution, stop,all);
					viz[i]=0;
				}

				return all;
			}
		
		private ArrayList<ArrayList<Integer>> getResult() {
			    
            //show all combinations of N taken by K of the set {1...N}
			viz= new int[n+1];
			solution = new int[k];
   			ArrayList<ArrayList<Integer>> all = new ArrayList<>();
			all = back(0, solution, k, all );
			return all;
			
		}


		public void solve() {
			readInput();
		
			writeOutput(getResult());
		}
	}

	public static void main(String[] args) {
		new Task().solve();
	}
}
