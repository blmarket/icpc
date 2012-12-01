import java.util.*;
import java.lang.*;
import java.text.*;
import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import java.security.*;
import javax.swing.*;
import javax.imageio.*;

public class DistrictVis {
    boolean err;
    static String input;
    static String output;
    int [][] t_table;
    int [][] e_table;
    int n, m;
    int dist_n;
    int yy, xx, t_sum, e_sum;
    static int pixel;
    int [][] dist_table;
    int N;		//number of colors/types
    int S;		//board size
    int D;		//number of tiles allowed to be discarded in row
    int nd;		//number of tiles discarded in row now
    int nt;		//number of tiles on the board
    int nm;		//number of tiles placed
    int sc;		//score
    String newt;	//next tile
    String errmes;	//error message from validMove() and/or validReturn()
    // -----------------------------------------
    public void runTest() {
      try {
        yy = xx = -1;
        jf.setSize(pixel*m+200,pixel*n+33);
        v.repaint();
        jf.setVisible(true);

        //start simulation
        phase = 0;
        while (true) {
          draw();
          waitNextMode();
        }
      }
      catch (Exception e) { 
        System.err.println("An exception occurred while trying to draw.");
        e.printStackTrace(); 
      }
    }
// ------------- server part -------------------
    public String checkData(String test) {
        return "";
    }
    // -----------------------------------------
    public String displayTestCase(String test) {
        StringBuffer sb = new StringBuffer();
        sb.append("seed = "+test);
        return sb.toString();
    }
    // -----------------------------------------
    public double[] score(double[][] sc) {
        double[] res = new double[sc.length];
        //exotic relative
        int i,j,k;
        for (i=0; i<sc.length; i++)
            res[i]=0;
        if (sc.length<=1)
            return res;
        for (j=0; j<sc[0].length; j++)
        for (i=0; i<sc.length; i++)
        for (k=i+1; k<sc.length; k++)
        {   if (sc[i][j]>sc[k][j])
                res[i]++;
            else
            if (sc[i][j]<sc[k][j])
                res[k]++;
            else
            {   res[i]+=0.5;
                res[k]+=0.5;
            }
        }
        for (i=0; i<sc.length; i++)
            res[i]/=(sc.length-1);
        return res;
    }
// ------------- visualization part ------------
    static boolean vis;
    static boolean manual;
    static Process proc;
    static int del;
    int phase;
    InputStream is;
    OutputStream os;
    BufferedReader br;
    JFrame jf;
    Vis v;
    int visret;
    // -----------------------------------------
    void waitNextMode() throws IOException {
        while (visret == 0) {try{Thread.sleep(50);}catch(Exception e){e.printStackTrace();}}
        visret = 0;
    }
    // -----------------------------------------
    void draw() {
        if (!vis) return;
        v.repaint();
        if (del>0)
            try { Thread.sleep(del); } 
            catch (Exception e) { e.printStackTrace(); };
    }
    // -----------------------------------------
    public class Vis extends JPanel implements MouseListener, WindowListener {
        public void paint(Graphics g) {
            //do painting here
            BufferedImage bi = new BufferedImage(m*pixel+200,n*pixel+20,BufferedImage.TYPE_INT_RGB);
            Graphics2D g2 = (Graphics2D)bi.getGraphics();
            //background
            g2.setColor(Color.LIGHT_GRAY);
            g2.fillRect(0,0,m*pixel+200,n*pixel+15);

            //cells of the board

            if (phase > 0) {
              int mmax = 1;
              for (int y=0; y<n; y++)
                for (int x=0; x<m; x++) {
                  if (phase == 1) mmax = Math.max(mmax, t_table[y][x]);
                  if (phase == 2) mmax = Math.max(mmax, e_table[y][x]);
                }
              for (int y=0; y<n; y++)
                for (int x=0; x<m; x++) {
                  double rr = t_table[y][x] / (double)mmax;
                  if (phase == 2) rr = e_table[y][x] / (double)mmax;
                  if (phase == 3) rr = t_table[y][x] / (double)(e_table[y][x] + t_table[y][x]);
                  int v = (int)Math.round(rr * 192);
                  if (v < 0) v = 0;
                  if (phase == 2) v <<= 8;
                  if (phase == 3) v <<= 16;
                  g2.setColor(new Color(v));
                  g2.fillRect(x*pixel, y*pixel, pixel, pixel);
                }
            }

            //lines in board grid
            if (phase == 0) g2.setColor(Color.BLACK);
            if (phase == 1) g2.setColor(Color.YELLOW);
            if (phase == 2) g2.setColor(Color.RED);
            if (phase == 3) g2.setColor(Color.GREEN);

            g2.drawLine(0, 0, m*pixel, 0);
            g2.drawLine(0, n*pixel, m*pixel, n*pixel);
            g2.drawLine(0, 0, 0, n*pixel);
            g2.drawLine(m*pixel, 0, m*pixel, n*pixel);
            for (int y=0; y<n; y++)
              for (int x=1; x<m; x++)
                if (dist_table[y][x-1] != dist_table[y][x])
                  g2.drawLine(x*pixel,y*pixel,x*pixel,(y+1)*pixel);
            for (int y=1; y<n; y++)
              for (int x=0; x<m; x++)
                if (dist_table[y-1][x] != dist_table[y][x])
                  g2.drawLine(x*pixel,y*pixel,(x+1)*pixel,y*pixel);

            //text info
            g2.setColor(Color.BLACK);
            g2.setFont(new Font("Arial",Font.BOLD,18));
            char[] ch;

            g2.drawRect(pixel*m+6, 16, 180, 48);
            ch = ("Teletubbies density").toCharArray();
            g2.drawChars(ch,0, ch.length,pixel*m+10, 45);

            g2.drawRect(pixel*m+6, 76, 180, 48);
            ch = ("   E.T. density    ").toCharArray();
            g2.drawChars(ch,0, ch.length,pixel*m+10, 105);

            g2.drawRect(pixel*m+6, 136, 180, 48);
            ch = (" Teletubbies Ratio ").toCharArray();
            g2.drawChars(ch,0, ch.length,pixel*m+10, 165);

            if (yy > -1 && xx > -1) {
              ch = ("Sum of Tele: " + t_sum).toCharArray();
              g2.drawChars(ch,0, ch.length,pixel*m+10, 258);
              ch = ("Sum of E.T.: " + e_sum).toCharArray();
              g2.drawChars(ch,0, ch.length,pixel*m+10, 288);
            }

            g.drawImage(bi,0,0,m*pixel+200,n*pixel+20,null);
        }
        public Vis() {
            addMouseListener(this);
            jf.addWindowListener(this);
        }
        //MouseListener
        public void mouseClicked(MouseEvent e) {
            //convert to args only clicks with valid coordinates
            visret = 1;
            int ey = e.getY();
            int ex = e.getX();
            if (ex >= pixel*m+6 && ex <= pixel*m+6+180 && ey >= 16 && ey <= 16+48) { phase = 1; return; }
            if (ex >= pixel*m+6 && ex <= pixel*m+6+180 && ey >= 76 && ey <= 76+48) { phase = 2; return; }
            if (ex >= pixel*m+6 && ex <= pixel*m+6+180 && ey >= 136 && ey <= 136+48) { phase = 3; return; }

            int r = ey/pixel, c = ex/pixel;
            if (r < 0 || c < 0 || r >= n || c >= m) return;
            yy = r;
            xx = c;
	    t_sum = e_sum = 0;
            for (int i=0; i<n; i++)
              for (int j=0; j<m; j++)
                if (dist_table[i][j] == dist_table[yy][xx]) {
                  t_sum += t_table[i][j];
                  e_sum += e_table[i][j];
                }
        }
        public void mousePressed(MouseEvent e) { }
        public void mouseReleased(MouseEvent e) { }
        public void mouseEntered(MouseEvent e) { }
        public void mouseExited(MouseEvent e) { }
        //WindowListener
        public void windowClosing(WindowEvent e){ 
            if(proc != null)
                try { proc.destroy(); } 
                catch (Exception ex) { ex.printStackTrace(); }
            System.exit(0); 
        }
        public void windowActivated(WindowEvent e) { }
        public void windowDeactivated(WindowEvent e) { }
        public void windowOpened(WindowEvent e) { }
        public void windowClosed(WindowEvent e) { }
        public void windowIconified(WindowEvent e) { }
        public void windowDeiconified(WindowEvent e) { }
    }
    // -----------------------------------------
    public void getInput() {
      try {
        BufferedReader in = new BufferedReader(new FileReader(input));
        String s;
        s = in.readLine();
        String[] sp = s.split(" ");
        n = Integer.parseInt(sp[0]);
        m = Integer.parseInt(sp[1]);
        if (pixel == 0) {
          if (n > m) pixel = 800 / n; else pixel = 800 / m;
        }
        t_table = new int[n][m];
        e_table = new int[n][m];
        for (int i=0; i<n; i++) {
          s = in.readLine();
          sp = s.split(" ");
          for (int j=0; j<m; j++)
            t_table[i][j] = Integer.parseInt(sp[j]);
        }
        for (int i=0; i<n; i++) {
          s = in.readLine();
          sp = s.split(" ");
          for (int j=0; j<m; j++)
            e_table[i][j] = Integer.parseInt(sp[j]);
        }

        in.close(); 
      }
      catch (Exception e) {
        addFatalError("An exception occurred while reading input file.");
        e.printStackTrace();
      }
    }
    // ----------------------------------------
    public int getOutput() {
      try {
        BufferedReader in = new BufferedReader(new FileReader(output));
        String s;
        s = in.readLine();
        dist_n = Integer.parseInt(s);
        dist_table = new int[n][m];
        int total_cnt = 0;
        int min_pop = 99999999;
        int max_pop = 0;
        for (int i=0; i<dist_n; i++) {
          s = in.readLine();
          String[] sp = s.split(" ");
          int sz = Integer.parseInt(sp[0]);
          if (sz <= 0 || sz > n*m || sp.length < 1 + sz*2) {
            addFatalError("For district #" + i + ", your result has too few or too many area segment.");
            return 0;
          }
          int t_pop = 0;
          int e_pop = 0;
          for (int j=0; j<sz; j++) {
            int y = Integer.parseInt(sp[j*2+1]);
            int x = Integer.parseInt(sp[j*2+2]);
            if (y<0 || y>=n || x<0 || x>=m) {
              addFatalError("For district #" + i + ", Out of bounds.");
              return 0;
            }
            if (dist_table[y][x] != 0) {
              addFatalError("For district #" + i + ", (" + y + ", " + x + ") was used twice.");
              return 0;
            }
            dist_table[y][x] = -(i+1);
            total_cnt ++;
            t_pop += t_table[y][x];
            e_pop += e_table[y][x];
          }
          if (t_pop <= e_pop) {
            addFatalError("For district #" + i + ", Teletubbies population should be strictly larger than E.T. population.");
            return 0;
          }
          min_pop = Math.min(min_pop, t_pop + e_pop);
          max_pop = Math.max(max_pop, t_pop + e_pop);
          // check connectivity inefficiently.
          int[] yy = new int[sz];
          int[] xx = new int[sz];
          int rr = 1, ll = 0;
          yy[0] = Integer.parseInt(sp[1]);
          xx[0] = Integer.parseInt(sp[2]);
          dist_table[yy[0]][xx[0]] = i+1;
          while (ll < rr) {
            if (yy[ll]>0 && dist_table[yy[ll]-1][xx[ll]] == -(i+1)) {
              yy[rr] = yy[ll]-1;
              xx[rr] = xx[ll];
              dist_table[yy[rr]][xx[rr]] = i+1;
              rr ++;
            }
            if (yy[ll]<n-1 && dist_table[yy[ll]+1][xx[ll]] == -(i+1)) {
              yy[rr] = yy[ll]+1;
              xx[rr] = xx[ll];
              dist_table[yy[rr]][xx[rr]] = i+1;
              rr ++;
            }
            if (xx[ll]>0 && dist_table[yy[ll]][xx[ll]-1] == -(i+1)) {
              yy[rr] = yy[ll];
              xx[rr] = xx[ll]-1;
              dist_table[yy[rr]][xx[rr]] = i+1;
              rr ++;
            }
            if (xx[ll]<m-1 && dist_table[yy[ll]][xx[ll]+1] == -(i+1)) {
              yy[rr] = yy[ll];
              xx[rr] = xx[ll]+1;
              dist_table[yy[rr]][xx[rr]] = i+1;
              rr ++;
            }
            ll ++;
          }
          if (rr != sz) {
            addFatalError("Your District #" + i + " is not 4-connected.");
            return 0;
          }
        }
        if (total_cnt != n*m) {
          addFatalError("You didn't assign all area segments to districts.");
          return 0;
        }
        if (max_pop > min_pop * 5) {
          addFatalError("Your largest district is too large than your smallest district.");
          return 0;
        }

        in.close();
      }
      catch (Exception e) {
        addFatalError("An exception occurred while reading output file.");
        e.printStackTrace();
      }
      return 1;
    }
    // ----------------------------------------

