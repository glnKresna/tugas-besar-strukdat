#include "arsip.h"
#include <iostream>

// Inisialisasi
void createArsip(Arsip &A) {
    A.firstTahun = NULL;
}

// Tambah Tahun
void tambahTahun(Arsip &A, int th) {
    Tahun* baru = new Tahun;
    baru->tahun = th;
    baru->firstKategori = NULL;
    baru->nextTahun = NULL;

    if (A.firstTahun == NULL) {
        A.firstTahun = baru;
    } else {
        Tahun* temp = A.firstTahun;
        while (temp->nextTahun != NULL)
            temp = temp->nextTahun;
        temp->nextTahun = baru;
    }
}

// Cari Tahun
Tahun* cariTahun(Arsip A, int th) {
    Tahun* temp = A.firstTahun;
    while (temp != NULL) {
        if (temp->tahun == th)
            return temp;
        temp = temp->nextTahun;
    }
    return NULL;
}

// Cari Kategori
Kategori* cariKategori(Tahun* T, string namaKategori) {
    Kategori* temp = T->firstKategori;
    while (temp != NULL) {
        if (temp->namaKategori == namaKategori)
            return temp;
        temp = temp->nextKategori;
    }
    return NULL;
}

// Tambah Kategori
void tambahKategori(Arsip &A, int th, string namaKategori) {
    Tahun* T = cariTahun(A, th);
    if (T == NULL) return;

    Kategori* baru = new Kategori;
    baru->namaKategori = namaKategori;
    baru->firstMedia = NULL;
    baru->nextKategori = NULL;

    if (T->firstKategori == NULL) {
        T->firstKategori = baru;
    } else {
        Kategori* temp = T->firstKategori;
        while (temp->nextKategori != NULL)
            temp = temp->nextKategori;
        temp->nextKategori = baru;
    }
}

// Tambah Media
void tambahMedia(Arsip &A, int th, string namaKategori,
                 string namaMedia, string format, int ukuran) {
    Tahun* T = cariTahun(A, th);
    if (T == NULL) return;

    Kategori* K = cariKategori(T, namaKategori);
    if (K == NULL) return;

    Media* baru = new Media;
    baru->namaMedia = namaMedia;
    baru->format = format;
    baru->ukuran = ukuran;
    baru->nextMedia = NULL;

    if (K->firstMedia == NULL) {
        K->firstMedia = baru;
    } else {
        Media* temp = K->firstMedia;
        while (temp->nextMedia != NULL)
            temp = temp->nextMedia;
        temp->nextMedia = baru;
    }
}

// Tampilkan Arsip
void tampilArsip(Arsip A) {
    Tahun* T = A.firstTahun;
    while (T != NULL) {
        cout << "Tahun: " << T->tahun << endl;
        Kategori* K = T->firstKategori;
        while (K != NULL) {
            cout << "  Kategori: " << K->namaKategori << endl;
            Media* M = K->firstMedia;
            while (M != NULL) {
                cout << "    - " << M->namaMedia
                     << " | " << M->format
                     << " | " << M->ukuran << " MB" << endl;
                M = M->nextMedia;
            }
            K = K->nextKategori;
        }
        cout << endl;
        T = T->nextTahun;
    }
}
