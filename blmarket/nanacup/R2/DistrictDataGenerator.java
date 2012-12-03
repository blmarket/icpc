import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import java.security.*;
import javax.swing.*;
import java.lang.Math.*;

public class DistrictDataGenerator {
    static Process proc;
    JFrame jf;
    InputStream is;
    OutputStream os;
    BufferedReader br;
    static int dump;

    int n, m;
    double [][] t_table;
    double [][] e_table;

    int valid;
    
    // ---------------------------------------------------

    void generate(String seed) {
      try {
        SecureRandom r = SecureRandom.getInstance("SHA1PRNG");
        r.setSeed(Long.parseLong(seed));

        n = r.nextInt(81) + 20;
        m = r.nextInt(81) + 20;
        if (seed.equals("1")) n = m = 20;
        if (seed.equals("10")) n = m = 100;
        int t = r.nextInt(9) + 2;
        int e = r.nextInt(9) + 2;
        t_table = new double[n][m];
        e_table = new double[n][m];

        for (int i=0; i<t; i++) {
          int y0 = r.nextInt(n);
          int x0 = r.nextInt(m);
          double d = r.nextDouble() * 1.0 + 0.5;
          double b = r.nextDouble() * 9.0 + 1.0;
          double M = r.nextDouble() * 1000.0 + 500.0;
          for (int y=0; y<n; y++)
            for (int x=0; x<m; x++) {
              t_table[y][x] += M/Math.pow(b + Math.sqrt((y-y0)*(y-y0)+(x-x0)*(x-x0)), d) * (r.nextDouble() * 0.3 + 0.85);
}
        }

        for (int i=0; i<e; i++) {
          int y0 = r.nextInt(n);
          int x0 = r.nextInt(m);
          double d = r.nextDouble() * 1.0 + 0.5;
          double b = r.nextDouble() * 9.0 + 1.0;
          double M = r.nextDouble() * 1000.0 + 500.0;
          for (int y=0; y<n; y++)
            for (int x=0; x<m; x++)
              e_table[y][x] += M/Math.pow(b + Math.sqrt((y-y0)*(y-y0)+(x-x0)*(x-x0)), d) * (r.nextDouble() * 0.3 + 0.85);
        }

        double sum_t = 0.0, sum_e = 0.0;
        for (int i=0; i<n; i++)
          for (int j=0; j<m; j++) {
            sum_t += t_table[i][j];
            sum_e += e_table[i][j];
          }

        double ratio = sum_t / sum_e * (r.nextDouble() * 0.18 + 0.8);

        for (int i=0; i<n; i++)
          for (int j=0; j<m; j++)
            e_table[i][j] *= ratio;
      }
      catch (Exception e) {
        addFatalError("An exception occurred while generating test case.");
        e.printStackTrace();
      }
    }
    // ---------------------------------------------------

    int calcScore() {
      if (valid == 0) {
        addFatalError("Your return syntax is not valid.");
        return 0;
      }
      return 0;
    }

    public int runTest(String seed) { // double in latter cases
      try {
        generate(seed);

        System.out.println(n + " " + m);
        for (int i=0; i<n; i++) {
          for (int j=0; j<m; j++) {
            if (j > 0) System.out.print(" ");
            int t = (int)Math.round(t_table[i][j]);
            System.out.print(t);
          }
          System.out.println("");
        }
        for (int i=0; i<n; i++) {
          for (int j=0; j<m; j++) {
            if (j > 0) System.out.print(" ");
            int t = (int)Math.round(e_table[i][j]);
            System.out.print(t);
          }
          System.out.println("");
        }

        return 0;
      }
      catch (Exception e) {
        addFatalError("An exception occurred while trying to get your program's results.");
        e.printStackTrace();
        return 0;
      }
    }

    public DistrictDataGenerator(String seed) {
        //interface for runTest
        runTest(seed);

        if (proc != null)
            try { proc.destroy(); }
            catch (Exception e) { e.printStackTrace(); }
    }
    // ---------------------------------------------------
    public static void main(String[] args) {
        String seed = "1";
        dump = 1;
        for (int i = 0; i<args.length; i++)
        {   if (args[i].equals("-seed"))
                seed = args[++i];
        }
        DistrictDataGenerator f = new DistrictDataGenerator(seed);
    }
    // ---------------------------------------------------
    void addFatalError(String message) {
        System.out.println(message);
    }
}

class ErrorReader extends Thread{
    InputStream error;
    public ErrorReader(InputStream is) {
        error = is;
    }
    public void run() {
        try {
            byte[] ch = new byte[50000];
            int read;
            while ((read = error.read(ch)) > 0)
            {   String s = new String(ch,0,read);
                System.out.print(s);
                System.out.flush();
            }
        } catch(Exception e) { }
    }
}

