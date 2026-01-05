#include "BSTFilm.h"
#include <limits>

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

    while (true) {
        cout << "\n===== SISTEM ARSIP FILM =====\n";
        cout << "1. Tambah Film\n";
        cout << "2. Cari Film (Judul)\n";
        cout << "3. Cari Film (Rating)\n";
        cout << "4. Cari Film (Genre)\n";
        cout << "5. Edit Data Film\n";
        cout << "6. Hapus Film\n";
        cout << "7. Tampilkan Semua Film\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";

        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cout << "\nERROR: Input menu harus berupa ANGKA!\n";
            cin.get();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (pilihan < 0 || pilihan > 7) {
            cout << "\nERROR: Menu tidak tersedia!\n";
        }

        if (pilihan == 0) {
            cout << "\nKeluar dari program.\n";
            break;
        }

        switch (pilihan) {
        case 1: // Tambah Film
            cout << "Judul Film : ";
            getline(cin, judul);

            if (searchByJudul(filmBST.root, judul)) {
                cout << "ERROR: Judul film sudah ada!\n";
                break;
            }

            cout << "Genre      : ";
            getline(cin, genre);

            cout << "Tahun      : ";
            cin >> tahun;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR: Tahun harus angka!\n";
                break;
            }

            cout << "Rating     : ";
            cin >> rating;

            if (cin.fail() || rating < 0 || rating > 10) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR: Rating harus 0 - 10!\n";
                break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            insertFilm(filmBST, createNode(judul, genre, tahun, rating));
            cout << "Film berhasil ditambahkan.\n";
            break;

        case 2: // Cari Judul
            if (filmBST.root == NULL) {
                cout << "\nData film masih kosong.\n";
                break;
            }

            cout << "Masukkan judul film: ";
            getline(cin, judul);

            if (filmData* f = searchByJudul(filmBST.root, judul)) {
                cout << "\nJudul  : " << f->judul
                     << "\nGenre  : " << f->genre
                     << "\nTahun  : " << f->tahunTayang
                     << "\nRating : " << f->rating << endl;
            } else {
                cout << "Film tidak ditemukan.\n";
            }
            break;

        case 3: // Cari Rating
            if (filmBST.root == NULL) {
                cout << "\nData film masih kosong.\n";
                break;
            }

            cout << "Masukkan rating: ";
            cin >> rating;
            cout << "\nFilm dengan rating " << rating << ":\n";
            
            if (rating < 0 || rating > 10) {
                cout << "ERROR: Rating harus 0 - 10!\n";
                break;
            }

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR: Rating harus angka!\n";
                break;
            }

            searchByRating(filmBST.root, rating);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;

        case 4: // Cari Genre
            if (filmBST.root == NULL) {
                cout << "\nData film masih kosong.\n";
                break;
            }

            cout << "Masukkan genre: ";
            getline(cin, genre);
            if (genre.empty()) getline(cin, genre);
            if (adaGenre(filmBST.root, genre) == false) {
                cout << "\nGenre tidak ditemukan dalam data film.\n";
            } else {
                searchByGenre(filmBST.root, genre);
            }
            break;

        case 5: // Edit Film
            if (filmBST.root == NULL) {
                cout << "\nData film masih kosong.\n";
                break;
            }

            cout << "Judul film yang diedit: ";
            getline(cin, judul);

            if (filmData* f = searchByJudul(filmBST.root, judul)) {
                cout << "Judul baru  : ";
                getline(cin, f->judul);

                cout << "Genre baru  : ";
                getline(cin, f->genre);

                cout << "Tahun baru  : ";
                cin >> f->tahunTayang;

                cout << "Rating baru : ";
                cin >> f->rating;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nData film berhasil diperbarui.\n";
            } else {
                cout << "\nFilm tidak ditemukan.\n";
            }
            break;

        case 6: // Hapus Film
            if (filmBST.root == NULL) {
                cout << "\nData film masih kosong.\n";
                break;
            }

            cout << "Judul film yang dihapus: ";
            getline(cin, judul);

            if (searchByJudul(filmBST.root, judul) == NULL) {
                cout << "\nFilm tidak ditemukan.\n";
            } else {
                filmBST.root = deleteByJudul(filmBST.root, judul);
                cout << "\nFilm berhasil dihapus.\n";
            }
            break;

        case 7: // Tampilkan Semua Film
            if (filmBST.root == NULL) {
                cout << "\nData film masih kosong.\n";
            } else {
                inorder(filmBST.root);
            }
            break;
        }
    }

    return 0;
}
