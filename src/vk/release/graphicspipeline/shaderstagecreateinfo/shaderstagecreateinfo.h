#ifndef NALI_VK_GRAPHICSPIPELINE_SHADERSTAGECREATEINFO_H
#define NALI_VK_GRAPHICSPIPELINE_SHADERSTAGECREATEINFO_H

void vk_setVkPipelineShaderStageCreateInfo(uint32_t device, uint32_t vert, uint32_t frag, VkPipelineShaderStageCreateFlags vkpipelineshaderstagecreateflags_vert, VkPipelineShaderStageCreateFlags vkpipelineshaderstagecreateflags_frag, VkShaderModule *vkshadermodule_vert_p, VkShaderModule *vkshadermodule_frag_p, VkPipelineShaderStageCreateInfo *vkpipelineshaderstagecreateinfo_p);

#endif