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
            aux->next->prev = newNode; // Fix: Update aux->next->prev
        }
        aux->next = newNode;
        newNode->prev = aux; // Update newNode's prev pointer
    }
}

void insert(node *&list, int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (list == NULL)
    {
        list = newNode;
    }
    else
    {
        node *aux = list;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = newNode;
    }
}

void show(node *&list)
{
    node *aux = list;
    if (aux == NULL)
    {
        cout << "The list is null." << endl; // Added period and newline
    }
    else
    {
        while (aux != NULL)
        {
            cout << aux->data << " ";
            aux = aux->next;
        }
        cout << endl; // Ensure there's a newline after printing the list
    }
}

void pop(node *&list) // Change parameter to reference to modify head pointer
{
    node *aux = list;

    while (aux != NULL)
    {
        node *temp = aux; // Save the current node
        aux = aux->next;  // Move to the next node
        delete temp;      // Delete the current node
    }

    list = NULL; // Set head pointer to NULL after deletion
}

void search(node *&list, int data)
{

    node *aux = list;

    bool found = false;

    while (aux != NULL)
    {
        if (aux->data == data)
        {
            found = true;
        }
        aux = aux->next;
    }

    if (found)
    {
        cout << "The element " << data << " was found." << endl;
    }
    else
    {
        cout << "The element " << data << " was not found." << endl;
    }
}

void bubbleSort(node *head)
{
    bool swapped;
    node *aux;
    node *last = NULL;

    // Si la lista está vacía, no hay nada que ordenar
    if (head == NULL)
        return;

    do
    {
        swapped = false;
        aux = head;

        while (aux->next != last)
        {
            if (aux->data > aux->next->data)
            {
                // Intercambio de datos entre nodos adyacentes
                int temp = aux->data;
                aux->data = aux->next->data;
                aux->next->data = temp;
                swapped = true;
            }
            aux = aux->next;
        }
        // Después de cada pasada, el último nodo está en su lugar correcto
        last = aux;

    } while (swapped);

    show(head);
}

void popRepeated(node *&list)
{

    node *curr = list;

    while (curr != NULL)
    {

        if (curr->next == NULL)
        {
            break;
        }

        if (curr->data == curr->next->data)
        {
            node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }

        curr = curr->next;
    }

    show(list);
}

void popRepeatedDisorder(node *&list)
{
    node *curr = list;

    while (curr != NULL)
    {

        if (curr->next == NULL)
        {
            break;
        }

        while (curr != NULL)
        {
            // Check if the next node exists and is a duplicate
            while (curr->next != NULL && curr->data == curr->next->data)
            {
                node *temp = curr->next;
                curr->next = curr->next->next;

                // Update the next node's prev pointer, if it exists
                if (curr->next != NULL)
                {
                    curr->next->prev = curr;
                }

                delete temp;
            }

            curr = curr->next;
        }
    }

    show(list);
}

void invert(node *&list)
{

    node *current = list;
    node *prev = nullptr;
    node *next = nullptr;

    while (current != NULL)
    {

        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    list = prev;

    show(list);
}

void insertTwoInOne(node *&list1, node *&list2)
{
    node *aux = list1;
    node *aux2 = list2;

    node *result = NULL;

    if (aux == NULL && aux2 == NULL)
    {
        cout << "Both lists are empty." << endl;
        return;
    }
    else
    {
        while (aux != NULL && aux2 != NULL)
        {
            insert(result, aux->data);
            insert(result, aux2->data);

            aux = aux->next;
            aux2 = aux2->next;
        }

        if (result != NULL)
        {

            bool swapped;
            node *aux;
            node *last = NULL;

            do
            {
                swapped = false;
                aux = result;

                while (aux->next != last)
                {
                    if (aux->data > aux->next->data)
                    {
                        int temp = aux->data;
                        aux->data = aux->next->data;
                        aux->next->data = temp;
                        swapped = true;
                    }

                    aux = aux->next;
                }
            } while (swapped);
        }
    }

    show(result);
}

void sumLists(node *list, node *list2)
{
    node *aux = list;
    node *aux2 = list2;
    node *result;
    int sum = 0;

    if (aux != NULL && aux2 != NULL)
    {

        insert(result, aux->data);
        aux = aux->next;
        insert(result, aux2->data);
        aux2 = aux2->next;

        while (result != NULL)
        {
            sum += result->data;
            result = result->next;
        }
    }
    cout << "Result List:" << endl;
    show(result);
    cout << "The sum of the lists is: " << sum << endl;
}

void multiplyLists(node *list, node *list2)
{
    node *aux = list;
    node *aux2 = list2;
    node *result;
    int product = 1;

    if (aux != NULL && aux2 != NULL)
    {

        insert(result, aux->data);
        aux = aux->next;
        insert(result, aux2->data);
        aux2 = aux2->next;

        while (result != NULL)
        {
            product *= result->data;
            result = result->next;
        }
    }
    cout << "Result List:" << endl;
    show(result);
    cout << "The product of the lists is: " << product << endl;
}

int main()
{
    node *list = NULL;
    node *list2 = NULL;

    insertInOrder(list, 5);
    insertInOrder(list, 3);
    insertInOrder(list, 7);
    insertInOrder(list, 1);
    insertInOrder(list, 9);
    insertInOrder(list, 2);
    insertInOrder(list, 4);
    insertInOrder(list, 6);

    cout << "List:" << endl;
    show(list);

    pop(list);

    cout << "List after pop:" << endl;
    show(list);

    insertInOrder(list, 5);
    insertInOrder(list, 3);
    insertInOrder(list, 7);
    insertInOrder(list, 1);
    insertInOrder(list, 9);
    insertInOrder(list, 2);
    insertInOrder(list, 4);
    insertInOrder(list, 6);

    cout << "List after insert:" << endl;
    show(list);

    cout << "Search for 5:" << endl;
    search(list, 5);

    pop(list);

    cout << "List after pop:" << endl;
    show(list);

    insert(list, 5);
    insert(list, 3);
    insert(list, 7);
    insert(list, 1);
    insert(list, 9);
    insert(list, 2);
    insert(list, 4);
    insert(list, 6);
    insert(list, 5);
    insert(list, 3);
    insert(list, 7);
    insert(list, 1);
    insert(list, 9);
    insert(list, 2);
    insert(list, 4);
    insert(list, 6);

    cout << "List after insert:" << endl;
    show(list);

    cout << "List sorted:" << endl;
    bubbleSort(list);

    cout << "List without repeated elements:" << endl;
    popRepeated(list);

    // cout << "List without repeated elements and disordered:" << endl;
    // popRepeatedDisorder(list);

    cout << "List inverted:" << endl;
    invert(list);

    pop(list);

    insert(list, 5);
    insert(list, 3);
    insert(list, 7);
    insert(list2, 1);
    insert(list2, 2);
    insert(list2, 9);

    cout << "List 1:" << endl;
    show(list);

    cout << "List 2:" << endl;
    show(list2);

    cout << "List 1 and List 2:" << endl;
    insertTwoInOne(list, list2);

    cout << "Sum of List 1 and List 2:" << endl;
    sumLists(list, list2);

    return 0;
}
