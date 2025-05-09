// mtx_t *m_mtx_t_draw_p = &(mtx_t){};

// static clock_t frame_start, frame_end;
// static uint32_t frame;
// static clock_t frame_time;

// //s0-share
// static VkDevice vkdevice;
// static VkQueue vkqueue_graphic;
// //e0-share

// //s0-d
// static VkDescriptorPoolSize vkdescriptorpoolsize_array[2];
// static VkDescriptorPool vkdescriptorpool;
// static VkDescriptorSetLayout vkdescriptorsetlayout;
// static VkDescriptorSet vkdescriptorset;
// //e0-d

// //s0-s
// static VkPipelineLayout vkpipelinelayout;
// static VkPipeline vkpipeline;
// //e0-s

// //s0-cmd
// static VkCommandBufferBeginInfo vkcommandbufferbegininfo =
// {
// 	.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
// 	.pInheritanceInfo = VK_NULL_HANDLE,

// 	.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,
// 	.pNext = VK_NULL_HANDLE
// };

// static VkCommandBuffer vkcommandbuffer;
// //e0-cmd

// //s0-ubo
// static VkWriteDescriptorSet vkwritedescriptorset_array[2];
// static VkDescriptorBufferInfo vkdescriptorbufferinfo;
// static VkDescriptorImageInfo vkdescriptorimageinfo;
// //e0-ubo

// //s0-draw
// static VkClearValue vkclearvalue_array[2] =
// {
// 	{.color = {.float32 = {0.0F, 0.0F, 0.0F, 1.0F}}},
// 	{.depthStencil =
// 		{
// 			.depth = 1.0F,
// 			.stencil = 0.0F
// 		}
// 	}
// };
// static VkRenderPassBeginInfo vkrenderpassbegininfo =
// {
// 	.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
// 	.renderArea.offset = {0, 0},
// 	.clearValueCount = 2,
// 	.pClearValues = vkclearvalue_array,

// 	.pNext = VK_NULL_HANDLE
// };
// static VkViewport vkviewport =
// {
// 	.x = 0.0F,
// 	.y = 0.0F,
// 	.minDepth = 0.0F,
// 	.maxDepth = 1.0F
// };
// static VkRect2D vkrect2d =
// {
// 	.offset = {0, 0}
// };
// //s1-queue

// //graphic
// static VkFence vkfence;
// //image render
// static VkSemaphore vksemaphore_array[2];

// static VkSubmitInfo image_vksubmitinfo =
// {
// 	.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
// 	.waitSemaphoreCount = 1,
// 	.pWaitDstStageMask = (VkPipelineStageFlags[]){VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT},
// 	.commandBufferCount = 1,
// 	.pCommandBuffers = &vkcommandbuffer,
// 	.signalSemaphoreCount = 1,

// 	.pNext = VK_NULL_HANDLE
// };
// static VkPresentInfoKHR vkpresentinfokhr =
// {
// 	.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
// 	.waitSemaphoreCount = 1,

// 	.swapchainCount = 1,
// 	.pSwapchains = &m_vkswapchainkhr,

// 	.pResults = VK_NULL_HANDLE,
// 	.pNext = VK_NULL_HANDLE
// };
// //e1-queue
// //e0-draw

// void vk_initCmdDraw()
// {
// 	//s0-share
// 	vkdevice = m_vkdevice_p[m_device];
// 	vkqueue_graphic = m_vkqueue_p[m_device][m_queue_g];
// 	//e0-share

// 	//s0-d
// 	lc_setVkDescriptorPoolSize(vkdescriptorpoolsize_array);
// 	vk_makeDescriptorSetPool(m_device, vkdescriptorpoolsize_array, 2, &vkdescriptorpool);
// 	lc_setVkDescriptorSetLayout(&vkdescriptorsetlayout);
// 	vk_makeDescriptorSet(m_device, vkdescriptorpool, &vkdescriptorsetlayout, 1, &vkdescriptorset);
// 	//e0-d

// 	//s0-s
// 	VkShaderModule vkshadermodule_vert;
// 	VkShaderModule vkshadermodule_frag;
// 	VkPipelineShaderStageCreateInfo vkpipelineshaderstagecreateinfo_array[2];

// 	// const char shader_type[] = ".spv";

// 	// const char vert_shader_path[] = NALI_HOME NALI_HOME_SHADER NALI_HOME_SHADER_VERT "/";
// 	// uint32_t vert_index = 0;
// 	// uint8_t vert_name_index = sizeof(vert_shader_path)-1;
// 	// char *vert_file = malloc(vert_name_index + MATH_LENGTH(vert_index) + sizeof(shader_type)-1 + 1);
// 	// strcpy(vert_file, vert_shader_path);
// 	// sprintf(vert_file + vert_name_index, "%u", vert_index);
// 	// strcat(vert_file, shader_type);

