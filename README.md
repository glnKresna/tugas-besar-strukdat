# 📚 Tugas Struktur Data

## Implementasi Multi Linked List (MLL)

### 🧾 Deskripsi Singkat

Program ini merupakan implementasi **Multi Linked List (MLL)** sebagai bagian dari tugas mata kuliah **Struktur Data**. Multi Linked List digunakan untuk merepresentasikan data yang memiliki **lebih dari satu hubungan** antar node, sehingga cocok untuk sistem pengarsipan atau relasi data yang kompleks.

Pada program ini, setiap data utama dapat terhubung dengan beberapa data lain melalui linked list tambahan, sehingga membentuk struktur data bertingkat dan saling terhubung.

---

### 🎯 Tujuan

Tujuan pembuatan program ini adalah:

1. Memahami konsep **Multi Linked List**
2. Menerapkan **ADT (Abstract Data Type)** dalam bahasa C++
3. Mengelola data dengan **relasi satu ke banyak**
4. Melatih pemisahan program ke dalam file **`.h`**, **`.cpp`**, dan **`main.cpp`**

---

### 🧩 Konsep Multi Linked List

Multi Linked List adalah pengembangan dari linked list biasa, di mana:

* Satu node utama dapat memiliki **lebih dari satu pointer**
* Digunakan untuk menyimpan data yang memiliki **relasi kompleks**
* Contoh penerapan:

  * Sistem pengarsipan
  * Data mahasiswa & mata kuliah
  * Media dan kategori

---

### 🗂️ Struktur File

Program ini terdiri dari beberapa file utama:

## Konsep Besar

Struktur arsip dibuat **bertingkat**:

```
Tahun
 └── Kategori
      └── Media
```

### Contoh

```
2023
 ├── Foto
 │    ├── pantai.jpg
 │    └── gunung.png
 └── Video
      └── liburan.mp4

2024
 └── Dokumen
      └── laporan.pdf
```

---

### ⚙️ Fitur Program

Fitur-fitur yang tersedia dalam program ini antara lain:

* Menambahkan data utama
* Menambahkan data relasi (anak)
* Menampilkan seluruh data beserta relasinya
* Menghapus data tertentu
* Pencarian data berdasarkan kriteria tertentu

---

### 🛠️ Bahasa & Tools

* **Bahasa Pemrograman** : C++
* **Konsep Struktur Data** : Multi Linked List
* **IDE/Compiler** : VS Code

---

### ▶️ Cara Menjalankan Program

1. Pastikan seluruh file (`main.cpp`, `.h`, `.cpp`) berada dalam satu folder
2. Compile program menggunakan compiler C++
3. Jalankan file hasil kompilasi
4. Gunakan menu yang tersedia untuk mengelola data

---

### 📌 Kesimpulan

Dengan menggunakan Multi Linked List, program ini mampu mengelola data yang memiliki hubungan kompleks secara terstruktur dan efisien. Implementasi ini membantu memahami bagaimana struktur data lanjutan bekerja serta bagaimana mengelola relasi data dalam pemrograman C++.

