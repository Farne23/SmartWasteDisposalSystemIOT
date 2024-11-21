package model.api;

import java.util.Optional;

import util.Pair;

/**
 * This interfce represents the waste container system, it doesn't refer
 * to its hw components, only displays the logic operation available for 
 * the operators to the container.
 */
public interface WasteDisposalModel {
    /**
     * Gets the current status of the container.
     * @return composed by the filling percentage (double from 0.0 to 1.0)
     * a flag that expresses if the container is in alarm state (false) or
     * not (true);
     */
    public Optional<Pair<Double, Pair<Double, Boolean>>> getStatus();
    /**
     * The container gets emptied.
     */
    public void empty();
    /**
     * The alarm state gets resolved.
     */
    public void coolDown();
}
