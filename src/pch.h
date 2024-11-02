#ifdef PCH_GLTF

	#define GLTF_IN "G_I"
	#define GLTF_OUT "G_O"

#endif
#ifdef PCH_COLLADA

	#define CP_IN "./C_I"
	#define CP_OUT "./C_O"

	#define CP_COMPRESS 1
	#define CP_FIX_ANIMATION 1
	// #define CP_DECOMPOSED 0
	// #define CP_CREATE_COLOR 0
	#define CP_ARMATURE_NAME "<animation id=\""
	#define CP_VERTICES_NAME "/vertex.bin"
	#define CP_NORMALS_NAME "/normal.bin"
	#define CP_TEXCOORD_NAME "/texcoord.bin"
	#define CP_COLOR_NAME "/color.bin"
	#define CP_JOINTS_NAME "/joint.bin"
	#define CP_WEIGHTS_NAME "/weight.bin"
	#define CP_BINDPOSES_NAME "/bindpose.bin"
	#define CP_JOINTSIDENTITY_NAME "/jointsidentity.dat"
	#define CP_INDEX_NAME "/index.bin"
	#define CP_ANIMATION_NAME "/frame"
	#define CP_BONES_NAME "/bone"
	#define CP_BONES_M4X4_NAME "/BonesM4x4"
	#define CP_SKINNING_BONES_NAME "/SkinningBones"
	#define CP_ANIMATION_BONES_NAME "/AnimationBones"
	#define CP_TIMES_NAME "/time.bin"
	#define CP_TRANSFORMS_NAME "/transform.bin"
	#define CP_VISUALBONES_NAME "/visualbone.bin"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdint.h>
	#include <sys/stat.h>
	#include <ctype.h>
	#include <dirent.h>
	#include <math.h>
	#include <threads.h>

	#include "math/math.h"
	#include "math/m4x4/m4x4.h"

	#include "collada/collada.h"
	#include "collada/file_reader/file_reader.h"
	#include "collada/file_writer/file_writer.h"
	#include "collada/graphic_reader/graphic_reader.h"

#endif
#ifdef PCH_LWJGL64
	// #include <stdio.h>
	// #include <dlfcn.h>
	// #include <stdint.h>
	#include <stdlib.h>
	#include <jni.h>
	#include <threads.h>
	#include <string.h>
	// #include <math.h>

	#include <png.h>

	#include <wayland-client.h>
	#include <wayland-xdg-shell-client-protocol.h>

	#include <GL/gl.h>
	#include <GL/glx.h>
	#include <X11/Xlib.h>

	#include "lwjgl/gl/11/GL11.h"

	#include <al.h>
	#include <alc.h>

	#include <vulkan/vulkan.h>
	#include <vulkan/vulkan_wayland.h>

	#include "al/al.h"

	#include "lwjgl/lwjgl.h"
	#include "surface/surface.h"
	#include "vk/vk.h"
	#include "vk/instance/instance.h"
	#include "vk/instance/debug/debug.h"
	#include "vk/instance/physical_device/physical_device.h"
	#include "vk/instance/physical_device/queue/queue.h"
	#include "vk/surface/surface.h"
	#include "vk/instance/device/device.h"
	#include "vk/swapchain/swapchain.h"
	#include "vk/fence/fence.h"
	#include "vk/semaphore/semaphore.h"
	#include "vk/commandbuffer/commandpool/commandpool.h"
	#include "vk/commandbuffer/commandbuffer.h"
	#include "vk/heap/imageview/image/image.h"
	#include "vk/heap/imageview/imageview.h"
	#include "vk/shadermodule/shadermodule.h"

	#include <sys/stat.h>
	#include <dirent.h>
	// #include <ctype.h>

#endif
#ifdef PCH_NALIGL

	#define NALI_LWJGL2
	#define NALI_X11
	// #define NALI_EGL

	// #define NALI_LWJGL3

	#include <jni.h>
	#include <GL/gl.h>

	#ifdef NALI_LWJGL3
		#define tlsGetFunction(index) (uintptr_t)((void **)(*__env)->reserved3)[index]
		typedef void (APIENTRY *glGenVertexArraysPROC) (jint, uintptr_t);
	#endif

	#ifdef NALI_EGL
		#include <EGL/egl.h>
		#define GETPROCADDRESS(proc) eglGetProcAddress((const GLubyte*)proc)
		#define NALI_LWJGL2
	#endif

	#ifdef NALI_X11
		#include <GL/glx.h>
		#define GETPROCADDRESS(proc) glXGetProcAddress((const GLubyte*)proc)
		#define NALI_LWJGL2
	#endif

#endif

#define info(format, ...) \
	printf("nali_info: " format "\n", ##__VA_ARGS__); \
	fflush(stdout);

#define error(format, ...) \
	printf("nali_error: " format "\n", ##__VA_ARGS__); \
	fflush(stdout); \
	exit(EXIT_FAILURE);
