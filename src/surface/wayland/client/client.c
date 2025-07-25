struct wl_display *wlc_wl_display_client_p = NULL;
struct wl_registry *wlc_wl_registry_p = NULL;
struct wl_compositor *wlc_wl_compositor_p = NULL;
struct wl_surface *wlc_wl_surface_p = NULL;

struct xdg_wm_base *wlc_xdg_wm_base_p = NULL;
struct xdg_surface *wlc_xdg_surface_p = NULL;
struct xdg_toplevel *wlc_xdg_toplevel_p = NULL;

struct wl_seat *wlc_wl_seat_p = NULL;
struct wl_keyboard *wlc_wl_keyboard_p = NULL;
struct wl_shm *wlc_wl_shm_p = NULL;
struct wl_pointer *wlc_wl_pointer_p = NULL;
// struct wl_touch *m_wl_touch_p = NULL;

struct zwp_pointer_constraints_v1 *wlc_zwp_pointer_constraints_v1_p = NULL;
struct zwp_locked_pointer_v1 *wlc_zwp_locked_pointer_v1_p = NULL;

struct zwp_relative_pointer_manager_v1 *wlc_zwp_relative_pointer_manager_v1_p = NULL;
struct zwp_relative_pointer_v1 *wlc_zwp_relative_pointer_v1_p = NULL;

void swlc_clean()
{
	if (wlc_wl_seat_p)
	{
		wl_seat_destroy(wlc_wl_seat_p);
		wlc_wl_seat_p = NULL;
	}
	if (wlc_wl_keyboard_p)
	{
		wl_keyboard_destroy(wlc_wl_keyboard_p);
		wlc_wl_keyboard_p = NULL;
	}
	if (wlc_wl_pointer_p)
	{
		wl_pointer_destroy(wlc_wl_pointer_p);
		wlc_wl_pointer_p = NULL;
	}

	if (wlc_xdg_toplevel_p)
	{
		xdg_toplevel_destroy(wlc_xdg_toplevel_p);
		wlc_xdg_toplevel_p = NULL;
	}
	if (wlc_xdg_surface_p)
	{
		xdg_surface_destroy(wlc_xdg_surface_p);
		wlc_xdg_surface_p = NULL;
	}
	if (wlc_xdg_wm_base_p)
	{
		xdg_wm_base_destroy(wlc_xdg_wm_base_p);
		wlc_xdg_wm_base_p = NULL;
	}

	if (wlc_zwp_locked_pointer_v1_p)
	{
		zwp_locked_pointer_v1_destroy(wlc_zwp_locked_pointer_v1_p);
		wlc_zwp_locked_pointer_v1_p = NULL;
	}
	if (wlc_zwp_pointer_constraints_v1_p)
	{
		zwp_pointer_constraints_v1_destroy(wlc_zwp_pointer_constraints_v1_p);
		wlc_zwp_pointer_constraints_v1_p = NULL;
	}

	if (wlc_zwp_relative_pointer_v1_p)
	{
		zwp_relative_pointer_v1_destroy(wlc_zwp_relative_pointer_v1_p);
		wlc_zwp_relative_pointer_v1_p = NULL;
	}
	if (wlc_zwp_relative_pointer_manager_v1_p)
	{
		zwp_relative_pointer_manager_v1_destroy(wlc_zwp_relative_pointer_manager_v1_p);
		wlc_zwp_relative_pointer_manager_v1_p = NULL;
	}

	if (wlc_wl_surface_p)
	{
		wl_surface_destroy(wlc_wl_surface_p);
		wlc_wl_surface_p = NULL;
	}
	if (wlc_wl_compositor_p)
	{
		wl_compositor_destroy(wlc_wl_compositor_p);
		wlc_wl_compositor_p = NULL;
	}
	if (wlc_wl_shm_p)
	{
		wl_shm_destroy(wlc_wl_shm_p);
		wlc_wl_shm_p = NULL;
	}

	if (wlc_wl_registry_p)
	{
		wl_registry_destroy(wlc_wl_registry_p);
		wlc_wl_registry_p = NULL;
	}
	if (wlc_wl_display_client_p)
	{
		wl_display_disconnect(wlc_wl_display_client_p);
		wlc_wl_display_client_p = NULL;
	}
}

static int loop(void* arg)
{
	// while (!(s_surface_state & NALI_S_S_CONFIG))
	// {
	// 	thrd_sleep(&(struct timespec){.tv_sec = 1, .tv_nsec = 0}, NULL);
	// }

	//wl_display_dispatch after then set vk
	int r = wl_display_dispatch(wlc_wl_display_client_p);
	//if surface fail on vk need re vksurface
	if (r < 0)
	{
		NALI_D_LOG("wl_display_dispatch %d", r);
		swlc_clean();
		swlc_set();
	}
	s_state |= NALI_S_S_RENDER_ABLE;

	while (r > -1 && r != INT_MAX)
	{
		if (s_state & NALI_S_S_CLEAN)
		{
			r = INT_MAX;
		}
		else
		{
			swlcsp_change_cursor(1);
			r = wl_display_dispatch(wlc_wl_display_client_p);
		}
	}

	if (r < 0)
	{
		NALI_D_LOG("wl_display_dispatch %d", r);
		swlc_clean();
	}
	return 0;
}
void swlc_set()
{
	NALI_D_INFO("wl_display_connect %p", wlc_wl_display_client_p = wl_display_connect(getenv("WAYLAND_DISPLAY")))
	// info("wl_display_get_fd %d", wl_display_get_fd(m_wl_display_client))

	NALI_D_INFO("wl_display_get_registry %p", wlc_wl_registry_p = wl_display_get_registry(wlc_wl_display_client_p))

	NALI_D_INFO("wl_registry_add_listener %d", wl_registry_add_listener(wlc_wl_registry_p, &swlcr_wl_registry_listener, NULL))
	NALI_D_INFO("wl_display_roundtrip %d", wl_display_roundtrip(wlc_wl_display_client_p))
	swlcsp_init_cursor();

	// if (!m_wl_compositor)
	// {
	// 	error("m_wl_compositor")
	// }

	NALI_D_INFO("wl_compositor_create_surface %p", wlc_wl_surface_p = wl_compositor_create_surface(wlc_wl_compositor_p))

	NALI_D_INFO("xdg_wm_base_get_xdg_surface %p", wlc_xdg_surface_p = xdg_wm_base_get_xdg_surface(wlc_xdg_wm_base_p, wlc_wl_surface_p))
	NALI_D_INFO("xdg_surface_get_toplevel %p", wlc_xdg_toplevel_p = xdg_surface_get_toplevel(wlc_xdg_surface_p))

	NALI_D_INFO("xdg_surface_add_listener %d", xdg_surface_add_listener(wlc_xdg_surface_p, &swlcxdg_xdg_surface_listener, NULL))
	NALI_D_INFO("xdg_toplevel_add_listener %d", xdg_toplevel_add_listener(wlc_xdg_toplevel_p, &swlcxdg_xdg_toplevel_listener, NULL))

	wl_surface_commit(wlc_wl_surface_p);

	NALI_D_INFO("thrd_create %d", thrd_create(&(thrd_t){}, loop, NULL))
}