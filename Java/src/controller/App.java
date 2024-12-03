package controller;


import controller.api.ControlPanelController;
import view.Dashboard;

/**
 * Entry point class
 */
public class App {
    /**
     * Entry point of the application.
     * @param args parameters by command line
     */
    public static void main(String args[]) {
        //@SuppressWarnings("unused")
        String port = "";
        ControlPanelController controller = new DashboardController(port);
    }
}
