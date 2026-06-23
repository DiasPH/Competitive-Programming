#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n, x;
    cin >> n >> x;

    deque<int> dq;
    for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    dq.push_back(num);
    }
    sort(dq.begin(), dq.end());


    int res = 0;
    while(!dq.empty()){
        if(dq.front() + dq.back() <= x && dq.size() != 1){
            dq.pop_front();
            dq.pop_back();
            res++;
        }
        else{
            dq.pop_back();
            res++;
        }
    }

    cout << res << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}