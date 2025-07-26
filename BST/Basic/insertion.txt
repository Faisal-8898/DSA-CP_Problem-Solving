#include <bits/stdc++.h>
using namespace std;

// Macros for common operations
#define INF 1e9
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define F first
#define S second

// Shortcuts for frequently used code
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define REV(i, a, b) for (int i = a; i >= b; --i)
#define REPR(i, n) REV(i, n - 1, 0)

// Function for fast I/O
void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// Custom sort function (optional)
bool compare(const int &a, const int &b)
{
    return a < b;
}

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

node *minNode(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL)
    {
        return root;
    }

    return minNode(root->left);
}


int findTreeHeight(node* root) {
    if (root == nullptr) {
        return 0; // Height of an empty tree is -1
    }

    int leftHeight = findTreeHeight(root->left);
    int rightHeight = findTreeHeight(root->right);

    return std::max(leftHeight, rightHeight) + 1;
}

// Main function
int main()
{

    // Your code here
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

    preorder(root);
    cout<< minNode(root)->value<< endl;
    cout << findTreeHeight(root);

    return 0;
}
