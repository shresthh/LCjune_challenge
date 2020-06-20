#define p 10000007
vector<int> roll;
class Solution {
    bool match(string s,int len , int size, string& ans){
        unordered_map<int, vector<int>> m;
        int hash = 0;
        for(int i = 0; i<size;i++){
            hash = (hash*26 + (s[i]-'a'))%p;
        }
        m[hash].push_back(0);
        
        for(int j = size; j<len; j++){
            hash  = ((hash-roll[size-1]* (s[j-size] - 'a'))%p + p)%p;
            hash  = (hash*26 + (s[j]-'a'))%p;
            if(m.find(hash)!=m.end()){
                for(auto start : m[hash]){
                    string temp = s.substr(start,size);
                    string curr = s.substr(j-size+1,size);
                    if(temp.compare(curr)==0){
                        ans = temp;
                        return true;
                    }
                }
            }
            m[hash].push_back(j-size+1);
        }
        return false;
    }
public:
    string longestDupSubstring(string S) {
        int len = S.size();
        if(len == 0){
            return "";
        }
        
        roll.resize(len);
        roll[0]=1;
        for (int i =1; i<len ;  i++){
            roll[i] = (26*roll[i-1])%p;
        }
        int low = 1, high = len, mid;
        string ans = "", temp;
        while(low <= high){
            temp = "";
            mid = low + (high-low)/2;
            bool flag = match(S,len,mid,temp);
            if(flag){
                if(temp.size()>ans.size()){
                    ans = temp;
                }
                low  = mid +1;
            }
            else{
                high = mid -1;
            }
        }
        return ans;
        
    }
};
