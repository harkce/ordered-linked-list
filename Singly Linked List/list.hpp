#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

using namespace std;

struct AlatMusik {
    int ID, harga, stok, garansi;
    string merk, jenis, supplier;
};

typedef struct AlatMusik infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct list {
    address first;
};

list L;
infotype data;

void CreateList(list &L);

address alokasi(infotype data);
void dealokasi(address P);

address findID(list L, infotype data);

void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address P, address Prec);
void insertData(list &L, infotype data);

void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address &P, address Prec);
void deleteData(list &L, infotype data);

list reverseList(list L);

void input_data(infotype &data);
void printInfo(list L);

#endif // LIST_HPP_INCLUDED
