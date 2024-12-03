package model;

import java.util.Optional;

import model.api.WasteDisposalModel;
import model.communication.SerialCommChannel;
import model.communication.api.CommChannel;
import util.Pair;

public class WasteDisposalImpl implements WasteDisposalModel {

    private final int BAUDRATE = 9600,
            NVALUES = 3;
    private Optional<Pair<Double, Pair<Double, Boolean>>> lastValue;
    private Optional<CommChannel> channel;
    private boolean sendOn = false;
    private final SendAgent agent = new SendAgent();

    public WasteDisposalImpl(String port) {
        try {
            this.channel = Optional.of(new SerialCommChannel(port, BAUDRATE));
        } catch (Exception e) {
            e.printStackTrace();
            this.channel = Optional.empty();
        }
        this.lastValue = Optional.empty();
    }

    @Override
    public Optional<Pair<Double, Pair<Double, Boolean>>> getStatus() {
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
                if (msg.equals("OK")) {
                    this.sendOn = false;
                }
                try {
                    if (values.length == NVALUES) {
                        double level = Double.parseDouble(values[0]),
                                temp = Double.parseDouble(values[1]);
                        boolean alarm = Integer.parseInt(values[2]) == 1;
                        if (level <= 100 && level >= 0) {
                            /*
                            System.out.println("{\nLevel: " + level + "  (sent : " + values[0] + ")\n"
                                    + "Temp: " + temp + "  (sent : " + values[1] + ")\n"
                                    + "Alarm: " + alarm + "  (sent : " + values[2] + ")\n"
                                    + "}");
                            */
                            // /100 beacuse level is showed as a percentage from 0.0 to 1.0
                            this.lastValue = Optional.of(new Pair<>(level, new Pair<>(temp, alarm)));
                            return this.lastValue;
                        }
                    }
                    throw new NumberFormatException();
                } catch (NumberFormatException e) {
                    System.out.println("Invalid message format " + msg);
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
            this.agent.setMsg("L");
            this.agent.start();
        }
    }

    @Override
    public void coolDown() {
        if (this.channel.isPresent()) {
            /*
             * the message format "A" ends the
             * alarm state.
             */
            this.agent.setMsg("T");
            this.agent.start();
        }
    }

    private final class SendAgent extends Thread {
        private String msg;

        public void setMsg(String newMsg) {
            this.msg = newMsg;
        }

        @Override
        public void run() {
            sendOn = true;
            while (sendOn) {
                channel.get().sendMsg(this.msg);
            }
        }
    }
}
