#include <iostream>
#include <string>
#include "atlet.h"
using namespace std;

void menu() {
    cout << "+===================================================================+" << endl;
    cout << "|                      PERTANDINGAN DAN ATLET                       |" << endl;
    cout << "+============================= Menu ================================+" << endl;
    cout << "|1. Tambah Pertandingan                                             |" << endl;
    cout << "|2. Tambah Atlet ke Pertandingan                                    |" << endl;
    cout << "|3. Tampilkan Semua Pertandingan dan Atlet                          |" << endl;
    cout << "|4. Cari Pertandingan                                               |" << endl;
    cout << "|5. Cari Atlet                                                      |" << endl;
    cout << "|6. Hitung Jumlah Pertandingan                                      |" << endl;
    cout << "|7. Hitung Jumlah Atlet                                             |" << endl;
    cout << "|8. Hapus Pertandingan                                              |" << endl;
    cout << "|9. Hapus Atlet                                                     |" << endl;
    cout << "|0. Keluar                                                          |" << endl;
    cout << "+===================================================================+" << endl;
}

void inputData(sll &pertandinganList) {
    // Pertandingan 1
    pertandingan p1 = {"Stadion Gelora Bung Karno", "12 Desember 2024", "Tim A", 50000000, 5};
    adrpert pertandingan1 = pertandinganBaru(p1);
    insertFirstPertandingan(pertandinganList, pertandingan1);

    peserta atlet1 = {"A001", "Budi", "Jakarta", 1};
    peserta atlet2 = {"A002", "Andi", "Bandung", 2};
    peserta atlet3 = {"A003", "Siti", "Surabaya", 3};
    insertatletterhadap(pertandinganList, pesertaBaru(atlet1),"Stadion Gelora Bung Karno");
    insertatletterhadap(pertandinganList, pesertaBaru(atlet2),"Stadion Gelora Bung Karno");
    insertatletterhadap(pertandinganList, pesertaBaru(atlet3),"Stadion Gelora Bung Karno");

    // Pertandingan 2
    pertandingan p2 = {"Stadion Mandala Krida", "14 Desember 2024", "Tim B", 30000000, 3};
    adrpert pertandingan2 = pertandinganBaru(p2);
    insertFirstPertandingan(pertandinganList, pertandingan2);

    peserta atlet4 = {"A004", "Lina", "Yogyakarta", 1};
    peserta atlet5 = {"A005", "Rina", "Solo", 2};
    insertatletterhadap(pertandinganList, pesertaBaru(atlet4),"Stadion Mandala Krida");
    insertatletterhadap(pertandinganList, pesertaBaru(atlet5),"Stadion Mandala Krida");

    // Pertandingan 3
    pertandingan p3 = {"Stadion Maguwoharjo", "15 Desember 2024", "Tim C", 40000000, 4};
    adrpert pertandingan3 = pertandinganBaru(p3);
    insertFirstPertandingan(pertandinganList, pertandingan3);

    peserta atlet6 = {"A006", "Joko", "Semarang", 1};
    peserta atlet7 = {"A007", "Dani", "Malang", 2};
    insertatletterhadap(pertandinganList, pesertaBaru(atlet6),"Stadion Maguwoharjo");
    insertatletterhadap(pertandinganList, pesertaBaru(atlet7),"Stadion Maguwoharjo");

    // Pertandingan 4
    pertandingan p4 = {"Stadion Si Jalak Harupat", "16 Desember 2024", "Tim D", 20000000, 2};
    adrpert pertandingan4 = pertandinganBaru(p4);
    insertFirstPertandingan(pertandinganList, pertandingan4);

    peserta atlet8 = {"A008", "Eko", "Bogor", 1};
    peserta atlet9 = {"A009", "Ari", "Depok", 2};
    peserta atlet10 = {"A010", "Rudi", "Tangerang", 3};
    insertatletterhadap(pertandinganList, pesertaBaru(atlet8),"Stadion Si Jalak Harupat");
    insertatletterhadap(pertandinganList, pesertaBaru(atlet9),"Stadion Si Jalak Harupat");
    insertatletterhadap(pertandinganList, pesertaBaru(atlet10),"Stadion Si Jalak Harupat");
}

