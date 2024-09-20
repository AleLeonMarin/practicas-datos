#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

tree *createLeef(int data)
{
    tree *newLeef = new tree();
    newLeef->data = data;
    newLeef->left = nullptr;
    newLeef->right = nullptr;
    return newLeef;
}

tree *insert(tree *root, int data)
{

    if (root == nullptr)
    {
        return createLeef(data);
    }
    else
    {
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
    }

    return root;
}

tree *printTree(tree *root)
{
    if (root != nullptr)
    {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }

    return root;
}

tree *printPostOrder(tree *root)
{

    if (root != nullptr)
    {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->data << " ";
    }

    return root;
}

tree *printPreOrder(tree *root)
{

    if (root != nullptr)
    {
        cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }

    return root;
}

tree *search(tree *root, int data)
{
    if (root == nullptr || root->data == data)
    {
        return root;
    }

    if (root->data < data)
    {
        return search(root->right, data);
    }

    return search(root->left, data);
}

tree *deleteNode(tree *root, int data)
{
    if (root == nullptr)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == nullptr)
        {
            tree *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            tree *temp = root->left;
            delete root;
            return temp;
        }

        tree *temp = root->right;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

tree *minValueNode(tree *root)
{
    tree *current = root;

    while (current->left != nullptr)
    {
        current = current->left;
    }

    return current;
}

tree *maxValueNode(tree *root)
{
    tree *current = root;

    while (current->right != nullptr)
    {
        current = current->right;
    }

    return current;
}

tree *successor(tree *root, int data)
{
    tree *current = search(root, data);

    if (current == nullptr)
    {
        return nullptr;
    }

    if (current->right != nullptr)
    {
        return minValueNode(current->right);
    }

    tree *successor = nullptr;

    while (root != nullptr)
    {
        if (current->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (current->data > root->data)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }

    return successor;
}

tree *predecessor(tree *root, int data)
{
    tree *current = search(root, data);

    if (current == nullptr)
    {
        return nullptr;
    }

    if (current->left != nullptr)
    {
        return maxValueNode(current->left);
    }

    tree *predecessor = nullptr;

    while (root != nullptr)
    {
        if (current->data > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else if (current->data < root->data)
        {
            root = root->left;
        }
        else
        {
            break;
        }
    }

    return predecessor;
}

tree *deleteTree(tree *root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    return nullptr;
}

int sumLeafsAndUpdate(tree *root)
{
    // Si el nodo es nulo, retornar 0
    if (root == nullptr)
    {
        return 0;
    }

    // Si el nodo es una hoja, retornar su valor (sin modificarlo)
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->data;
    }

    // Obtener la suma de los subárboles izquierdo y derecho
    int sumLeft = sumLeafsAndUpdate(root->left);
    int sumRight = sumLeafsAndUpdate(root->right);

    // Actualizar el valor del nodo actual con la suma de sus hijos
    root->data = sumLeft + sumRight;

    // Retornar la nueva suma del nodo actualizado
    return root->data;
}

tree *invertTree(tree *root)
{
    // Caso base: si el nodo es nulo, no hacer nada
    if (root == nullptr)
    {
        return nullptr;
    }

    // Intercambiar los subárboles izquierdo y derecho
    tree *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Llamar recursivamente para los subárboles izquierdo y derecho
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main()
{

    tree *root = nullptr;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 12);
    root = insert(root, 18);

    cout << "Tree: ";
    printTree(root);
    cout << endl;

    cout << "PostOrder: ";
    printPostOrder(root);
    cout << endl;

    cout << "PreOrder: ";
    printPreOrder(root);
    cout << endl;

    // Invertir el árbol una sola vez
    cout << "Inverted tree: ";
    invertTree(root);
    printTree(root);
    cout << endl;

    // Recorrer el árbol invertido en PostOrden y PreOrden sin volver a invertir
    cout << "Inverted tree PostOrder: ";
    printPostOrder(root); // Recorrido postorden del árbol invertido
    cout << endl;

    cout << "Inverted tree PreOrder: ";
    printPreOrder(root); // Recorrido preorden del árbol invertido
    cout << endl;

    // Sumar hojas y actualizar el árbol
    cout << "Sum of leafs and update predecessor: ";
    invertTree(root);
    sumLeafsAndUpdate(root);
    printTree(root);
    cout << endl;

    return 0;
}
