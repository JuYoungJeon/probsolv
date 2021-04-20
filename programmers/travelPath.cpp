#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct ap{
	string city;
	queue<string> destin;
};

vector<ap> airports;
map<string, int> ap2idx;
vector<string> path;
vector<string> alphPath;
int apIdx=0;
int leftTickets=0;

void dfs(int idx){
	if(leftTickets==0) {
		if(alphPath.empty()) alphPath=path;
		else{
			for(int i=0; i<path.size(); i++){
				if(path[i].compare(alphPath[i])<0){
					alphPath=path;
					break;
				}else if(path[i].compare(alphPath[i])>0) break;
			}
		}
		return ;
	}
	for(int i=0; i<airports[idx].destin.size(); i++){
		if(airports[idx].destin.empty()) return ;
		else{
			string nextDest = (airports[idx].destin).front();
			(airports[idx].destin).pop();
			leftTickets-=1;
			path.push_back(nextDest);
			dfs(ap2idx.find(nextDest)->second);
			leftTickets+=1;
			(airports[idx].destin).push(nextDest);
			path.pop_back();
		}
	}
	return ;

}

vector<string> solution(vector<vector<string> > tickets){
	vector<string> answer;
	for(int i=0; i<tickets.size(); i++){
		if(ap2idx.find(tickets[i][0])==ap2idx.end()){
			ap2idx.insert(make_pair(tickets[i][0], apIdx));
			apIdx++;
			ap newAirport = {tickets[i][0], queue<string>()};
			newAirport.destin.push(tickets[i][1]);
			airports.push_back(newAirport);
		}else{
			airports[ap2idx.find(tickets[i][0])->second].destin.push(tickets[i][1]);
		}
		if(ap2idx.find(tickets[i][1])==ap2idx.end()){
			ap2idx.insert(make_pair(tickets[i][1], apIdx));
			apIdx++;
			ap newAirport ={tickets[i][1]};
			airports.push_back(newAirport);
		}
		leftTickets+=1;
	}
	int targetIdx=ap2idx.find("ICN")->second;
	path.push_back(airports[targetIdx].city);
	dfs(targetIdx);
	answer=alphPath;
	return answer;
}

int main(void){
	/*vector<vector<string> > vec {
		{"A", "C"}, {"A", "D"}, {"D", "B"}, {"B", "A"}, {"ICN", "A"}};
	auto a = solution(vec);
	for(int i=0; i<a.size(); i++){
		cout << a[i] <<'\n';
	}*/
	vector<vector<string> > vec2 {
		{"ICN", "A"}, {"A", "C"}, {"A", "D"}, {"D", "B"}, {"B", "A"}};
	auto a = solution(vec2);
	for(int i=0; i<a.size(); i++){
		cout << a[i] <<'\n';
	}
}

