#include <iostream>

using namespace std;

int main() {
    int n; 
    int *p;
    p = &n;

    cout << "Ingrese un numero: "<<endl;
    cin >> n;

    cout << "El valor de n es: " << n << endl;

    if(*p %2 == 0){
        cout << "El valor " << *p << " es par"<< endl;
        cout << "La direccion de memoria de n es: " << p << endl;
    } else {
        cout << "El valor " << *p << " es impar"<< endl;
        cout << "La direccion de memoria de n es: " << p << endl;
    }


}