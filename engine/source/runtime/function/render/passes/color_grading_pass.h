#pragma once

#include "runtime/function/render/render_pass.h"

namespace Piccolo
{
    struct ColorGradingPassInitInfo : RenderPassInitInfo
    {
        VkRenderPass render_pass;
        VkImageView*  input_attachment;
    };

    class ColorGradingPass : public RenderPass
    {
    public:
        void initialize(const RenderPassInitInfo* init_info) override final;
        void draw() override final;
        void preDraw(VkRenderPass render_pass);
        void updateAfterFramebufferRecreate();

    private:
        void setupDescriptorSetLayout();
        void setupPipelines(VkRenderPass input_attachment);
        void setupDescriptorSet();


        VkImageView* input_attachment;
    };
} // namespace Piccolo
