package view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import view.api.ControlPanelView;

public class Dashboard extends JFrame implements ControlPanelView {

    private static final long serialVersionUID = 1L;
    private static final int WIDTH = 900,
            HEIGHT = 800,
            PADDING = 40;
    private static final DecimalFormat FORMAT = new DecimalFormat("0.00");
    private final ImageIcon bgN = new ImageIcon(getClass().getResource("/images/bgnorth.jpg")),
            bgS = new ImageIcon(getClass().getResource("/images/bgsouth.jpg"));
    private final Color BG = new Color(32, 64, 96);
    private static final Font FONT = new Font("Arial", Font.BOLD, 20);
    private  static final String TITLE = "Smart Waste Disposal System";
    private final JButton empty = new JButton("Empty"),
            repair = new JButton("Repair");
    private MyChart chart = new MyChart(BG, new Font("Arial", Font.PLAIN, 12));
    private final JLabel temp = new JLabel("---°C"),
            wasteLv = new JLabel("---%"),
            alarm = new JLabel();
    private final JPanel north = new JPanel(new GridBagLayout()) {
        private static final long serialVersionUID = 1L;
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            if (bgN != null) {
                g.drawImage(bgN.getImage(), 0, 0, getWidth(), getHeight(), this);
            }
        }
    },
            south = new JPanel(new GridBagLayout())  {
                private static final long serialVersionUID = 2L;
                @Override
                protected void paintComponent(Graphics g) {
                    super.paintComponent(g);
                    if (bgS != null) {
                        g.drawImage(bgS.getImage(), 0, 0, getWidth(), getHeight(), this);
                    }
                    
                }
            };

    public Dashboard(Runnable empty, Runnable repair) {
        super(TITLE);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        initialize();
        /*
         * Assignining handlers to the buttons.
         */
        this.empty.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                empty.run();
            }
        });
        this.repair.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                repair.run();
            }
        });
        this.setVisible(true);
    }

    @Override
    public void update(double level, double temp, boolean alarmOn) {
        this.wasteLv.setText(FORMAT.format(level * 100) + " %");
        this.temp.setText(FORMAT.format(temp) + " °C");
        this.repair.setEnabled(alarmOn);
        // add data to the graphic
        this.chart.addData(level, temp, alarmOn);
        // GRAPHIC DETAILS
        if (level > 0.5) {
            this.wasteLv.setForeground(Color.orange);
            if (level > 0.75) {
                this.wasteLv.setForeground(Color.red);
            }
        } else {
            this.wasteLv.setForeground(Color.white);
        }
        this.temp.setForeground(alarmOn ? Color.red : Color.white);
        this.alarm.setVisible(alarmOn);
        this.revalidate();
        this.repaint();
    }

    private void initialize() {
        var content = new JPanel(new BorderLayout());
        JLabel wasteHeader = new JLabel("Waste Level: "),
                tempHeader = new JLabel("Temperature: ");
        JPanel wasteWrap = new JPanel(),
                tempWrap = new JPanel();
        this.alarm.setIcon(new ImageIcon(getClass().getResource("/images/overheat.png")));
        GridBagConstraints gbc = new GridBagConstraints();
        this.setSize(WIDTH, HEIGHT);
        this.setContentPane(content);
        this.empty.setFont(FONT);
        this.repair.setFont(FONT);
        this.wasteLv.setFont(FONT);
        this.temp.setFont(FONT);
        wasteHeader.setFont(FONT);
        tempHeader.setFont(FONT);
        this.alarm.setVisible(false);
        // add label to respective wrappers
        wasteWrap.add(wasteHeader);
        wasteWrap.add(this.wasteLv);
        tempWrap.add(tempHeader);
        tempWrap.add(this.temp);
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(PADDING, 0, PADDING, 0);
        gbc.weightx = 0.5;
        this.north.add(this.empty, gbc);
        gbc.gridx = 1;
        this.north.add(this.repair, gbc);
        // Configurazione pannello south per layout verticale
        gbc.gridx = 0; // Prima colonna (tutta la larghezza del pannello sud)
        gbc.weighty = 0.5; // Distribuzione equa dello spazio verticale
        gbc.gridy = 0; // Prima riga
        gbc.insets = new Insets(0, PADDING, 0, PADDING);
        gbc.anchor = GridBagConstraints.WEST; // Centra nella cella
        this.south.add(wasteWrap, gbc);
        gbc.anchor = GridBagConstraints.NORTH;
        gbc.gridy = 1; // Seconda riga
        this.south.add(tempWrap, gbc);
        gbc.anchor = GridBagConstraints.CENTER;
        gbc.fill = GridBagConstraints.BOTH;
        gbc.gridy = 0;
        gbc.gridx = 1;
        gbc.weighty = 0.9;
        // add chart
        this.south.add(this.chart.getPanel(), gbc);
        gbc.fill = GridBagConstraints.NONE;
        gbc.gridy = 1;
        gbc.weighty = 0.1;
        // add alarm label
        this.south.add(this.alarm, gbc);
        // STYLE COMPONENTS
        this.empty.setBackground(BG);
        this.empty.setForeground(Color.white);
        this.repair.setBackground(BG);
        this.repair.setForeground(Color.white);
        if (this.bgN == null || bgS == null) {
            this.north.setBackground(BG);
            this.south.setBackground(BG);
        }
        this.wasteLv.setForeground(Color.WHITE);
        this.temp.setForeground(Color.WHITE);
        wasteHeader.setForeground(Color.WHITE);
        tempHeader.setForeground(Color.WHITE);
        wasteWrap.setOpaque(false);
        tempWrap.setOpaque(false);
        // add in main panel
        content.add(this.north, BorderLayout.NORTH);
        content.add(this.south, BorderLayout.CENTER);
    }
}
