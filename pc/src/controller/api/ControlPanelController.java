package controller.api;

/**
 * This interface represents the controller of the
 * control panel available for the operators to
 * operate on the system.
 */
public interface ControlPanelController {
    /**
     * Gets infos from the model and renders
     * them through the view.
     */
    public void refresh();
    /**
     * Empties the container, setting the
     * waste level back to 0.
     */
    public void empty();
    /**
     * Repairs the system, ending the alarm state.
     */
    public void repair();
}
