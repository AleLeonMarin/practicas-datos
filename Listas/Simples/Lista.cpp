#include <iostream>
#include <math.h>

using namespace std;

struct node
{
    int data;
    node *next;
};

void show(node *p)
{
    if (p == NULL)
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void insert(node *&a, int n)
{
    node *aux = a;
    node *add = new node;
    add->data = n;
    add->next = NULL;

    if (a == NULL)
    {
        a = add;
    }
    else
    {

        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = add;
    }
}

void pop(node *&a)
{
    node *aux = a;

    while (aux != NULL)
    {
        aux = aux->next;
        a = aux;
    }
}

void orderInsert(node *&a, int n)
{
    node *aux = a;
    node *add = new node;
    add->data = n;
    add->next = nullptr;

    if (a == NULL || aux->data > n)
    {
        add->next = a;
        a = add;
    }
    else
    {

        while (aux->next != NULL && aux->next->data < n)
        {
            aux = aux->next;
        }
        add->next = aux->next;
        aux->next = add;
    }
}

void pairNumbers(node *&a)
{
    node *aux = a;

    while (aux != NULL)
    {
        if (aux->data % 2 == 0)
        {
            cout << "El numero " << aux->data << " es par" << endl;
        }
        else
        {
            cout << "El numero " << aux->data << " es impar" << endl;
        }

        aux = aux->next;
    }
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void primeNumbers(node *&a)
{
    node *aux = a;

    while (aux != NULL)
    {
        if (isPrime(aux->data))
        {
            cout << "El numero " << aux->data << " es primo" << endl;
        }
        else
        {
            cout << "El numero " << aux->data << " no es primo" << endl;
        }
        aux = aux->next;
    }
}

void calculateMaxMin(node *&list)
{

    node *aux = list;

    int max = aux->data;
    int min = aux->data;

    while (aux != NULL)
    {
        if (aux->next != NULL && aux->data < aux->next->data)
        {
            max = aux->next->data;
        }
        if (aux->next != NULL && aux->data > aux->next->data)
        {
            min = aux->next->data;
        }
        aux = aux->next;
    }

    cout << "El numero mayor es: " << max << endl;
    cout << "El numero menor es: " << min << endl;
}

void listsToMatrix(node *&a, node *&b)
{
    node *aux = a;
    node *aux2 = b;

    int matrix[2][10];
    int i = 0; // Índice de filas
    int j = 0; // Índice de columnas

    // Rellenar la primera fila de la matriz con los valores de la lista 'a'
    while (aux != NULL && j < 10)
    {
        matrix[0][j] = aux->data;
        aux = aux->next;
        j++;
    }

    j = 0; // Reiniciar el índice de columnas

    // Rellenar la segunda fila de la matriz con los valores de la lista 'b'
    while (aux2 != NULL && j < 10)
    {
        matrix[1][j] = aux2->data;
        aux2 = aux2->next;
        j++;
    }

    // Imprimir la matriz para verificar
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            cout << matrix[x][y] << " ";
        }
        cout << endl;
    }
}

void calculateSumAverage(node *&a)
{
    node *aux = a;
    float sum = 0;
    float count = 0;

    while (aux != NULL)
    {
        sum += aux->data;
        count++;
        aux = aux->next;
    }

    cout << "La suma de los elementos es: " << sum << endl;
    cout << "El promedio de los elementos es: " << sum / count << endl;
}

void matrixToList(int matriz[2][10], node *&a, node *&b)
{

    for (int j = 0; j < 10; j++)
    {
        orderInsert(a, matriz[0][j]);
        orderInsert(b, matriz[1][j]);
    }

    cout << "Listas extraidas de la matriz" << endl;
    cout << endl;

    cout << "Lista 1: ";
    show(a);
    cout << endl;

    cout << "Lista 2: ";
    show(b);
    cout << endl;
}

int main()
{
    node *Lista = nullptr;
    node *Lista2 = nullptr;

    show(Lista);

    insert(Lista, 1);
    insert(Lista, 2);
    insert(Lista, 3);

    show(Lista);

    pop(Lista);

    show(Lista);

    orderInsert(Lista, 3);
    orderInsert(Lista, 1);
    orderInsert(Lista, 2);

    show(Lista);

    pairNumbers(Lista);

    primeNumbers(Lista);

    pop(Lista);

    show(Lista);

    orderInsert(Lista, 3);
    orderInsert(Lista, 1);
    orderInsert(Lista, 2);
    orderInsert(Lista, 4);
    orderInsert(Lista, 5);
    orderInsert(Lista, 6);
    orderInsert(Lista, 7);
    orderInsert(Lista, 8);
    orderInsert(Lista, 9);
    orderInsert(Lista, 10);
    orderInsert(Lista, 11);

    pairNumbers(Lista);
    primeNumbers(Lista);
    calculateMaxMin(Lista);

    pop(Lista);

    show(Lista);

    orderInsert(Lista, 3);
    orderInsert(Lista, 1);
    orderInsert(Lista, 2);
    orderInsert(Lista, 4);
    orderInsert(Lista, 5);
    orderInsert(Lista, 6);
    orderInsert(Lista, 7);
    orderInsert(Lista, 8);
    orderInsert(Lista, 9);
    orderInsert(Lista, 10);

    cout << "Lista 1" << endl;
    show(Lista);

    orderInsert(Lista2, 3);
    orderInsert(Lista2, 1);
    orderInsert(Lista2, 2);
    orderInsert(Lista2, 4);
    orderInsert(Lista2, 5);
    orderInsert(Lista2, 6);
    orderInsert(Lista2, 7);
    orderInsert(Lista2, 8);
    orderInsert(Lista2, 9);
    orderInsert(Lista2, 10);

    cout << "Lista 2" << endl;
    show(Lista2);

    cout << "Matriz" << endl;
    listsToMatrix(Lista, Lista2);

    cout << "Suma y promedio" << endl;
    calculateSumAverage(Lista);

    cout << "Listas vacias" << endl;

    pop(Lista);
    pop(Lista2);

    show(Lista);
    show(Lista2);
    cout << endl;
    cout << "Matriz a listas" << endl;
    cout << endl;
    int matriz[2][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                         {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}};

    matrixToList(matriz, Lista, Lista2);
    

    return 0;
}