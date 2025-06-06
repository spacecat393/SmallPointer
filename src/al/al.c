static ALCdevice *alcdevice_p = NULL;
static ALCcontext *alccontext_p = NULL;

static ALuint buffer, source;

void al_set()
{
	NALI_D_LOG("run_initAL")

	NALI_D_INFO("alcOpenDevice %p", alcdevice_p = alcOpenDevice(NULL))

	NALI_D_LOG("ALC_DEVICE_SPECIFIER %s", alcGetString(alcdevice_p, ALC_DEVICE_SPECIFIER))

	NALI_D_INFO("alcCreateContext %p", alccontext_p = alcCreateContext(alcdevice_p, NULL))

	NALI_D_INFO("alcMakeContextCurrent %d", alcMakeContextCurrent(alccontext_p))

	NALI_D_INFO_A("alcGetError %d", alcGetError(alcdevice_p))

	int sample_rate, nb_channels;
	ffmpeg_read(NALI_F_HOME_SOUND_BGM);

	uint32_t data_bl;
	uint8_t *data_p = ffmpeg_ogg(&sample_rate, &nb_channels, &data_bl);
	ffmpeg_free();

	NALI_D_LOG("nb_channels %d", nb_channels)
	ALenum format;
	if (nb_channels == 1)
		format = AL_FORMAT_MONO16;
	else if (nb_channels == 2)
		format = AL_FORMAT_STEREO16;

	alGenBuffers(1, &buffer);
	alGenSources(1, &source);

	alBufferData(buffer, format, data_p, data_bl, sample_rate);

	alSourcei(source, AL_BUFFER, buffer);
	alSourcei(source, AL_LOOPING, AL_TRUE);
	alSourcef(source, AL_GAIN, 1.0F);

	alSourcePlay(source);
}

void al_clean()
{
	alSourceStop(source);

	alDeleteSources(1, &source);
	alDeleteBuffers(1, &buffer);

	alcMakeContextCurrent(NULL);
	alcDestroyContext(alccontext_p);
	alccontext_p = NULL;
	alcCloseDevice(alcdevice_p);
	alcdevice_p = NULL;
}