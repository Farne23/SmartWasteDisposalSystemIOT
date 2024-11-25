package model.communication;

public class TempInfo {

    private final double temp;
    private final boolean alarmFlag;

    public TempInfo(double temp, boolean alarmFlag) {
        this.temp = temp;
        this.alarmFlag = alarmFlag;
    }

    public double getTemperature() {
        return this.temp;
    }

    public boolean getState() {
        return this.alarmFlag;
    }
}
