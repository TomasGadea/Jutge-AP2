// Arbres - Recorreguts recursius

#include<iostream>
using namespace std;

struct Node;

using Tree = Node*;

struct Node{
    int x;
    Tree left;
    Tree right;

    ~Node()
    {
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
        return new Node {x, l, r};
    }
}

void write_postorder(Tree a)
{
    if (a != nullptr) {
        write_postorder(a->left);
        write_postorder(a->right);
        cout << " " << a->x;

    }
}

void write_inorder(Tree a)
{
    if (a != nullptr) {
        write_inorder(a->left);
        cout << " " << a->x;
        write_inorder(a->right);

    }
}

int main()
{
    Tree a = read_tree();
    cout << "pos:";
    write_postorder(a);
    cout << endl;
    cout << "ino:";
    write_inorder(a);
    cout << endl;
    delete a;
}
