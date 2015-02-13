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

#include "roscpp_nodewrap_tutorial/ParamClientNode.h"

NODEWRAP_EXPORT_CLASS(roscpp_nodewrap_tutorial, nodewrap::ParamClientNode)

namespace nodewrap {

/*****************************************************************************/
/* Constructors and Destructor                                               */
/*****************************************************************************/

ParamClientNode::ParamClientNode() {
}

ParamClientNode::~ParamClientNode() {
}

/*****************************************************************************/
/* Methods                                                                   */
/*****************************************************************************/

void ParamClientNode::init() {
  configClient = NodeImpl::configClient("config");
  
  xmlClient = configClient.paramClient<XmlRpc::XmlRpcValue>("xml");
  stringClient = configClient.paramClient<std::string>("string");
  doubleClient = configClient.paramClient<double>("double");
  integerClient = configClient.paramClient<int>("integer");
  booleanClient = configClient.paramClient<bool>("boolean");

  NODEWRAP_INFO("I'm sorry, did you just say you needed my brain?");
  
  NODEWRAP_INFO("Value of [xml]: %s",
    xmlClient.getParamValue<XmlRpc::XmlRpcValue>().toXml().c_str());
  NODEWRAP_INFO("Value of [string]: %s",
    stringClient.getParamValue<std::string>().c_str());
  NODEWRAP_INFO("Value of [double]: %lf",
    doubleClient.getParamValue<double>());
  NODEWRAP_INFO("Value of [integer]: %d",
    integerClient.getParamValue<int>());
  NODEWRAP_INFO("Value of [boolean]: %s",
    booleanClient.getParamValue<bool>() ? "true" : "false");
}

void ParamClientNode::cleanup() {
  NODEWRAP_INFO("So this is it. We're going to die.");
}

}
