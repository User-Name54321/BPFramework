#pragma once
#include <SDL3_mixer/SDL_mixer.h>
#include "events.h"
#include <deque>
#include <string>
#include <map>
#include <tuple>

namespace BPF {
	class AudioPlayer {
	private:
		short int trackCnt;

		MIX_Mixer* device; // might want to make a vector or smtn to hold more?
		std::vector<MIX_Track*> sfxTracks; 
		std::unordered_map<short int, short int> freeTracks; //1st  = index, 2nd = audio id | -1 means free

		std::unordered_map<short int, MIX_Audio*> audioList; 

	public:
		void init(short int tracks = 2); // Initialize audio subsystem, input number of sfx tracks to be made - max amount of sounds to be played at once
		void loadAudio(short int ID, std::string imgPath, bool compress); // pass in whatever id, path of iamge, if you want to decompress audio when  laionmgsasffawfsa
		int playAudio(short int ID, bool override); // pass in sound id and whether or not you wish to override existing sounds with that id
		
		void quit();
	};
}