class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
		int count = 0;
		for(int i=0; i<n-1; i++){
			if(s[i] == '0'){
				count += 2;
			}
			else if(s[i] == '2'){
				if((s[i+1] - '0') > 6) count++;
			}
		}
		int para = n-1-count;
		if(para<0) return 0;
		return pow(2.0,para);
    }
};
