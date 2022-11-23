// find subarray sum = 0 of given array
// WE CAN HELP OF HASHING
// hashing work as unorder_map
// hashing means -> first value stored and second store it's key
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int arr[num];
    int sum = 0;

    // we can store map key as vector because store second value in map as line
    map<int, int> m;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < num; i++)
    {
        sum += arr[i];
        m[sum]++;
    }
    int ans = 0;
    for (auto val : m)
    {
        int c = val.second;
        ans += (c * (c - 1)) / 2;
        if (val.first == 0)
        {
            ans += val.second;
        }
    }
    cout << "the sub is = " << ans << endl;
    return 0;
}