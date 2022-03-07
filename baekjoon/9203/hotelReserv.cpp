#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>

using namespace std;

string addCleaning(string t, int clean){
	int y, m, d, h, min;
	y=stoi(t.substr(0,4));
	m=stoi(t.substr(5,2));
	d=stoi(t.substr(8,2));
	h=stoi(t.substr(11,2));
	min = stoi(t.substr(14,2))+clean;	
	if(min>=60) {
		h+=(min/60);
		min%=60;
	}
	if(h>=24){
		d+=1;
		h%=24;
	}
	if(y%4==0&&m==2&&d>=30){
		m+=1;
		d=1;
	}else if(y%4!=0&&m==2&&d>=29){
		m+=1;
		d=1;
	}else if(((m<8&&m%2==0)||(m>=8&&m%2==1))&&d>30){
		m+=1;
		d=1;
	}else if(d>31){
		m+=1;
		d=1;
	}
	if(m>12){
		y+=1;
		m=1;
	}
	string sy, sm, sd, sh, smin;
	sy=to_string(y);
	sm=m<10?'0'+to_string(m):to_string(m);
	sd=d<10?'0'+to_string(d):to_string(d);
	sh=h<10?'0'+to_string(h):to_string(h);
	smin=min<10?'0'+to_string(min):to_string(min);
	return sy+'-'+sm+'-'+sd+' '+sh+':'+smin;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC;
	cin >> TC;
	while(TC--){
		int B, C;
		int ans=0;
		cin >> B >>C;
		vector<pair<string, string>> resv;
		for(int i=0;i<B; i++){
			string idx, inDate, inTime, outDate, outTime;
			cin >> idx >> inDate >> inTime >> outDate >> outTime;
			resv.push_back({inDate+' '+inTime, addCleaning(outDate+' '+outTime, C)});
		}
		sort(resv.begin(), resv.end());

		priority_queue<string, vector<string>, greater<string>> pq;
		for(auto c: resv){
			while(!pq.empty()&&(pq.top()<=c.first)) pq.pop();
			pq.push(c.second);
			ans = ans> pq.size()?ans: pq.size();
		}
		cout << ans<<'\n';
	}
}
