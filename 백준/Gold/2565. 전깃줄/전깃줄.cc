#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, ret = 0;
    cin >> n;
    int A[501] = {}, dp[501];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        A[a] = b;
    }

    for(int i = 0; i < 501; i++){
        dp[i] = 1;
    }

    for(int i = 1; i < 501; i++){
        if(A[i] == 0) continue;
        for(int j = 1; j < i; j++){
            if(A[i] > A[j] && A[j] != 0){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ret = max(ret, dp[i]);
    }
    cout << n - ret;
    return 0;
}