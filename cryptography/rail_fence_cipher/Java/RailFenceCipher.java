import java.util.*;

public class RailFenceCipher {

    static String encode(String s, int n) {
        // Your code here
        String encodedString = "";

        if (s.isEmpty()) {
            return encodedString;
        }

        char [][] charArray = new char[n][s.length()];
        int row = 0;
        int col = 0;
        boolean up = false;
        for (int k = 0; k < s.length(); k++) {
            charArray[row][col] = s.charAt(k);

            if (row == (n - 1)) {
                up = true;
            } else if (row == 0) {
                up = false;
            }
            row = (up) ? --row : (++row);
            col = ((col + 1) >= s.length()) ? 0 : (++col);
        }

        for (row = 0; row < n; row++) {
            for (col = 0; col < s.length(); col++)
            {
                if (charArray[row][col] != 0) {
                    encodedString += charArray[row][col];
                }
            }
        }

        return encodedString;
    }

    static String decode(String s, int n) {
        // Your code here
        String decodedString = "";

        if (s.isEmpty()) {
            return decodedString;
        }

        char [][] charArray = new char[n][s.length()];
        int row = 0;
        int col = 0;
        int l = n;
        boolean up = false;
        int m = row;
        boolean odd = true;
        int buffer = 0;

        for (int k = 0; k < s.length(); k++)
        {
            charArray[row][col] = s.charAt(k);

            if (row == (n - 1)) {
                m = 0;
            } else {
                m = row;
            }

            if (row == 0 || row == (n-1)) {
                buffer = ((n - 2) * 2) + 2;
            } else {
                if (odd) {
                    buffer = (((n - (2 + m)) * 2) + 2);
                    odd = false;
                } else {
                    buffer = ((row - 1) * 2) + 2;
                    odd = true;
                }
            }

            col += buffer;

            if (col >= s.length()) {
                row++;
                col = row;
                odd = true;
            }
        }

        int j = 0;
        up = false;
        row = 0;
        col = 0;
        while (j < s.length()) {
            decodedString += charArray[row][col];

            if (row == (n - 1)) {
                up = true;
            } else if (row == 0) {
                up = false;
            }

            row = (up) ? --row : (++row);
            col = ((col + 1) >= s.length()) ? 0 : (++col);

            j++;
        }

        return decodedString;
    }
}
