#include <iostream>
#include "arsip.h"

using namespace std;

int main() {
    Arsip A;
    createArsip(A);

    // Tambah kategori
    tambahKategori(A, "Foto");
    tambahKategori(A, "Video");
    tambahKategori(A, "Dokumen");

    // Tambah media
    tambahMedia(A, "Foto", "pantai.jpg", "JPG", 2);
    tambahMedia(A, "Foto", "gunung.png", "PNG", 3);
    tambahMedia(A, "Video", "liburan.mp4", "MP4", 150);
    tambahMedia(A, "Dokumen", "laporan.pdf", "PDF", 5);

    // Tampilkan arsip
    tampilArsip(A);

    return 0;
}
