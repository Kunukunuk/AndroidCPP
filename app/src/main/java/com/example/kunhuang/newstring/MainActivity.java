package com.example.kunhuang.newstring;

import android.content.Context;
import android.content.res.AssetManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private native String stringFromJNI(AssetManager mana);
    ArrayList<String> words = new ArrayList<String>();
    Button getStringButton;
    private AssetManager aManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        //tv.setText(stringFromJNI());

        final ListAdapter adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, words);
        ListView list = (ListView) findViewById(R.id.listView);
        list.setAdapter(adapter);

        aManager = getResources().getAssets();

        getStringButton = (Button) findViewById(R.id.getsringbutton);
        getStringButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String word = stringFromJNI(aManager);
                words.add(word);

                ((ArrayAdapter) adapter).notifyDataSetChanged();

            }
        });

    }

}
