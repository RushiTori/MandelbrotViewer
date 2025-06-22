%ifndef RAUDIO_INC
%define RAUDIO_INC

; Audio device management functions

	; Initialize audio device and context
	; void InitAudioDevice(void);
	extern InitAudioDevice

	; Close the audio device and context
	; void CloseAudioDevice(void);
	extern CloseAudioDevice

	; Check if audio device has been initialized successfully
	; bool IsAudioDeviceReady(void);
	extern IsAudioDeviceReady

	; Set master volume (listener)
	; void SetMasterVolume(float volume);
	extern SetMasterVolume

	; Get master volume (listener)
	; float GetMasterVolume(void);
	extern GetMasterVolume

; Wave/Sound loading/unloading functions

	; Load wave data from file
	; Wave LoadWave(const char* fileName);
	extern LoadWave

	; Load wave from memory buffer, fileType refers to extension: i.e. '.wav'
	; Wave LoadWaveFromMemory(const char* fileType, const unsigned char* fileData, int dataSize);
	extern LoadWaveFromMemory

	; Checks if wave data is valid (data loaded and parameters)
	; bool IsWaveValid(Wave wave);
	extern IsWaveValid

	; Load sound from file
	; Sound LoadSound(const char* fileName);
	extern LoadSound

	; Load sound from wave data
	; Sound LoadSoundFromWave(Wave wave);
	extern LoadSoundFromWave

	; Create a new sound that shares the same sample data as the source sound, does not own the sound data
	; Sound LoadSoundAlias(Sound source);
	extern LoadSoundAlias

	; Checks if a sound is valid (data loaded and buffers initialized)
	; bool IsSoundValid(Sound sound);
	extern IsSoundValid

	; Update sound buffer with new data
	; void UpdateSound(Sound sound, const void* data, int sampleCount);
	extern UpdateSound

	; Unload wave data
	; void UnloadWave(Wave wave);
	extern UnloadWave

	; Unload sound
	; void UnloadSound(Sound sound);
	extern UnloadSound

	; Unload a sound alias (does not deallocate sample data)
	; void UnloadSoundAlias(Sound alias);
	extern UnloadSoundAlias

	; Export wave data to file, returns true on success
	; bool ExportWave(Wave wave, const char* fileName);
	extern ExportWave

	; Export wave sample data to code (.h), returns true on success
	; bool ExportWaveAsCode(Wave wave, const char* fileName);
	extern ExportWaveAsCode

; Wave/Sound management functions

	; Play a sound
	; void PlaySound(Sound sound);
	extern PlaySound

	; Stop playing a sound
	; void StopSound(Sound sound);
	extern StopSound

	; Pause a sound
	; void PauseSound(Sound sound);
	extern PauseSound

	; Resume a paused sound
	; void ResumeSound(Sound sound);
	extern ResumeSound

	; Check if a sound is currently playing
	; bool IsSoundPlaying(Sound sound);
	extern IsSoundPlaying

	; Set volume for a sound (1.0 is max level)
	; void SetSoundVolume(Sound sound, float volume);
	extern SetSoundVolume

	; Set pitch for a sound (1.0 is base level)
	; void SetSoundPitch(Sound sound, float pitch);
	extern SetSoundPitch

	; Set pan for a sound (0.5 is center)
	; void SetSoundPan(Sound sound, float pan);
	extern SetSoundPan

	; Copy a wave to a new wave
	; Wave WaveCopy(Wave wave);
	extern WaveCopy

	; Crop a wave to defined frames range
	; void WaveCrop(Wave* wave, int initFrame, int finalFrame);
	extern WaveCrop

	; Convert wave data to desired format
	; void WaveFormat(Wave* wave, int sampleRate, int sampleSize, int channels);
	extern WaveFormat

	; Load samples data from wave as a 32bit float data array
	; float* LoadWaveSamples(Wave wave);
	extern LoadWaveSamples

	; Unload samples data loaded with LoadWaveSamples()
	; void UnloadWaveSamples(float* samples);
	extern UnloadWaveSamples

