/*
* This file has been created by github user vn17.
* Feel free to use it for any purpose.
*
* This file makes extensive use of Java 8 lambdas.
*
* For more details on the algorithm,
* refer to @see <a href=https://en.wikipedia.org/wiki/Histogram_equalization>https://en.wikipedia.org/wiki/Histogram_equalization</a>
*/
package Java;

import java.util.Arrays;
import java.util.HashMap;
import java.util.stream.IntStream;

import static java.util.stream.Collectors.joining;


public class HistogramEqualization {

    public static void main(String[] args) {
        ImageMatrix imageMatrix = new ImageMatrix(new int[][]{{2, 3, 1}, {3, 4, 6}, {7, 3, 6}});
        System.out.println("Input Matrix: \n" + imageMatrix);
        System.out.println("Frequency: \t" + imageMatrix.frequency() + "\nCDF: \t\t" + imageMatrix.cdf() + "\n");
        ImageMatrix equalizedImageMatrix = imageMatrix.equalize();
        System.out.println("Histogram Equalized Matrix: \n" + equalizedImageMatrix);
    }
}

class ImageMatrix {
    private static final int NUMBER_OF_LEVELS = 8;//This is the intensity range.
    // Eg. For a 3 bit per pixel image, the intensity value is 8.

    private int cdfMin = -1;//This is the cdf of the minimum intensity value

    private int size;//Size of the image. 3 x 3 = 9 in this case

    private int[][] imageArray;//3 x 3 Array to store intensity values at each pixel

    private HashMap<Integer, Integer> frequency;//HashMap to store the frequency of each intensity value i.e.
    // the number of times each value has appeared in the 3 x 3 array.

    private HashMap<Integer, Integer> cdf;//HashMap to store the CDF of each intensity value i.e.
    // the sum of the frequency values of all intensities lesser than the current intensity level.

    public ImageMatrix(int[][] arr) {
        this.imageArray = arr;
        this.size = (int) Arrays.stream(arr).flatMapToInt(IntStream::of).count();
    }

    public int getFrequency(int key) {
        if (frequency == null) calculateFrequency();
        return frequency().get(key);
    }

    public int getCdf(int key) {
        if (cdf == null) calculateCdf();
        return cdf().get(key);
    }

    public HashMap<Integer, Integer> frequency() {
        if (frequency == null) calculateFrequency();
        return frequency;
    }

    public HashMap<Integer, Integer> cdf() {
        if (cdf == null) calculateCdf();
        return cdf;
    }

    /**
     * This method calculates the frequency of each intensity value in the given intensity range.
     */
    private void calculateFrequency() {
        this.frequency = new HashMap<>();
        Arrays.stream(imageArray)//Get the 2D array
                .flatMapToInt(IntStream::of)//Convert it to a 1D array
                .forEach(intensity -> {//Increment the frequency value for intensity by 1
                    if (frequency.containsKey(intensity)) frequency.put(intensity, frequency.get(intensity) + 1);
                    else frequency.put(intensity, 1);
                });
    }

    /**
     * This method calculates the CDF by adding all the intensity values lesser than the current value.
     */
    private void calculateCdf() {
        if (frequency == null) calculateFrequency();
        cdf = (HashMap) frequency().clone();
        cdf.keySet().stream()
                .sorted().mapToInt(Integer::intValue)
                .reduce(0, (previousSum, currentKey) -> {
                    int sum = previousSum + cdf.get(currentKey);
                    cdf.put(currentKey, sum);
                    if (cdfMin == -1)//To store the cdf of the minimum intensity value
                        cdfMin = sum;
                    return sum;
                });
    }

    /**
     * This method applies the equalization formula to each element in the matrix.
     * @return
     */
    public ImageMatrix equalize() {
        int[][] equalizedArray = Arrays.stream(imageArray)
                .map(p -> Arrays.stream(p).map(q -> (getCdf(q) - cdfMin) * (NUMBER_OF_LEVELS - 2) / (size - 1) + 1).toArray())
                .toArray(int[][]::new);
        return new ImageMatrix(equalizedArray);
    }

    /**
     * Prints a 2D array line by line for each array.
     * @return
     */
    @Override
    public String toString() {
        return Arrays.stream(imageArray).map(s -> String.format("%s\n", Arrays.toString(s))).collect(joining());
    }
}

