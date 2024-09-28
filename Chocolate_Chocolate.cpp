#include <bits/stdc++.h>

using namespace std;
int exchange_wrapper(int wrapper)
{
    if (wrapper < 3)
    {
        return 0;
    }
    int choc = wrapper / 3;
    int remain = wrapper % 3;
    return choc + exchange_wrapper(choc + remain);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int choclate = n / 5;
        int wrapper = choclate;
        int newChoc = exchange_wrapper(wrapper);
        cout << choclate + newChoc << endl;
    }
    return 0;
}