    public DistrictVis() {
      try {
        //interface for runTest
        if (vis)
        {   jf = new JFrame();
            v = new Vis();
            jf.getContentPane().add(v);
        }

        getInput();
        if (err) {
          System.out.println("Score = 0");
          return;
        }
        getOutput();
        if (err) {
          System.out.println("Score = 0");
          return;
        }

        System.out.println("Score = " + dist_n);
        if (vis) runTest();
        if (proc != null)
            try { proc.destroy(); } 
            catch (Exception e) { e.printStackTrace(); }
        if (manual)
            System.exit(0);
      }
      catch (Exception e) {
        addFatalError("An exception occurred while trying to get your program's results.");
        e.printStackTrace();
      }
    }
    // -----------------------------------------
    public static void main(String[] args) {
        vis = true;
        manual = false;
        del=100;
        for (int i = 0; i<args.length; i++)
        {
            if (args[i].equals("-input"))
                input = args[++i];
            if (args[i].equals("-output"))
                output = args[++i];
            if (args[i].equals("-novis"))
                vis = false;
//            if (args[i].equals("-manual"))
//                manual = true;
	    if (args[i].equals("-pixel"))
		pixel = Integer.parseInt(args[++i]);
        }
        if (manual)
        {   vis = true;
            del = 0;	//no artificial delays
        }
        DistrictVis f = new DistrictVis();
    }
    // -----------------------------------------
    void addFatalError(String message) {
        System.out.println(message);
        err = true;
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
