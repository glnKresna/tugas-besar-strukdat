#include "BSTFilm.h"

void initBST(BSTFilm &T) {
    T.root = NULL;
}

filmData* createNode(string judul, string genre, int tahun, float rating) {
    filmData* node = new filmData;
    node->judul = judul;
    node->genre = genre;
    node->tahunTayang = tahun;
    node->rating = rating;
    node->left = node->right = NULL;
    return node;
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
        if (toLowerCase(newNode->judul) < toLowerCase(curr->judul))
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (toLowerCase(newNode->judul) < toLowerCase(parent->judul))
        parent->left = newNode;
    else
        parent->right = newNode;
}

filmData* searchByJudul(filmData* root, string judul) {
    if (root == NULL) return NULL;

    string a = toLowerCase(judul);
    string b = toLowerCase(root->judul);

    if (a == b) return root;
    return (a < b) ? searchByJudul(root->left, judul)
    : searchByJudul(root->right, judul);
}

filmData* findMin(filmData* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

filmData* deleteByJudul(filmData* root, string judul) {
    if (root == NULL) return NULL;

    if (toLowerCase(judul) < toLowerCase(root->judul))
        root->left = deleteByJudul(root->left, judul);
    else if (toLowerCase(judul) > toLowerCase(root->judul))
        root->right = deleteByJudul(root->right, judul);
    else {
        if (root->left == NULL) {
            filmData* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
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
        cout << "-----------------------------\n";
        cout << "Judul  : " << root->judul << endl;
        cout << "Genre  : " << root->genre << endl;
        cout << "Tahun  : " << root->tahunTayang << endl;
        cout << "Rating : " << root->rating << endl;
        inorder(root->right);
    }
}

void searchByRating(filmData* root, float minRating) {
    if (root == NULL) return;
    searchByRating(root->left, minRating);

    if (root->rating >= minRating && root->rating < minRating + 1) {
        cout << root->judul << " (" << root->rating << ")\n";
    }
    
    searchByRating(root->right, minRating);
}

string trim(const string &s) {
    int i = 0, j = (int)s.size() - 1;
    while (i <= j && isspace((unsigned char)s[i])) i++;
    while (j >= i && isspace((unsigned char)s[j])) j--;
    return (i > j) ? "" : s.substr(i, j - i + 1);
}

bool hasGenreManual(const string &genreField, const string &wanted) {
    string key = toLowerCase(trim(wanted));
    string token = "";

    for (int i = 0; i <= (int)genreField.size(); i++) {
        if (i == (int)genreField.size() || genreField[i] == ',') {
            string g = toLowerCase(trim(token));
            if (!g.empty() && g == key) return true;
            token = "";
        } else {
            token += genreField[i];
        }
    }
    return false;
}

void searchByGenre(filmData* root, string genre) {
    if (root == NULL) return;
    searchByGenre(root->left, genre);

    if (hasGenreManual(root->genre, genre)) {
        cout << root->judul << " - " << root->genre << endl;
    }

    searchByGenre(root->right, genre);
}

bool adaGenre(filmData* root, string genre) {
    if (root == NULL) return false;

    if (adaGenre(root->left, genre)) return true;
    if (hasGenreManual(root->genre, genre)) return true;
    return adaGenre(root->right, genre);
}

string toLowerCase(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}