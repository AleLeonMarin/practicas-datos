#include <iostream>

using namespace std;

struct tree
{
    int data;
    int height;
    tree *left;
    tree *right;
};

tree *createLeaf(int data)
{
    tree *leaf = new tree;
    leaf->data = data;
    leaf->height = 1;
    leaf->left = nullptr;
    leaf->right = nullptr;
    return leaf;
}

int height(tree *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->height;
}

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

    root->height = 1 + max(height(root->left), height(root->right));

    return root;
}

tree *printInorder(tree *root)
{
    if (root == nullptr)
    {
        return root;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);

    return root;
}

tree *printPreorder(tree *root)
{
    if (root == nullptr)
    {
        return root;
    }

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);

    return root;
}

tree *printPostorder(tree *root)
{
    if (root == nullptr)
    {
        return root;
    }

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";

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

    return root;
}

int calculateHeight(tree *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return 1 + max(calculateHeight(root->left), calculateHeight(root->right));
}

tree *deleteNode(tree *root, int data)
{

    if (root == nullptr)
    {
        return root;
    }
    else
    {

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
    }

    return root;
}

int main()
{

    tree *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder: ";
    printPreorder(root);
    cout << endl;

    cout << "Postorder: ";
    printPostorder(root);
    cout << endl;

    int data;

    cout << "Ingrese el dato a buscar: ";
    cin >> data;

    tree *found = search(root, data);

    if (found != nullptr)
    {
        cout << "Dato encontrado: " << found->data << endl;
    }
    else
    {
        cout << "Dato no encontrado" << endl;
    }

    cout << "Ingrese el dato a eliminar: ";
    cin >> data;

    root = deleteNode(root, data);


    cout << "Inorder: ";

    printInorder(root);

    return 0;
}