// 	// const char frag_shader_path[] = NALI_HOME NALI_HOME_SHADER NALI_HOME_SHADER_FRAG "/";
// 	// uint32_t frag_index = 0;
// 	// uint8_t frag_name_index = sizeof(frag_shader_path)-1;
// 	// char *frag_file = malloc(frag_name_index + MATH_LENGTH(frag_index) + sizeof(shader_type)-1 + 1);
// 	// strcpy(frag_file, frag_shader_path);
// 	// sprintf(frag_file + frag_name_index, "%u", frag_index);
// 	// strcat(frag_file, shader_type);

// 	// vk_setVkPipelineShaderStageCreateInfo(m_device, vert_file, frag_file, &vkshadermodule_vert, &vkshadermodule_frag, vkpipelineshaderstagecreateinfo_array);
// 	vk_setVkPipelineShaderStageCreateInfo(m_device, NALI_HOME NALI_HOME_SHADER "vert.spv", NALI_HOME NALI_HOME_SHADER "frag.spv", &vkshadermodule_vert, &vkshadermodule_frag, vkpipelineshaderstagecreateinfo_array);
// 	// free(vert_file);
// 	// free(frag_file);

// 	//s1-s
// 	vk_makePipelineLayout(m_device, &vkdescriptorsetlayout, 1, &vkpipelinelayout);
// 	vk_makeGraphicsPipeline(m_device, vkpipelineshaderstagecreateinfo_array, m_vkrenderpass, vkpipelinelayout, &vkpipeline);
// 	//e1-s

// 	vkDestroyShaderModule(vkdevice, vkshadermodule_frag, VK_NULL_HANDLE);
// 	vkDestroyShaderModule(vkdevice, vkshadermodule_vert, VK_NULL_HANDLE);
// 	//e0-s

// 	//s0-cmd
// 	vk_makeCommandBuffer(m_device, m_queue_g, &vkcommandbuffer, 1);
// 	vk_cmd(vkcommandbuffer, &vkcommandbufferbegininfo, vkqueue_graphic);
// 	//e0-cmd

// 	//s0-ubo
// 	lc_setVkWriteDescriptorSet(vkdescriptorset, &vkdescriptorbufferinfo, &vkdescriptorimageinfo, vkwritedescriptorset_array);
// 	//s1-update
// 	vkUpdateDescriptorSets(vkdevice, 6, vkwritedescriptorset_array, 0, VK_NULL_HANDLE);
// 	//e1-update
// 	//e0-ubo

// 	//s0-draw
// 	VK_makeFence(m_device, &vkfence)

// 	for (uint8_t i = 0; i < 2; ++i)
// 	{
// 		vk_makeSemaphore(m_device, &vksemaphore_array[i]);
// 	}

// 	vkrenderpassbegininfo.renderPass = m_vkrenderpass;
// 	vkrenderpassbegininfo.renderArea.extent = m_vkextent2d;

// 	vkviewport.width = m_vkextent2d.width;
// 	vkviewport.height = m_vkextent2d.height;

// 	vkrect2d.extent = m_vkextent2d;

// 	image_vksubmitinfo.pWaitSemaphores = &vksemaphore_array[0];
// 	image_vksubmitinfo.pSignalSemaphores = &vksemaphore_array[1];

// 	vkpresentinfokhr.pWaitSemaphores = &vksemaphore_array[1];
// 	//e0-draw

// 	//s0-mtx
// 	nali_info("mtx_init %d", mtx_init(m_mtx_t_draw_p, mtx_plain))
// 	//e0-mtx

// 	frame_start = time(0);
// }

// void freeCmdDraw()
// {
// 	nali_info("vkQueueWaitIdle %d", vkQueueWaitIdle(vkqueue_graphic))

// 	vkFreeCommandBuffers(vkdevice, m_vkcommandpool_p[m_device][m_queue_g], 1, &vkcommandbuffer);
// 	vkDestroyPipeline(vkdevice, vkpipeline, VK_NULL_HANDLE);
// 	vkDestroyPipelineLayout(vkdevice, vkpipelinelayout, VK_NULL_HANDLE);

// 	vkDestroyDescriptorSetLayout(vkdevice, vkdescriptorsetlayout, VK_NULL_HANDLE);
// 	vkDestroyDescriptorPool(vkdevice, vkdescriptorpool, VK_NULL_HANDLE);

