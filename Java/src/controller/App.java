package controller;


import controller.api.ControlPanelController;

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
        ControlPanelController controller = new DashboardController("COM3");
    }
}
