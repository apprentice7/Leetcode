#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
		if(n<=0) return false; 
		bool eflag = false;
		bool dflag = false;
		int z = 0;

		while(s[z] == ' '){
			s.erase(s.begin());
		}
		z=s.size()-1;
		while(s[z] == ' '){
			s.erase(s.begin()+z);
			z = s.size()-1;
		}
		n = s.size();
		if(n<=0) return false; 
		if(n==1 && (!isdigit(s[0]))) return false;
		for(int i=0; i<n; i++){
			if(isdigit(s[i])) continue;
			else if(i==0){
				if(s[i]=='.' || s[i]=='-' || s[i]=='+'){
					if(!isdigit(s[i+1])) return false;
					else if(s[i] == '.') dflag = true;
				}
				else return false;
			}
			else if(s[i] == 'e'){
				if(eflag == false){ 
					if(i==0 || i==n-1) return false;
					if( !isdigit(s[i-1]) ) return false;
					if(s[i+1] == '-' || s[i+1] == '+'){
						if(i+2<n && isdigit(s[i+2])){
							i++;
						}
						else return false;
					}
					eflag = true;
				}
				else return false;
			}
			else if(s[i] == '.'){
				if(dflag == false){ 
					if(eflag == true) return false;
					dflag = true;
				}
				else return false;
			}
			else return false;
		}
		return true;
    }
};

 //For testing
int main(){
	Solution test;
	string s = "2e3.";
	cout << test.isNumber(s) << endl;
	return 0;
}
