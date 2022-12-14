//
// Created by shivaaz on 12/11/22.
//

#include "OboeAudioRenderer.h"
using namespace oboe;
int OboeAudioRenderer::prepare()
{
    AudioStreamBuilder builder;
    builder.setCallback(this);
    builder.setSampleRate(44100);
    builder.setFormat(AudioFormat::Float);
    builder.setContentType(ContentType::Music);
    builder.setPerformanceMode(PerformanceMode::LowLatency);
    builder.setSharingMode(SharingMode::Exclusive);
    builder.setChannelCount(2);
    builder.setFramesPerCallback(1024);
    Result result = builder.openStream(audioStream);
    if (result != Result::OK)
    {
       // Log::error(TAG,"THE STREAM COULD NOT BE CREATES");
        return -1;
    }
       auto bufferSizeResult = audioStream->setBufferSizeInFrames(1024*2);//buffersize result twice so that glitch does not occur even if we miss onec callback in time

    return 0;
}

int OboeAudioRenderer::play() {
    audioStream->requestStart();
    return 0;
}

int OboeAudioRenderer::resume() {
    audioStream->requestStart();
    return 0;
}

int OboeAudioRenderer::pause() {
    audioStream->requestPause();
    return 0;
}

int OboeAudioRenderer::stop() {
    audioStream->requestStop();
    return 0;
}
#define TWO_PI 6.28

oboe::DataCallbackResult
OboeAudioRenderer::onAudioReady(oboe::AudioStream *audioStream, void *audioData,
                                int32_t numFrames){

    static float phase = 0;
    float *audio = (float *) audioData;
    for (int i = 0; i < numFrames * 2; i += 2) {

        phase += TWO_PI * 440.0 / 44100;
        if (phase > TWO_PI)
            phase -= TWO_PI;
        audio[i] =   sin(phase);
        audio[i + 1] = audio[i];
    }

    return oboe::DataCallbackResult::Continue;
}

bool OboeAudioRenderer::onError(oboe::AudioStream *stream, oboe::Result result) {
    return AudioStreamErrorCallback::onError(stream, result);
}

void OboeAudioRenderer::onErrorAfterClose(oboe::AudioStream *stream, oboe::Result result) {
    AudioStreamErrorCallback::onErrorAfterClose(stream, result);
}

void OboeAudioRenderer::onErrorBeforeClose(oboe::AudioStream *stream, oboe::Result result) {
    AudioStreamErrorCallback::onErrorBeforeClose(stream, result);
}

