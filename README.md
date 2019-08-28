# GazeboResetButtonPlugin


Plugins for a reset button for the Gazebo GUI Client with a backend that resets the simulation

Contents:
    - GUI_ResetWorld.cc/.hh : GUI Button plugin that publishes out a request to reset the simulation
    - ResetWorld.cc/.hh : Subscriber plugin that pauses and resets the simulation. User has to manually unpause the simulation via the Gazebo GUI to begin the simulation again
