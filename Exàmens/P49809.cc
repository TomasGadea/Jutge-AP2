// Lowest common ancestor (Nathaniel Mitrani)

#include <iostream>
using namespace std;

// define standard binary trees

struct Node;

using Tree = Node*;

struct Node {
    int x;
    Tree left;
    Tree right;

    ~Node()
    {
        delete left;
        delete right;
    }
};

// reads a tree according to the specification in the problem statement
Tree read()
{
    int x;
    cin >> x;
    if (x == -1) {
        return nullptr;
    } else {
        Tree left = read();
        Tree right = read();
        return new Node { x, left, right };
    }
};

bool is_inside(Tree T, int x){
    if (T == nullptr) return false;
    if (T->x == x) return true;
    else return (is_inside(T->left,x) or is_inside(T->right,x));
}

Tree lowest_common_ancestor(Tree T, int x, int y)
{
    if (is_inside(T->left,x) and is_inside(T->left,y)) return lowest_common_ancestor(T->left,x,y);
    else if (is_inside(T->right,x) and is_inside(T->right,y)) return lowest_common_ancestor(T->right,x,y);
    else return T;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Tree t = read();
        int u, v;
        cin >> u >> v;
        while (u != -1) {
            Tree lca = lowest_common_ancestor(t, u, v);
            cout << lca->x << endl;
            cin >> u >> v;
        }
        delete t;
        cout << endl;
    }
}
