/*



*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, k, count = 0;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    while(n--){
        if(a[n] >= a[k-1] && a[n] > 0)
            count++;
    }
    cout << count << endl;    
    return 0;
}