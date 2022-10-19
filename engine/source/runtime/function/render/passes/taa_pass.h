#pragma once

#include "runtime/function/render/render_pass.h"

namespace Piccolo
{
    struct TaaPassInitInfo : RenderPassInitInfo
    {
        VkRenderPass render_pass;
        VkImageView  input_attachment; // probably dont need input attachment
    };

    class TaaPass : public RenderPass
    {
    public:
        void initialize(const RenderPassInitInfo* init_info) override final;
        void preDraw(VkImageView scene_color, VkImageView history_buffer, VkRenderPass render_pass);
        void draw() override final;

        void updateAfterFramebufferRecreate(VkImageView scene_color, VkImageView history_buffer);

    private:
        void setupDescriptorSetLayout();
        void setupPipelines(VkRenderPass render_pass);
        void setupDescriptorSet();

        VkImageView _scene_color, _history_buffer; 
        VkRenderPass _render_pass;
    };
} // namespace Piccolo
