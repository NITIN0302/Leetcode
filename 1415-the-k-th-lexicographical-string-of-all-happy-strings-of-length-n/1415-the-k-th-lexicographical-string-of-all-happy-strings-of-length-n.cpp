class Solution {
public:
    
    string getHappyString(int n, int k)
    {
        auto prem = 1 << (n - 1);
        if (k > 3 * prem)
            return "";
        string s;
        s+=('a' + (k - 1) / prem);
        cout<<s<<endl;
        while (prem > 1) 
        {
            k = (k - 1) % prem + 1;
            prem >>= 1;
            s += (k - 1) / prem == 0 ? 'a' + (s.back() == 'a') : 'b' + (s.back() != 'c');
        }
        return s;
    }
};