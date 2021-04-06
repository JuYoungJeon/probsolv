#include <iostream>
#include <string>
#include <vector>


using namespace std;

int getSubIdx(int l, string adv){
	vector<int> adv_sub(l);
	adv_sub[0]=0;
	int j=0;
	int length=0;
	for (int i=1; i<l; i++){
		while(j>0&& adv[i]!=adv[j]){
			j=adv_sub[j-1];
		}
		if(adv[i]==adv[j]){
			adv_sub[i]=j+1;
			j+=1;
		}else{
			adv_sub[i]=0;
		}
	}
	return l-adv_sub[l-1];

}


int main(void){
	int l;
	string adv;
	cin >> l ;
	cin.get();
	getline(cin, adv);

	cout << getSubIdx(l, adv);

}
