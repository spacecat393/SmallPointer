NALI_LCS_DSIT *lc_dsi_p;
uint8_t *lc_a_p;

VkBuffer lc_vkbuffer;
VkDeviceMemory lc_vkdevicememory;
void *lc_vkbuffer_p;
VkDeviceSize lc_vkdevicesize;

mtx_t *lc_mtx_t_p = &(mtx_t){};

NALI_LB_PT lc_net_bl = 0;
uint8_t lc_net_p[NALI_LB_NET_BL];

// #define NALI_LC_STATE_ON 1
// static uint8_t lc_state;
void lc_set()
{
	lcs_set();
	s_set();
	lckf_set();
	lcp_set();
	s_surface_state |= NALI_S_S_DATA_ABLE;

	// lc_state = NALI_LC_STATE_ON;

	lc_dsi_p = malloc(0);
	lc_a_p = malloc(0);

	lcu_set();

	lcm_set();

	NALI_D_INFO("mtx_init %d", mtx_init(lc_mtx_t_p, mtx_plain))
	// NALI_D_INFO("thrd_create %d", thrd_create(&(thrd_t){}, lc_loop, NULL))

	nlc_set();
}

void lc_re()
{
	lc_dsi_p = realloc(lc_dsi_p, 0);
	lc_a_p = realloc(lc_a_p, 0);

	lcu_re();

	lcm_re();
}

void lc_vk()
{
	while (!(s_surface_state & NALI_S_S_DATA_ABLE))
	{
		thrd_sleep(&(struct timespec){.tv_sec = 1, .tv_nsec = 0}, NULL);
	}

	VkMemoryRequirements vkmemoryrequirements;
	//VK_MEMORY_PROPERTY_HOST_COHERENT_BIT
	//VK_BUFFER_USAGE_STORAGE_BUFFER_BIT
	VK_makeBuffer(vk_device, lc_vkdevicesize, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, lc_vkbuffer, lc_vkdevicememory, vkmemoryrequirements)
	NALI_D_INFO("vkMapMemory %d", vkMapMemory(vkqd_vkdevice_p[vk_device], lc_vkdevicememory, 0, lc_vkdevicesize, 0, &lc_vkbuffer_p))
	lcp_vk();

	// //update vkbuffer
	// vkFlushMappedMemoryRanges(vkqd_vkdevice_p[vk_device], 1, &(VkMappedMemoryRange)
	// {
	// 	.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE,
	// 	.memory = m_vkdevicememory,
	// 	.offset = 0,
	// 	.size = step,
	// 	// .size = m_vkdevicesize
	// 	.pNext = VK_NULL_HANDLE
	// });

	lcs_vk();

	vk_cmd_draw_set();
	NALI_D_INFO("thrd_create %d", thrd_create(&(thrd_t){}, vk_cmd_draw_loop, NULL))
}

void lc_freeloop()
{
	//switch to render loop
	// while (lc_state & NALI_LC_STATE_ON)
	// {
	// 	// mtx_lock(lc_mtx_t_p);
	// 	// mtx_unlock(lc_mtx_t_p);
	// }

	mtx_lock(lc_mtx_t_p);

	lcp_free();
	lcs_free();
	lcu_free();

	free(lc_dsi_p);
	free(lc_a_p);

	lcm_free();

	mtx_destroy(lc_mtx_t_p);

	lc_net_bl = 0;

	mtx_unlock(lb_mtx_t_p);
}

void lc_freeVk(uint32_t device)
{
	lcs_freeVk(device);

	VkDevice vkdevice = vkqd_vkdevice_p[device];
	vkUnmapMemory(vkqd_vkdevice_p[device], lc_vkdevicememory);
	vkDestroyBuffer(vkdevice, lc_vkbuffer, VK_NULL_HANDLE);
	vkFreeMemory(vkdevice, lc_vkdevicememory, VK_NULL_HANDLE);
	lc_vkbuffer_p = NULL;
}

void lc_free()
{
	if (s_surface_state & NALI_S_S_EXIT_C)
	{
		return;
	}
	s_surface_state |= NALI_S_S_EXIT_C;

	mtx_lock(lb_mtx_t_p);
	mtx_lock(lc_mtx_t_p);

	nlc_state |= NALI_NC_FAIL;

	s_surface_state |= NALI_S_S_CLEAN;
	// lc_state &= 0xFFu - NALI_LC_STATE_ON;
}