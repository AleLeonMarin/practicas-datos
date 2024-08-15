#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

void insertar(node *&lista, int n)
{
    node *aux = lista;
    node *nuevo = new node();
    nuevo->data = n;
    nuevo->next = lista;
    
    if(lista == NULL || aux->data > n)
    {
        nuevo->next = lista;
        lista = nuevo;
    }
    else
    {
        while(aux->next != NULL && aux->next->data < n)
        {
            aux = aux->next;
        }
        nuevo->next = aux->next;
        aux->next = nuevo;
    }
}

void show(node *lista)
{
    node *aux = lista;
    while(aux != NULL)
    {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

void sum(node *lista){
    node *aux = lista;
    int sum = 0; 
    while(aux != NULL){
        sum += aux->data;
        aux = aux->next;
    }
    cout << "La suma de los elementos de la lista es: " << sum << endl;
}

void comparator(node *lista1, node *lista2){
    node *aux1 = lista1;
    node *aux2 = lista2;
    while(aux1 != NULL && aux2 != NULL){
        if (aux1->data == aux2->data)
        {
            cout << "Los elementos de las listas son iguales" << endl;
            return;
        }
        else if (aux1->data != aux2->data){
            cout << "Los elementos de las listas no son iguales" << endl;
            return;
        }
        
    }
    aux1 = aux1->next;
    aux2 = aux2->next;
}

void pop(node *&lista)
{
    node *aux = lista;
    while(aux != NULL )
    {
        aux = aux->next;
        lista = aux;

    }
}

void pairList(node *lista){
    node *aux = lista;
    while(aux != NULL){
        if (aux->data % 2 == 0 ){
            cout << "El numero " << aux->data << " es par" << endl;
            aux = aux->next;
        }
        else{
            cout << "El numero " << aux->data << " es impar" << endl;
            aux = aux->next;
        }
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void prime(node* list) {
    node* aux = list;
    while (aux != nullptr) {
        if (isPrime(aux->data)) {
            cout << "El numero " << aux->data << " es primo" << endl;
        } else {
            cout << "El numero " << aux->data << " no es primo" << endl;
        }
        aux = aux->next; // Move to the next node
    }
}

int main(){
    node *lista = NULL;
    node *lista2 = NULL;

    insertar(lista, 5);
    insertar(lista, 3);
    insertar(lista, 4);
    insertar(lista, 1);
    insertar(lista, 2);

    insertar(lista2, 10);
    insertar(lista2, 8);
    insertar(lista2, 9);
    insertar(lista2, 6);
    insertar(lista2, 7);

    show(lista);
    sum(lista);

    show(lista2);
    sum(lista2);

    comparator(lista, lista2);
    pop(lista);
    show(lista);
    insertar(lista, 10);
    insertar(lista, 8);
    insertar(lista, 9);
    insertar(lista, 6);
    insertar(lista, 7);
    show(lista);
    pairList(lista);
    prime(lista);
    return 0;
}
