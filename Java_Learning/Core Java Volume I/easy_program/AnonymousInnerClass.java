import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class AnonymousInnerClass {
    public static void main(String[] args) {
        TalkingClock clock = new TalkingClock();
        clock.start(1000, true);

        // keep program running until user selects "OK"
        javax.swing.JOptionPane.showMessageDialog(null, "Quit program?");
        System.exit(0);
    }
}

class TalkingClock {
    public void start(int interval, boolean beep) {
        ActionListener listener = new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                System.out.println("At the tone, the time is " + new Date());
                if (beep) Toolkit.getDefaultToolkit().beep();
            }
        };
        javax.swing.Timer t = new javax.swing.Timer(interval, listener);
        t.start();
    }
}