package com.example.menumakanan;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    RecyclerView rMakanan;
    RecyclerView.Adapter adapter;
    RecyclerView.LayoutManager layoutManager;
    ArrayList<Makanan> listMakanan;

    void dataDummy(){
        listMakanan = new ArrayList<>();
        listMakanan.add(new Makanan("bakso",10000, R.drawable.bakso));
        listMakanan.add(new Makanan("mie ayam",8000, R.drawable.miayam));
        listMakanan.add(new Makanan("pecel",5000, R.drawable.pecel));
    }

    void data(){
        rMakanan = findViewById(R.id.rec_menu);
        adapter = new Adapter(this, listMakanan);
        layoutManager = new LinearLayoutManager(this);
        rMakanan.setLayoutManager(layoutManager);
        rMakanan.setAdapter(adapter);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        dataDummy();
        data();
    }
}