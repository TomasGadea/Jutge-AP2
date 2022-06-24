// Escriptura d'arbres en graelles (Nathaniel Mitrani)

#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct BinT;
using Tree = BinT*;
using Matrix = vector<vector<char>>;
using row = vector<char>;

struct BinT{
    char x;
    int nodes;
    int depth;
    Tree left;
    Tree right;
};

struct info{
    int nodes;
    int levels;
};

Tree read_tree(){
    char c;
    cin>>c;
    if (c=='-') return new BinT{'-',0,0,nullptr,nullptr};
    else {
        Tree l = read_tree();
        Tree r = read_tree();
        int nodes = l->nodes+r->nodes;
        int depth = max(l->depth,r->depth);
        return new BinT{c,nodes+1,depth+1,l,r};
    }
}

void paint_in_grid(Tree&T,Matrix&grid, int i, int j){
    if (T->x != '-'){
        int l=T->left->nodes;
        grid[i][j+l]=T->x;
        paint_in_grid(T->left,grid,i+1,j);
        paint_in_grid(T->right,grid,i+1,j+l+1);
    }
}

int main (){
    int n;
    cin>>n;
    while (n--){
        Tree T=read_tree();
        Matrix grid(T->depth, row(T->nodes,'.'));
        paint_in_grid(T,grid,0,0);
    
    for (int i=0;i<grid.size();i++){
        for (int j=0;j<grid[0].size();j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    }
}
