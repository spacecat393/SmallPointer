void vk_makeSemaphore(uint32_t device, uint32_t graphic)
{
	VkSemaphoreCreateInfo vksemaphorecreateinfo =
	{
		.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO,
		.pNext = VK_NULL_HANDLE,
		.flags = 0
	};
	vkCreateSemaphore(m_vkdevice_ptr[device], &vksemaphorecreateinfo, VK_NULL_HANDLE, &m_vksemaphore_ptr[device][graphic][0]);//img
	vkCreateSemaphore(m_vkdevice_ptr[device], &vksemaphorecreateinfo, VK_NULL_HANDLE, &m_vksemaphore_ptr[device][graphic][1]);//render
}