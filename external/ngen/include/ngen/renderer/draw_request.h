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

#ifndef NGEN_DRAW_REQUEST_H
#define NGEN_DRAW_REQUEST_H


////////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <vectormath_aos.h>
#include "primitive_type.h"


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    namespace renderer {
        class Geometry;

        struct IMaterial;

        struct PrimitiveRequest {
            kPrimitiveType type;
            uint32_t count;         // Number of primitives to render
            uint32_t start;         // Start offset within vertex buffer
            uint32_t baseIndex;
        };

        struct GeometryRequest {
            Geometry *geometry;
            Vectormath::Aos::Vector3 position;
            Vectormath::Aos::Matrix3 orientation;
        };

        //! \brief  A draw request represents a block of geometry to be rendered by the framework.
        struct DrawRequest : public GeometryRequest {
            int layerId;            // TODO: obtain from material?
            IMaterial *material;
        };
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_DRAW_REQUEST_H
