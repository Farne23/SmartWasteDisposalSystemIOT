package controller;

import controller.api.ControlPanelController;
import model.WasteDisposalImpl;
import model.api.WasteDisposalModel;
import view.Dashboard;
import view.api.ControlPanelView;

public class DashboardController implements ControlPanelController {

    private final WasteDisposalModel model;
    private final ControlPanelView view;

    public DashboardController(String port) {
        super();
        this.model = new WasteDisposalImpl(port);
        // initialize view
        this.view = new Dashboard(() -> empty(), () -> repair());
    }

    @Override
    public void refresh() {
        var data = this.model.getStatus();
        if (data.getX().isPresent()) {
            this.view.updateLv(data.getX().get().getLevel());
        } else {
            this.view.updateTemp(data.getY().get().getTemperature(),
                    data.getY().get().getState());
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
}
