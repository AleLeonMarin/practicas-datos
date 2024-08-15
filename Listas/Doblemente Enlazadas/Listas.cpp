#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

void insertInOrder(node *&head, int data)
{

    node *aux = head;
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL || head->data > data)
    {
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
    }
    else
    {
        while (aux->next != NULL && aux->next->data < data)
        {
            aux = aux->next;
        }

        newNode->next = aux->next;
        if (aux->next != NULL)
        {
            head->next->prev = newNode;
        }
        aux->next = newNode;
    }
}

void show(node *&list)
{
    node *aux = list;
    if (aux == NULL)
    {
        cout << "The list is null " << endl;
    }
    else
    {
        while (aux != NULL)
        {
            cout << aux->data << " ";
            aux = aux->next;
        }
    }
}

int main()
{
    node *list = NULL;

    insertInOrder(list, 5);
    insertInOrder(list, 3);
    insertInOrder(list, 7);
    insertInOrder(list, 1);
    insertInOrder(list, 9);
    insertInOrder(list, 2);
    insertInOrder(list, 4);
    insertInOrder(list, 6);
    cout << "List" << endl;
    show(list);
}