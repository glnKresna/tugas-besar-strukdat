#ifndef ARSIP_H
#define ARSIP_H

#include <string>
using namespace std;

// ===== Media =====
struct Media {
    string namaMedia;
    string format;
    int ukuran;
    Media* nextMedia;
};

// ===== Kategori =====
struct Kategori {
    string namaKategori;
    Media* firstMedia;
    Kategori* nextKategori;
};

// ===== Tahun =====
struct Tahun {
    int tahun;
    Kategori* firstKategori;
    Tahun* nextTahun;
};

// ===== Arsip =====
struct Arsip {
    Tahun* firstTahun;
};

// ===== Prototype =====
void createArsip(Arsip &A);
void tambahTahun(Arsip &A, int th);
Tahun* cariTahun(Arsip A, int th);
Kategori* cariKategori(Tahun* T, string namaKategori);
void tambahKategori(Arsip &A, int th, string namaKategori);
void tambahMedia(Arsip &A, int th, string namaKategori,
                 string namaMedia, string format, int ukuran);
void tampilArsip(Arsip A);

#endif
