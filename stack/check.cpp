#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    t = t - 1;
lable1:
    int num;
    cin >> num;
    long long n, check, count = 0, co = 0;
    cin >> n >> check;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
lable:
    for (int i = 0; i < num; i++)
    {
        if (count < check)
        {
            if (co == num - 1)
            {
                co = 0;
                count++;
                arr[i] = arr[i] ^ n;
                goto lable;
            }
            co++;
            count++;
            arr[i] = arr[i] ^ n;
        }
        else
        {
            break;
        }
    }
    sort(arr, arr + num);
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    while (t--)
    {
        goto lable1;
    }
    return 0;
}
