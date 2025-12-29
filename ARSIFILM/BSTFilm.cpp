#include "BSTFilm.h"

void initBST(BSTFilm &T) {
    T.root = NULL;
}

filmData* createNode(
    string judul,
    string genre,
    int tahunTayang,
    int durasi,
    float rating
) {
    filmData* newNode = new filmData;
    newNode->judul = judul;
    newNode->genre = genre;
    newNode->tahunTayang = tahunTayang;
    newNode->durasi = durasi;
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
    if (root == NULL || root->judul == judul)
        return root;

    if (judul < root->judul)
        return searchByJudul(root->left, judul);
    else
        return searchByJudul(root->right, judul);
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
        root->durasi = temp->durasi;
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
        cout << "Durasi : " << root->durasi << " menit" << endl;
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

filmData* findHighestRating(filmData* root) {
    if (root == NULL)
        return NULL;

    filmData* maxNode = root;
    filmData* leftMax = findHighestRating(root->left);
    filmData* rightMax = findHighestRating(root->right);

    if (leftMax != NULL && leftMax->rating > maxNode->rating)
        maxNode = leftMax;
    if (rightMax != NULL && rightMax->rating > maxNode->rating)
        maxNode = rightMax;

    return maxNode;
}
