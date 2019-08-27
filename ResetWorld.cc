


#include <gazebo/common/Events.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo.hh>
#include "ResetWorld.hh"

#include "reset_world_request.pb.h"

using namespace gazebo;

GZ_REGISTER_WORLD_PLUGIN(ResetWorld)


// ResetWorld::ResetWorld()
// {

// }
void ResetWorld::Callback(ResetWorldRequestPtr &_msg)
{

    if (_msg->DebugString() == "Hello World")
    {
        gzdbg << "Hi" << std::endl;
    }

}

void ResetWorld::Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
{
    this->world = _world;

    // Create node for communication
    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    node->Init();

    // Listen to Gazebo reset world topic
    gazebo::transport::SubscriberPtr sub = node->Subscribe(this->topic_name, Callback);


    // Busy wait loop
    while (true)
        gazebo::common::Time::MSleep(10);
    //this->updateConnection = event::Events::ConnectWorldUpdateBegin(
    //    std::bind(&ResetWorld::OnUpdate, this));
}


