#ifndef NALI_VK_DESCRIPTORSET_POOL_H
#define NALI_VK_DESCRIPTORSET_POOL_H

void vk_makeDescriptorSetPool(uint32_t device, VkDescriptorPoolSize *vkdescriptorpoolsize_p, uint32_t vkdescriptorpoolsize_size, VkDescriptorPool *vkdescriptorpool_p);

#endif