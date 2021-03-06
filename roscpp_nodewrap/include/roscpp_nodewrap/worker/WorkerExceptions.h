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

/** \file WorkerExceptions.h
  * \brief Header file defining exceptions for the node worker
  */

#ifndef ROSCPP_NODEWRAP_WORKER_EXCEPTIONS_H
#define ROSCPP_NODEWRAP_WORKER_EXCEPTIONS_H

#include <string>

#include <ros/exception.h>

namespace nodewrap {
  /** \brief Exception thrown in case of an invalid worker name
    */
  class InvalidWorkerNameException :
    public ros::Exception {
  public:
    InvalidWorkerNameException(const std::string& name, const std::string&
      reason);
  };
};

#endif
