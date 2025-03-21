void vk_makeCommandPool(uint32_t device, VkCommandPoolCreateFlags vkcommandpoolcreateflags, uint32_t graphic)
{
	VkCommandPoolCreateInfo vkcommandpoolcreateinfo =
	{
		.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
		.queueFamilyIndex = m_graphic_p[device][graphic],
		.flags = vkcommandpoolcreateflags,
		.pNext = VK_NULL_HANDLE
	};
	vkCreateCommandPool(m_vkdevice_p[device], &vkcommandpoolcreateinfo, VK_NULL_HANDLE, &m_vkcommandpool_p[device][graphic]);
}