// 	vkDestroyFence(vkdevice, vkfence, VK_NULL_HANDLE);
// 	for (uint8_t i = 0; i < 2; ++i)
// 	{
// 		vkDestroySemaphore(vkdevice, vksemaphore_array[i], VK_NULL_HANDLE);
// 	}

// 	vk_clean();

// 	mtx_destroy(m_mtx_t_draw_p);
// }

// int vk_cmdDraw(void *arg)
// {
// 	while (!(m_surface_state & NALI_SURFACE_C_S_CLEAN))
// 	{
// 		vkWaitForFences(vkdevice, 1, &vkfence, VK_TRUE, UINT64_MAX);
// 		vkResetFences(vkdevice, 1, &vkfence);

// 		if (m_surface_state & NALI_SURFACE_C_S_RE)
// 		{
// 			m_surface_state &= 255 - NALI_SURFACE_C_S_RE;
// 			vk_freeSwapchain();
// 			vk_makeSwapchain(m_max_queue_surface_p[m_device] == 1 ? VK_SHARING_MODE_EXCLUSIVE : VK_SHARING_MODE_CONCURRENT);

// 			vkrenderpassbegininfo.renderPass = m_vkrenderpass;
// 			vkviewport.width = m_vkextent2d.width;
// 			vkviewport.height = m_vkextent2d.height;
// 			vkrenderpassbegininfo.renderArea.extent = m_vkextent2d;
// 			vkrect2d.extent = m_vkextent2d;
// 		}

// 		uint32_t image_index;
// 		VkResult vkresult = vkAcquireNextImageKHR(vkdevice, m_vkswapchainkhr, UINT64_MAX, vksemaphore_array[0], VK_NULL_HANDLE, &image_index);
// 		if (vkresult != VK_SUCCESS)
// 		{
// 			//support recreate vkswapchainkhr if need
// 			nali_log("vkAcquireNextImageKHR %d", vkresult)
// 		}

// 		vkrenderpassbegininfo.framebuffer = m_vkswapchainkhr_vkframebuffer_p[image_index];
// 		vkpresentinfokhr.pImageIndices = &image_index;

// 		vkBeginCommandBuffer(vkcommandbuffer, &vkcommandbufferbegininfo);

// 			vkCmdBeginRenderPass(vkcommandbuffer, &vkrenderpassbegininfo, VK_SUBPASS_CONTENTS_INLINE);

// 				vkCmdBindPipeline(vkcommandbuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipeline);

// 				//s0-VkDynamicState
// 				// if (update)
// 				// {
// 				vkCmdSetViewport(vkcommandbuffer, 0, 1, &vkviewport);
// 				vkCmdSetScissor(vkcommandbuffer, 0, 1, &vkrect2d);
// 				// 	update = 0;
// 				// }
// 				//e0-VkDynamicState

// 				mtx_lock(m_mtx_t_draw_p);
// 				for (uint16_t u = 0; u < 1; ++u)
// 				{
// 					//vkUpdateDescriptorSets
// 					vkCmdBindVertexBuffers(vkcommandbuffer, 0, 1, m_nali_g_data_vkbuffer_p[0], (VkDeviceSize[]){0});
// 					vkCmdBindIndexBuffer(vkcommandbuffer, *m_nali_g_index_vkbuffer_p[0], 0, VK_INDEX_TYPE_UINT16);
// 					vkCmdBindDescriptorSets(vkcommandbuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipelinelayout, 0, 1, &vkdescriptorset, 0, VK_NULL_HANDLE);
// 					vkCmdDrawIndexed(vkcommandbuffer, 6, 1, 0, 0, 0);
// 				}
// 				mtx_unlock(m_mtx_t_draw_p);

// 			vkCmdEndRenderPass(vkcommandbuffer);

// 		vkEndCommandBuffer(vkcommandbuffer);

// 		vkQueueSubmit(vkqueue_graphic, 1, &image_vksubmitinfo, vkfence);
// 		vkQueuePresentKHR(vkqueue_graphic, &vkpresentinfokhr);

// 		++frame;
// 		frame_end = time(0);
// 		frame_time = frame_end - frame_start;
// 		if (frame_time > 0)
// 		// if (frame == 144)
// 		{
// 			// end = clock();
// 			// cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
// 			frame_start = frame_end;
// 			nali_log("time %ld", frame_time)
// 			nali_log("frame %d", frame)
// 			frame = 0;
// 		}
// 	}

// 	freeCmdDraw();
// 	return 0;
// }