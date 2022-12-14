//
// Created by shivaaz on 12/11/22.
//

#include <complex>
#include "AAudioRenderer.h"

#define TWO_PI 6.28

aaudio_data_callback_result_t dataCallback(AAudioStream *stream,void *audioData,int32_t numFrames)
{
    static float phase = 0;
    float *audio = (float *) audioData;

    for (int i = 0; i < numFrames * 2; i += 2)
    {

        phase += TWO_PI * 440.0 / 44100;
        if (phase > TWO_PI)
            phase -= TWO_PI;
        audio[i] = INT16_MAX * sin(phase);
        audio[i + 1] = audio[i];
    }

    return AAUDIO_OK;

}

void errorCallback(AAudioStream *stream,
                                    aaudio_result_t error){



    aaudio_stream_state_t streamState = AAudioStream_getState(stream);//Stream might be different?
    if (streamState == AAUDIO_STREAM_STATE_DISCONNECTED){

        // Handle stream restart on a separate thread
    }
}
int AAudioRenderer::prepare()
{
    AAudioStreamBuilder *builder = nullptr;
    aaudio_result_t result = AAudio_createStreamBuilder(&builder);
    if (result != AAUDIO_OK) {
       // LOGE("Error creating stream builder: %s", AAudio_convertResultToText(result));
    }

    AAudioStreamBuilder_setDeviceId(builder, 0);
    AAudioStreamBuilder_setFormat(builder, AAUDIO_FORMAT_PCM_FLOAT);
    AAudioStreamBuilder_setChannelCount(builder, 2);

    // We request EXCLUSIVE mode since this will give us the lowest possible latency.
    // If EXCLUSIVE mode isn't available the builder will fall back to SHARED mode.
    AAudioStreamBuilder_setSharingMode(builder, AAUDIO_SHARING_MODE_EXCLUSIVE);
    AAudioStreamBuilder_setPerformanceMode(builder, AAUDIO_PERFORMANCE_MODE_LOW_LATENCY);
    AAudioStreamBuilder_setDirection(builder, AAUDIO_DIRECTION_OUTPUT);
    AAudioStreamBuilder_setDataCallback(builder,
                                        reinterpret_cast<AAudioStream_dataCallback>(dataCallback), this);
    AAudioStreamBuilder_setErrorCallback(builder,
                                         reinterpret_cast<AAudioStream_errorCallback>(errorCallback), this);

     result = AAudioStreamBuilder_openStream(builder, &mStream);

    if (result == AAUDIO_OK && mStream != nullptr) {

        // check that we got PCM_FLOAT format
        if (AAudioStream_getFormat(mStream) != 44100) {
            // LOGW("Sample format is not PCM_FLOAT");
        }
    }
       sampleRate = AAudioStream_getSampleRate(mStream);
         framesPerBurse = AAudioStream_getFramesPerBurst(mStream);

        // Set the buffer size to the burst size - this will give us the minimum possible latency
        AAudioStream_setBufferSizeInFrames(mStream, 2*framesPerBurse);
        bufSize =  2 * framesPerBurse;

        AAudioStreamBuilder_delete(builder);

        return 0;
}

int AAudioRenderer::play() {

    AAudioStream_requestStart(mStream);
    return 0;
}

int AAudioRenderer::resume() {

    AAudioStream_requestStart(mStream);

    return 0;
}

int AAudioRenderer::pause() {
    AAudioStream_requestPause(mStream);

    return 0;
}

int AAudioRenderer::stop() {
    AAudioStream_requestFlush(mStream);
    AAudioStream_requestStop(mStream);

    return 0;
}

AAudioRenderer::AAudioRenderer() {
 prepare();
}
