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

#ifndef NGEN_LAYER_DESC_H
#define NGEN_LAYER_DESC_H


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    struct GeneratorDesc {
        const char *name;
    };


    //! \brief  Describes a single render layer within a render pipeline.
    struct LayerDesc {
        const char *name;
        size_t generatorCount;
        GeneratorDesc *generators;
    };
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_LAYER_DESC_H
