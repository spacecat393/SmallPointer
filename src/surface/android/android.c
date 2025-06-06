ANativeWindow *sa_anativewindow_p = NULL;
ANativeActivity *sa_anativeactivity_p;
AInputQueue *sa_ainputqueue_p = NULL;
//static int32_t orientation;

static uint8_t a_state = 0;
#define A_STATE_WAIT 1
#define A_STATE_READY 2

static void onNativeWindowCreated(ANativeActivity* activity, ANativeWindow* window)
{
	NALI_D_LOG("window %p", window)
	s_width = ANativeWindow_getWidth(window);
	s_height = ANativeWindow_getHeight(window);
	sa_anativewindow_p = window;
}

static void onNativeWindowResized(ANativeActivity* activity, ANativeWindow* window)
{
	NALI_D_LOG("window resize")
	s_width = ANativeWindow_getWidth(window);
	s_height = ANativeWindow_getHeight(window);
	s_surface_state |= NALI_SURFACE_C_S_RE;
}

static void onNativeWindowDestroyed(ANativeActivity* activity, ANativeWindow* window)
{
	NALI_D_LOG("window 0")
	sa_anativewindow_p = NULL;
	s_surface_state |= NALI_SURFACE_C_S_RE;
}

//static void onConfigurationChanged(ANativeActivity* activity)
//{
//	NALI_D_LOG("onConfigurationChanged")
//
//	AConfiguration *aconfiguration_p = AConfiguration_new();
//	AConfiguration_fromAssetManager(aconfiguration_p, activity->assetManager);
//
//	orientation = AConfiguration_getOrientation(aconfiguration_p);
//
//	NALI_D_LOG("orientation %d", orientation)
////	if (orientation == ACONFIGURATION_ORIENTATION_PORT)
////	{
////	}
////	else if (orientation == ACONFIGURATION_ORIENTATION_LAND)
////	{
////	}
////	else
////	{
////	}
//
//	AConfiguration_delete(aconfiguration_p);
//}

static void onInputQueueCreated(ANativeActivity* activity, AInputQueue* queue)
{
	sa_ainputqueue_p = queue;
}

static void onInputQueueDestroyed(ANativeActivity* activity, AInputQueue* queue)
{
	sa_ainputqueue_p = NULL;
}

void ANativeActivity_onCreate(ANativeActivity* activity, void* savedState, size_t savedStateSize)
{
	#ifdef NALI_D_FILE
		d_set();
	#endif

	NALI_D_LOG("ANativeActivity_onCreate")
	if (!(a_state & A_STATE_READY))
	{
		a_state |= A_STATE_READY;
		NALI_D_LOG("scene")
		NALI_D_INFO("thrd_create %d", thrd_create(&(thrd_t){}, s1_set, NULL))
	}
	activity->callbacks->onNativeWindowCreated = onNativeWindowCreated;
	activity->callbacks->onNativeWindowResized = onNativeWindowResized;
	activity->callbacks->onNativeWindowDestroyed = onNativeWindowDestroyed;
	activity->callbacks->onInputQueueCreated = onInputQueueCreated;
	activity->callbacks->onInputQueueDestroyed = onInputQueueDestroyed;
//	activity->callbacks->onConfigurationChanged = onConfigurationChanged;
	sa_anativeactivity_p = activity;

//	SLObjectItf slobjectitf;
//	NALI_D_INFO("slCreateEngine %d", slCreateEngine(&slobjectitf, 0, NULL, 0, NULL, NULL))
}

void sa_wait()
{
	while (!sa_anativewindow_p)
	{
		a_state |= A_STATE_WAIT;
		thrd_sleep(&(struct timespec){.tv_sec = 1, .tv_nsec = 0}, NULL);
	}

	if (a_state & A_STATE_WAIT)
	{
//		lc_set();
//		vk_init();
////		al_set();
//		lc_vk();

//		vk_freeDevice();
//		vk_freeQueue();
		VK_freeSurface
		VK_makeSurface
//		vk_initQueue();
//		vk_initDevice();
//		vk_setQueue(vk_device);
//		vk_makeDevice(vk_device);
//		vk_getQueue(vk_device);

//		m_surface_state |= NALI_SURFACE_C_S_CLEAN;
		s_surface_state |= NALI_SURFACE_C_S_RE;
		a_state &= 0xFFu - A_STATE_WAIT;
	}
}

//AAudioStreamDataCallbackResult data_callback(AAudioStream *stream, void *userData, void *audioData, int32_t numFrames) {
//	// Fill audioData with the samples to be played
//	// For this example, we'll just produce silence (zeros)
//	float *buffer = (float*)audioData;
//	for (int i = 0; i < numFrames; i++) {
//		buffer[i] = 0.0f;  // Silence
//	}
//	return AAUDIO_STREAM_DATA_CALLBACK_RESULT_CONTINUE;
//}
//
//void play_audio() {
//	AAudioStreamBuilder *builder = NULL;
//	AAudioStream *stream = NULL;
//
//	// Create the AAudio stream builder
//	AAudio_createStreamBuilder(&builder);
//
//	// Set the callback function
//	AAudioStreamBuilder_setDataCallback(builder, data_callback);
//
//	// Configure the stream parameters (e.g., format, channels, sample rate)
//	AAudioStreamBuilder_setFormat(builder, AAUDIO_FORMAT_PCM_FLOAT);
//	AAudioStreamBuilder_setChannelCount(builder, 1);  // Mono
//	AAudioStreamBuilder_setSampleRate(builder, 44100); // 44.1 kHz
//
//	// Open the stream
//	AAudio_createStream(builder, &stream);
//
//	// Start the stream for playback
//	AAudioStream_requestStart(stream);
//
//	// Let the audio play for a few seconds (e.g., 5 seconds)
//	usleep(5000000);  // 5 seconds in microseconds
//
//	// Stop and release the stream
//	AAudioStream_requestStop(stream);
//	AAudioStream_close(stream);
//}