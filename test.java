import java.util.Scanner;

public class test {
  static final double INF = 4e18;
  static double[][] dp;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String xInput = scanner.nextLine().trim();
    String yInput = scanner.nextLine().trim();
    int sInput = scanner.nextInt();
    int rInput = scanner.nextInt();
    dp = new double[104 + 1][104 + 1];
    for (int i = 0; i <= 104; i++) {
      for (int j = 0; j <= 104; j++) {
        dp[i][j] = -1;
      }
    }

    double ansResult = solve(sInput, rInput, xInput, yInput);
    if (ansResult == INF) {
      System.out.print("Impossible");
    } else {
      System.out.print(ansResult);
    }
  }

  static double minStringFactor(int i, int j, int s, int r, String x, String y, String y1) {
    if (i > j) {
      return 0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    double mini = INF;
    for (int k = i; k <= j; k++) {
      if (y1.contains(x.substring(i, k + 1))) {
        mini = Math.min(mini, r + minStringFactor(k + 1, j, s, r, x, y, y1));
      }
      if (y.contains(x.substring(i, k + 1))) {
        mini = Math.min(mini, s + minStringFactor(k + 1, j, s, r, x, y, y1));
      }
    }

    dp[i][j] = mini;
    return mini;
  }

  static double solve(int s, int r, String x, String y) {
    String y1 = new StringBuilder(y).reverse().toString();
    return minStringFactor(0, x.length() - 1, s, r, x, y, y1);
  }
}