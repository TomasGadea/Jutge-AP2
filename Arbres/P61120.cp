// Arbres - Profunditat

#include <iostream>
using namespace std;

struct Node;

using Tree = Node*;

struct Node {
    int x;
    Tree left;
    Tree right;

    ~Node() {
        delete left;
        delete right;
    }
};

Tree read_tree()
{
    int x;
    cin >> x;
    if (x == -1) {
        return nullptr;
    } else {
        Tree l = read_tree();
        Tree r = read_tree();
        return new Node { x, l, r };
    }
}

int levels(Tree a)
{
    if (a == nullptr) return 0;

    return max(levels(a->left), levels(a->right)) + 1;
}

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {

        Tree a = read_tree();

        cout << levels(a) << endl;

        delete a;
    }
}
