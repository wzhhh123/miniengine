#pragma once

#include "runtime/function/render/render_pass.h"

namespace Piccolo
{
    class WindowUI;

    struct FXAAPassInitInfo : RenderPassInitInfo
    {
        VkRenderPass render_pass;
        VkImageView*  input_attachment;
    };

    class FXAAPass : public RenderPass
    {
    public:
        void initialize(const RenderPassInitInfo* init_info) override final;
        void draw() override final;

        void preDraw(VkRenderPass );

        void updateAfterFramebufferRecreate();

    private:
        void setupDescriptorSetLayout();
        void setupPipelines(VkRenderPass render_pass);
        void setupDescriptorSet();

        VkImageView* input_attachment;

    };
} // namespace Piccolo
