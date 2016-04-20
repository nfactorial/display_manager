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

#include <ngen/renderer/imaterial.h>
#include <ngen/renderer/render_args.h>

#include "gtest/gtest.h"
#include "request_provider.h"

//! \brief Simple class to mock a material implementation, allows us to verify the system is calling the appropriate methods.
struct MockMaterial : public ngen::renderer::IMaterial {
    size_t m_endRendering;
    size_t m_beginRendering;

    MockMaterial() : m_endRendering(0), m_beginRendering(0) {}

    void reset() { m_endRendering = 0; m_beginRendering = 0; }

    void onEndRendering(const ngen::renderer::RenderArgs &renderArgs) { m_endRendering++; }
    void onBeginRendering(const ngen::renderer::RenderArgs &renderArgs) { m_beginRendering++; }

    void execute(const ngen::renderer::RenderArgs &renderArgs, ngen::renderer::GeometryRequest *requests, size_t count) {}
};

//! \brief  Ensure the request provider begins life as we expect.
TEST(RequestProvider, Construction) {
    ngen::renderer::RequestProvider provider;

    EXPECT_EQ(0, provider.getMaterialCapacity());
    EXPECT_EQ(0, provider.getMaterialAllocations());

    EXPECT_EQ(0, provider.getPageCount());
    EXPECT_EQ(0, provider.getPageCapacity());

    EXPECT_EQ(nullptr, provider.allocateRequestPage());
}

//! \brief  Ensure the initialize methods responds in the correct manner.
TEST(RequestProvider, Initialize) {
    const size_t kMaterials = 16;
    const size_t kPages = 16;

    ngen::renderer::RequestProvider provider;

    EXPECT_FALSE(provider.initialize(0, 0));
    EXPECT_FALSE(provider.initialize(kMaterials, 0));
    EXPECT_FALSE(provider.initialize(0, kPages));
    EXPECT_TRUE(provider.initialize(kMaterials, kPages));
    EXPECT_FALSE(provider.initialize(kMaterials, kPages));
}

//! \brief  Verify we can allocate material requests correctly
TEST(RequestProvider, MaterialRequests) {
    const size_t kMaterials = 16;
    const size_t kPages = 16;

    ngen::renderer::RequestProvider provider;

    EXPECT_FALSE(provider.allocateMaterialRequest(nullptr));
    //EXPECT_FALSE(provider.allocateMaterialRequest(&mockMaterial));

    EXPECT_TRUE(provider.initialize(kMaterials, kPages));

    EXPECT_FALSE(provider.allocateMaterialRequest(nullptr));
}

//! \brief  Verify the allocation of draw request pages behaves as expected.
TEST(RequestProvider, RequestPage) {
    const size_t kMaterials = 16;
    const size_t kPages = 16;

    ngen::renderer::RequestProvider provider;

    EXPECT_EQ(nullptr, provider.allocateRequestPage());

    EXPECT_TRUE(provider.initialize(kMaterials, kPages));

    for (size_t loop = 0; loop < kPages; ++loop ) {
        EXPECT_NE(nullptr, provider.allocateRequestPage());
    }

    EXPECT_EQ(nullptr, provider.allocateRequestPage());

    provider.reset();

    for (size_t loop = 0; loop < kPages; ++loop ) {
        EXPECT_NE(nullptr, provider.allocateRequestPage());
    }

    EXPECT_EQ(nullptr, provider.allocateRequestPage());
}
