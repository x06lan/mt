#include <vector>
#include <iostream>
using namespace std;
class Solution{
	public:
		vector<string> res;
		void recur(string temp,int open ,int close){
			//printf("s=%s o=%d c=%d\n",temp,open,close);
			if(open==0&&close){
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
	printf("%s",temp);

	return 0;

}

