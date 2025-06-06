#ifndef NALI_VK_FRAMEBUFFER_H
#define NALI_VK_FRAMEBUFFER_H

#define VK_makeFramebuffer(device, vkimageview_p, vkimageview_size, vkrenderpass, vkframebuffer_p) \
	NALI_D_INFO \
	( \
		"vkCreateFramebuffer %d", \
		vkCreateFramebuffer \
		( \
			vkqd_vkdevice_p[device], \
			&(VkFramebufferCreateInfo) \
			{ \
				.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO, \
				.renderPass = vkrenderpass, \
				.attachmentCount = vkimageview_size, \
				.pAttachments = vkimageview_p, \
				.width = vksc_vkextent2d.width, \
				.height = vksc_vkextent2d.height, \
				.layers = 1, \
				.flags = 0, \
				.pNext = VK_NULL_HANDLE \
			}, \
			VK_NULL_HANDLE, \
			vkframebuffer_p \
		) \
	)

#endif