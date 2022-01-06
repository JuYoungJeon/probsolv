#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    int arr[1000000];
    while(cin>>x){
        int n;
        memset(arr, 0, sizeof(arr));
        cin >> n;
        x*=10000000;
        for(int i=0;i<n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        long long l, r;
        bool found=false;
        for(int i=0; i<n-1; i++){
            int tar = x-arr[i];
            r=*lower_bound(arr+i+1, arr+n, tar);
            if(r==tar){
                l=arr[i];
                found=true;
                break;
            }
        }
        if(!found){
            cout << "danger\n";
        }else{
            cout << "yes "<<l<<' '<<r<<'\n';
        }
    }

}
