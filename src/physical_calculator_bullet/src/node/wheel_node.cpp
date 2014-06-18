#include "wheel_node.hpp"


#include <phy_api/torque.h>
#include <phy_api/rotation.h>

WheelNode::WheelNode(Wheel* wheel)
    : _wheel(wheel), _node(wheel->getName()) {

    _set_torque_service =
            _node.advertiseService("set_torque", &WheelNode::setTorqueService, this);

    _torque_publisher = _node.advertise<phy_api::torque>("torque", 1000);
    _rotation_publisher = _node.advertise<phy_api::rotation>("rotation", 1000);

    _timer = _node.createTimer(ros::Duration(1.0), &WheelNode::onTimerTick, this);
}

bool WheelNode::setTorqueService(phy_api::set_torque::Request& req, phy_api::set_torque::Response&  res) {
    _wheel->setTorque(req.value);
    return true;
}

void WheelNode::onTimerTick(const ros::TimerEvent& evt) {
    phy_api::torque torque;
    torque.value = _wheel->getTorque();
    _torque_publisher.publish(torque);

    phy_api::rotation rot;
    rot.value = _wheel->getRotation();
    _rotation_publisher.publish(rot);
}
