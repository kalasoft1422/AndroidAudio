#include <jni.h>

// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("myapplication");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("myapplication")
//      }
//    }
#include "AudioPlayer/Player.h"
extern "C"
JNIEXPORT jlong JNICALL
Java_com_shiva1422_myapplication_AudioPlayer_createPlayerNative(JNIEnv *env, jobject thiz) {
    //
    IPlayer::env = env;
    return reinterpret_cast<jlong>(Player::getInstance());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_shiva1422_myapplication_AudioPlayer_playNative(JNIEnv *env, jobject thiz, jlong ptr) {
    // TODO: implement playNative()
    return ((IPlayer *)ptr)->play();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_shiva1422_myapplication_AudioPlayer_pauseNative(JNIEnv *env, jobject thiz, jlong ptr) {
    // TODO: implement pauseNative()
    return ((IPlayer *)ptr)->pause();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_shiva1422_myapplication_AudioPlayer_resumeNative(JNIEnv *env, jobject thiz, jlong ptr) {
    // TODO: implement resumeNative()
    return ((IPlayer *)ptr)->resume();
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_shiva1422_myapplication_AudioPlayer_stopNative(JNIEnv *env, jobject thiz, jlong ptr) {
    return ((IPlayer *)ptr)->stop();
}