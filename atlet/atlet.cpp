#include <iostream>
#include <string>
#include "atlet.h"
using namespace std;

void createListSLL(sll &Q) {
    // is terdapat SLL kosong
    // fs Sll terdefinisi
    Q.first = NULL;
}

void createListDLL(dll &Q) {
        // is terdapat DLL kosong
    // fs DLL terdefinisi
    Q.first = NULL;
    Q.last = NULL;
}

adrpert pertandinganBaru(pertandingan X) {
    /*
        IS masuk tipedata pertandingan FS terdapat adress pertandingan baru
    */
    adrpert P = new pertandinganlist;
    P->info = X;
    createListDLL(P->firstatlet);
    P->next = NULL;
    return P;
}

adruser pesertaBaru(peserta X) {
        /*
        IS masuk tipedata peserta FS terdapat adress peserta baru
    */
    adruser P = new atletlist;
    P->info = X;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirstPertandingan(sll &Q, adrpert P) {
    /*
        IS terdapat SLL yang mungkin kosong
        FS Terisi SLL Dengan data pertandingan baru di depan
    */
    if (Q.first == NULL) {
        Q.first = P;
    } else {
        P->next = Q.first;
        Q.first = P;
    }
}

void insertFirstAtlet(dll &Q, adruser P) {
        /*
        IS terdapat DLL atlet yang mungkin kosong
        FS Terisi DLL Dengan data pertandingan baru di depan
        */
    if (Q.first == NULL) {
        Q.first = P;
        Q.last = P;
    } else {
        P->next = Q.first;
        Q.first->prev = P;
        Q.first = P;
    }
}

void insertLastAtlet(dll &Q, adruser P) {
        /*
        IS terdapat DLL atlet yang mungkin kosong
        FS Terisi DLL Dengan data pertandingan baru di belakang
        */
    if (Q.first == NULL) {
        Q.first = P;
        Q.last = P;
    } else {
        P->prev = Q.last;
        Q.last->next = P;
        Q.last = P;
    }
}

void deleteFirstPertandingan(sll &Q, adrpert &P) {
        /*
        IS terdapat SLL Pertandingan yang mungkin kosong
        FS Terhapus SLL Dengan data pertandingan masuk pointer P paling depan
        */
    if (Q.first == NULL) {
        P = NULL;
    } else {
        P = Q.first;
        Q.first = Q.first->next;
    }
}

void deleteAfterPertandingan(sll &Q, adrpert target, adrpert &P) {
        /*
        IS terdapat SLL Pertandingan yang mungkin kosong
        FS Terhapus SLL Dengan data pertandingan masuk pointer P sesuai target
        */
    if (Q.first == NULL) return;

    adrpert SS = Q.first;
    adrpert prev = NULL;

    while (SS != NULL) {
        if (SS == target) {
            if (prev != NULL) {
                P = prev->next;
                prev->next = SS->next;
                return;
            } else {
                P = Q.first;
                Q.first = SS->next;
                return;
            }
        }
        prev = SS;
        SS = SS->next;
    }
}

void delLastPertandingan(sll &Q, adrpert &P) {
            /*
        IS terdapat SLL Pertandingan yang mungkin kosong
        FS Terhapus SLL Dengan data pertandingan masuk pointer P paling belakang
        */
    if (Q.first == NULL) {
        P = NULL;
        return;
    }

    if (Q.first->next == NULL) {
        P = Q.first;
        Q.first = NULL;
        return;
    }

    adrpert R = Q.first;
    adrpert prev = NULL;

    while (R->next != NULL) {
        prev = R;
        R = R->next;
    }

    P = R;
    prev->next = NULL;
}

void deleteFirstAtlet(dll &Q, adruser &P) {
                /*
        IS terdapat DLL Pertandingan yang mungkin kosong
        FS Terhapus DLL Dengan data pertandingan masuk pointer P paling depan
        */
    if (Q.first == NULL) {
        P = NULL;
        return;
    }

    P = Q.first;

    if (Q.first == Q.last) {
        Q.first = NULL;
        Q.last = NULL;
    } else {
        Q.first = Q.first->next;
        Q.first->prev = NULL;
    }

    P->next = NULL;
    P->prev = NULL;
}

void deleteAfterAtlet(adruser prev, adruser &P) {
            /*
        IS terdapat DLL Pertandingan yang mungkin kosong
        FS Terhapus DLL Dengan data pertandingan masuk pointer P tengah
        */
    if (prev == NULL || prev->next == NULL) {
        P = NULL;
        return;
    }

    P = prev->next;
    prev->next = P->next;

    if (P->next != NULL) {
        P->next->prev = prev;
    }

    P->next = NULL;
    P->prev = NULL;
}

void delLastAtlet(dll &Q, adruser &P) {
            /*
        IS terdapat DLL Pertandingan yang mungkin kosong
        FS Terhapus DLL Dengan data pertandingan masuk pointer P paling belakang
        */
    if (Q.first == NULL) {
        P = NULL;
        return;
    }

    P = Q.last;

    if (Q.first == Q.last) {
        Q.first = NULL;
        Q.last = NULL;
    } else {
        Q.last = Q.last->prev;
        Q.last->next = NULL;
    }

    P->next = NULL;
    P->prev = NULL;
}

void showPertandingan(sll Q) {
         /*
        IS terdapat SLL yang mungkin kosong
        FS Output semua pertandingan
        */
    adrpert P = Q.first;
    int jumlah = 1;
    while (P != NULL) {
        cout << jumlah++ << ". Tempat: " << P->info.tempat << endl;
        cout << "   Waktu: " << P->info.waktu << endl;
        cout << "   Pemenang: " << P->info.pemenang << endl;
        cout << "   Total Hadiah: " << P->info.totalhad << endl;
        cout << "   Jumlah Peserta: " << P->info.jmlpeserta << endl;
        cout << "---------------------------------------------------------" << endl;
        P = P->next;
    }
}

void showAtlet(sll Q) {
     /*
        IS terdapat SLL yang mungkin kosong
        FS Output semua Atlet
        */
    adrpert PP = Q.first;
    int jumlah = 1;

    while (PP != NULL) {
        adruser P = PP->firstatlet.first;
        while (P != NULL) {
            cout << jumlah++ << ". ID Atlet: " << P->info.id << endl;
            cout << "   Nama: " << P->info.nama << endl;
            cout << "   Daerah: " << P->info.daerah << endl;
            cout << "   Juara Ke-: " << P->info.juara << endl;
            cout << "---------------------------------------------------------" << endl;

            P = P->next;
        }
        PP = PP->next;
    }
}

void showAll(sll Q) {
     /*
        IS terdapat SLL yang mungkin kosong
        FS Output semua pertandingan dan atlet
        */
    adrpert PP = Q.first;
    int jumlah = 1;
    int iterasi = 1;

    while (PP != NULL) {
        cout << iterasi++ << ". Pertandingan di Tempat: " << PP->info.tempat << endl;
        cout << "   Waktu: " << PP->info.waktu << endl;
        cout << "   Total Hadiah: " << PP->info.totalhad << endl;
        cout << "   Peserta:" << endl;
        adruser P = PP->firstatlet.first;
        while (P != NULL) {
            cout << jumlah++ << ". ID Atlet: " << P->info.id << endl;
            cout << "   Nama: " << P->info.nama << endl;
            cout << "   Daerah: " << P->info.daerah << endl;
            cout << "   Juara Ke-: " << P->info.juara << endl;
            cout << "---------------------------------------------------------" << endl;

            P = P->next;
        }
        PP = PP->next;
    }
}

adrpert searchPertandingan(sll S, string nama) {
     /*
        IS terdapat SLL yang mungkin kosong dan string nama
        FS Output adress pertandingan jika ditemukan
        */
    adrpert P = S.first;

    while (P != NULL) {
        if (P->info.tempat == nama) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

adruser searchAtlet(sll S, string searchTerm) {
    /*
        IS terdapat SLL yang mungkin kosong dan string cari
        FS Output adress Atlet jika ditemukan
        */
    adrpert SS = S.first;
    while (SS != NULL) {
        adruser P = SS->firstatlet.first;
        while (P != NULL) {
            if (P->info.id == searchTerm || P->info.nama == searchTerm) {
                return P;
            }
            P = P->next;
        }
        SS = SS->next;
    }
    return NULL;
}

int hitungPertandingan(sll &Q) {
    /*
        IS terdapat SLL yang mungkin kosong ]
        FS Output Jumlah data pertandingan
        */
    int hitung = 0;
    adrpert P = Q.first;
    while (P != NULL) {
        hitung++;
        P = P->next;
    }
    return hitung;
}

int hitungAtlet(sll &Q) {
        /*
        IS terdapat SLL yang mungkin kosong ]
        FS Output Jumlah data Atlet
        */
    int hitung = 0;
    adrpert P = Q.first;
    while (P != NULL) {
        adruser A = P->firstatlet.first;
        while (A != NULL) {
            hitung++;
            A = A->next;
        }
        P = P->next;
    }
    return hitung;
}

void deletepertandingansearch(sll &Q, string tempat) {
        /*
        IS terdapat SLL yang mungkin kosong dan string cari
        FS terhapuskan data pertandingan sesuai nama tempat
        */
    adrpert prev = NULL;
    adrpert current = Q.first;

    while (current != NULL) {
        if (current->info.tempat == tempat) {
            if (prev == NULL) {
                adrpert deleted;
                deleteFirstPertandingan(Q, deleted);
                return;
            } else if (current->next == NULL) {
                adrpert deleted;
                delLastPertandingan(Q, deleted);
                return;
            } else {
                adrpert deleted;
                deleteAfterPertandingan(Q, prev, deleted);
                return;
            }
        }
        prev = current;
        current = current->next;
    }
}

void deleteatletsearch(sll &Q, string nama) {
            /*
        IS terdapat SLL yang mungkin kosong dan string cari
        FS terhapuskan data pertandingan sesuai nama atlet
        */
    adrpert pertandinganCurrent = Q.first;

    while (pertandinganCurrent != NULL) {
        dll &atletList = pertandinganCurrent->firstatlet;
        adruser prev = NULL;
        adruser current = atletList.first;

        while (current != NULL) {
            if (current->info.nama == nama) {
                if (prev == NULL) {
                    adruser deleted;
                    deleteFirstAtlet(atletList, deleted);
                    break;
                } else if (current->next == NULL) {
                    adruser deleted;
                    delLastAtlet(atletList, deleted);
                    break;
                } else {
                    adruser deleted;
                    deleteAfterAtlet(prev, deleted);
                    break;
                }
            }
            prev = current;
            current = current->next;
        }

        pertandinganCurrent = pertandinganCurrent->next;
    }
}

void insertatletterhadap(sll &Q, adruser S, string id) {
        /*
        IS terdapat SLL yang mungkin kosong adr user dan nama id pertandingan
        FS masuk data atlet ke belakang dari pertandingan yang ada
        */
    adrpert A = searchPertandingan(Q, id);
    if (A != NULL) {
        insertLastAtlet(A->firstatlet, S);
    }
}
