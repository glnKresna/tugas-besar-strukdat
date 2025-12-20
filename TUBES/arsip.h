#ifndef ARSIP_H
#define ARSIP_H

#include <string>
using namespace std;

// ===== Struktur Media (Child) =====
struct Media {
    string namaMedia;
    string jenis;
    int ukuran;
    Media* next;
};

// ===== Struktur Kategori (Parent) =====
struct Kategori {
    string namaKategori;
    Media* firstMedia;
    Kategori* next;
};

// ===== Struktur Arsip =====
struct Arsip {
    Kategori* firstKategori;
};

// ===== Prototype Function =====
void createArsip(Arsip &A);
void tambahKategori(Arsip &A, string namaKategori);
Kategori* cariKategori(Arsip A, string namaKategori);
void tambahMedia(Arsip &A, string namaKategori, string namaMedia, string jenis, int ukuran);
void tampilArsip(Arsip A);

#endif
