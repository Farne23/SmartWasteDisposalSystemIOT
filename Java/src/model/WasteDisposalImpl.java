package model;

import java.util.Optional;

import model.api.WasteDisposalModel;
import model.communication.LevelInfo;
import model.communication.SerialCommChannel;
import model.communication.TempInfo;
import model.communication.api.CommChannel;
import util.Pair;

public class WasteDisposalImpl implements WasteDisposalModel {

    private final int BAUDRATE = 9600;
    private Pair<Optional<LevelInfo>, Optional<TempInfo>> lastValue;
    private Optional<CommChannel> channel;

    public WasteDisposalImpl(String port) {
        try {
            this.channel = Optional.of(new SerialCommChannel(port, BAUDRATE));
        } catch (Exception e) {
            System.out.println("Invalid port");
            this.channel = Optional.empty();
        }
        this.lastValue = new Pair<>(Optional.empty(), Optional.empty());
    }

    @Override
    public Pair<Optional<LevelInfo>, Optional<TempInfo>> getStatus() {
        if(this.channel.isPresent() && this.channel.get().isMsgAvailable()) {
            
            /*
             * the received message should be
             * a string of the format: "level" or "temperature;alarm"
             * with level in [0.0, 1.0] and alarm as 0/1.
             */
            try {
                String msg = this.channel.get().receiveMsg();
                // potrebbe tirare eccezione, si suppone che se 
                // la stringa non continene ";" non divide e basta
                String[] values = msg.split(";");
                try {
                    if (values.length == 1) {
                        double level = Double.parseDouble(values[0]);
                        // if level in [0.0, 1.0]
                        if (1.0 >= level && level >= 0.0) {
                            this.lastValue = new Pair<>(Optional.of(new LevelInfo(level)),
                                    Optional.empty());
                            return this.lastValue;
                        }
                    } else {
                        double temp = Double.parseDouble(values[0]);
                        boolean alarm = Boolean.parseBoolean(values[1]);
                        this.lastValue = new Pair<>(Optional.empty(),
                                Optional.of(new TempInfo(temp, alarm)));
                        return this.lastValue;
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
