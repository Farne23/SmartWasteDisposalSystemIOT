package view;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

public class MyChart {

    private static final long TIME = System.currentTimeMillis();
    private static final double MIN_TEMP = -30.0,
            MAX_TEMP = 70.0,
            TO_PERC = 100;
    private final XYSeriesCollection dataset = new XYSeriesCollection();
    private JFreeChart chart;
    private ChartPanel pane;

    public MyChart() {
        init();
    }

    private void init() {
        // adding new series to the dataset
        dataset.addSeries(new XYSeries("Waste level"));
        dataset.addSeries(new XYSeries("Temperature"));
        dataset.addSeries(new XYSeries("State"));
        // giving a dataset to the chart
        this.chart = ChartFactory.createXYLineChart("System current state",
                "Time (s)", "Percentage %", this.dataset);
        // add all to the panel
        this.pane = new ChartPanel(this.chart);
    }

    public ChartPanel getPanel() {
        return this.pane;
    }

    public void addData(double level, double temp, boolean alarmOn) {
        // compute elapsed time
        long elapsed = System.currentTimeMillis() - TIME;
        this.dataset.getSeries(0).add(elapsed, level * TO_PERC);
        // compute percentage temp
        double percTemp = ((temp - MIN_TEMP)/(MAX_TEMP - MIN_TEMP)) * TO_PERC;
        this.dataset.getSeries(1).add(elapsed, percTemp);
        this.dataset.getSeries(2).add(elapsed, alarmOn ? TO_PERC : 0);
    }
}

