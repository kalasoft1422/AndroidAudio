//
// Created by shivaaz on 12/11/22.
//

#ifndef AUDIOLIBTEST_IPLAYER_H
#define AUDIOLIBTEST_IPLAYER_H


class IPlayer{

public:

    virtual int prepare() = 0;
    virtual int play() = 0;
    virtual int resume() = 0;
    virtual int pause() = 0;
    virtual int stop() = 0;

    static JNIEnv *env;

};
#endif //AUDIOLIBTEST_IPLAYER_H
