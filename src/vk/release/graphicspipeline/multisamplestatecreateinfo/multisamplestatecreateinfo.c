void vk_setPipelineMultisampleStateCreateInfo(VkPipelineMultisampleStateCreateInfo *vkpipelinemultisamplestatecreateinfo_p)
{
	*vkpipelinemultisamplestatecreateinfo_p = (VkPipelineMultisampleStateCreateInfo)
	{
		.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,

		.sampleShadingEnable = NALI_VK_SAMPLE_S,
		.rasterizationSamples = NALI_VK_SAMPLE_C,

		.minSampleShading = NALI_VK_SAMPLE_V,
		.pSampleMask = VK_NULL_HANDLE,
		.alphaToCoverageEnable = VK_FALSE,
		.alphaToOneEnable = VK_FALSE,

		.flags = 0,
		.pNext = VK_NULL_HANDLE
	};
}