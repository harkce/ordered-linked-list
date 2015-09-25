#include "list.hpp"
#define Nil NULL
#define first(L) (L).first
#define info(P) (P)->info
#define next(P) (P)->next

void CreateList(list &L) {
    first(L) = Nil;
}

address alokasi(infotype data) {
    address P = new elmlist;
    info(P) = data;
    next(P) = Nil;
    return P;
}

void dealokasi(address P) {
    delete P;
}

address findID(list L, infotype data) {
    address P = first(L);
    while(P != Nil)
    {
        if(info(P).ID == data.ID)
        {
            return P;
        }
        P = next(P);
    }
    return 0;
}

void insertFirst(list &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(list &L, address P) {
    address Q = first(L);
    while(next(Q) != Nil)
    {
        Q = next(Q);
    }
    next(Q) = P;
}

void insertAfter(list &L, address P, address Prec) {
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertData(list &L, infotype data) {
    address P = alokasi(data);
    if(findID(L,data) == 0)
    {
        if(first(L) == Nil || data.ID < info(first(L)).ID)
        {
            insertFirst(L,P);
        }
        else
        {
            address Q = first(L);
            while(next(Q) != Nil && info(next(Q)).ID < data.ID)
            {
                Q = next(Q);
            }
            if(next(Q) != Nil)
            {
                insertAfter(L,P,Q);
            }
            else
            {
                insertLast(L,P);
            }
        }
        cout << "Insert sukses!" << endl;
    }
    else
    {
        cout << "Data dengan ID = " << data.ID << " sudah ada!" << endl;
    }
}

void deleteFirst(list &L, address &P) {
    P = first(L);
    if(next(P) != Nil)
    {
        first(L) = next(P);
    }
    else
    {
        first(L) = Nil;
    }
    next(P) = Nil;
}

void deleteLast(list &L, address &P) {
    address Q = first(L);
    while(next(next(Q)) != Nil)
    {
        Q = next(Q);
    }
    P = next(Q);
    next(Q) = Nil;
}

void deleteAfter(list &L, address &P, address Prec) {
    P = next(Prec);
    if(next(P) == Nil)
    {
        deleteLast(L,P);
    }
    else
    {
        next(Prec) = next(P);
        next(P) = Nil;
    }
}

void deleteData(list &L, infotype data) {
    address P = findID(L,data);
    if(P != 0)
    {
        if(info(P).ID == info(first(L)).ID)
        {
            deleteFirst(L,P);
        }
        else
        {
            if(next(P) == Nil)
            {
                deleteLast(L,P);
            }
            else
            {
                address Q = first(L);
                while(info(next(Q)).ID != info(P).ID)
                {
                    Q = next(Q);
                }
                deleteAfter(L,P,Q);
            }
        }
        cout << "Delete sukses!" << endl;
    }
    else
    {
        cout << "Data dengan ID = " << data.ID << " tidak ditemukan!" << endl;
    }
}

list reverseList(list L) {
    list M;
    CreateList(M);
    address P = first(L);
    while(P != Nil)
    {
        address Q = alokasi(info(P));
        insertFirst(M,Q);
        P = next(P);
    }
    return M;
}

void input_data(infotype &data) {
    cout << "ID : "; cin >> data.ID;
    cout << "Jenis : "; cin.ignore(); getline(cin, data.jenis);
    cout << "Merk : "; getline(cin, data.merk);
    cout << "Harga : "; cin >> data.harga;
    cout << "Stok : "; cin >> data.stok;
    cout << "Supplier : "; cin.ignore(); getline(cin, data.supplier);
    cout << "Garansi : "; cin >> data.garansi;
}

void printInfo(list L) {
    if(first(L) != Nil)
    {
        address P = first(L);
        int i = 1;
        while(P != Nil)
        {
            cout << "Elemen ke " << i << endl;
            cout << "ID : " << info(P).ID << endl;
            cout << "Jenis : " << info(P).jenis << endl;
            cout << "Merk : " << info(P).merk << endl;
            cout << "Harga : " << info(P).harga << endl;
            cout << "Stok : " << info(P).stok << endl;
            cout << "Supplier : " << info(P).supplier << endl;
            cout << "Garansi : " << info(P).garansi << endl;
            cout << endl;
            P = next(P);
            i += 1;
        }
    }
    else
    {
        cout << "List kosong" << endl;
    }
}
