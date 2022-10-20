#pragma once

#include "runtime/function/render/render_pass.h"

namespace Piccolo
{
    struct ToneMappingPassInitInfo : RenderPassInitInfo
    {
        VkRenderPass render_pass;
        VkImageView  *input_attachment;
    };

    class ToneMappingPass : public RenderPass
    {
    public:
        void initialize(const RenderPassInitInfo* init_info) override final;
        void draw() override final;
        void preDraw(VkRenderPass);
        void updateAfterFramebufferRecreate();

    private:
        void setupDescriptorSetLayout();
        void setupPipelines(VkRenderPass);
        void setupDescriptorSet();

        VkImageView* input_attachment;
    };
} // namespace Piccolo
