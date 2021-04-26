#include <iostream>
#include <algorithm>

using namespace std;

int c[500000];
int f[500000];

int main(void){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> c[i];
    int m;
    cin >> m;
    for(int i=0; i<m; i++)
        cin >> f[i];
    sort(c, c+n);
    sort(f, f+m);
    int maxIdx=n-1;
    int minIdx=0;
    int midIdx;
    for(int i=0; i<m; i++){
        bool found=false;
        midIdx=(maxIdx+minIdx)/2;
        maxIdx=n-1;
        while(maxIdx>=minIdx){
            if(c[midIdx]==f[i]){
                found=true;
                break;
            }
            if(c[midIdx]<f[i])
                minIdx=midIdx+1;
            if(c[midIdx]>f[i])
                maxIdx=midIdx-1;
            midIdx=(maxIdx+minIdx)/2;
        }
        if(found) cout << "1 ";
        else cout << "0 ";
    }

}
