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

#ifndef NGEN_DISPLAY_PORT_H
#define NGEN_DISPLAY_PORT_H


////////////////////////////////////////////////////////////////////////////

#include <ngen/renderer/render_args.h>
#include "display_pipeline.h"
#include "camera_args.h"


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    namespace renderer {
        class RequestProvider;

        //! \brief  Represents a view into the world.
        class DisplayPort {
        public:
            DisplayPort();
            ~DisplayPort();

            // Internal methods
            bool initialize(RequestProvider &requestProvider);

            void onRender();

            // IDisplayPort methods
            void dispose();

            void getCameraArgs(ngen::renderer::CameraArgs &cameraArgs);

            bool isEnabled() const;

            void setEnabled(bool isEnabled);

        private:
            void prepareRenderArgs(const ngen::renderer::CameraArgs &cameraArgs, float aspectRatio);

        private:
            RequestProvider *m_requestProvider;

            bool m_isEnabled;
            DisplayPipeline m_pipeline;

            ngen::renderer::CameraArgs m_cameraArgs;
            ngen::renderer::RenderArgs m_renderArgs;
        };


        ////////////////////////////////////////////////////////////////////////////

        //! \brief  Determines whether or not the display port is currently enabled.
        //! \return <em>True</em> if the display port is enabled otherwise <em>false</em>.
        inline bool DisplayPort::isEnabled() const {
            return m_isEnabled;
        }
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_DISPLAY_PORT_H
