
## SISTEM PENGARSIPAN MEDIA DIGITAL

## (Multi Linked List – 3 Level)

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

👉 Ini **Multi Linked List kompleks**, karena:

* Linked list **Tahun**
* Setiap Tahun punya linked list **Kategori**
* Setiap Kategori punya linked list **Media**

---

## STRUKTUR DATA (MLL 3 Level)

### Node Media (Level 3)

* namaMedia
* format
* ukuran
* nextMedia

### Node Kategori (Level 2)

* namaKategori
* firstMedia
* nextKategori

### Node Tahun (Level 1)

* tahun
* firstKategori
* nextTahun

---

## KAMUS DATA (BUAT LAPORAN)

```
type Media:
    namaMedia : string
    format    : string
    ukuran    : integer
    nextMedia : pointer Media

type Kategori:
    namaKategori : string
    firstMedia   : pointer Media
    nextKategori : pointer Kategori

type Tahun:
    tahun         : integer
    firstKategori : pointer Kategori
    nextTahun     : pointer Tahun

type Arsip:
    firstTahun : pointer Tahun
    
```

---

## OPERASI SISTEM

1. Tambah tahun arsip
2. Tambah kategori pada tahun tertentu
3. Tambah media pada kategori & tahun tertentu
4. Tampilkan seluruh arsip bertingkat
5. Cari media berdasarkan tahun & kategori
6. Hitung total ukuran media per kategori

---

## CONTOH PSEUDOCODE (INTI MLL)

```
Inisialisasi Arsip
procedure createArsip(A)
    A.firstTahun ← NULL

Tambah Tahun
procedure tambahTahun(A, th)
    buat node Tahun baru
    node.tahun ← th
    node.firstKategori ← NULL
    node.nextTahun ← NULL

    jika A.firstTahun = NULL
        A.firstTahun ← node
    else
        temp ← A.firstTahun
        selama temp.nextTahun ≠ NULL
            temp ← temp.nextTahun
        temp.nextTahun ← node

Tambah Kategori pada Tahun Tertentu
procedure tambahKategori(A, th, namaKategori)
    cari Tahun dengan nilai th
    jika ditemukan
        buat node Kategori baru
        node.namaKategori ← namaKategori
        node.firstMedia ← NULL
        node.nextKategori ← NULL

        jika Tahun.firstKategori = NULL
            Tahun.firstKategori ← node
        else
            sisipkan di akhir list kategori
    else
        tampilkan "Tahun tidak ditemukan"

Tambah Media
procedure tambahMedia(A, th, namaKategori, namaMedia, format, ukuran)
    cari Tahun
    cari Kategori di Tahun
    jika ditemukan
        buat node Media baru
        isi data media
        sisipkan ke akhir list media
    else
        tampilkan "Data tidak ditemukan"


Tampilkan Arsip
procedure tampilArsip(A)
    tahun ← A.firstTahun
    selama tahun ≠ NULL
        tampilkan tahun
        kategori ← tahun.firstKategori
        selama kategori ≠ NULL
            tampilkan kategori
            media ← kategori.firstMedia
            selama media ≠ NULL
                tampilkan data media
                media ← media.nextMedia
            kategori ← kategori.nextKategori
        tahun ← tahun.nextTahun

```

### Tambah Media (3 Level Traversal)

```
addMedia(A, tahun, kategori, media)
    cari node Tahun
    jika tidak ada → buat Tahun baru

    cari Kategori di Tahun
    jika tidak ada → buat Kategori baru

    tambahkan Media ke linked list Media
```

---

## LANDASAN TEORI

> Sistem ini menggunakan **Multi Linked List bertingkat**, di mana setiap node Tahun memiliki linked list Kategori, dan setiap Kategori memiliki linked list Media. Struktur ini memungkinkan pengelompokan data arsip secara hierarkis dan efisien.

---