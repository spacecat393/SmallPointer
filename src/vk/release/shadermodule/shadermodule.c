void vk_makeShaderModule(uint32_t device, uint32_t *uint32_t_p, size_t size, VkShaderModule *vkshadermodule_p)
{
	VkShaderModuleCreateInfo vkshadermodulecreateinfo =
	{
		.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
		.pCode = uint32_t_p,
		.codeSize = size,

		.flags = 0,
		.pNext = VK_NULL_HANDLE
	};
	vkCreateShaderModule(m_vkdevice_p[device], &vkshadermodulecreateinfo, VK_NULL_HANDLE, vkshadermodule_p);
}