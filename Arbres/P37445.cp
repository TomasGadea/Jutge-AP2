// Arbres - Amplada

#include <iostream>
#include <queue>
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

int width(Tree a)
{
    if (not a) return 0;
    queue<Tree> q;
    q.push(a);
    int width = 0;
    while (not(q.empty())) {
        int nodes_in_level = q.size();
        width = max(width, nodes_in_level);
        while (nodes_in_level > 0){
            Tree T = q.front();
            q.pop();
            --nodes_in_level;
            if (T->left) q.push(T->left);
            if (T->right) q.push(T->right);
        }
    }
    return width;
}

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {

        Tree a = read_tree();
        cout << width(a) << endl;

        delete a;
    }
}
