#include <iostream>
#include <iomanip>

using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
    int height; // Agregar un atributo de altura para cada nodo
};

// Función para obtener la altura del nodo
int height(tree *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->height;
}

// Función para calcular el factor de balance de un nodo
int balanceFactor(tree *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}

// Función para realizar una rotación a la derecha
tree *rightRotate(tree *y)
{
    tree *x = y->left;
    tree *T2 = x->right;

    // Realizar rotación
    x->right = y;
    y->left = T2;

    // Actualizar alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Retornar la nueva raíz
    return x;
}

// Función para realizar una rotación a la izquierda
tree *leftRotate(tree *x)
{
    tree *y = x->right;
    tree *T2 = y->left;

    // Realizar rotación
    y->left = x;
    x->right = T2;

    // Actualizar alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Retornar la nueva raíz
    return y;
}

// Función para crear un nuevo nodo
tree *createLeaf(int data)
{
    tree *newLeaf = new tree();
    newLeaf->data = data;
    newLeaf->left = nullptr;
    newLeaf->right = nullptr;
    newLeaf->height = 1; // La altura de un nodo nuevo es 1
    return newLeaf;
}

// Función para insertar un nodo en el árbol AVL
tree *insertAVL(tree *root, int data)
{
    if (root == nullptr)
    {
        return createLeaf(data);
    }

    if (data < root->data)
    {
        root->left = insertAVL(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertAVL(root->right, data);
    }
    else
    {
        return root; // Evitar duplicados
    }

    // Actualizar la altura del nodo actual
    root->height = 1 + max(height(root->left), height(root->right));

    // Calcular el factor de balance
    int balance = balanceFactor(root);

    // Rotaciones necesarias para balancear el árbol
    // Caso izquierda-izquierda
    if (balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }

    // Caso derecha-derecha
    if (balance < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }

    // Caso izquierda-derecha
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Caso derecha-izquierda
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Función para insertar un nodo en el árbol desbalanceado
tree *insert(tree *root, int data)
{
    if (root == nullptr)
    {
        return createLeaf(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Función para imprimir el árbol en un formato visual
void printTreeVisual(tree *root, int space = 0, int level = 0)
{
    if (root == nullptr)
    {
        return;
    }

    space += 10; // Espaciado para el siguiente nivel

    // Primero imprime el subárbol derecho
    printTreeVisual(root->right, space, level + 1);

    // Imprime el nodo actual después del espacio necesario
    cout << endl;
    cout << setw(space) << root->data << "(h=" << root->height << ")" << endl;

    // Ahora imprime el subárbol izquierdo
    printTreeVisual(root->left, space, level + 1);
}

// Función para recorrer el árbol desbalanceado e insertar los nodos en un árbol AVL
void balancearArbol(tree *desbalanceado, tree *&avl)
{
    if (desbalanceado != nullptr)
    {
        balancearArbol(desbalanceado->left, avl);
        avl = insertAVL(avl, desbalanceado->data);
        balancearArbol(desbalanceado->right, avl);
    }
}

int main()
{
    tree *desbalanceado = nullptr;
    tree *avl = nullptr;

    // Insertar nodos en el árbol desbalanceado
    desbalanceado = insert(desbalanceado, 10);
    desbalanceado = insert(desbalanceado, 20);
    desbalanceado = insert(desbalanceado, 30);
    desbalanceado = insert(desbalanceado, 40);
    desbalanceado = insert(desbalanceado, 50);
    desbalanceado = insert(desbalanceado, 25);

    cout << "Árbol desbalanceado en formato visual:\n";
    printTreeVisual(desbalanceado);
    cout << endl;

    // Balancear el árbol desbalanceado
    balancearArbol(desbalanceado, avl);

    cout << "Árbol AVL balanceado en formato visual:\n";
    printTreeVisual(avl);
    cout << endl;

    return 0;
}
