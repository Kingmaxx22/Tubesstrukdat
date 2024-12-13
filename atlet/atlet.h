#ifndef ATLET_H_INCLUDED
#define ATLET_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct pertandingan {
    string tempat, waktu, pemenang;
    int totalhad, jmlpeserta;
};

struct peserta {
    string id, nama, daerah;
    int juara;
};

typedef struct pertandinganlist *adrpert;
typedef struct atletlist *adruser;

struct sll {
    adrpert first;
};

struct dll {
    adruser first, last;
};

struct atletlist {
    peserta info;
    adruser prev, next;
};

struct pertandinganlist {
    pertandingan info;
    dll firstatlet;
    adrpert next;
};

// Function Prototypes
void createListSLL(sll &Q);
void createListDLL(dll &Q);
adrpert pertandinganBaru(pertandingan X);
adruser pesertaBaru(peserta X);
void insertFirstPertandingan(sll &Q, adrpert P);
void insertFirstAtlet(dll &Q, adruser P);
void insertLastAtlet(dll &Q, adruser P);
void deleteFirstPertandingan(sll &Q, adrpert &P);
void deleteAfterPertandingan(sll &Q, adrpert target, adrpert &P);
void delLastPertandingan(sll &Q, adrpert &P);
void deleteFirstAtlet(dll &Q, adruser &P);
void deleteAfterAtlet(adruser prev, adruser &P);
void delLastAtlet(dll &Q, adruser &P);
void showPertandingan(sll Q);
void showAtlet(sll Q);
void showAll(sll Q);
adrpert searchPertandingan(sll S, string nama);
adruser searchAtlet(sll S, string id);
int hitungPertandingan(sll &Q);
int hitungAtlet(sll &Q);
void deletepertandingansearch(sll &Q, string id);
void deleteatletsearch(sll &Q, string id);
void insertatletterhadap(sll &Q, adruser S, string id);

#endif
