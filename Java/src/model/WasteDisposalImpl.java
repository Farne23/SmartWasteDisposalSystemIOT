package model;

import java.util.Optional;

import model.api.WasteDisposalModel;
import model.communication.SerialCommChannel;
import model.communication.api.CommChannel;
import util.Pair;

public class WasteDisposalImpl implements WasteDisposalModel {

    private final int VALUESN = 3;
    private final int BAUDRATE = 9600;
    private Optional<Pair<Double, Pair<Double, Boolean>>> lastValue;
    private Optional<CommChannel> channel;

    public WasteDisposalImpl(String port) {
        try {
            this.channel = Optional.of(new SerialCommChannel(port, BAUDRATE));
        } catch (Exception e) {
            System.out.println("Invalid port");
            this.channel = Optional.empty();
        }
        this.lastValue = Optional.empty();
    }

    @Override
    public Optional<Pair<Double, Pair<Double, Boolean>>> getStatus() {
        if(this.channel.isPresent() && this.channel.get().isMsgAvailable()) {
            
            /*
             * the received message should be
             * a string of the format: "level;temperature;alarm"
             * with level in [0.0, 1.0] and temeperature as 0/1.
             */
            try {
                String msg = this.channel.get().receiveMsg();
                String[] values = msg.split(";");
                try {
                    if (values.length == VALUESN) {
                        double level, temp;
                        int alarm;
                        level = Double.parseDouble(values[0]);
                        temp = Double.parseDouble(values[1]);
                        alarm = Integer.parseInt(values[2]);
                        // if level in [0.0, 1.0] and alarm in [0,1]
                        if (1.0 >= level && level >= 0.0 &&
                                alarm >= 0 && alarm <= 1) {
                            this.lastValue = Optional.of(new Pair<>(level,
                                    new Pair<>(temp, alarm == 1)));
                            return this.lastValue;
                        }
                    }
                    throw new NumberFormatException();
                } catch (NumberFormatException e) {
                    System.out.println("Invalid message format");
                    return this.lastValue;
                }
            } catch (InterruptedException e) {
                return this.lastValue;
            }
        }
        return this.lastValue;
    }

    @Override
    public void empty() {
        if (this.channel.isPresent()) {
            /*
             * the message format "L" sets
             * the waste level back to 0.
             */
            this.channel.get().sendMsg("L");
        }
    }

    @Override
    public void coolDown() {
        if (this.channel.isPresent()) {
            /*
             * the message format "A" ends the
             * alarm state.
             */
            this.channel.get().sendMsg("T");
        }
    }

}
