// void (**vk_cmd_d_fp)();
// uint16_t vk_cmd_d_fp_bl = 0;
// mtx_t *m_mtx_t_draw_p = &(mtx_t){};

// static clock_t frame_start, frame_end;
static struct timespec frame_start = {0}, frame_end;
// static struct timespec delta_start = {0}, delta_end;
static uint32_t frame;
// static clock_t frame_time;
static double frame_time = 0;

//s0-share
static VkDevice vkdevice;
static VkQueue vkqueue_graphic;
//e0-share

//s0-s
static VkPipelineLayout vkpipelinelayout;
static VkPipeline vkpipeline;
//e0-s

//s0-cmd
static VkCommandBufferBeginInfo vkcommandbufferbegininfo =
{
	.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
	.pInheritanceInfo = VK_NULL_HANDLE,

	.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,
	.pNext = VK_NULL_HANDLE
};

static VkCommandBuffer vkcommandbuffer;
//e0-cmd

//s0-draw
static VkClearValue vkclearvalue_array[2] =
{
	{.color = {.float32 = {0.0F, 0.0F, 0.0F, 1.0F}}},
	{.depthStencil =
		{
			.depth = 1.0F,
			.stencil = 0.0F
		}
	}
};
static VkRenderPassBeginInfo vkrenderpassbegininfo =
{
	.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
	.renderArea.offset = {0, 0},
	.clearValueCount = 2,
	.pClearValues = vkclearvalue_array,

	.pNext = VK_NULL_HANDLE
};
static VkViewport vkviewport =
{
	.x = 0.0F,
	.y = 0.0F,
	.minDepth = 0.0F,
	.maxDepth = 1.0F
};
static VkRect2D vkrect2d =
{
	.offset = {0, 0}
};
//s1-queue

//graphic
static VkFence vkfence;
//image render
static VkSemaphore vksemaphore_array[2];

static VkSubmitInfo image_vksubmitinfo =
{
	.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
	.waitSemaphoreCount = 1,
	.pWaitDstStageMask = (VkPipelineStageFlags[]){VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT},
	.commandBufferCount = 1,
	.pCommandBuffers = &vkcommandbuffer,
	.signalSemaphoreCount = 1,

	.pNext = VK_NULL_HANDLE
};
static VkPresentInfoKHR vkpresentinfokhr =
{
	.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
	.waitSemaphoreCount = 1,

	.swapchainCount = 1,
	.pSwapchains = &vksc_vkswapchainkhr,

	.pResults = VK_NULL_HANDLE,
	.pNext = VK_NULL_HANDLE
};
//e1-queue
//e0-draw

