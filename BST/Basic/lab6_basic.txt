#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node *left, *right;

} *root = NULL;

struct node *insert_tree(struct node *root, int item)
{
    if (root == NULL)
    {
        root = new node;

        root->left = NULL;
        root->right = NULL;
        root->value = item;
        return root;
    }
    else if (item < root->value)
        root->left = insert_tree(root->left, item);
    else
        root->right = insert_tree(root->right, item);
    return root;
}

void preorder(struct node *root)
{

    if (root != NULL)
    {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{

    if (root != NULL)
    {

        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}

struct node *searchTree(struct node *root, int searchValue)
{
    if (root == NULL || root->value == searchValue)
        return root;
    if (searchValue > root->value)
    {
        return searchTree(root->right, searchValue);
    }
    return searchTree(root->left, searchValue);
}

struct node *searchMin(struct node *root)
{
    if (root->left == NULL)
        return root;
    return searchMin(root->left);
}
struct node *searchMax(struct node *root)
{
    if (root->right == NULL)
        return root;
    return searchMin(root->right);
}
struct node *deleteNode(struct node *root, int value)
{
    searchMin(root);
    if (root->left == NULL && root->right == NULL)
    {

        delete (root);
        root = NULL;
        return root;
    }

    else if (root->left == NULL)
    {
        node *temp = root;
        root = root->right;
        delete (temp);
        return root;
    }

    else if (root->right == NULL)
    {
        node *temp = root;
        root = root->left;
        delete (temp);
        return root;
    }
    
    else
    {
        node *temp = searchMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
        return root;
    }
}
int main()
{

    while (1)
    {
        cout << "\nMENU\n";
        cout << "1.Insert Operation\n";
        cout << "2.Search Operation\n";
        cout << "3.Traversal Operation\n";
        cout << "4.Deletion Operation\n";
        cout << "5.Smallest and Largest Element Searching Operation\n";
        cout << "6.To terminal the program\n";
        int enter;
        cout << "Enter your choise: ";
        cin >> enter;
        switch (enter)
        {
        case 1:
            int item;
            int n;
            cout << "Insert the number of tree: \n";
            cin >> n;
            while (n--)
            {
                cout << "Insert the value: \n";
                cin >> item;
                root = insert_tree(root, item);
            }
            break;
        case 3:
            cout << "\n Preorder: \n";
            preorder(root);
            cout << "\n Inorder: \n";
            inorder(root);
            cout << "\n Postorder: \n";
            postorder(root);
            break;
        case 2:
            int searchValue;
            cout << "Enter the search value: \n";
            cin >> searchValue;
            if (searchTree(root, searchValue))
                cout << "Found \n";
            else
                cout << "Not found \n";
            break;
        case 5:
            cout << "Smallest Value\n";
            searchMin(root);
            cout << root->value << "\n";
            cout << "Largest Value\n";
            searchMin(root);
            cout << root << "\n";
            break;
        case 4:
            int delvalue;
            cin >> delvalue;
            deleteNode(root, delvalue);
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Wrong choise \n";
            break;
        }
    }
}
