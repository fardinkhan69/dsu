
#include <bits/stdc++.h>

using namespace std;
long long int binarySearch(const vector<long long>& prefix_sum, long long x) {
    long long int left = 0;
    long long int right = prefix_sum.size() - 1;

    while (left <= right) {
        long long int mid = left + (right - left) / 2;
        if (prefix_sum[mid] >= x) {
            if (mid == 0 || prefix_sum[mid-1] < x) {
                return mid;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long long int> A(n+1,0);
    vector<long long int> prefix_sum(n+1,0);

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        prefix_sum[i] = prefix_sum[i-1] + A[i];
    }

    long long int q;
    cin>>q;
    while(q--){
        long long int s;
        cin>>s;
        long long int index = binarySearch(prefix_sum,s);
        if(index == -1 || index > n){
            cout<<"-1 \n";
        }else{
            cout<<index<<"\n";
        }
    }
    
    
    return 0;
}