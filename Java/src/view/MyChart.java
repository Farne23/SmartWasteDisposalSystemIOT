package view;

import java.awt.Color;
import java.awt.Font;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.plot.XYPlot;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

public class MyChart {

    private static final int MAX_ITEM = 30;
    private static final long TIME = System.currentTimeMillis();
    private static final double MIN_TEMP = -30.0,
            MAX_TEMP = 70.0,
            TO_PERC = 100;
    private final Font font;
    private final Color BG;
    private final XYSeriesCollection dataset = new XYSeriesCollection();
    private JFreeChart chart;
    private ChartPanel pane;

    public MyChart(Color bg, Font font) {
        this.font = font;
        this.BG = bg;
        init();
    }

    private void init() {
        XYSeries wasteLvSeries = new XYSeries("Waste level"),
                tempSeries = new XYSeries("Temperature"),
                stateSeries = new XYSeries("State");
        wasteLvSeries.setMaximumItemCount(MAX_ITEM);
        tempSeries.setMaximumItemCount(MAX_ITEM);
        stateSeries.setMaximumItemCount(MAX_ITEM);
        
        // adding new series to the dataset
        dataset.addSeries(wasteLvSeries);
        dataset.addSeries(tempSeries);
        dataset.addSeries(stateSeries);
        // giving a dataset to the chart
        this.chart = ChartFactory.createXYLineChart("System current state",
                "Time (ms)", "Percentage %", this.dataset);
        // add all to the panel
        this.pane = new ChartPanel(this.chart);
        // STYLE COMPONENTS
        //this.chart.setBackgroundPaint(BG);
        this.pane.setOpaque(false);
        this.chart.setBackgroundPaint(new Color(0, 0, 0, 0));
        this.chart.getPlot().setBackgroundPaint(Color.black);
        var plot = (XYPlot) chart.getPlot();
        NumberAxis rangeAxis = (NumberAxis)plot.getRangeAxis();
        rangeAxis.setRangeWithMargins(0.0, 100.0);
        this.chart.getTitle().setPaint(Color.white);
        plot.getDomainAxis().setLabelPaint(Color.white);
        plot.getDomainAxis().setLabelFont(this.font);
        plot.getRangeAxis().setLabelPaint(Color.white);
        plot.getRangeAxis().setLabelFont(this.font);
        plot.getDomainAxis().setTickLabelPaint(Color.white);
        plot.getDomainAxis().setTickLabelFont(this.font);
        plot.getRangeAxis().setTickLabelPaint(Color.white);
        plot.getRangeAxis().setTickLabelFont(this.font);
        this.chart.getLegend().setItemPaint(Color.white);
        this.chart.getLegend().setBackgroundPaint(BG);
        this.chart.getLegend().setItemFont(this.font);
    }

    public ChartPanel getPanel() {
        return this.pane;
    }

    public void addData(double level, double temp, boolean alarmOn) {
        // compute elapsed time
        long elapsed = System.currentTimeMillis() - TIME;
        this.dataset.getSeries(0).add(elapsed, level);
        // compute percentage temp
        double percTemp = ((temp - MIN_TEMP)/(MAX_TEMP - MIN_TEMP) * TO_PERC);
        this.dataset.getSeries(1).add(elapsed, percTemp);
        this.dataset.getSeries(2).add(elapsed, alarmOn ? TO_PERC : 0);
    }
}

