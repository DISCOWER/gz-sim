/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef IGNITION_GAZEBO_COMPONENTS_MATERIAL_HH_
#define IGNITION_GAZEBO_COMPONENTS_MATERIAL_HH_

#include <ignition/msgs/material.pb.h>

#include <sdf/Material.hh>

#include <ignition/gazebo/components/Factory.hh>
#include <ignition/gazebo/components/Component.hh>
#include <ignition/gazebo/config.hh>

namespace ignition
{
namespace gazebo
{
// Inline bracket to help doxygen filtering.
inline namespace IGNITION_GAZEBO_VERSION_NAMESPACE {
namespace components
{
  /// \brief Base class which can be extended to add serialization
  using MaterialBase = Component<sdf::Material, class MaterialTag>;

  /// \brief This component holds an entity's geometry.
  class Material : public MaterialBase
  {
    // Documentation inherited
    public: Material() : MaterialBase()
    {
    }

    // Documentation inherited
    public: explicit Material(const sdf::Material &_data)
      : MaterialBase(_data)
    {
    }

    // Documentation inherited
    public: void Serialize(std::ostream &_out) const override
    {
      auto msg = convert<msgs::Material>(this->Data());
      msg.SerializeToOstream(&_out);
    }

    // Documentation inherited
    public: void Deserialize(std::istream &_in) override
    {
      msgs::Material msg;
      msg.ParseFromIstream(&_in);

      this->Data() = convert<sdf::Material>(msg);
    }
  };

  IGN_GAZEBO_REGISTER_COMPONENT(
      "ign_gazebo_components.Material", Material)
}
}
}
}

#endif
