#ifndef NALI_WAYLAND_CLIENT_POINTER_H
#define NALI_WAYLAND_CLIENT_POINTER_H

extern uint8_t swlcsp_pointer;

extern struct wl_pointer_listener swlcsp_wl_pointer_listener;

void swlcsp_init_cursor();
void swlcsp_change_cursor();

#endif