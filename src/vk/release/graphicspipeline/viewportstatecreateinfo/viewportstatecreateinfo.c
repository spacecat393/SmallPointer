void vk_setPipelineViewportStateCreateInfo(uint32_t device, VkPipelineViewportStateCreateInfo *vkpipelineviewportstatecreateinfo_p)
{
	VkViewport vkviewport =
	{
		.x = 0,
		.y = 0,
		.width = m_vkextent2d.width,
		.height = m_vkextent2d.height,
		.minDepth = 0.0F,
		.maxDepth = 1.0F
	};
	VkRect2D vkrect2d =
	{
		.offset = {0, 0},
		.extent = m_vkextent2d
	};
	*vkpipelineviewportstatecreateinfo_p = (VkPipelineViewportStateCreateInfo)
	{
		.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
		.viewportCount = 1,
		.pViewports = &vkviewport,
		.scissorCount = 1,
		.pScissors = &vkrect2d,
		.flags = 0,
		.pNext = VK_NULL_HANDLE
	};
}