void vk_makeQueue(uint32_t device)
{
	VkPhysicalDevice vkphysicaldevice = m_vkphysicaldevice_ptr[device];

	uint32_t queuefamilies = 0;

	vkGetPhysicalDeviceQueueFamilyProperties(vkphysicaldevice, &queuefamilies, VK_NULL_HANDLE);

	VkQueueFamilyProperties* vkqueuefamilyproperties_ptr = malloc(queuefamilies * sizeof(VkQueueFamilyProperties));

	vkGetPhysicalDeviceQueueFamilyProperties(vkphysicaldevice, &queuefamilies, vkqueuefamilyproperties_ptr);

	m_max_graphic_ptr[device] = 0;

	info("queue_families %d", queuefamilies)

	for (uint32_t i = 0; i < queuefamilies; i++)
	{
		VkQueueFamilyProperties vkqueuefamilyproperties = vkqueuefamilyproperties_ptr[i];
		if (vkqueuefamilyproperties.queueFlags & VK_QUEUE_GRAPHICS_BIT)
		{
			info("VK_QUEUE_GRAPHICS_BIT %d", i);
			m_queue_graphic = i;
		}

		VkBool32 surface_support;

		vkGetPhysicalDeviceSurfaceSupportKHR(vkphysicaldevice, i, m_vksurfacekhr, &surface_support);

		if (surface_support)
		{
			info("index/size %d", m_max_graphic_ptr[device])
			info("byte size %ld", (m_max_graphic_ptr[device] + 1) * sizeof(uint32_t))
			m_graphic_ptr[device] = realloc(m_graphic_ptr[device], (m_max_graphic_ptr[device] + 1) * sizeof(uint32_t));
			m_graphic_ptr[device][m_max_graphic_ptr[device]++] = i;
			info("new_size %d", m_max_graphic_ptr[device])
			info("surface_1 %d", i);
			m_queue_render = i;
		}
		else
		{
			info("surface_0 %d", i);
		}

		if (vkqueuefamilyproperties.queueFlags & VK_QUEUE_TRANSFER_BIT)
		{
			info("VK_QUEUE_TRANSFER_BIT %d", i);
		}

		VkFormatProperties vkformatproperties;
		vkGetPhysicalDeviceFormatProperties(vkphysicaldevice, VK_FORMAT_R8G8B8A8_UNORM, &vkformatproperties);
		if (vkformatproperties.optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_SRC_BIT)
		{
			info("VK_FORMAT_FEATURE_BLIT_SRC_BIT %d", i)
		}
		if (vkformatproperties.optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_DST_BIT)
		{
			info("VK_FORMAT_FEATURE_BLIT_DST_BIT %d", i)
		}
	}

	info("queuelist_max_graphics %d", m_max_graphic_ptr[device])

	free(vkqueuefamilyproperties_ptr);
}
