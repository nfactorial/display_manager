//
// Copyright 2016 nfactorial
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "display_port.h"
#include "gtest/gtest.h"

//! \brief  Tests the initial state of the display when first created.
TEST( DisplayPort, Construction ) {
    ngen::renderer::DisplayPort displayPort;

    ngen::renderer::CameraArgs cameraArgs;
    displayPort.getCameraArgs(cameraArgs);

    EXPECT_TRUE(displayPort.isEnabled());
    EXPECT_EQ(ngen::renderer::kCameraType::Invalid, cameraArgs.type);
    EXPECT_EQ(45.0, cameraArgs.fov);
}


//! \brief  Tests functionality of the enable/disable capability.
//!
//! TODO: Also need to verify the display port does not perform rendering when it's disabled.
TEST( DisplayPort, EnableDisable ) {
    ngen::renderer::DisplayPort displayPort;

    EXPECT_TRUE(displayPort.isEnabled());

    displayPort.setEnabled(false);
    EXPECT_FALSE(displayPort.isEnabled());

    displayPort.setEnabled(true);
    EXPECT_TRUE(displayPort.isEnabled());
}
