#include <vector>
#include <iostream>
using namespace std;
class Solution{
	public:
		vector<string> res;
		void recur(string temp,int open ,int close){
			if(open==0&&close==0){
				res.push_back(temp);
			}
			if(open>0){
				recur(temp+"(",open-1,close);
			}
			if(close>0){
				recur(temp+")",open,close-1);
			}
		}
		vector<string> deal(int n){
			recur("",n,n);
			return res;
		}
};
int main(){

	Solution call;
	vector<string> temp= call.deal(3);
	printf("%s",temp[0]);

	return 0;

}

