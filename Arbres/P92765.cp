// Arbres - Buscant en un arbre de cerca

#include <iostream>
using namespace std;

struct Node {
    int x;
    Node* left;
    Node* right;
    ~Node() {
        delete left;
        delete right;
    }
};

using Tree = Node*;


Tree read_bst()
{
    int x;
    cin >> x;
    if (x == -1) {
        return nullptr;
    } else {
        Tree l = read_bst();
        Tree r = read_bst();
        return new Node { x, l, r };
    }
}


bool contains(Tree T, int num)
{
    if (not T) return false;
    if (num == T->x) return true;
    if (num > T->x) return contains(T->right, num);
    if (num < T->x) return contains(T->left, num);
}


int main()
{
    int useless;
    cin >> useless;
    Tree T = read_bst();

    int num;
    while(cin >> num) {
        cout << num <<' '<< contains(T, num) << endl;
    }
    delete T;
}