void vk_cmd_draw_set()
{
	// vk_cmd_d_fp = malloc(0);

	//s0-share
	vkdevice = vkqd_vkdevice_p[vk_device];
	vkqueue_graphic = vkq_vkqueue_p[vk_device][vk_queue_g];
	//e0-share

	//s0-s
	VkShaderModule vkshadermodule_vert;
	VkShaderModule vkshadermodule_frag;
	VkPipelineShaderStageCreateInfo vkpipelineshaderstagecreateinfo_array[2];

	// const char shader_type[] = ".spv";

	// const char vert_shader_path[] = NALI_F_HOME NALI_F_HOME_SHADER NALI_F_HOME_SHADER_VERT "/";
	// uint32_t vert_index = 0;
	// uint8_t vert_name_index = sizeof(vert_shader_path)-1;
	// char *vert_file = malloc(vert_name_index + M_LENGTH(vert_index) + sizeof(shader_type)-1 + 1);
	// strcpy(vert_file, vert_shader_path);
	// sprintf(vert_file + vert_name_index, "%u", vert_index);
	// strcat(vert_file, shader_type);

	// const char frag_shader_path[] = NALI_F_HOME NALI_F_HOME_SHADER NALI_F_HOME_SHADER_FRAG "/";
	// uint32_t frag_index = 0;
	// uint8_t frag_name_index = sizeof(frag_shader_path)-1;
	// char *frag_file = malloc(frag_name_index + M_LENGTH(frag_index) + sizeof(shader_type)-1 + 1);
	// strcpy(frag_file, frag_shader_path);
	// sprintf(frag_file + frag_name_index, "%u", frag_index);
	// strcat(frag_file, shader_type);

	// vk_setVkPipelineShaderStageCreateInfo(vk_device, vert_file, frag_file, &vkshadermodule_vert, &vkshadermodule_frag, vkpipelineshaderstagecreateinfo_array);
	// vk_setVkPipelineShaderStageCreateInfo(vk_device, NALI_F_HOME NALI_F_HOME_SHADER "vert.spv", NALI_F_HOME NALI_F_HOME_SHADER "frag.spv", &vkshadermodule_vert, &vkshadermodule_frag, vkpipelineshaderstagecreateinfo_array);
	vk_setVkPipelineShaderStageCreateInfo(vk_device, NALI_F_HOME_VERT, NALI_F_HOME_FRAG, &vkshadermodule_vert, &vkshadermodule_frag, vkpipelineshaderstagecreateinfo_array);
	// free(vert_file);
	// free(frag_file);

	//s1-s
	vkgplpllo_make(vk_device, &lcs_vkdescriptorsetlayout, 1, &vkpipelinelayout);
	vkgpl_make(vk_device, vkpipelineshaderstagecreateinfo_array, vksc_vkrenderpass, vkpipelinelayout, &vkpipeline);
	//e1-s

	vkDestroyShaderModule(vkdevice, vkshadermodule_frag, VK_NULL_HANDLE);
	vkDestroyShaderModule(vkdevice, vkshadermodule_vert, VK_NULL_HANDLE);
	//e0-s

	//s0-cmd
	vkcb_make(vk_device, vk_queue_g, &vkcommandbuffer, 1);
	vk_cmd(vkcommandbuffer, &vkcommandbufferbegininfo, vkqueue_graphic);
	//e0-cmd

	// //s0-ubo
	// // lc_setVkWriteDescriptorSet(vkdescriptorset, &vkdescriptorbufferinfo, &vkdescriptorimageinfo, vkwritedescriptorset_array);
	// lc_setVkWriteDescriptorSet(vkdescriptorset, &vkdescriptorbufferinfo, vkwritedescriptorset_array);
	// //s1-update
	// vkUpdateDescriptorSets(vkdevice, 6, vkwritedescriptorset_array, 0, VK_NULL_HANDLE);
	// //e1-update
	// //e0-ubo

	//s0-draw
	VK_makeFence(vk_device, &vkfence)

	for (uint8_t l_0 = 0; l_0 < 2; ++l_0)
	{
		vksp_make(vk_device, &vksemaphore_array[l_0]);
	}

	vkrenderpassbegininfo.renderPass = vksc_vkrenderpass;
	vkrenderpassbegininfo.renderArea.extent = vksc_vkextent2d;

	vkviewport.width = vksc_vkextent2d.width;
	vkviewport.height = vksc_vkextent2d.height;

	vkrect2d.extent = vksc_vkextent2d;

	image_vksubmitinfo.pWaitSemaphores = &vksemaphore_array[0];
	image_vksubmitinfo.pSignalSemaphores = &vksemaphore_array[1];

	vkpresentinfokhr.pWaitSemaphores = &vksemaphore_array[1];
	//e0-draw

	// //s0-mtx
	// NALI_D_INFO("mtx_init %d", mtx_init(m_mtx_t_draw_p, mtx_plain))
	// //e0-mtx

	// // frame_start = time(0);
	// clock_gettime(CLOCK_MONOTONIC, &frame_start);
}

void freeCmdDraw()
{
	NALI_D_INFO("vkQueueWaitIdle %d", vkQueueWaitIdle(vkqueue_graphic))

	vkFreeCommandBuffers(vkdevice, vkcbcp_vkcommandpool_p[vk_device][vk_queue_g], 1, &vkcommandbuffer);
	vkDestroyPipeline(vkdevice, vkpipeline, VK_NULL_HANDLE);
	vkDestroyPipelineLayout(vkdevice, vkpipelinelayout, VK_NULL_HANDLE);

	vkDestroyFence(vkdevice, vkfence, VK_NULL_HANDLE);
	for (uint8_t l_0 = 0; l_0 < 2; ++l_0)
	{
		vkDestroySemaphore(vkdevice, vksemaphore_array[l_0], VK_NULL_HANDLE);
	}

	vk_free();

	lc_freeloop();

	// free(vk_cmd_d_fp);
	// mtx_destroy(m_mtx_t_draw_p);
}

