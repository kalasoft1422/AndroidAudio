//
// Created by shivaaz on 12/13/22.
//

#ifndef AUDIOLIBTEST_AUDIOTRACKRENDERER_H
#define AUDIOLIBTEST_AUDIOTRACKRENDERER_H

#include "AudioTrackRenderer.h"
#include "IPlayer.h"
#include "atomic"
class AudioTrackRenderer : IPlayer{

public:
    AudioTrackRenderer(){prepare();}
    int prepare() override;

    int play() override;

    int resume() override;

    int pause() override;

    int stop() override;

public:

 jobject audioTrack;
 jmethodID writeMID,playMID,pauseMID,stopMID;

 std::atomic<bool> paused {true};
};


#endif //AUDIOLIBTEST_AUDIOTRACKRENDERER_H
