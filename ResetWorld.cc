


#include <gazebo/common/Events.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo.hh>
#include "ResetWorld.hh"

using namespace gazebo;

GZ_REGISTER_WORLD_PLUGIN(ResetWorld)


ResetWorld::ResetWorld()
{

}


void ResetWorld::Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
{
    this->world = _world;

    // Create node for communication
    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    node->Init();

    // Listen to Gazebo reset world topic
    gazebo::transport::SubscriberPtr sub = node->Subscribe(this->topic_name, this->Callback);


    // Busy wait loop
    while (true)
        gazebo::common::Time::MSleep(10);
    //this->updateConnection = event::Events::ConnectWorldUpdateBegin(
    //    std::bind(&ResetWorld::OnUpdate, this));
}


void ResetWorld::Callback(ConstWorldStatisticsPtr &_msg)
{
    gzdbg << _msg->DebugString() << std::endl;

}