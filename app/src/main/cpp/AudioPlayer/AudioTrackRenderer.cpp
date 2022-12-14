//
// Created by shivaaz on 12/13/22.
//

#include <jni.h>
#include <cassert>
#include "AudioTrackRenderer.h"
#include "thread"
#include "android/log.h"

int AudioTrackRenderer::prepare()
{
    JNIEnv* env = IPlayer::env;
    jclass audTrackCls = env->FindClass("com/shiva1422/myapplication/AudioTrackRenderer");
    jmethodID constructor = env->GetMethodID(audTrackCls,"<init>","(II)V");
    assert(constructor != nullptr);
    jobject track = env->NewObject(audTrackCls,constructor,44100,2);
    assert(track != nullptr);
    audioTrack = env->NewGlobalRef(track);

    playMID = env->GetMethodID(audTrackCls,"play","()I");
    pauseMID = env->GetMethodID(audTrackCls,"pause","()I");
    stopMID = env->GetMethodID(audTrackCls,"stop","()I");

    writeMID = env->GetMethodID(audTrackCls,"write","()I");

    assert(writeMID != nullptr);

    env->NewGlobalRef(audioTrack);
   // new std::thread(write,this);


    return 0;
}

int AudioTrackRenderer::play() {

    IPlayer::env->CallIntMethod(audioTrack,playMID);
    paused = false;
    return 0;
}

int AudioTrackRenderer::resume() {
    paused = false;
    IPlayer::env->CallIntMethod(audioTrack,playMID);
    return 0;
}

int AudioTrackRenderer::pause() {
    paused = true;
    IPlayer::env->CallIntMethod(audioTrack,pauseMID);
    return 0;
}

int AudioTrackRenderer::stop() {
    paused = true;
    IPlayer::env->CallIntMethod(audioTrack,pauseMID);
    return 0;
}
