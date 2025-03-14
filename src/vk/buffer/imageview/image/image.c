void vk_makeImage(uint32_t device, VkFormat vkformat, VkExtent3D vkextent3d, VkImageCreateFlags vkimagecreateflags, VkImageUsageFlags vkimageusageflags, VkImage* vkimage_ptr)
{
	VkImageCreateInfo vkimagecreateinfo =
	{
		.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
		.imageType = VK_IMAGE_TYPE_2D,
		.format = vkformat,
		.extent = vkextent3d,
		.mipLevels = 1,
		.arrayLayers = 1,
		.samples = VK_SAMPLE_COUNT_1_BIT,
		.tiling = VK_IMAGE_TILING_OPTIMAL,
		.usage = vkimageusageflags,
		.sharingMode = VK_SHARING_MODE_EXCLUSIVE,
		.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED,

		.flags = vkimagecreateflags,

		.pNext = VK_NULL_HANDLE,
		.queueFamilyIndexCount = 0,
		.pQueueFamilyIndices = VK_NULL_HANDLE
	};
	vkCreateImage(m_vkdevice_ptr[device], &vkimagecreateinfo, VK_NULL_HANDLE, vkimage_ptr);
}

void vk_genImage(uint32_t device, VkImage vkimage, VkDeviceMemory* vkdevicememory_ptr)
{
	VkDevice vkdevice = m_vkdevice_ptr[device];
	VkMemoryRequirements vkmemoryrequirements;
	vkGetImageMemoryRequirements(vkdevice, vkimage, &vkmemoryrequirements);

	VkMemoryAllocateInfo vkmemoryallocateinfo =
	{
		.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
		.allocationSize = vkmemoryrequirements.size,
		.memoryTypeIndex = vk_findMemoryType(device, vkmemoryrequirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT),
		.pNext = VK_NULL_HANDLE
	};

	vkAllocateMemory(vkdevice, &vkmemoryallocateinfo, VK_NULL_HANDLE, vkdevicememory_ptr);

	vkBindImageMemory(vkdevice, vkimage, *vkdevicememory_ptr, 0);
}

//vkCmdBlitImage vkCmdCopyImage VK_QUEUE_TRANSFER_BIT