#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const int MOD = 1000000007;
const ll inv2 = 500000004; // Обратный элемент для 2 по модулю 1e9+7

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;
    
    ll sum1 = 0; // Сумма a_i
    ll sum2 = 0; // Сумма a_i^2
    ll result = 0;
    
    for(int k = 0; k < n; ++k){
        if(k >= 2){
            // (sum1^2 - sum2) / 2
            ll temp = (sum1 * sum1) % MOD;
            temp = (temp - sum2 + MOD) % MOD;
            temp = (temp * inv2) % MOD;
            // Добавляем a_k * temp к результату
            result = (result + (a[k] % MOD) * temp) % MOD;
        }
        // Обновляем sum1 и sum2
        sum1 = (sum1 + a[k]) % MOD;
        sum2 = (sum2 + (a[k] * a[k]) % MOD) % MOD;
    }
    
    cout << result;
    return 0;
}