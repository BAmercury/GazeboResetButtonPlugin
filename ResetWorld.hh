

#ifndef _GAZEBO_RESETWORLD_PLUGIN_HH_
#define _GAZEBO_RESETWORLD_PLUGIN_HH_

#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/Event.hh>
#include <stdio.h>


namespace gazebo
{
    class GAZEBO_VISIBLE ResetWorld : public WorldPlugin
    {
        // Constructor
        public: ResetWorld();


        public: virtual void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf);

        // Callback for the world update events
        //private: void OnUpdate();

        // Callback for topic subscriber
        private: void Callback(ConstWorldStatisticsPtr &_msg);

        // Gazebo topic name for subscriber
        private: std::string topic_name = "topic";


        // Pointer for the world
        private: physics::WorldPtr world;

        // Connection Pointer for world update events
        private: event::ConnectionPtr updateConnection;











    };
}





#endif