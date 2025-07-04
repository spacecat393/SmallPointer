static void wl_seat_listener_capabilities(void* data, struct wl_seat* wl_seat, uint32_t capabilities)
{
	if (capabilities & WL_SEAT_CAPABILITY_KEYBOARD)
	{
		NALI_D_INFO("wl_seat_get_keyboard %p", wlc_wl_keyboard_p = wl_seat_get_keyboard(wl_seat))
		NALI_D_INFO("wl_keyboard_add_listener %d", wl_keyboard_add_listener(wlc_wl_keyboard_p, &swlcsk_wl_keyboard_listener, NULL))
	}
	if (capabilities & WL_SEAT_CAPABILITY_POINTER)
	{
		NALI_D_INFO("wl_seat_get_pointer %p", wlc_wl_pointer_p = wl_seat_get_pointer(wl_seat))
		NALI_D_INFO("wl_pointer_add_listener %d", wl_pointer_add_listener(wlc_wl_pointer_p, &swlcsp_wl_pointer_listener, NULL))
	}
}

struct wl_seat_listener swlcs_wl_seat_listener =
{
	.capabilities = wl_seat_listener_capabilities,
};