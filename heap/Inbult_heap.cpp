#include <bits/stdc++.h>
using namespace std;

int main()
{
    // this will be perform always maxheap
    priority_queue<int, vector<int>> pq;

    // this will be perform always minheap
    // priority_queue<int,vector<int>,greater<int>> pq;

    // we can inisiliz other way of min heap see below
    int num;
    // for (int i = 0; i < 6; i++)
    // {
    //     cin >> num;
    //     // store with minus value
    //     pq.push(-num);
    // }
    // while (!pq.empty())
    // {
    //     // and print with minus value than we get right value of minheap
    //     cout << -pq.top() << " ";
    //     pq.pop();
    // }

    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        pq.push(num);
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
