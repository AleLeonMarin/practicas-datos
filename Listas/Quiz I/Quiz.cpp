#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void insert(node *&head, int data)
{
    node *aux = head;
    node *newNode = new node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = newNode;
    }
}

bool isMagic(int a, int b, int c)
{
    return (a == b && a == c);
}

void listToMatrix(node *list)
{
    node *aux = list;
    int matrix[3][3];
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sumDiagonal1 = 0;
    int sumDiagonal2 = 0;
    int sumColumn1 = 0;
    int sumColumn2 = 0;
    int sumColumn3 = 0;

    // Primera fila
    for (int j = 0; j < 3 && aux != NULL; j++)
    {
        matrix[0][j] = aux->data;
        sum1 += matrix[0][j];
        aux = aux->next;
    }

    // Segunda fila
    for (int j = 0; j < 3 && aux != NULL; j++)
    {
        matrix[1][j] = aux->data;
        sum2 += matrix[1][j];
        aux = aux->next;
    }

    // Tercera fila
    for (int j = 0; j < 3 && aux != NULL; j++)
    {
        matrix[2][j] = aux->data;
        sum3 += matrix[2][j];
        aux = aux->next;
    }

    // Mostrar la matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";

            if (i == j)
            {
                sumDiagonal1 += matrix[i][j];
            }
            if (i + j == 2)
            {
                sumDiagonal2 += matrix[i][j];
            }
            if (j == 0)
            {
                sumColumn1 += matrix[i][j];
            }
            if (j == 1)
            {
                sumColumn2 += matrix[i][j];
            }
            if (j == 2)
            {
                sumColumn3 += matrix[i][j];
            }
        }
        cout << endl;
    }

    cout << "Suma de la primera fila: " << sum1 << endl;
    cout << "Suma de la segunda fila: " << sum2 << endl;
    cout << "Suma de la tercera fila: " << sum3 << endl;
    cout << "Suma de la diagonal principal: " << sumDiagonal1 << endl;
    cout << "Suma de la diagonal secundaria: " << sumDiagonal2 << endl;
    cout << "Suma de la primera columna: " << sumColumn1 << endl;
    cout << "Suma de la segunda columna: " << sumColumn2 << endl;
    cout << "Suma de la tercera columna: " << sumColumn3 << endl;

    // Verificar si la matriz es mágica
    if (isMagic(sum1, sum2, sum3) && isMagic(sumColumn1, sumColumn2, sumColumn3) && isMagic(sumDiagonal1, sumDiagonal2, sumDiagonal1))
    {
        cout << "La matriz es magica" << endl;
    }
    else
    {
        cout << "La matriz no es magica" << endl;
    }
}

void show(node *head)
{
    node *aux = head;

    if (aux == NULL)
    {
        cout << "Li``````````sta vacia" << endl;
    }
    else
    {
        while (aux != NULL)
        {
            cout << aux->data << " ";
            aux = aux->next;
        }
        cout << endl;
    }
}

int main()
{
    node *list = NULL;

    insert(list, 6);
    insert(list, 1);
    insert(list, 8);
    insert(list, 7);
    insert(list, 5);
    insert(list, 3);
    insert(list, 2);
    insert(list, 9);
    insert(list, 4);

    show(list);

    cout << "Matriz generada a partir de la lista" << endl;

    listToMatrix(list);
}