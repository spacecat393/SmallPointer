#ifndef NALI_VK_DESCRIPTORSET_H
#define NALI_VK_DESCRIPTORSET_H

void vkds_make(uint32_t device, VkDescriptorPool vkdescriptorpool, VkDescriptorSetLayout *vkdescriptorsetlayout_p, uint32_t vkdescriptorsetlayout_size, VkDescriptorSet *vkdescriptorset_p);
void vkds_setVkWriteDescriptorSet(uint32_t device, uint32_t bind, VkDescriptorImageInfo *vkdescriptorimageinfo_p, VkDescriptorBufferInfo *vkdescriptorbufferinfo_p, VkDescriptorType vkdescriptortype, VkDescriptorSet vkdescriptorset, VkWriteDescriptorSet *vkwritedescriptorset_p);

#endif