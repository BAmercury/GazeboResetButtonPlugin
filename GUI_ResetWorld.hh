

#ifndef GAZEBO_PLUGINS_GUI_RESETWORLD_HH_
#define GAZEBO_PLUGINS_GUI_RESETWORLD_HH_


#include <gazebo/common/Plugin.hh>
#include <gazebo/gui/GuiPlugin.hh>
#include <gazebo/transport/transport.hh>
//#include <gazebo/gui/gui.hh>
#include <gazebo/physics/physics.hh>


namespace gazebo
{
    class GAZEBO_VISIBLE GUI_ResetWorld : public GUIPlugin
    {
        Q_OBJECT


        // Constructor/Deconstructor
        public: GUI_ResetWorld();

        //public: virtual ~GUI_ResetWorld();

        // Callback triggered when the button is pressed
        protected slots: void OnButton();

        // Node used to establish communication with gzserver
        private: gazebo::transport::NodePtr node;

        // Publisher of factory messages
        private: gazebo::transport::PublisherPtr flagPub;

        // Pointer for the world
        //private: physics::WorldPtr _world;



    };
}

#endif