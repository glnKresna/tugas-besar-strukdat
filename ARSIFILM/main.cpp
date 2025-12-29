#include "BSTFilm.h"

int main() {
    BSTFilm filmBST;
    initBST(filmBST);

    int pilihan;
    string judul, genre;
    int tahun, durasi;
    float rating;

    do {
        cout << "\n===== SISTEM ARSIP FILM (BST) =====\n";
        cout << "1. Tambah Data Film\n";
        cout << "2. Cari Film (Judul)\n";
        cout << "3. Hapus Film\n";
        cout << "4. Tampilkan Semua Film (A - Z)\n";
        cout << "5. Cari Film Berdasarkan Rating\n";
        cout << "6. Cari Film Berdasarkan Tahun\n";
        cout << "7. Jumlah Film\n";
        cout << "8. Film Rating Tertinggi\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            cout << "Judul Film   : ";
            getline(cin, judul);
            cout << "Genre        : ";
            getline(cin, genre);
            cout << "Tahun Tayang : ";
            cin >> tahun;
            cout << "Durasi (mnt) : ";
            cin >> durasi;
            cout << "Rating       : ";
            cin >> rating;

            insertFilm(filmBST, createNode(judul, genre, tahun, durasi, rating));
            cout << "Film berhasil ditambahkan!\n";
            break;

        case 2:
            cout << "Masukkan judul film: ";
            getline(cin, judul);
            {
                filmData* hasil = searchByJudul(filmBST.root, judul);
                if (hasil != NULL) {
                    cout << "Film ditemukan!\n";
                    cout << "Judul  : " << hasil->judul << endl;
                    cout << "Rating : " << hasil->rating << endl;
                } else {
                    cout << "Film tidak ditemukan.\n";
                }
            }
            break;

        case 3:
            cout << "Judul film yang dihapus: ";
            getline(cin, judul);
            filmBST.root = deleteByJudul(filmBST.root, judul);
            cout << "Data film diproses.\n";
            break;

        case 4:
            inorder(filmBST.root);
            break;

        case 5:
            cout << "Minimal rating: ";
            cin >> rating;
            searchByRating(filmBST.root, rating);
            break;

        case 6:
            cout << "Tahun tayang: ";
            cin >> tahun;
            searchByTahun(filmBST.root, tahun);
            break;

        case 7:
            cout << "Jumlah film: " << countFilm(filmBST.root) << endl;
            break;

        case 8:
            {
                filmData* best = findHighestRating(filmBST.root);
                if (best != NULL) {
                    cout << "Film Rating Tertinggi:\n";
                    cout << best->judul << " (" << best->rating << ")\n";
                }
            }
            break;
        }
    } while (pilihan != 0);

    return 0;
}
