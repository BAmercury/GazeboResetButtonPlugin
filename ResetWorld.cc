


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

    if (_msg->data() == "Reset")
    {
        gzdbg << "World Paused" << std::endl;
        this->world->SetPaused(true);
        gzdbg << "Resetting Physics States" << std::endl;
        this->world->ResetPhysicsStates();
        this->world->Reset();
        gzdbg << "Resetting World" << std::endl;
    }

}

void ResetWorld::Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
{
    this->world = _world;

    // Create node for communication
    this->node = gazebo::transport::NodePtr(new gazebo::transport::Node());
    this->node->Init();

    // Listen to Gazebo reset world topic
    this->sub = this->node->Subscribe(this->topic_name, &ResetWorld::Callback, this);

    // Use this to keep thread alive?
    this->updateConnection = event::Events::ConnectWorldUpdateBegin(std::bind(&ResetWorld::OnUpdate, this));

}

void ResetWorld::OnUpdate()
{
    //Process callbacks
    this->node->ProcessIncoming();

    
}

