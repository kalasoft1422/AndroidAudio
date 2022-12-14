package com.shiva1422.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    AudioPlayer audioPlayer = null;
    Button play,pause,resume, stop;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        audioPlayer = new AudioPlayer();
        play = (Button) findViewById(R.id.play);
        pause = (Button) findViewById(R.id.pause);
        resume = (Button) findViewById(R.id.resume);
        stop = (Button)  findViewById(R.id.stop);

        play.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                audioPlayer.play();
            }
        });


        pause.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                audioPlayer.pause();
            }
        });

        resume.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                audioPlayer.resume();
            }
        });

        stop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                audioPlayer.stop();
            }
        });
    }
}