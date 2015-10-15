// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 15-10-2015

/********************************************************************************** 
* Given an absolute path for a file (Unix-style), simplify it.
* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
* Corner Cases:
* Did you consider the case where path = "/../"?
* In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
* In this case, you should ignore redundant slashes and return "/home/foo".
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
    vector<string> sPath;
		string output;
		sPath = splitPath(path);
		int n = sPath.size();

		for(int i=0; i<n; i++){
			if(output != "/" ) output += '/';
			if(sPath[i] == "."){
				output.pop_back();
			}
			else if(sPath[i] == ".."){
				if(output.size() == 1 || i==0) continue;
				else{
					output.pop_back();
					while(output.back() != '/'){
						output.pop_back();
					}
					output.pop_back();
				}
			}
			else{
				output += sPath[i];
			}
		}
		if(output.size() == 0) output.push_back('/');
		return output;
		
    }
	vector<string> splitPath(string path){
		int n = path.size();
		string out;
		vector<string> re;
		for(int i=0; i<n; i++){
			if(path[i] =='/'){
				if(out.size()!=0){
					re.push_back(out);
					out.clear();
				}
				else if(i==n-1) continue;
				else {
					while(path[i+1]=='/'){
						i++;
					}
				}
			}
			else {
				out += path[i];
			}
		}
		if(out.size()!=0){
			re.push_back(out);
		}
		return re;
	}
};

/* //For testing
int main(){
	Solution test;
	//string arr = "//home//./boom//../";
	//string arr = "/a/./b/../../c/";
	//string arr = "/home/../../..";
	//string arr = "///eHx/..";
	string arr = "/..";
	cout<< test.simplifyPath(arr) << endl;

	return 0;
}
*/
