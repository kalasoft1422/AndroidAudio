package com.shiva1422.myapplication;

import android.util.Log;

public class AudioPlayer {
   private long ptr = 0;
   private boolean bPlaying = false;

   static{
       System.loadLibrary("myapplication");
   }


    AudioPlayer()
    {
        ptr = createPlayerNative();
      }

    int play()
    {
        int res = 0;
        if(!bPlaying)
        {
            bPlaying = true;
            res = playNative(ptr);
        }
        else
            Log.w("AudioPlayer.java","alreadyPlaying");
        return res;
    }

    int pause()
    {
        int res = 0;
        if(bPlaying)
        {
            bPlaying = false;
            res = pauseNative(ptr);
        }
        else
            Log.w("AudioPlayer.java","already paused");
        return res;
    }
    int resume()
    {
        return resumeNative(ptr);
    }
    int stop()
    {
        return stopNative(ptr);
    }


    public boolean isPlaying(){return bPlaying;}



    private native long createPlayerNative();
    private native int playNative(long ptr);
    private native int pauseNative(long ptr);
    private native int resumeNative(long ptr);
    private native int stopNative(long ptr);


}
