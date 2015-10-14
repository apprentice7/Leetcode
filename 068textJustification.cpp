#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
		unsigned int max = maxWidth;
		vector<string> result;

		while(words.size() > 0){
			string output;
			
			//check number of words
			int i = 0;
			int l = words[i].size();
			while(i<words.size()-1 && l < max){
				i++;
				l = l + 1 + words[i].size();
			}
			if(i!=0){
				l = l - 1 - words[i].size();
				i--;
			}
			//check words and space
			int wordsLen = 0;
			for(int j=0; j<i+1; j++){
				wordsLen += words[j].size();
			}
			int space = maxWidth - wordsLen;
			if(i==0){
				output += words[0];
				while(space>0){
					output += ' ';
					space--;
				}	
			}
			else{
				int rearSpace = space / i;
				int addSpace = space % i;
				string fSpace;
				string rSpace;
				for(int s=0; s<rearSpace;s++){
					rSpace += ' ';
				}
				fSpace = rSpace + ' ';
				
				//append words and space to a new string
				for(int s=0; s<i+1; s++){
					output += words[s];
					if(s==i) break;
					if(addSpace>0) {
						output += fSpace;
						addSpace--;
					}
					else{
						output += rSpace;
					}
				}
			}
			result.push_back(output);
			words.erase(words.begin(),words.begin()+i+1);
		}
		return result;
    }
};

 //For testing
int main(){
	Solution test;
	vector<string> v;
	string arr[] = {"this","is","an","example","of","text","justification."};
	v.assign(arr,arr+7);
	vector<string> out;
	out = test.fullJustify(v,16);
	for(int i=0; i<out.size();i++){
		cout<<out[i]<<endl;
	}
	return 0;
}
