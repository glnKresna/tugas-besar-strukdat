#include "BSTFilm.h"

void initBST(BSTFilm &T) {
    T.root = NULL;
}

filmData* createNode(
    string judul,
    string genre,
    int tahunTayang,
    float rating
) {
    filmData* newNode = new filmData;
    newNode->judul = judul;
    newNode->genre = genre;
    newNode->tahunTayang = tahunTayang;
    newNode->rating = rating;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertFilm(BSTFilm &T, filmData* newNode) {
    if (T.root == NULL) {
        T.root = newNode;
        return;
    }

    filmData* curr = T.root;
    filmData* parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (newNode->judul < curr->judul)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (newNode->judul < parent->judul)
        parent->left = newNode;
    else
        parent->right = newNode;
}

filmData* searchByJudul(filmData* root, string judul) {
    if (root == NULL)
        return NULL;

    string a = toLowerCase(judul);
    string b = toLowerCase(root->judul);

    if (a == b)
        return root;

    return (a < b)
        ? searchByJudul(root->left, judul)
        : searchByJudul(root->right, judul);
}


filmData* findMin(filmData* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

filmData* deleteByJudul(filmData* root, string judul) {
    if (root == NULL)
        return root;

    if (judul < root->judul)
        root->left = deleteByJudul(root->left, judul);
    else if (judul > root->judul)
        root->right = deleteByJudul(root->right, judul);
    else {
        if (root->left == NULL) {
            filmData* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            filmData* temp = root->left;
            delete root;
            return temp;
        }

        filmData* temp = findMin(root->right);
        root->judul = temp->judul;
        root->genre = temp->genre;
        root->tahunTayang = temp->tahunTayang;
        root->rating = temp->rating;

        root->right = deleteByJudul(root->right, temp->judul);
    }
    return root;
}

void inorder(filmData* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << "Judul  : " << root->judul << endl;
        cout << "Genre  : " << root->genre << endl;
        cout << "Tahun  : " << root->tahunTayang << endl;
        cout << "Rating : " << root->rating << endl;
        cout << "-----------------------------\n";
        inorder(root->right);
    }
}

void preorder(filmData* root) {
    if (root != NULL) {
        cout << root->judul << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(filmData* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->judul << " ";
    }
}

int countFilm(filmData* root) {
    if (root == NULL)
        return 0;
    return 1 + countFilm(root->left) + countFilm(root->right);
}

void searchByRating(filmData* root, float minRating) {
    if (root == NULL) return;
    searchByRating(root->left, minRating);

    float min = minRating;
    float max = minRating + 1.0f;

    if (root->rating >= min && root->rating < max) {
        cout << "Judul  : " << root->judul << endl;
        cout << "Genre  : " << root->genre << endl;
        cout << "Tahun  : " << root->tahunTayang << endl;
        cout << "Rating : " << root->rating << endl;
        cout << "-----------------------------\n";
    }

    searchByRating(root->right, minRating);
}


void searchByGenre(filmData* root, string genre) {
    if (root != NULL) {
        searchByGenre(root->left, genre);

        if (toLowerCase(root->genre) == toLowerCase(genre)) {
            cout << "Judul  : " << root->judul << endl;
            cout << "Genre  : " << root->genre << endl;
            cout << "Tahun  : " << root->tahunTayang << endl;
            cout << "Rating : " << root->rating << endl;
            cout << "-----------------------------\n";
        }

        searchByGenre(root->right, genre);
    }
}

string toLowerCase (string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    
    return s;
}