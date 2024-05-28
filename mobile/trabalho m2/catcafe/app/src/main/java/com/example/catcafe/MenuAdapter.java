package com.example.catcafe;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class MenuAdapter extends RecyclerView.Adapter<MenuAdapter.MenuViewHolder> {

    private List<MenuItem> menuItems;
    private boolean isOffline;

    public static class MenuViewHolder extends RecyclerView.ViewHolder {
        public ImageView imageView;
        public TextView nameTextView;
        public TextView priceTextView;

        public MenuViewHolder(View view) {
            super(view);
            imageView = view.findViewById(R.id.imageView);
            nameTextView = view.findViewById(R.id.nameTextView);
            priceTextView = view.findViewById(R.id.priceTextView);
        }
    }

    public MenuAdapter(List<MenuItem> menuItems, boolean isOffline) {
        this.menuItems = menuItems;
        this.isOffline = isOffline;
    }

    @NonNull
    @Override
    public MenuViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.menu_item, parent, false);
        return new MenuViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(@NonNull MenuViewHolder holder, int position) {
        MenuItem currentItem = menuItems.get(position);
        holder.imageView.setImageResource(currentItem.getImageDrawable());
        holder.nameTextView.setText(currentItem.getName());
        if (isOffline) {
            holder.priceTextView.setText("a consultar");
        } else {
            holder.priceTextView.setText(String.format("$%.2f", currentItem.getPrice()));
        }
    }

    @Override
    public int getItemCount() {
        return menuItems.size();
    }
}
