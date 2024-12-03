package controller;

import controller.api.ControlPanelController;
import model.WasteDisposalImpl;
import model.api.WasteDisposalModel;
import view.Dashboard;
import view.api.ControlPanelView;

public class DashboardController implements ControlPanelController {

    private final WasteDisposalModel model;
    private final ControlPanelView view;
    private final UpdateAgent agent;

    public DashboardController(String port) {
        this.model = new WasteDisposalImpl(port);
        // initialize view
        this.view = new Dashboard(() -> empty(), () -> repair());
        this.agent = new UpdateAgent();
        this.agent.start();
    }

    /**
     * EXCLUSIVELY FOR TESTING!!!
    public DashboardController() {
        this.model = null;
        this.view = new Dashboard(() -> {}, () -> {});
        this.agent = new UpdateAgent();
        this.agent.start();
    }
    */

    @Override
    public void refresh() {
        var data = this.model.getStatus();
        if (data.isPresent()) {
            this.view.update(data.get().getX(),
                    data.get().getY().getX(),
                    data.get().getY().getY());
        }
    }

    @Override
    public void empty() {
        this.model.empty();
    }

    @Override
    public void repair() {
        this.model.coolDown();
    }

    private final class UpdateAgent extends Thread {

        private static final long DELAY = 150;
        // just for testing
        // private static final Random rnd = new Random();

        public UpdateAgent() {}

        public void run() {
            while(true) {
                refresh();
                // just for testing
                // view.update(rnd.nextDouble(1.0), rnd.nextDouble(), rnd.nextInt() % 2 == 0);
                try {
                    Thread.sleep(DELAY);
                } catch (InterruptedException e) {}
            }
        }   
    }
}
