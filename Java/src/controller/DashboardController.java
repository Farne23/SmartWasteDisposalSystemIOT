package controller;

import controller.api.ControlPanelController;
import model.WasteDisposalImpl;
import model.api.WasteDisposalModel;
import view.api.ControlPanelView;

public class DashboardController implements ControlPanelController {

    private final WasteDisposalModel model;
    private final ControlPanelView view;

    public DashboardController(String port) {
        super();
        this.model = new WasteDisposalImpl(port);
        // initialize view
        this.view = null;
    }

    @Override
    public void refresh() {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void empty() {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void repair() {
        // TODO Auto-generated method stub
        
    }

}
