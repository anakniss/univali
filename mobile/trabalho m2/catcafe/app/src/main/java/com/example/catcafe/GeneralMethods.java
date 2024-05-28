package com.example.catcafe;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class GeneralMethods {
    public static String loadJSONFromAsset(File context) {
        String json = null;
        File file = new File(context, "menu.json");
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

    public static boolean isNetworkAvailable(Context context) {

        ConnectivityManager cm = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);

        NetworkInfo netInfo = cm.getActiveNetworkInfo();

        assert netInfo != null;
        System.out.println("NETWORK INFO: " + netInfo.getSubtypeName());

        return netInfo.isConnectedOrConnecting() && netInfo.isAvailable();
    }
}
