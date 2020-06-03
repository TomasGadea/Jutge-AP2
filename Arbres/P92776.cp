// Arbres - Inserint en un arbre de cerca

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


void insert(int num, Tree& T)
{
    if (not T) T = new Node {num, nullptr, nullptr};
    else if (num > T->x) insert(num, T->right);
    else if (num < T->x) insert(num, T->left);
}

void write_preorder(Tree T)
{
    if (T != nullptr) {
        cout << T->x << endl;
        write_preorder(T->left);
        write_preorder(T->right);
    }
}


int main()
{
    Tree T = nullptr;
    int num;
    while (cin >> num) {
        insert(num, T);
    }

    write_preorder(T);
    delete T;
}
