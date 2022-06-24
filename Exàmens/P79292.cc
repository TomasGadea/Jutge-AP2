// Queues of a supermarket (3) (Nathaniel Mitrani)

#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<sstream>
using namespace std;


int rank_to_int(const string& rank){
    if (rank=="soldier") return 0;
    else if (rank=="sergeant") return 1;
    else if (rank=="captain") return 2;
    else return 3;
}

struct military {
    int rank;
    string name;
    int timestamp;
    bool operator< (const military&rhs) const{
        if (rank==rhs.rank){
            return timestamp>rhs.timestamp;
        }
    return rank<rhs.rank;
}
};

bool valid_queue(const int &n, const int& queue){
    return queue>=1 and queue<=n;
}

void print_supermarket(vector<priority_queue<military>>&s){
    cout<<endl;
    cout<<"FINAL CONTENTS"<<endl;
    cout<<"--------------"<<endl;
    for (int i=0;i<s.size();i++){
        cout<<"queue "<<i+1<<":";
        while (not s[i].empty()){
            cout<<" "<<s[i].top().name;
            s[i].pop();
        }
        cout<<endl;
    }
}

vector<priority_queue<military>> read_supermarket(const int &n, int&i){
vector<priority_queue<military>> s(n);
string line;
getline(cin, line);
for (int k=0;k<n;k++){
string name,rank;
getline(cin,line);
istringstream iss(line);
while (iss>>name){
    iss>>rank;
    military m;
    m.name=name;
    m.rank=rank_to_int(rank);
    m.timestamp=i++;
    s[k].push(m);
}
}
return s;
}

int main (){
int n,i=0;
cin>>n;
vector<priority_queue<military>> s=read_supermarket(n,i);
string instructions;

cout<<"DEPARTS"<<endl;
cout<<"-------"<<endl;

while (cin>>instructions){
    string name, rank;
    int queue_number;
    if (instructions=="LEAVES"){
    cin>>queue_number;
    if (valid_queue(n, queue_number) and not s[queue_number-1].empty()){
        cout<<s[queue_number-1].top().name<<endl;
        s[queue_number-1].pop();
    }
    }
    else if (instructions=="ENTERS"){
        cin>>name>>rank>>queue_number;
        military m;
        m.name=name;
        m.rank=rank_to_int(rank);
        m.timestamp=i++;
        if (valid_queue(n,queue_number)){
            s[queue_number-1].push(m);
        }
    }
}
print_supermarket(s);
}
