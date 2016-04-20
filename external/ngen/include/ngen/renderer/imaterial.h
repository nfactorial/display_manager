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

#ifndef NGEN_DISPLAY_MANAGER_IMATERIAL_H
#define NGEN_DISPLAY_MANAGER_IMATERIAL_H


////////////////////////////////////////////////////////////////////////////

#include <cstddef>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    namespace renderer {
        struct RenderArgs;
        struct GeometryRequest;

        //! \brief  Interface definition for a material.
        //!
        //! Materials define the rendering process for a surface in the scene.
        //! When a material is being rendered the framework will first invoke onBeginRendering allowing
        //! the material to prepare the device for use.
        //! The execute method is then invoked, this method is supplied a pointer to a list of geometry requests
        //! along with a counter containing the number of requests in the list. The material should perform
        //! any processing necessary to output the supplied geometry to the display.
        //! Once the framework has finished with the material for the frame, it will then invoke the
        //! onEndRendering method to allow the material to perform any cleanup if necessary.
        struct IMaterial {
            virtual void onEndRendering(const RenderArgs &renderArgs) = 0;
            virtual void onBeginRendering(const RenderArgs &renderArgs) = 0;

            virtual void execute(const RenderArgs &renderArgs, GeometryRequest *requests, size_t count) = 0;
        };
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_DISPLAY_MANAGER_IMATERIAL_H
