#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

void insert(node *&head, int data)
{
    node *aux = head;
    node *newnode = new node();
    newnode->data = data;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    if (head == NULL)
    {
        newnode->next = head;
        if (head != NULL)
        {
            head->prev = newnode;
        }
        head = newnode;
    }
    else
    {
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        newnode->next = aux->next;
        if (aux->next != NULL)
        {
            head->next->prev = newnode;
        }
        aux->next = newnode;
    }
}

void show(node *head)
{
    node *aux = head;
    while (aux != NULL)
    {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

bool isMagicForRowsAndColumns(int a, int b, int c)
{
    return a == b && a == c;
}
bool isMagicForDiagonals(int a, int b)
{
    return a == b;
}

void listToMatrix(node *list)
{

    node *aux = list;
    int matrix[3][3];
    int sumRow1 = 0;
    int sumRow2 = 0;
    int sumRow3 = 0;
    int sumColumn1 = 0;
    int sumColumn2 = 0;
    int sumColumn3 = 0;
    int sumDiagonal1 = 0;
    int sumDiagonal2 = 0;

    for (int i = 0; i < 3 && aux != NULL; i++)
    {
        for (int j = 0; j < 3 && aux != NULL; j++)
        {
            matrix[i][j] = aux->data;
            aux = aux->next;
        }
    }

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cout << matrix[x][y] << " ";

            if (x == 0)
            {
                sumRow1 += matrix[x][y];
            }
            if (x == 1)
            {
                sumRow2 += matrix[x][y];
            }
            if (x == 2)
            {
                sumRow3 += matrix[x][y];
            }

            if (y == 0)
            {
                sumColumn1 += matrix[x][y];
            }
            if (y == 1)
            {
                sumColumn2 += matrix[x][y];
            }
            if (y == 2)
            {
                sumColumn3 += matrix[x][y];
            }

            if (x == y)
            {
                sumDiagonal1 += matrix[x][y];
            }
            if (x + 2 == y + 2)
            {
                sumDiagonal2 += matrix[x][y];
            }
        }
        cout << endl;
    }
    cout << "        La suma de las filas        " << endl;
    cout << "La suma de la fila 1 es: " << sumRow1 << endl;
    cout << "La suma de la fila 2 es: " << sumRow2 << endl;
    cout << "La suma de la fila 3 es: " << sumRow3 << endl;
    cout << "          La suma de las Columnas         " << endl;
    cout << "La suma de la columna 1 es: " << sumColumn1 << endl;
    cout << "La suma de la columna 2 es: " << sumColumn2 << endl;
    cout << "La suma de la columna 3 es: " << sumColumn3 << endl;
    cout << "         La suma de las Diagonales           " << endl;
    cout << "La suma de la diagonal 1 es: " << sumDiagonal1 << endl;
    cout << "La suma de la diagonal 2 es: " << sumDiagonal2 << endl;

    if (isMagicForRowsAndColumns(sumRow1, sumRow2, sumRow3) && isMagicForRowsAndColumns(sumColumn1, sumColumn2, sumColumn3) && isMagicForDiagonals(sumDiagonal1, sumDiagonal2))
    {
        cout << "La matriz es magica" << endl;
    }
    else
    {
        cout << "La matriz no es magica" << endl;
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
    cout << "Impresion de la lista" << endl;
    show(list);
    cout << endl;
    cout << "Matriz" << endl;
    listToMatrix(list);
    return 0;
}