// static void c1j1()
// {
// }

// static void c1j0()
// {
// }

// static void (*a_fp[NALI_LCS_A_BL])() = {c1j1, c1j0};
int vk_cmd_draw_loop(void *p)
{
	while (!(s_state & NALI_S_S_CLEAN))
	{
		nc_send();

		// clock_gettime(CLOCK_MONOTONIC, &delta_end);
		// lc_delta = delta_end.tv_sec + (double)delta_end.tv_nsec / 1e9 - delta_start.tv_sec - (double)delta_start.tv_nsec / 1e9;
		// // ry += M_MIN(0.5F * (delta_end.tv_sec + delta_end.tv_nsec / 1e9 - delta_start.tv_sec - delta_start.tv_nsec / 1e9), 1.0F);
		// delta_start = delta_end;

		// for (uint8_t l_0 = 0; l_0 < vk_cmd_d_fp_bl; ++l_0)
		// {
		// 	//model add/update
		// 	vk_cmd_d_fp[l_0]();
		// }

		nc_get();
		lcu_update();
		lcm_update();
		// lcs_loop();

		vkFlushMappedMemoryRanges(vkqd_vkdevice_p[vk_device], 1, &(VkMappedMemoryRange)
		{
			.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE,
			.memory = lc_vkdevicememory,
			.offset = 0,
			.size = 16 * sizeof(float),
			.pNext = VK_NULL_HANDLE
		});

		vkWaitForFences(vkdevice, 1, &vkfence, VK_TRUE, UINT64_MAX);
		vkResetFences(vkdevice, 1, &vkfence);

		if (s_state & NALI_S_S_RE)
		{
			vksc_free();

			#ifdef C_NALI_S_ANDROID
				sa_wait();
			#endif

			vksc_make(vkq_max_queue_surface_p[vk_device] == 1 ? VK_SHARING_MODE_EXCLUSIVE : VK_SHARING_MODE_CONCURRENT);

			vkrenderpassbegininfo.renderPass = vksc_vkrenderpass;
			vkviewport.width = vksc_vkextent2d.width;
			vkviewport.height = vksc_vkextent2d.height;
			vkrenderpassbegininfo.renderArea.extent = vksc_vkextent2d;
			vkrect2d.extent = vksc_vkextent2d;

			vkQueueWaitIdle(vkqueue_graphic);
			MM4X4_P(tanf(90.0F * (M_PI / 180.0F) / 2.0F), s_width / s_height, 0.1F, 100.0F, (float *)lc_vkbuffer_p + 16)
//			if (m_vksurfacetransformflagbitskhr == VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR || m_vksurfacetransformflagbitskhr == VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR)
//			{
//				rz = 0.0F;
//			}
//			else
//			{
//				rz = 180.0F;
//			}
			vkFlushMappedMemoryRanges(vkqd_vkdevice_p[vk_device], 1, &(VkMappedMemoryRange)
			{
				.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE,
				.memory = lc_vkdevicememory,
				.offset = 16 * sizeof(float),
				.size = 16 * sizeof(float),
				.pNext = VK_NULL_HANDLE
			});
			s_state &= 0xFFu - NALI_S_S_RE;
		}

		uint32_t image_index;
		VkResult vkresult = vkAcquireNextImageKHR(vkdevice, vksc_vkswapchainkhr, UINT64_MAX, vksemaphore_array[0], VK_NULL_HANDLE, &image_index);
		if (vkresult != VK_SUCCESS)
		{
			//support recreate vkswapchainkhr if need
			NALI_D_LOG("vkAcquireNextImageKHR %d", vkresult)
		}

		vkrenderpassbegininfo.framebuffer = vksc_vkswapchainkhr_vkframebuffer_p[image_index];
		vkpresentinfokhr.pImageIndices = &image_index;

		vkBeginCommandBuffer(vkcommandbuffer, &vkcommandbufferbegininfo);

			vkCmdBeginRenderPass(vkcommandbuffer, &vkrenderpassbegininfo, VK_SUBPASS_CONTENTS_INLINE);

				vkCmdBindPipeline(vkcommandbuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipeline);

				//s0-VkDynamicState
				// if (update)
				// {
				vkCmdSetViewport(vkcommandbuffer, 0, 1, &vkviewport);
				vkCmdSetScissor(vkcommandbuffer, 0, 1, &vkrect2d);
				// 	update = 0;
				// }
				//e0-VkDynamicState

				// // mtx_lock(m_mtx_t_draw_p);

				// for (uint8_t l_0 = 0; l_0 < NALI_LCS_A_BL; ++l_0)
				// {
				// 	vkCmdBindVertexBuffers(vkcommandbuffer, 0, 1, &lc_vkbuffer, lcs_a_vkdevicesize_p + l_0);

				// 	// a_fp[l_0]();
				// 	// for (uint8_t l_1 = 0; l_1 < lcm_joint_count_bl; ++l_1)
				// 	for (NALI_LCS_DSIT l_1 = 0; l_1 < lcs_a_bl_p[l_0]; ++l_1)
				// 	{
				// 		// vkCmdBindDescriptorSets(vkcommandbuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipelinelayout, 0, 1, lcs_vkdescriptorset_p + l_1, 0, VK_NULL_HANDLE);
				// 		vkCmdBindDescriptorSets(vkcommandbuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipelinelayout, 0, 1, &lcs___p[lcs__i_p[l_0][l_1]].vkdescriptorset, 0, VK_NULL_HANDLE);

				// 		//mix all to one to use address
				// 		for (NALI_LCS_AIT l_2 = 1; l_2 < lcs___p[lcs__i_p[l_0][l_1]].a_p[0]; ++l_2)
				// 		{
				// 			vkCmdBindIndexBuffer(vkcommandbuffer, lc_vkbuffer, lcs_i_p[lcs___p[lcs__i_p[l_0][l_1]].a_p[l_2]], VK_INDEX_TYPE_UINT32);
				// 			vkCmdDrawIndexed(vkcommandbuffer, lcs_ic_p[lcs___p[lcs__i_p[l_0][l_1]].a_p[l_2]], 1, 0, 0, 0);
				// 		}
				// 	}
				// }

				for (NALI_LCS_DSIT l_0 = 0; l_0 < lcs_s_bl; ++l_0)
				{
					lcs__ _ = lcs___p[lcs_s_p[l_0]._];
					vkCmdBindDescriptorSets(vkcommandbuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipelinelayout, 0, 1, &_.vkdescriptorset, 0, VK_NULL_HANDLE);
					vkCmdBindVertexBuffers(vkcommandbuffer, 0, 1, &lc_vkbuffer, lcs_a_vkdevicesize_p + _.mab);

					vkCmdBindIndexBuffer(vkcommandbuffer, lc_vkbuffer, lcs_ib_p[lcs_s_p[l_0].i], VK_INDEX_TYPE_UINT32);
					vkCmdDrawIndexed(vkcommandbuffer, lcs_ic_p[lcs_s_p[l_0].i], 1, 0, 0, 0);
				}

			vkCmdEndRenderPass(vkcommandbuffer);

		vkEndCommandBuffer(vkcommandbuffer);

		vkQueueSubmit(vkqueue_graphic, 1, &image_vksubmitinfo, vkfence);
		vkQueuePresentKHR(vkqueue_graphic, &vkpresentinfokhr);

		++frame;
		// frame_end = time(0);
		// frame_time = frame_end - frame_start;
		clock_gettime(CLOCK_MONOTONIC, &frame_end);
		frame_time = frame_end.tv_sec + (double)frame_end.tv_nsec / 1e9 - frame_start.tv_sec - (double)frame_start.tv_nsec / 1e9;
		// if (frame_time > 0)
		// if (frame == 144)
		if (frame_time >= 1.0)
		{
			// end = clock();
			// cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			frame_start = frame_end;
			// NALI_D_LOG("time %ld", frame_time)
			NALI_D_LOG("time %f", frame_time)
			NALI_D_LOG("frame %d", frame)
			frame = 0;
		}

//		#ifdef C_NALI_S_ANDROID
//			sa_wait();
//		#endif
	}

//	#ifdef C_NALI_S_ANDROID
//		m_surface_state &= 0xFFu - NALI_S_S_CLEAN;
//	#else
	freeCmdDraw();
	return 0;
//	#endif
}