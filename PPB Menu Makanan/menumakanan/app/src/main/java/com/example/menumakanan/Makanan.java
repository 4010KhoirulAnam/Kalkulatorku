package com.example.menumakanan;

public class Makanan {

    private String nama;
    private Integer harga, gambar;

    public Makanan(String nama, Integer harga, Integer gambar) {
        this.nama = nama;
        this.harga = harga;
        this.gambar = gambar;
    }

    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public Integer getHarga() {
        return harga;
    }

    public void setHarga(Integer harga) {
        this.harga = harga;
    }

    public Integer getGambar() {
        return gambar;
    }

    public void setGambar(Integer gambar) {
        this.gambar = gambar;
    }
}