int main(){
    sll pertandinganlist;
    createListSLL(pertandinganlist);
    inputData(pertandinganlist);

    int pilihan;
    do {
        menu();
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                pertandingan p;
                cout << "Masukkan tempat: ";
                getline(cin, p.tempat);
                cout << "Masukkan waktu: ";
                getline(cin, p.waktu);
                cout << "Masukkan pemenang: ";
                getline(cin, p.pemenang);
                cout << "Masukkan total hadiah: ";
                cin >> p.totalhad;
                cout << "Masukkan jumlah peserta: ";
                cin >> p.jmlpeserta;

                adrpert newPertandingan = pertandinganBaru(p);
                insertFirstPertandingan(pertandinganlist, newPertandingan);
                cout << "Pertandingan berhasil ditambahkan.\n";
                break;
            }
            case 2: {
                string tempat;
                cout << "Masukkan tempat pertandingan: ";
                getline(cin, tempat);

                adrpert pertandingan = searchPertandingan(pertandinganlist, tempat);
                if (pertandingan == NULL) {
                    cout << "Pertandingan tidak ditemukan.\n";
                } else {
                    peserta atlet;
                    cout << "Masukkan ID atlet: ";
                    getline(cin, atlet.id);
                    cout << "Masukkan nama atlet: ";
                    getline(cin, atlet.nama);
                    cout << "Masukkan daerah atlet: ";
                    getline(cin, atlet.daerah);
                    cout << "Masukkan juara ke-: ";
                    cin >> atlet.juara;
                    cin.ignore();

                    adruser newAtlet = pesertaBaru(atlet);
                    insertatletterhadap(pertandinganlist,newAtlet,tempat);
                    cout << "Atlet berhasil ditambahkan ke pertandingan.\n";
                }
                break;
            }
            case 3: {
                int opsi;
                cout << "\nPilih opsi:" << endl;
                cout << "1. Tampilkan Pertandingan" << endl;
                cout << "2. Tampilkan Atlet" << endl;
                cout << "3. Tampilkan Pertandingan dan Atlet" << endl;
                cout << "Pilihan: ";
                cin >> opsi;
                cin.ignore();

                cout << "====================================================================" << endl;
                if (opsi == 1) {
                    cout << "Daftar semua Pertandingan:" << endl;
                    showPertandingan(pertandinganlist);
                } else if (opsi == 2) {
                    cout << "Daftar semua Atlet:" << endl;
                    showAtlet(pertandinganlist);
                    break;
                } else if (opsi == 3) {
                    cout << "Daftar semua Pertandingan beserta Atlet:" << endl;
                    showAll(pertandinganlist);
                } else {
                    cout << "Pilihan tidak tersedia. Silahkan coba lagi." << endl;
                    break;
                }
                cout << "====================================================================" << endl;
                break;
            }
            case 4: {
                string tempat;
                cout << "Masukkan tempat pertandingan: ";
                getline(cin, tempat);

                adrpert pertandingan = searchPertandingan(pertandinganlist, tempat);
                if (pertandingan != NULL) {
                    cout << "Pertandingan ditemukan: " << endl;cout <<  ". Tempat: " << pertandingan->info.tempat << endl;
                    cout << "   Waktu: " << pertandingan->info.waktu << endl;
                    cout << "   Pemenang: " << pertandingan->info.pemenang << endl;
                    cout << "   Total Hadiah: " << pertandingan->info.totalhad << endl;
                    cout << "   Jumlah Peserta: " << pertandingan->info.jmlpeserta << endl;
                    cout << "---------------------------------------------------------" << endl;
                } else {
                    cout << "Pertandingan tidak ditemukan.\n";
                }
                break;
            }
            case 5: {
                string nama;
                cout << "Masukkan Nama atlet: ";
                getline(cin, nama);

                adruser atlet = searchAtlet(pertandinganlist, nama);
                if (atlet != NULL) {
                    cout << "Atlet ditemukan: " << endl;
                    cout << "   Nama: " << atlet->info.nama << endl;
                    cout << "   Daerah: " << atlet->info.daerah << endl;
                    cout << "   Juara Ke-: " << atlet->info.juara << endl;
                    cout << "---------------------------------------------------------" << endl;
                } else {
                    cout << "Atlet tidak ditemukan.\n";
                }
                break;
            }
            case 6: {
                int totalPertandingan = hitungPertandingan(pertandinganlist);
                cout << "Total Pertandingan: " << totalPertandingan << "\n";
                break;
            }
            case 7: {
                int totalAtlet = hitungAtlet(pertandinganlist);
                cout << "Total Atlet: " << totalAtlet << "\n";
                break;
            }
            case 8: {
                string tempat;
                cout << "Masukkan tempat pertandingan yang akan dihapus: ";
                getline(cin, tempat);

                deletepertandingansearch(pertandinganlist, tempat);
                cout << "Pertandingan dengan tempat " << tempat << " telah dihapus.\n";
                break;
            }
            case 9: {
                string nama;
                cout << "Masukkan nama atlet yang akan dihapus: ";
                getline(cin, nama);

                deleteatletsearch(pertandinganlist, nama);
                cout << "Atlet dengan nama " << nama << " telah dihapus.\n";
                break;
            }
            case 0:
                cout << "Anda berhasil keluar.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
