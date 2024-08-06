#include <iostream>

using namespace std;

int main()
{

    int array[10];
    int *p;
    p = array;

    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese un numero: " << endl;
        cin >> array[i];
    }

    for (int i = 0; i < 10; i++)
    {
        if (*p % 2 == 0)
        {
            cout << "El valor " << *p << " es par" << endl;
            cout << "La direccion de memoria de n es: " << p << endl;
        }
        else
        {
            cout << "El valor " << *p << " es impar" << endl;
            cout << "La direccion de memoria de n es: " << p << endl;
        }
        p++;
    }
}