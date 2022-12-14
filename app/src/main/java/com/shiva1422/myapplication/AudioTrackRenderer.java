package com.shiva1422.myapplication;

import static java.lang.Math.sin;

import android.media.AudioAttributes;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.util.Log;

import java.util.concurrent.atomic.AtomicBoolean;

public class AudioTrackRenderer implements Runnable
{
    private AudioTrack audioTrack = null;
  int sampleRate = 44100;
  int channelCnt =2;
  AtomicBoolean paused = new AtomicBoolean(false);



  @Override public void run()
  {
      while(true)
      {
          while(!paused.get())
              write();

      }
  }
    AudioTrackRenderer(int sampleRate,int channelCnt)
    {
         audioTrack =  new AudioTrack.Builder()
            .setAudioAttributes(new AudioAttributes.Builder()
                    .setUsage(AudioAttributes.USAGE_MEDIA)
                    .build())
            .setAudioFormat(new AudioFormat.Builder()
                    .setEncoding(AudioFormat.ENCODING_PCM_FLOAT)
                    .setSampleRate(44100)
                    .setChannelMask(AudioFormat.CHANNEL_OUT_STEREO)
                    .build())
            .setBufferSizeInBytes(1024)
            .build();
         play();
         run();
    }

    int play()
    {
        Log.i("AudioTrck","resume");
        paused.set(false);
        audioTrack.play();
        return 1;
    }
    int pause()
    {
        paused.set(true);
        audioTrack.pause();
       return 1;
    }
    int  resume()
    {
        paused.set(false);
        Log.i("AudioTrck","resume");
        audioTrack.play();
       return 1;
    }
    int stop()
    {
        paused.set(true);
        audioTrack.stop();
       return 1;
    }

    static float phase = 0.0f;
    final float TWO_PI = (float) 6.28;

    int write()
    {

        float[] audioData = new float[1024*2];

        for (int i = 0; i < 1024 * 2; i += 2) {

            phase += TWO_PI * 440.0 / 44100;
            if (phase > TWO_PI)
                phase -= TWO_PI;
            audioData[i] = (float)  sin(phase);
            audioData[i + 1] = audioData[i];
        }

        audioTrack.write(audioData,0,1024*2,AudioTrack.WRITE_BLOCKING);
        Log.i("AudioTrack","wrote");
        return 1;
    }
}
