
/*
    ****这题的关键是构建自定义compare********
*/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> svec;
        string ans;
        for(int i=0; i<numbers.size(); ++i) {
            svec.push_back(int_to_str(numbers[i]));
        }
        sort(svec.begin(), svec.end(), mComp);
        for(int i=0; i<svec.size(); ++i) {
            ans += svec[i];
        }
        return ans;
    }
    static bool mComp(string x, string y) {
        return x+y<y+x;
    }
    
    string int_to_str(const int &a) {
        stringstream strm;
        strm<<a;
        return strm.str();
    }
    
    void str_to_int(const string &s, int &intx) {
        stringstream strm(s);
        strm>>intx;
    }
};
