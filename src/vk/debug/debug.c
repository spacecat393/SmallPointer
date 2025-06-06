VkDebugUtilsMessengerEXT vkd_vkdebugutilsmessengerext;

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT vkdebugutilsmessageseverityflagbitsext, VkDebugUtilsMessageTypeFlagsEXT vkdebugutilsmessagetypeflagsext, const VkDebugUtilsMessengerCallbackDataEXT *vkdebugutilsmessengercallbackdataext, void *data)
{
	NALI_D_INFO_A(">vk_debug: %s", vkdebugutilsmessengercallbackdataext->pMessage)
	return 0;
}

static VkResult createDebugUtilsMessengerEXT(VkInstance vkinstance, const VkDebugUtilsMessengerCreateInfoEXT *vkdebugutilsmessengercreateinfoext, const VkAllocationCallbacks *vkallocationcallbacks, VkDebugUtilsMessengerEXT *vkdebugutilsmessengerext)
{
	PFN_vkCreateDebugUtilsMessengerEXT pfn_vkcreatedebugutilsmessengerext = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(vkinstance, "vkCreateDebugUtilsMessengerEXT");

	if (pfn_vkcreatedebugutilsmessengerext)
	{
		return pfn_vkcreatedebugutilsmessengerext(vkinstance, vkdebugutilsmessengercreateinfoext, vkallocationcallbacks, vkdebugutilsmessengerext);
	}
	else
	{
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}

void vkd_make()
{
	NALI_D_INFO
	(
		"createDebugUtilsMessengerEXT %d",
		createDebugUtilsMessengerEXT
		(
			vkqdpdi_vkinstance,
			&(VkDebugUtilsMessengerCreateInfoEXT)
			{
				.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
				.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
				.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
				.pfnUserCallback = debugCallback,

				.flags = 0,
				.pNext = VK_NULL_HANDLE,
				.pUserData = VK_NULL_HANDLE
			},
			VK_NULL_HANDLE,
			&vkd_vkdebugutilsmessengerext
		)
	)
}

void vkd_free()
{
	PFN_vkDestroyDebugUtilsMessengerEXT pfn_vkdestroydebugutilsmessengerext = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(vkqdpdi_vkinstance, "vkDestroyDebugUtilsMessengerEXT");
	if (pfn_vkdestroydebugutilsmessengerext != NULL)
	{
		pfn_vkdestroydebugutilsmessengerext(vkqdpdi_vkinstance, vkd_vkdebugutilsmessengerext, VK_NULL_HANDLE);
	}
}