package GUI;

import javax.swing.*;
import java.awt.*;

class MyFrame extends JFrame{
    MyFrame(){
        JPanel jPanel = new JPanel();
        jPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 20, 10));
        jPanel.setBackground(Color.YELLOW);
        add(jPanel, BorderLayout.NORTH);

        //header
        JLabel jLabel = new JLabel("Welcome");
        jLabel.setForeground(Color.BLACK);
        jLabel.setFont(new Font("Monospaced", Font.BOLD, 30));
        //logo
        ImageIcon imageIcon = new ImageIcon("logo.png");
        Image image = imageIcon.getImage().getScaledInstance(70, 70, Image.SCALE_SMOOTH);
        ImageIcon imageIcon1 = new ImageIcon(image);
        jLabel.setIcon(imageIcon1);
        jLabel.setIconTextGap(10);

        jPanel.add(jLabel);



        JPanel jPanel1 = new JPanel();
        jPanel1.setBorder(BorderFactory.createEmptyBorder(20, 10, 20, 10));
        jPanel1.setBackground(Color.GRAY);
        add(jPanel1, BorderLayout.CENTER);

        JTextField jTextField = new JTextField();
        jPanel1.add(jTextField);


        setVisible(true);
        setSize(640, 480);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

public class Frame {
    public static void main(String[] args) {
        MyFrame myFrame = new MyFrame();
    }
}
