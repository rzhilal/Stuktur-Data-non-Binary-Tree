/*
Nama pemrogram : Rizq Hilal Rifaasya
Program : non Binary tree, pengoperasian delete dengan sistem waris dan insert
source : Bu Santi dan Bu Ade, dosen pengampu matkul Struktur Data di Politeknik Negeri Bandung
*/
#ifndef nbtree_H
#define nbtree_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Info(P) (P)->info
#define FS(P) (P)->fs
#define Root(T) (T).root
#define NB(P) (P)->nb
#define Parent(P) (P)->parent

/*** Struktur Data ***/
typedef int nbType;		//boleh diganti char
typedef struct TnbTreeNode *nbAddr;

typedef struct TnbTreeNode{
	nbAddr fs; //First child
	nbType info; // variabel yang menyimpan data
	nbAddr nb; //Next brother
	nbAddr parent; // menunjuk atasannya
}nbTreeNode;

struct nbTree{
	nbAddr root;
};

/* ---------------- Konstruktor Tree ---------------- */
void nbCreate(nbTree *x);
//Membuat tree kosong (X.root=NULL)

/* ---------------- Alokasi node baru Tree ---------------- */
nbAddr nbCNode(nbType X);
//Alokasi untuk membuat node baru

void nbDNode(nbAddr *Node);
//Dealokasi untuk melepas node di memory

/* ---------------- Operasi-operasi Tree ---------------- */
void nbInsert(nbTree *tRoot, nbAddr parent, nbType X);
// Menambah element pada node parent

nbAddr nbSearch(nbAddr root, nbType src);
// Mencari node dengan info ttn dan mengembalikan addressnya

void nbUpgrade(nbAddr *root);
// Mengupgrade parent dari beberapa node. (digunakan pada proses penghapusan)

void nbDelete(nbAddr *pDel, nbTree *pTree);
// Menghapus node tertentu dan jika node tersebut memiliki child, maka posisinya digantikan oleh fs dari node tsb

void nbDeleteSub(nbAddr *pDel, nbTree *pTree);
//Mengapus node beserta bawahannyaa, jika menghapus root maka tree akan menjadi kosong

void nbPrint(nbAddr node, char tab[]);

int getLevel(nbAddr Node);

int nbNumLev(nbTree X);

int getHeight (nbAddr Node, nbTree X);

int degree(nbAddr Node);

#endif
