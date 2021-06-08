// Rifa de nadal

#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;


void update(map<int,int>& nums, map<int,int>& tens, int n, int& mn, int& mt){
    ++nums[n];
    ++tens[n%100];
    if(nums[n] > nums[mn] or (nums[n] == nums[mn] && n < mn)) mn = n;
    if(tens[n%100] > tens[mt] or (tens[n%100] == tens[mt] && n%100 < mt)) mt = n%100;
}

void write(int mn, int mt, map<int,int>& nums, map<int,int>& tens)
{
    cout << mn <<' '<< nums[mn] <<' ';
    if(mt < 10) cout << 0;
    cout << mt <<' '<< tens[mt] << endl;
}

void write_end(map<int,int>& nums)
{
    cout << endl;
    for(auto a : nums){
        cout << a.first << ' ' << a.second << endl;
    }
    cout << "----------" << endl;
}

int main()
{
    int n;
    while(cin >> n){
        map<int,int> nums;
        map<int,int> tens;
        int mn = n;
        int mt = n%100;
        while(n != -1){
            update(nums, tens, n, mn, mt);
            write(mn, mt, nums, tens);
            cin >> n;
        }
        write_end(nums);
    }
}
