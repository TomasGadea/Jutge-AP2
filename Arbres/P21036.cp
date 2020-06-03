// Arbres - Escrivint un arbre

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string word;
    int level;
    Node* left;
    Node* right;
    ~Node() {
        delete left;
        delete right;
    }
};

using Tree = Node*;


Tree read_tree(int level)
{
    string word;
    cin >> word;
    if (word == "-1") {
        return nullptr;
    } else {
        Tree l = read_tree(level+1);
        Tree r = read_tree(level+1);
        return new Node {word, level, l, r};
    }
}

void print_line(string& word, int level)
{
    for (int i = 0; i < level*10 - word.size(); ++i) {
        cout << ' ';
    }
    cout << word << endl;
}

void pretty_write(Tree T)
{
    if (T) {
        pretty_write(T->right);
        print_line(T->word, T->level);
        pretty_write(T->left);
    }
}

int main()
{
    Tree T = read_tree(1);
    pretty_write(T);
}
