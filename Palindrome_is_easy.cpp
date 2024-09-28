#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool canMakePalindrome(string s, int l, int r, int k) {
    vector<int> freq(26, 0);
    for (int i = l - 1; i < r; i++) {
        freq[s[i] - 'a']++;
    }
    
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }
    
    int len = r - l + 1;
    if (len % 2 == 0) {
        return oddCount <= k * 2;
    } else {
        return oddCount - 1 <= k * 2;
    }
}

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int q;
    cin >> q;
    
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        
        if (canMakePalindrome(s, l, r, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}