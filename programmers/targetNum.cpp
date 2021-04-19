#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target, int value){
	if(numbers.size()==0 && value==target) return 1;
	if(numbers.size()==0) return 0;
	int ans=0;
	int target_num=numbers.back();
	numbers.pop_back();
	value+=target_num;
	ans+=dfs(numbers, target, value);
	value-=(target_num*2);
	ans+=dfs(numbers, target, value);
	numbers.push_back(target_num);
	value+=target_num;
	return ans;
}

	

int solution(vector<int> numbers, int target) {
    int answer = 0;
	answer=dfs(numbers, target, 0);

    return answer;
}
