#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "list.hpp"
#include "list.cpp"

using namespace std;

void menu();
void input();
void tampil();
void cari();
void edit();
void hapus();

int main()
{
    CreateList(L);
    menu();
    return 0;
}

void menu() {
    char pilih;
    system("cls");
    cout << "Menu Utama" << endl;
    cout << "1. Input data" << endl;
    cout << "2. Tampil data" << endl;
    cout << "3. Cari data" << endl;
    cout << "4. Edit data" << endl;
    cout << "5. Hapus data" << endl;
    cout << "6. Reverse list" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    switch(pilih)
    {
        case '1' : input(); break;
        case '2' : tampil(); break;
        case '3' : cari(); break;
        case '4' : edit(); break;
        case '5' : hapus(); break;
        case '6' : L = reverseList(L); menu(); break;
        case '0' : exit(0); break;
        default : menu();
    }
}

void input() {
    system("cls");
    cout << "Input Data Baru" << endl;
    input_data(data);
    insertData(L,data);
    getche();
    menu();
}

void tampil() {
    system("cls");
    cout << "Tampil Data" << endl;
    printInfo(L);
    getche();
    menu();
}

void cari() {
    system("cls");
    cout << "Cari Data" << endl;
    cout << "ID data yang akan dicari : "; cin >> data.ID;
    address P = findID(L,data);
    if(P != 0) {
        cout << "Data dengan ID = " << data.ID << " ditemukan" << endl;
        cout << "Jenis : " << info(P).jenis << endl;
        cout << "Merk : " << info(P).merk << endl;
        cout << "Harga : " << info(P).harga << endl;
        cout << "Stok : " << info(P).stok << endl;
        cout << "Supplier : " << info(P).supplier << endl;
        cout << "Garansi : " << info(P).garansi << endl;
    }
    else
    {
        cout << "Data dengan ID = " << data.ID << " tidak ditemukan!" << endl;
    }
    getche();
    menu();
}

void edit() {
    system("cls");
    cout << "Edit Data" << endl;
    cout << "ID data yang akan diedit : "; cin >> data.ID;
    address P = findID(L,data);
    if(P != 0) {
        cout << "Edit data dengan ID = " << data.ID << endl;
        cout << "Jenis : " << info(P).jenis << endl;
        cout << "Merk : " << info(P).merk << endl;
        cout << "Harga : " << info(P).harga << endl;
        cout << "Stok : " << info(P).stok << endl;
        cout << "Supplier : " << info(P).supplier << endl;
        cout << "Garansi : " << info(P).garansi << endl;
        cout << "Sukses edit!" << endl;
    }
    else
    {
        cout << "Data dengan ID = " << data.ID << " tidak ditemukan!" << endl;
    }
}

void hapus() {
    system("cls");
    cout << "Hapus Data" << endl;
    cout << "ID data yang akan dihapus : "; cin >> data.ID;
    deleteData(L,data);
    getche();
    menu();
}
