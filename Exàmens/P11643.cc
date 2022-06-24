// Quick sort amb llistes (Nathaniel Mitrani)

#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int> &lst)
{
    for (auto e : lst)
    {
        cout << " " << e;
    }
    cout << endl;
}

list<int> concatenate(list<int> left, int x, list<int> right)
{
    list<int> new_lst = left;
    new_lst.push_back(x);
    for (auto it = right.begin(); it != right.end(); it++)
    {
        new_lst.push_back(*it);
    }
    return new_lst;
}

list<int> quicksort(const list<int> lst)
{
    if (lst.size() <= 1)
        return lst;
    else
    {
        int x = *lst.begin();
        list<int> smaller, bigger;
        for (auto it = ++lst.begin(); it != lst.end(); it++)
        {
            if (x <= *it)
            {
                bigger.push_back(*it);
            }
            else
            {
                smaller.push_back(*it);
            }
        }
        return concatenate(quicksort(smaller), x, quicksort(bigger));
    }
}

list<int> qsort(const list<int> &lst)
{
    list<int> l = lst;
    return quicksort(l);
}

int main()
{
    list<int> lst;

    int x;
    while (cin >> x)
    {
        lst.push_back(x);
    }

    list<int> sorted = qsort(lst);

    for (int y : sorted)
    {
        cout << y << endl;
    }
}

/*************************************************************************************

    Expliqueu aquí quin és el cost del vostre algorisme.

*************************************************************************************/
