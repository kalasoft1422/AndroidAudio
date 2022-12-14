//
// Created by shivaaz on 12/11/22.
//

#ifndef AUDIOLIBTEST_OBOEAUDIORENDERER_H
#define AUDIOLIBTEST_OBOEAUDIORENDERER_H


#include "IPlayer.h"
#include "oboe/Oboe.h"

class OboeAudioRenderer :  public IPlayer,public oboe::AudioStreamCallback{

public:
    OboeAudioRenderer(){prepare();}
    int prepare() override;

    int play() override;

    int resume() override;

    int pause() override;

    int stop() override;

    oboe::DataCallbackResult
    onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames) override;

    bool onError(oboe::AudioStream *stream, oboe::Result result) override;

    void onErrorBeforeClose(oboe::AudioStream *stream, oboe::Result result) override;

    void onErrorAfterClose(oboe::AudioStream *stream, oboe::Result result) override;

private:
    std::shared_ptr<oboe::AudioStream> audioStream;

};


#endif //AUDIOLIBTEST_OBOEAUDIORENDERER_H
