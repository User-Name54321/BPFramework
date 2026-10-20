#include "../include/audio.h"
#include <iostream>

namespace BPF {

	void AudioPlayer::init(short int tracks)
	{
		trackCnt = tracks;
		MIX_Init();
		device = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);

		for (short int i = 0; i < tracks; i++) {
			sfxTracks.push_back(MIX_CreateTrack(device));
			freeTracks[i] = -1;
		}
	}

	void AudioPlayer::loadAudio(short int ID, std::string imgPath, bool compress) 
	{
		audioList[ID] = MIX_LoadAudio(device, imgPath.c_str(), compress);
		if (!audioList[ID]) {
			std::cout << SDL_GetError() << "\n";
		}

	}

	void AudioPlayer::playAudio(short int ID, bool override)
	{
		if (!audioList.contains(ID)) {
			return;
		}

		if (override) {
			for (short int i = 0; i < freeTracks.size(); i++) {
				if (freeTracks[i] = ID) {
					MIX_PlayTrack(sfxTracks[i], 0);
					return;
				}
			}
		}

		for (short int i = 0; i < freeTracks.size(); i++) { // check if any free tracks
			if (freeTracks[i] != -1) { //by checking if any free keys/indexes exist
				MIX_SetTrackAudio(sfxTracks[i], audioList[ID]);
				MIX_PlayTrack(sfxTracks[i], 0);

				return;
			}
		}
// LOG SMTN

	}


	AudioPlayer::~AudioPlayer()
	{
		for (auto i = audioList.begin(); i != audioList.end(); i++) { //free data?
			
		}
		MIX_Quit();
	}

}