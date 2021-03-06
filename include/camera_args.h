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

#ifndef NGEN_CAMERA_ARGS_H_H
#define NGEN_CAMERA_ARGS_H_H


////////////////////////////////////////////////////////////////////////////

#include <vectormath_aos.h>
#include <ngen/renderer/camera_type.h>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    namespace renderer {
        struct CameraArgs {
            kCameraType type;
            float fov;                  // Field of view (for perspective cameras)
            float zNear;
            float zFar;
            Vectormath::Aos::Vector3 position;
            Vectormath::Aos::Quat orientation;
        };
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_CAMERA_ARGS_H_H
