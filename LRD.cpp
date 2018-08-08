class Solution {
public:
    bool judge(vector<int> a, int l, int r) {
        if(l>=r)
            return true;
        int i=r-1;//r=root, find first one that not greater than root
        while(a[r]<a[i]) --i;
        for(int k=l; k<i; ++k) {
            if(a[k]>a[r])
                return false;
        }
        return judge(a, l, i) && judge(a, i+1, r-1);
        
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        return judge(sequence, 0, sequence.size()-1);
        
    }
};
