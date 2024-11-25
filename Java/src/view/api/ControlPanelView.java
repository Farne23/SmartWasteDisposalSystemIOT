package view.api;

/**
 * This interface represents the dashboard view for the
 * waste disposal available for the operators.
 */
public interface ControlPanelView {
    /**
     * Updates the view with new information about the system.
     * @param level level of the waste in percentage.
     * @param temp current temperature of the container.
     * @param alarmOn flag for the alarm state.
     */
    public void update(double level, double temp, boolean alarmOn);
}
