// find minimum value of sum (sub array of key size) from entire array each itrait
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num, k;
    cout << "enter number for array size ==== and anter key value " << endl;
    cin >> num >> k;
    int arr[num];
    int sum = 0;
    int ans = INT_MAX;
    // we can store map key as vector because store second value in map as line
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    // first we can store sum of given key length
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    // find minimum value
    ans = min(ans, sum);
    cout << ans << " ";

    // here working sliding window algorithms
    for (int i = 1; i < num - k + 1; i++)
    {
        sum -= arr[i - 1];
        sum += arr[i + k - 1];
        ans = min(ans, sum);
        cout << ans << " ";
    }
    cout << endl;
    cout << "the minimum value is = " << ans << endl;
    return 0;
}