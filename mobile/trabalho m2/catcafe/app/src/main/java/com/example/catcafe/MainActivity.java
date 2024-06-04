package com.example.catcafe;

import android.content.ContentValues;
import android.content.Context;
import android.content.res.Resources;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private MenuAdapter menuAdapter;
    private List<MenuItem> menuItems;
    private DatabaseHelper dbHelper;
    private boolean isOffline = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        dbHelper = new DatabaseHelper(this);
        recyclerView = findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        menuItems = new ArrayList<>();

        if (isNetworkAvailable()) {
            try {
                JSONObject obj = new JSONObject(loadJSONFromAsset());
                JSONArray array = obj.getJSONArray("items");

                for (int i = 0; i < array.length(); i++) {
                    JSONObject inside = array.getJSONObject(i);
                    String name = inside.getString("name");
                    double price = inside.getDouble("price");
                    String image = inside.getString("image");

                    saveImageToInternalStorage(image);

                    saveDataToSQLite(name, price, image);

                    Resources resources = getApplicationContext().getResources();
                    final int resourceId = resources.getIdentifier(image, "drawable", getApplicationContext().getPackageName());
                    menuItems.add(new MenuItem(name, price, image, resourceId));
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        } else {
            isOffline = true;
            loadDataFromSQLite();
        }

        menuAdapter = new MenuAdapter(menuItems, isOffline);
        recyclerView.setAdapter(menuAdapter);
    }

    private boolean isNetworkAvailable() {
        ConnectivityManager connectivityManager = (ConnectivityManager) getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo activeNetworkInfo = connectivityManager.getActiveNetworkInfo();
        return activeNetworkInfo != null && activeNetworkInfo.isConnected();
    }

    private void saveImageToInternalStorage(String imageName) {
        try {
            File file = new File(getFilesDir(), imageName + ".png");
            if (!file.exists()) {
                FileOutputStream fos = new FileOutputStream(file);
                FileInputStream fis = new FileInputStream(getAssets().openFd("images/" + imageName + ".png").getFileDescriptor());
                byte[] buffer = new byte[1024];
                int length;
                while ((length = fis.read(buffer)) > 0) {
                    fos.write(buffer, 0, length);
                }
                fis.close();
                fos.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void saveDataToSQLite(String name, double price, String image) {
        SQLiteDatabase db = dbHelper.getWritableDatabase();

        // Verifica se os dados já existem no banco de dados
        Cursor cursor = db.rawQuery("SELECT * FROM " + DatabaseHelper.TABLE_MENU_ITEMS +
                " WHERE " + DatabaseHelper.COLUMN_NAME + " = ? AND " +
                DatabaseHelper.COLUMN_PRICE + " = ? AND " +
                DatabaseHelper.COLUMN_IMAGE + " = ?", new String[]{name, String.valueOf(price), image});

        if (cursor.getCount() == 0) {
            ContentValues values = new ContentValues();
            values.put(DatabaseHelper.COLUMN_NAME, name);
            values.put(DatabaseHelper.COLUMN_PRICE, price);
            values.put(DatabaseHelper.COLUMN_IMAGE, image);
            db.insert(DatabaseHelper.TABLE_MENU_ITEMS, null, values);
        }

        cursor.close();
    }


    private void loadDataFromSQLite() {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        Cursor cursor = db.query(DatabaseHelper.TABLE_MENU_ITEMS, null, null, null, null, null, null);

        while (cursor.moveToNext()) {
            String name = cursor.getString(cursor.getColumnIndexOrThrow(DatabaseHelper.COLUMN_NAME));
            double price = cursor.getDouble(cursor.getColumnIndexOrThrow(DatabaseHelper.COLUMN_PRICE));
            String image = cursor.getString(cursor.getColumnIndexOrThrow(DatabaseHelper.COLUMN_IMAGE));

            // Carrega a imagem do banco de dados (SQLite)
            File file = new File(getFilesDir(), image + ".png");
            if (file.exists()) {
                Resources resources = getApplicationContext().getResources();
                final int resourceId = resources.getIdentifier(image, "drawable", getApplicationContext().getPackageName());
                menuItems.add(new MenuItem(name, price, image, resourceId));
            }
        }
        cursor.close();
    }

    public String loadJSONFromAsset() {
        String json = null;
        File file = new File(this.getApplicationContext().getFilesDir(), "menu.json");
        try {
            FileInputStream fis = new FileInputStream(file);
            DataInputStream din = new DataInputStream(fis);
            byte[] data = new byte[din.available()];
            din.readFully(data);
            json = new String(data);
            din.close();
            fis.close();
        } catch (IOException ex) {
            ex.printStackTrace();
            return null;
        }
        return json;
    }
}
