import java.awt.EventQueue;

import javax.swing.JFrame;

import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;

import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.ActionEvent;

import javax.swing.JLabel;

import javax.swing.SwingConstants;

public class Frame1 {

    private JFrame frame;

    // we added the line below this one

    private JLabel lblMessage;

    /**
     * 
     * Launch the application.
     * 
     */

    public static void main(String[] args) {

        EventQueue.invokeLater(new Runnable() {

            public void run() {

                try {

                    Frame1 window = new Frame1();

                    window.frame.setVisible(true);

                } catch (Exception e) {

                    e.printStackTrace();

                }

            }

        });

    }

    /**
     * 
     * Create the application.
     * 
     */

    public Frame1() {

        initialize();

    }

    /**
     * 
     * Initialize the contents of the frame.
     * 
     */

    private void initialize() {

        frame = new JFrame();

        frame.setBounds(100, 100, 450, 300);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.getContentPane().setLayout(null);

        JTextField txtUserText = new JTextField("please enter text to capitalize");

        txtUserText.addMouseListener(new MouseListener() {

            @Override
            public void mouseReleased(MouseEvent e) {

            }

            @Override
            public void mousePressed(MouseEvent e) {

            }

            @Override
            public void mouseExited(MouseEvent e) {

            }

            @Override
            public void mouseEntered(MouseEvent e) {

            }

            @Override
            public void mouseClicked(MouseEvent e) {
                txtUserText.setText("");
            }
        });

        JButton btnNewButton = new JButton("Show Message");

        btnNewButton.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {

                lblMessage.setBounds(140, 68, 200, 14);
                lblMessage.setText(txtUserText.getText().toUpperCase());
                txtUserText.setText("please enter text to capitalize");

            }

        });

        txtUserText.setHorizontalAlignment(SwingConstants.CENTER);

        txtUserText.setBounds(140, 120, 200, 20);

        frame.getContentPane().add(txtUserText);

        btnNewButton.setBounds(140, 159, 122, 23);

        frame.getContentPane().add(btnNewButton);

        lblMessage = new JLabel("Message");

        lblMessage.setHorizontalAlignment(SwingConstants.CENTER);

        lblMessage.setBounds(140, 68, 137, 14);

        frame.getContentPane().add(lblMessage);

    }

}