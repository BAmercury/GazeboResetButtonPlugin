

#include <sstream>
#include <gazebo/msgs/msgs.hh>
#include "GUI_ResetWorld.hh"
#include <gazebo/transport/transport.hh>

#include "reset_world_request.pb.h"
#include "gz_string.pb.h"

using namespace gazebo;

GZ_REGISTER_GUI_PLUGIN(GUI_ResetWorld)


GUI_ResetWorld::GUI_ResetWorld() : GUIPlugin()
{
    // Set the frame background and foreground colours
    this->setStyleSheet(
        "QFrame { background-color : rgba(100, 100, 100, 255); color : white; }"
    );

    // Create main layout
    QHBoxLayout *mainLayout = new QHBoxLayout;

    // Create frame to hold all widgets
    QFrame *mainFrame = new QFrame();

    // Create the layout that sits inside the frame
    QVBoxLayout *frameLayout = new QVBoxLayout();

    // Create a push button, connect it with the OnButton function
    QPushButton *button = new QPushButton(tr("Reset World"));
    connect(button, SIGNAL(clicked()), this, SLOT(OnButton()));

    // Add the button to the frame layout
    frameLayout->addWidget(button);

    // Add frameLayout to the frame
    mainFrame->setLayout(frameLayout);

    // Add the frame to the main layout
    mainLayout->addWidget(mainFrame);

    // remove margins to reduce space
    frameLayout->setContentsMargins(0,0,0,0);
    mainLayout->setContentsMargins(0,0,0,0);

    this->setLayout(mainLayout);

    // Position and rsize this widgets
    this->move(10,10);
    this->resize(120, 30);

    // Create node for transportation
    this->node = gazebo::transport::NodePtr(new gazebo::transport::Node());
    this->node->Init();
    this->flagPub = this->node->Advertise<reset_world_request_msgs::msgs::ResetWorldRequest>("~/world_reset");
    gzdbg << "Advertising World Reset Button" << std::endl;


}


// Callback function for button
void GUI_ResetWorld::OnButton()
{
    //this->flagPub->WaitForConnection();
    reset_world_request_msgs::msgs::ResetWorldRequest msg_request;
    msg_request.set_data("Reset");
    this->flagPub->Publish(msg_request);
    gzdbg << "Message Sent" << std::endl;
    //gazebo::transport::fini();

}

