#ifndef BSTFILM_H
#define BSTFILM_H

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct filmData {
    string judul;
    string genre;
    int tahunTayang;
    float rating;

    filmData* left;
    filmData* right;
};

struct BSTFilm {
    filmData* root;
};

void initBST(BSTFilm &T);

filmData* createNode(
    string judul,
    string genre,
    int tahunTayang,
    float rating
);

void insertFilm(BSTFilm &T, filmData* newNode);
string toLowerCase(string s);
filmData* searchByJudul(filmData* root, string judul);
filmData* deleteByJudul(filmData* root, string judul);

void inorder(filmData* root);
void preorder(filmData* root);
void postorder(filmData* root);

void searchByRating(filmData* root, float rating);
void searchByGenre(filmData* root, string genre);

#endif
