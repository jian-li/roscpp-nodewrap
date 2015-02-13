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

namespace nodewrap {

/*****************************************************************************/
/* Methods                                                                   */
/*****************************************************************************/

template <typename P> ParamClient ConfigClient::paramClient(const std::string&
    key, bool persistent, ros::Duration timeout) {
  ParamClientOptions options;
  options.template init<P>(std::string(), persistent);
  
  return this->paramClient(key, options, timeout);
}

template <typename P> ParamClient ConfigClient::Impl::paramClient(const
    std::string& key, bool persistent) {
  ParamClientOptions options;
  options.template init<P>(std::string(), persistent);
  
  return this->paramClient(key, options);
}

}
