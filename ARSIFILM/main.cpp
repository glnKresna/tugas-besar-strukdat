#include "BSTFilm.h"

int main() {
    BSTFilm filmBST;
    initBST(filmBST);

    insertFilm(filmBST, createNode("Joker", "Drama", 2019, 8.8));
    insertFilm(filmBST, createNode("Avengers Endgame", "Action", 2019, 8.0));
    insertFilm(filmBST, createNode("La La Land", "Romance", 2016, 7.9));
    insertFilm(filmBST, createNode("The Truman Show", "Comedy", 1998, 8.4));
    insertFilm(filmBST, createNode("Interstellar", "Sci-Fi", 2014, 8.6));

    int pilihan;
    string judul, genre;
    int tahun;
    float rating;

    do {
        cout << "\n===== SISTEM ARSIP FILM =====\n";
        cout << "1. Tambah Data Film\n";
        cout << "2. Cari Film (Judul)\n";
        cout << "3. Cari Film (Rating)\n";
        cout << "4. Cari Film (Genre)\n";
        cout << "5. Hapus Film\n";
        cout << "6. Tampilkan Semua Film (A - Z)\n";
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
            cout << "Rating       : ";
            cin >> rating;
            cin.ignore();

            insertFilm(filmBST, createNode(judul, genre, tahun, rating));
            cout << "Film berhasil ditambahkan!\n";
            break;

        case 2:
            cout << "Masukkan judul film: ";
            getline(cin, judul);
            {
                filmData* hasil = searchByJudul(filmBST.root, judul);
                if (hasil != NULL) {
                    cout << "\nFilm ditemukan!\n";
                    cout << "Judul  : " << hasil->judul << endl;
                    cout << "Genre  : " << hasil->genre << endl;
                    cout << "Tahun  : " << hasil->tahunTayang << endl;
                    cout << "Rating : " << hasil->rating << endl;
                } else {
                    cout << "Film tidak ditemukan.\n";
                }
            }
            break;

        case 3:
            float minRating;
            cout << "Masukkan rating: ";
            cin >> minRating;
            searchByRating(filmBST.root, minRating);
            break;

        case 4:
            cout << "Masukkan genre film: ";
            getline(cin, genre);
            searchByGenre(filmBST.root, genre);

            break;

        case 5:
            cout << "Judul film yang dihapus: ";
            getline(cin, judul);
            filmBST.root = deleteByJudul(filmBST.root, judul);
            cout << "Data film dihapus.\n";
            break;

        case 6:
            inorder(filmBST.root);
            break;

        case 0:
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
