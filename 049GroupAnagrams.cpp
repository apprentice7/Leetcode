#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        int n = strs.size();
		vector<vector<string> > output;
		if(n<1) return output;

		for(int i=0; i<n; i++){
			string temp = strs[i];
			vector<string> tmpVector;
			tmpVector.push_back(temp);
			int len = temp.size();

			if(output.size() == 0) {
				output.push_back(tmpVector);
			}
			else{
				bool flag = false;
				for(int j=0; j<output.size() && flag == false; j++){
					temp = strs[i];
					string t = output[j][0];
					int f = 0;
					for(int tPara=0; tPara<t.size(); tPara++){
						for(int sPara=0; sPara<temp.size(); sPara++){
							if(t[tPara] == temp[sPara]){
								t.erase(t.begin()+tPara);
								temp.erase(temp.begin()+sPara);
								tPara = -1;
								break;
							}
						}
					}
					if(t.size() == 0 && temp.size() == 0){
						output[j].push_back(strs[i]);
						flag = true;
					}

				}
				if(flag == false){
					output.push_back(tmpVector);
				}
			}
		}
		return output;

    }
};

//For testing
int main(){
	Solution test;
	string arr[]={"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> v;
	v.assign(arr,arr+6);
	vector<vector<string> > re;
	re = test.groupAnagrams(v);

	for(int i=0; i<re.size(); i++){
		for(int j=0; j<re[i].size(); j++){
			cout<< re[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
