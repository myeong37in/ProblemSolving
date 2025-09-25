#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arr1(m, vector<int>(n,0));
    
    for(int i= 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr1[i][j];
        }
    }
    
    for(int i= 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int k;
            cin >> k;
            if(j == n-1)
                cout << arr1[i][j] + k;
            else
                cout << arr1[i][j] + k << " ";
        }
        if(i != m-1)
            cout << "\n";
    }   
}