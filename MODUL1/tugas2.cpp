#include <iostream>
using namespace std;

struct data{
    char nomor[15];
    char kendaraan[20];
    char pemilik[30];
    char alamat[25];
    char kota[15];
};

int main(){
    data mobil = {
        "DA1234MK",
        "RUSH",
        "Andika Hartanto",
        "Jl. Kayu Tangi 1",
        "Banjarmasin"
    };

    cout << "Plat Nomor Kendaraan : " << mobil.nomor << endl;
    cout << "Jenis Kendaraan : " << mobil.kendaraan << endl;
    cout << "Nama Pemilik : " << mobil.pemilik << endl;
    cout << "Alamat : " << mobil.alamat << endl;
    cout << "Kota : " << mobil.kota << endl;

    return 0;
}
