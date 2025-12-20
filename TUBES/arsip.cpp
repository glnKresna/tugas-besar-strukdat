#include "arsip.h"
#include <iostream>

// ===== Inisialisasi =====
void createArsip(Arsip &A) {
    A.firstKategori = NULL;
}

// ===== Tambah Kategori =====
void tambahKategori(Arsip &A, string namaKategori) {
    Kategori* baru = new Kategori;
    baru->namaKategori = namaKategori;
    baru->firstMedia = NULL;
    baru->next = NULL;

    if (A.firstKategori == NULL) {
        A.firstKategori = baru;
    } else {
        Kategori* temp = A.firstKategori;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// ===== Cari Kategori =====
Kategori* cariKategori(Arsip A, string namaKategori) {
    Kategori* temp = A.firstKategori;
    while (temp != NULL) {
        if (temp->namaKategori == namaKategori) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// ===== Tambah Media =====
void tambahMedia(Arsip &A, string namaKategori, string namaMedia, string jenis, int ukuran) {
    Kategori* kat = cariKategori(A, namaKategori);

    if (kat == NULL) {
        cout << "Kategori tidak ditemukan\n";
        return;
    }

    Media* baru = new Media;
    baru->namaMedia = namaMedia;
    baru->jenis = jenis;
    baru->ukuran = ukuran;
    baru->next = NULL;

    if (kat->firstMedia == NULL) {
        kat->firstMedia = baru;
    } else {
        Media* temp = kat->firstMedia;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// ===== Tampilkan Arsip =====
void tampilArsip(Arsip A) {
    Kategori* kat = A.firstKategori;
    while (kat != NULL) {
        cout << "Kategori: " << kat->namaKategori << endl;
        Media* med = kat->firstMedia;
        while (med != NULL) {
            cout << "  - " << med->namaMedia
                 << " | " << med->jenis
                 << " | " << med->ukuran << " MB" << endl;
            med = med->next;
        }
        cout << endl;
        kat = kat->next;
    }
}
