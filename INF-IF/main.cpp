#include <iostream>
#include "arsip.h"

using namespace std;

int main() {
    Arsip A;
    createArsip(A);

    // Data contoh
    tambahTahun(A, 2023);
    tambahTahun(A, 2024);

    tambahKategori(A, 2023, "Foto");
    tambahKategori(A, 2023, "Video");
    tambahKategori(A, 2024, "Dokumen");

    tambahMedia(A, 2023, "Foto", "pantai.jpg", "JPG", 2);
    tambahMedia(A, 2023, "Foto", "gunung.png", "PNG", 3);
    tambahMedia(A, 2023, "Video", "liburan.mp4", "MP4", 150);
    tambahMedia(A, 2024, "Dokumen", "laporan.pdf", "PDF", 5);

    tampilArsip(A);

    return 0;
}
