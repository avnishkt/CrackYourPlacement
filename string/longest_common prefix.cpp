class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
sort(strs.begin(),strs.end());
string s = "";
for(int j = 0;j<strs[0].size();j++){
    if(strs[0][j]==strs[strs.size()-1][j]){
         s = s + strs[0][j];
    }
    else break;   
}
return s;      
    }
};