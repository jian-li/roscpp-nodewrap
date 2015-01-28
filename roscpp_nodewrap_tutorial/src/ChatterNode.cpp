/******************************************************************************
 * Copyright (C) 2014 by Ralf Kaestner                                        *
 * ralf.kaestner@gmail.com                                                    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include "roscpp_nodewrap_tutorial/ChatterNode.h"

NODEWRAP_EXPORT_CLASS(roscpp_nodewrap_tutorial, nodewrap::ChatterNode)

namespace nodewrap {

/*****************************************************************************/
/* Constructors and Destructor                                               */
/*****************************************************************************/

ChatterNode::ChatterNode() {
}

ChatterNode::~ChatterNode() {
}

/*****************************************************************************/
/* Methods                                                                   */
/*****************************************************************************/

void ChatterNode::init() {
  publisher = advertise<std_msgs::String>("chat", "/chat", 100,
    boost::bind(&ChatterNode::connect, this, _1));
  NODEWRAP_INFO("Publishing to: %s", publisher.getTopic().c_str());
  subscriber = subscribe("chat", "/chat", 100, &ChatterNode::chat);
  NODEWRAP_INFO("Subscribed to: %s", subscriber.getTopic().c_str());
  server = advertiseService("call", "/call", &ChatterNode::call);
  
  name = getParam("chat/name", name);
  initiate = getParam("chat/initiate", false);
  say = getParam("chat/say", say);
  
  NODEWRAP_INFO("Hello, my name is %s!", name.c_str());
  
//   NODEWRAP_INFO_STREAM("ChatterNode::init() " << __LINE__);
  
//   bool trigger = false;
//   getNodeHandle().setParam("trigger", trigger);
//   getNodeHandle().getParamCached("trigger", trigger);
  // This is problematic as it prevents cache parameters to be updated!!!
//   ros::XMLRPCManager::instance()->unbind("paramUpdate");
//   ros::XMLRPCManager::instance()->bind("paramUpdate",
//     boost::bind(&ChatterNode::paramUpdate, this, _1, _2));
  
//   NODEWRAP_INFO_STREAM("ChatterNode::init() " << __LINE__);  
  
  advertiseParam("chat/name", name, false);
  advertiseParam("chat/initiate", initiate);
  advertiseParam("chat/say", say, &ChatterNode::sayUpdate);
}

void ChatterNode::cleanup() {
  NODEWRAP_INFO("Good bye from %s!", name.c_str());
}

void ChatterNode::connect(const ros::SingleSubscriberPublisher& pub) {
  if (initiate) {
    while (!publisher)
      ros::Duration(0.1).sleep();
    
    std_msgs::StringPtr msg(new std_msgs::String);
    msg->data = say;
    
    publisher.publish(msg);
    NODEWRAP_DEBUG("I said: [%s]", msg->data.c_str());
  }
}

void ChatterNode::chat(const std_msgs::String::ConstPtr& msg) {
  NODEWRAP_DEBUG("I heard: [%s]", msg->data.c_str());
  
  std_msgs::StringPtr reply(new std_msgs::String);
  reply->data = say;
  
  publisher.publish(reply);
  NODEWRAP_DEBUG("I said: [%s]", reply->data.c_str());
}

bool ChatterNode::call(std_srvs::Empty::Request& request,
    std_srvs::Empty::Response& response) {
  NODEWRAP_DEBUG("I have been called");
  return true;
}

// void ChatterNode::paramUpdate(XmlRpc::XmlRpcValue& params,
//     XmlRpc::XmlRpcValue& result) {
//   NODEWRAP_INFO_STREAM("ChatterNode::paramUpdate() " << __LINE__);
  
//   result[0] = 1;
//   result[1] = std::string("");
//   result[2] = 0;
// 
//   ros::param::update((std::string)params[1], params[2]);
  
//   bool trigger = getNodeHandle().getParam("trigger", trigger);
//   NODEWRAP_INFO_STREAM("params[2] = " << params[2] << " trigger = " << trigger);
// }

void ChatterNode::sayUpdate(const std::string& say) {
  this->say = say;
}

}
