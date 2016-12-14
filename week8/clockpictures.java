import java.util.*;
import java.io.*;

public class ClockPictures {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  public static void main(String[] args) throws IOException {

    String line[] = br.readLine().split(" +");
    int n = Integer.valueOf(line[0]);

    // Setup
    int[] clock1 = new int[2 * n];
    int[] clock2 = new int[n];
    int[] clock_tmp = new int[n];

    // Read in first clock
    readAndSort(clock_tmp);
    for (int i = 1; i < n; i++) {
      int angle = Math.abs(clock_tmp[i - 1] - clock_tmp[i]);
      clock1[i] = angle;
      clock1[n + i] = angle;
    }

    // Account for the clock being circular
    clock1[0] = clock1[n] = clock_tmp[0] + (360000 - clock_tmp[n - 1]);

    // Read in second clock
    readAndSort(clock_tmp);
    for (int i = 1; i < n; i++)
      clock2[i] = Math.abs(clock_tmp[i - 1] - clock_tmp[i]);

    // Account for the clock being circular
    clock2[0] = clock_tmp[0] + (360000 - clock_tmp[n - 1]);

    // Use KMP algorithm to see if one array is contained within the other
    if (kmp(clock1, clock2) > 0)
      System.out.println("possible");
    else
      System.out.println("impossible");

  }

  static int kmp(int[] txt, int[] pat) {
    int m = pat.length, n = txt.length, i = 0, j = 0, count = 0;
    int[] arr = kmpHelper(pat, m);
    while (i < n) {
      if (pat[j] == txt[i]) {
        j++;
        i++;
      }
      if (j == m) {
        count++; // match at i-j
        j = arr[j - 1];
      } else if (i < n && pat[j] != txt[i]) {
        if (j != 0) j = arr[j - 1];
        else i = i + 1;
      }
    }
    return count;
  }

  static void readAndSort(int[] clockTmp) throws IOException {
    String[] line = br.readLine().split(" +");
    for (int i = 0; i < clockTmp.length; i++)
      clockTmp[i] = Integer.valueOf(line[i]);
    Arrays.sort(clockTmp);
  }

  static int[] kmpHelper(int[] pat, int m) {
    int len = 0, i = 1;
    int[] arr = new int[m];
    arr[0] = 0;
    while (i < m) {
      if (pat[i] == pat[len]) {
        len++;
        arr[i] = len;
        i++;
      } else {
        if (len != 0) len = arr[len - 1];
        else {
          arr[i] = 0;
          i++;
        }
      }
    }
    return arr;
  }

}