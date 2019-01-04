import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ThreadDemo1 extends JFrame {
    private boolean stop1, stop2;
    private JTextField tfCount1, tfCount2;
    private int count = 1;

    public ThreadDemo1() {

        Container cp = getContentPane();
        cp.setLayout(new BorderLayout());

        JPanel panel1 = new JPanel();
        panel1.add(new JLabel("Counter"));
        tfCount1 = new JTextField(count + "", 10);
        tfCount1.setEditable(false);
        panel1.add(tfCount1);
        JButton btnStart1 = new JButton("Start Counting");
        JButton btnStop1 = new JButton("Stop Counting");
        panel1.add(btnStart1);
        panel1.add(btnStop1);
        JPanel panel2 = new JPanel();
        panel2.add(new JLabel("Counter"));
        tfCount2 = new JTextField(count + "", 10);
        tfCount2.setEditable(false);
        panel2.add(tfCount2);
        JButton btnStart2 = new JButton("Start Counting");
        JButton btnStop2 = new JButton("Stop Counting");
        panel2.add(btnStart2);
        panel2.add(btnStop2);
        btnStart1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent evt) {
                stop1 = false;

                Thread t1 = new Thread() {
                    @Override
                    public void run() {
                        for (int i = 0; i < 100000; ++i) {
                            if (stop1)
                                break;
                            tfCount1.setText(count + "");
                            ++count;
                            try {
                                sleep(10);
                            } catch (InterruptedException ex) {
                            }
                        }
                    }
                };
                t1.start();
            }
        });
        btnStart2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent evt) {
                stop2 = false;

                Thread t2 = new Thread() {
                    @Override
                    public void run() {
                        for (int i = 0; i < 100000; ++i) {
                            if (stop2)
                                break;
                            tfCount2.setText(count + "");
                            ++count;

                            try {
                                sleep(100);
                            } catch (InterruptedException ex) {
                            }
                        }
                    }
                };
                t2.start();
            }
        });

        btnStop1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent evt) {
                stop1 = true;
            }
        });
        btnStop2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent evt) {
                stop2 = true;
            }
        });

        cp.add(panel1, BorderLayout.NORTH);
        cp.add(panel2, BorderLayout.SOUTH);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Counter");
        setSize(500, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new ThreadDemo1();
            }
        });
    }
}