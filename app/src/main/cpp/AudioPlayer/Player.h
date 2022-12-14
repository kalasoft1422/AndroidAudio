//
// Created by shivaaz on 12/13/22.
//

#ifndef AUDIOLIBTEST_PLAYER_H
#define AUDIOLIBTEST_PLAYER_H


#include <jni.h>
#include "IPlayer.h"
class Player {

public:
  static IPlayer *getInstance();

private:
    static void *renderer ;
    static bool bCreated;

};


#endif //AUDIOLIBTEST_PLAYER_H
