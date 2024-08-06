#include <iostream>

using namespace std;

int main(){
    int n , *p;
    p = &n;

    cout << "Ingrese un numero: " << endl;
    cin >> n;

    cout << "El valor de n es: " << n << endl;

    int i , cont = 0; 

    for(i=1; i<*p; i++){
        if(*p % i == 0){
            cont++;
        }
    }

    if(cont>2){
        cout << "El valor " << *p << " no es primo" << endl;
        cout << "La direccion de memoria de n es: " << p << endl;
    } else {
        cout << "El valor " << *p << " es primo" << endl;
        cout << "La direccion de memoria de n es: " << p << endl;
    }
}