

#ifndef _GAZEBO_RESETWORLD_PLUGIN_HH_
#define _GAZEBO_RESETWORLD_PLUGIN_HH_

#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/Event.hh>
#include <stdio.h>
#include <boost/shared_ptr.hpp>

#include "reset_world_request.pb.h"
namespace gazebo
{
    class GAZEBO_VISIBLE ResetWorld : public WorldPlugin
    {

        // Pointer for custom message
        public: typedef const boost::shared_ptr<
            const reset_world_request_msgs::msgs::ResetWorldRequest>
                ResetWorldRequestPtr;

        public: virtual void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf);

        public: void OnUpdate();

        // Callback for the world update events
        //private: void OnUpdate();

        // Callback for topic subscriber
        public: void Callback(ResetWorldRequestPtr &_msg);


        // Gazebo topic name for subscriber
        private: std::string topic_name = "~/world_reset";


        // Pointer for the world
        private: physics::WorldPtr world;

        // Connection Pointer for world update events
        private: event::ConnectionPtr updateConnection;

        private: gazebo::transport::SubscriberPtr sub;
        private: gazebo::transport:: NodePtr node;












    };
}





#endif