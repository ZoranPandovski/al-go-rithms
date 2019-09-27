import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class FileHelper {

    public static void writeToFile(String fileName, String text) throws FileNotFoundException {
        PrintWriter printWriter = new PrintWriter(fileName);
        printWriter.print(text);
        printWriter.close();
    }

}
