// Arbres Verd-Blau


#include <iostream>
using namespace std;

struct Node;

using Tree = Node*;

struct Node {
    char col;  //color of the Node
    Tree left;
    Tree right;

    ~Node()   // destructor
    {
        delete left;
        delete right;
    }
};




Tree read_tree()
{
    char c;
    cin >> c;
    if (c == '-') {
        return nullptr;
    } else {
        Tree l = read_tree();
        Tree r = read_tree();
        return new Node {c, l, r};
    }
}



// Given a Tree T and the int H (blue height)
// returns whether T has the two properties of green-blue trees
bool is_green_blue(Tree T, int& H)
{
    if (T == nullptr) {
        // Base case:
        H = 0;
        return true;
    }
    int Hl, Hr;  // blue heights for left subtree and right subtree (will be returned by the recursion)

    bool both = is_green_blue(T->left, Hl) and is_green_blue(T->right, Hr);

    if (T->col == 'B') H = Hl + 1;  // Increase blue height. Notice Hl = Hr (if not, we'll return false)

    if (T->col == 'G') {
        H = Hl;  // Do not increase blue height

        // Check blue children condition:
        if (T->left != nullptr and T->left->col != 'B') return false;
        if (T->right != nullptr and T->right->col != 'B') return false;
    }

    return both and Hl == Hr;
}



int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Tree T = read_tree();
        int H = 0;
        if (is_green_blue(T, H)) cout << H;
        else cout << "no";
        cout << endl;

        delete(T);  // free memory
    }
}