; Music management functions

	; Load music stream from file
	; Music LoadMusicStream(const char* fileName);
	extern LoadMusicStream

	; Load music stream from data
	; Music LoadMusicStreamFromMemory(const char* fileType, const unsigned char* data, int dataSize);
	extern LoadMusicStreamFromMemory

	; Checks if a music stream is valid (context and buffers initialized)
	; bool IsMusicValid(Music music);
	extern IsMusicValid

	; Unload music stream
	; void UnloadMusicStream(Music music);
	extern UnloadMusicStream

	; Start music playing
	; void PlayMusicStream(Music music);
	extern PlayMusicStream

	; Check if music is playing
	; bool IsMusicStreamPlaying(Music music);
	extern IsMusicStreamPlaying

	; Updates buffers for music streaming
	; void UpdateMusicStream(Music music);
	extern UpdateMusicStream

	; Stop music playing
	; void StopMusicStream(Music music);
	extern StopMusicStream

	; Pause music playing
	; void PauseMusicStream(Music music);
	extern PauseMusicStream

	; Resume playing paused music
	; void ResumeMusicStream(Music music);
	extern ResumeMusicStream

	; Seek music to a position (in seconds)
	; void SeekMusicStream(Music music, float position);
	extern SeekMusicStream

	; Set volume for music (1.0 is max level)
	; void SetMusicVolume(Music music, float volume);
	extern SetMusicVolume

	; Set pitch for a music (1.0 is base level)
	; void SetMusicPitch(Music music, float pitch);
	extern SetMusicPitch

	; Set pan for a music (0.5 is center)
	; void SetMusicPan(Music music, float pan);
	extern SetMusicPan

	; Get music time length (in seconds)
	; float GetMusicTimeLength(Music music);
	extern GetMusicTimeLength

	; Get current music time played (in seconds)
	; float GetMusicTimePlayed(Music music);
	extern GetMusicTimePlayed

; AudioStream management functions

	; Load audio stream (to stream raw audio pcm data)
	; AudioStream LoadAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels);
	extern LoadAudioStream

	; Checks if an audio stream is valid (buffers initialized)
	; bool IsAudioStreamValid(AudioStream stream);
	extern IsAudioStreamValid

	; Unload audio stream and free memory
	; void UnloadAudioStream(AudioStream stream);
	extern UnloadAudioStream

	; Update audio stream buffers with data
	; void UpdateAudioStream(AudioStream stream, const void* data, int frameCount);
	extern UpdateAudioStream

	; Check if any audio stream buffers requires refill
	; bool IsAudioStreamProcessed(AudioStream stream);
	extern IsAudioStreamProcessed

	; Play audio stream
	; void PlayAudioStream(AudioStream stream);
	extern PlayAudioStream

	; Pause audio stream
	; void PauseAudioStream(AudioStream stream);
	extern PauseAudioStream

	; Resume audio stream
	; void ResumeAudioStream(AudioStream stream);
	extern ResumeAudioStream

	; Check if audio stream is playing
	; bool IsAudioStreamPlaying(AudioStream stream);
	extern IsAudioStreamPlaying

	; Stop audio stream
	; void StopAudioStream(AudioStream stream);
	extern StopAudioStream

	; Set volume for audio stream (1.0 is max level)
	; void SetAudioStreamVolume(AudioStream stream, float volume);
	extern SetAudioStreamVolume

	; Set pitch for audio stream (1.0 is base level)
	; void SetAudioStreamPitch(AudioStream stream, float pitch);
	extern SetAudioStreamPitch

	; Set pan for audio stream (0.5 is centered)
	; void SetAudioStreamPan(AudioStream stream, float pan);
	extern SetAudioStreamPan

	; Default size for new audio streams
	; void SetAudioStreamBufferSizeDefault(int size);
	extern SetAudioStreamBufferSizeDefault

	; Audio thread callback to request new data
	; void SetAudioStreamCallback(AudioStream stream, AudioCallback callback);
	extern SetAudioStreamCallback

	; Attach audio stream processor to stream, receives the samples as 'float'
	; void AttachAudioStreamProcessor(AudioStream stream, AudioCallback processor);
	extern AttachAudioStreamProcessor

	; Detach audio stream processor from stream
	; void DetachAudioStreamProcessor(AudioStream stream, AudioCallback processor);
	extern DetachAudioStreamProcessor

	; Attach audio stream processor to the entire audio pipeline, receives the samples as 'float'
	; void AttachAudioMixedProcessor(AudioCallback processor);
	extern AttachAudioMixedProcessor

	; Detach audio stream processor from the entire audio pipeline
	; void DetachAudioMixedProcessor(AudioCallback processor);
	extern DetachAudioMixedProcessor

%endif ; RAUDIO_INC
