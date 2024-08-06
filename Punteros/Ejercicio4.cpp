#include <iostream>

using namespace std;

int main() {
    int array[10];
    int *p = array;

    // Solicitar al usuario que ingrese los valores del arreglo
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese un numero: " << endl;
        cin >> *(p + i); // Usar puntero para ingresar valores
    }

    // Encontrar el menor valor en el arreglo usando punteros
    int menor = *p;
    for (int i = 1; i < 10; i++) {
        if (*(p + i) < menor) {
            menor = *(p + i);
        }
    }

    // Imprimir el menor valor
    cout << "El menor valor del arreglo es: " << menor << endl;

    return 0;
}
