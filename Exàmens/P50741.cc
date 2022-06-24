// Servidors (Nathaniel Mitrani)

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;
using Server = map<string, priority_queue<int>>;

void print_work(const priority_queue<int>& w, const bool& first)
{
    if (w.empty()) {
        cout << "-";
    } else {
        cout << w.top();
    }
    if (first)
        cout << " ";
    else
        cout << endl;
}

void transfer_work(priority_queue<int>& from_id, priority_queue<int>& to_id)
{
    if (not from_id.empty()) {
        to_id.push(from_id.top());
        from_id.pop();
    }
}

void execute_work(priority_queue<int>& w, const int& q, int& max_value)
{
    int to_do = q;
    while (not w.empty() and to_do > 0) {
        max_value = max(max_value, w.top());
        w.pop();
        to_do--;
    }
}

void read_server(Server& s)
{
    string server_id;
    cin >> server_id;
    priority_queue<int> t;
    s.insert({ server_id, t });
}

void print_summary(const Server& s, const int& max_value)
{
    cout << endl;
    cout << "MAX VALUE: " << max_value << endl;
    cout << endl;
    cout << "PENDING:" << endl;
    for (auto e : s) {
        cout << e.first << ": ";
        if (e.second.empty()) {
            cout << "-" << endl;
        } else {
            cout << e.second.top() << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Server s;
    for (int i = 0; i < n; i++)
        read_server(s);
    string instruction;
    int max_value = -1;
    while (cin >> instruction) {
        string server_id;
        int job_value;
        if (instruction == "ADD") {
            cin >> server_id >> job_value;
            if (s.count(server_id)) {
                s[server_id].push(job_value);
                print_work(s[server_id], false);
            } else
                cout << "identificador incorrecte" << endl;

        } else if (instruction == "EXECUTE") {
            int q;
            cin >> server_id >> q;
            if (s.count(server_id)) {
                execute_work(s[server_id], q, max_value);
                print_work(s[server_id], false);
            } else
                cout << "identificador incorrecte" << endl;
        } else if (instruction == "TRANSFER") {
            string from_id, to_id;
            cin >> from_id >> to_id;
            if (not s.count(from_id) or not s.count(to_id)) {
                cout << "identificador incorrecte" << endl;
            } else {
                transfer_work(s[from_id], s[to_id]);
                print_work(s[from_id], true);
                print_work(s[to_id], false);
            }
        }
    }
    print_summary(s, max_value);
}

// map of sets, ordered as map is unhashable.
