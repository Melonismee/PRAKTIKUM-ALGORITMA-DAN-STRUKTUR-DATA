#include <iostream>
using namespace std;

struct program{
    char huruf;
    char kata[10];
    int angka;
};

int main(){
    program input;

    cout<<"A. Masukkan sebuah huruf : "; cin>>input.huruf;
    cout<<"B. Masukkan sebuah kata  : "; cin>>input.kata;
    cout<<"C. Masukkan angka        : "; cin>>input.angka;

    cout<<"D. Huruf yang anda masukkan adalah : "<<input.huruf<<endl;
    cout<<"E. Kata yang anda masukkan adalah  : "<<input.kata<<endl;
    cout<<"F. Angka yang anda masukkan adalah : "<<input.angka<<endl;
}
