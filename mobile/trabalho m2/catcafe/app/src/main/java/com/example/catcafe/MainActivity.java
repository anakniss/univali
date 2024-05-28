package com.example.catcafe;

import static com.example.catcafe.GeneralMethods.isNetworkAvailable;
import static com.example.catcafe.GeneralMethods.loadJSONFromAsset;

import android.content.res.Resources;
import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private MenuAdapter menuAdapter;
    private List<MenuItem> menuItems;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        recyclerView = findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        try {
            File context = this.getApplicationContext().getFilesDir();
            JSONObject obj = new JSONObject(loadJSONFromAsset(context));
            JSONArray array = obj.getJSONArray("items");
            menuItems = new ArrayList<>();

            for(int i = 0; i < array.length(); i++){
                JSONObject inside = array.getJSONObject(i);
                String name = inside.getString("name");
                double price = inside.getDouble("price");
                String image = inside.getString("image");
                //Drawable imageDrawable = Drawable.createFromStream(getAssets().open(image), null);
                Resources resources = getApplicationContext().getResources();
                final int resourceId = resources.getIdentifier(image, "drawable",
                        getApplicationContext().getPackageName());
                menuItems.add(new MenuItem(name, price, image, resourceId));
            }
        } catch (JSONException e){
            e.printStackTrace();
        }

        menuAdapter = new MenuAdapter(menuItems);
        recyclerView.setAdapter(menuAdapter);
    }
}
