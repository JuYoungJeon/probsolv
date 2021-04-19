#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long min_time=*min_element(times.begin(), times.end());
    long long minAns=min_time;
    long long maxAns=(long long)(min_time)*n;

    while(minAns <= maxAns){
        long long mid = (long long)(maxAns+minAns)/2;
        long long leftA=0;
        long long leftB=0;
        answer=mid;
        for(int i=0; i<times.size(); i++){
            leftA+=(long long)(mid/times[i]);
            leftB+=(long long)((mid-1)/times[i]);
        }
		cout << leftA << ' ' << leftB <<'\n';
        if(leftA>=n && leftB<n) break;
        if (leftA>=n){
            maxAns=mid-1;
        }else if(leftA<n){
            minAns=mid+1;
        }
    }
    return answer;
}

int main(void){
	vector <int > a;
	a.push_back(6); a.push_back(10); 
	cout << solution(6, a)<<'\n';
}
