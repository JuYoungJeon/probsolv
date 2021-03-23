#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> heights, int l, int h){
	int ans=0;
	if (l==h) return heights[l];
	int mid = (h+l)/2;
	ans = max(solution(heights, l, mid), solution(heights, mid+1, h));
	int mid_l= mid, mid_h=mid+1;
	int height=min(heights[mid_l],heights[mid_h]);
	ans = max(ans, height*2);
	while(l < mid_l || mid_h < h){
		if(mid_h < h && (mid_l == l || heights[mid_h+1]>heights[mid_l-1])){
			mid_h++;
			height = min(height, heights[mid_h]);
		}else{
			mid_l--;
			height = min(height, heights[mid_l]);
		}
		ans = max(ans, height* (mid_h-mid_l+1));
	}
	return ans;	
}

int main(){
	int numTc;
	cin >> numTc;
	int ans[50];

	for (int i=0; i< numTc; i++){
		int n; 
		vector<int> heights;
		cin >> n;
		for (int j=0; j< n; j++){
			int tmp; 
			cin >> tmp; 
			heights.push_back(tmp);
		}
		ans[i] = solution(heights, 0, n-1);
	}
	for (int i=0; i<numTc; i++)
		cout << ans[i] << '\n';
}
