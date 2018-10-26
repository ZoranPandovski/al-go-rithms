import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

class Knn {
	static class Sample {
		int label;
		int [] pixels;
	}
	
	private static List<Sample> readFile(String file) throws IOException {
		List<Sample> samples = new ArrayList<Sample>();
		BufferedReader reader = new BufferedReader(new FileReader(file));
		try {
			String line = reader.readLine(); // ignore header
			while((line = reader.readLine()) != null) {
				String[] tokens = line.split(",");
				Sample sample = new Sample();
				sample.label = Integer.parseInt(tokens[0]);
				sample.pixels = new int[tokens.length - 1];
				for(int i = 1; i < tokens.length; i++) {
					sample.pixels[i-1] = Integer.parseInt(tokens[i]);
				}
				samples.add(sample);
			}	
		} finally { reader.close(); }
		return samples;
	}
	
	private static int distance(int[] a, int[] b) {
		int sum = 0;
		for(int i = 0; i < a.length; i++) {
			sum += (a[i] - b[i]) * (a[i] - b[i]);
		}
		return (int)Math.sqrt(sum); // euclidian distance would be sqrt(sum)...
	}
	
	private static int classify(List<Sample> trainingSet, int[] pixels) {
		int label = 0, bestDistance = Integer.MAX_VALUE;
		for(Sample sample: trainingSet) {
			int dist = distance(sample.pixels, pixels);
			if(dist < bestDistance) {
				bestDistance = dist;
				label = sample.label;
			}
		}
		return label;
	}
	
	public static void main(String[] argv) throws IOException {
		List<Sample> trainingSet = readFile("trainingsample.csv");
		List<Sample> validationSet = readFile("validationsample.csv");
		int numCorrect = 0;
		for(Sample sample:validationSet) {
			if(classify(trainingSet, sample.pixels) == sample.label) numCorrect++;
		}
		System.out.println("Accuracy: " + (double)numCorrect / validationSet.size() * 100 + "%");
	}
}
