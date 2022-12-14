//
// Created by shivaaz on 12/11/22.
//

#ifndef AUDIOLIBTEST_AAUDIORENDERER_H
#define AUDIOLIBTEST_AAUDIORENDERER_H

#include "IPlayer.h"
#include <aaudio/AAudio.h>

class AAudioRenderer : IPlayer{

public:

    AAudioRenderer();

    virtual int prepare();

    virtual int play();

    virtual int resume();

    virtual int pause();

    virtual int stop();


private:
    AAudioStream *mStream;
    int sampleRate;
    int framesPerBurse;
    int bufSize;


};


#endif //AUDIOLIBTEST_AAUDIORENDERER_H
