//
// Created by shivaaz on 12/13/22.
//

#include "Player.h"
#include "AudioTrackRenderer.h"
bool Player::bCreated = false;
void *Player::renderer = nullptr;
JNIEnv *IPlayer::env = nullptr;
IPlayer *Player::getInstance() {
    if(!bCreated)
    {
        renderer = new AudioTrackRenderer();
        bCreated = true;
    }




    return static_cast<IPlayer *>(renderer);

}
