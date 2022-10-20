#pragma once

#include "runtime/function/render/render_pass.h"

namespace Piccolo
{
    struct CombineUIPassInitInfo : RenderPassInitInfo
    {
        VkRenderPass render_pass;
        VkImageView*  scene_input_attachment;
        VkImageView*  ui_input_attachment;
    };

    class CombineUIPass : public RenderPass
    {
    public:
        void initialize(const RenderPassInitInfo* init_info) override final;
        void draw() override final;
        void preDraw(VkRenderPass render_pass);
        void updateAfterFramebufferRecreate();

    private:
        void setupDescriptorSetLayout();
        void setupPipelines(VkRenderPass render_pass);
        void setupDescriptorSet();

        VkImageView* scene_input_attachment;
        VkImageView* ui_input_attachment;
    };
} // namespace Piccolo
