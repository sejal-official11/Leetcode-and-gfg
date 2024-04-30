class Solution {
    private:
    void generate_Helper(int open, int close, string s, vector<string> &ans) {
        // Base case
        if(open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }


        if(open == close) {
            s.push_back('(');
            generate_Helper(open - 1, close, s, ans);
        }
        else if(open == 0) {
            s.push_back(')');
            generate_Helper(open, close - 1, s, ans);
        }
        else if(close == 0) {
            s.push_back('(');
            generate_Helper(open - 1, close, s, ans);
        }

        else {
            string s1 = s;
            s1.push_back('(');
            generate_Helper(open - 1, close, s1, ans);
            string s2 = s;
            s2.push_back(')');
            generate_Helper(open, close - 1, s2, ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        string s = "";
        vector<string> ans;

        generate_Helper(open, close, s, ans);
        return ans;
        
    }
};