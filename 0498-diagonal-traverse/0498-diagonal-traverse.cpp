class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int N = mat.size();
        int M = mat[0].size();
        // initialize the answer array that we have to return
        vector<int> ans(M * N);
        // initialize the answer array starting index
        int k = 0;

        for (int diag = 0; diag < M + N - 1; diag++) {

            vector<int> midArray;

            int row = diag < M ? 0 : diag - M + 1;
            int col = diag < M ? diag : M - 1;

            while (row < N && col > -1) {
                midArray.push_back(mat[row][col]);
                ++row;
                --col;
            }
            // if diagonal nuber is even
            if (diag % 2 == 0) {
                reverse(midArray.begin(), midArray.end());
            }

            for (int i = 0; i < midArray.size(); i++) {
                ans[k] = midArray[i];
                k++;
            }

            midArray.clear();
        }

        return ans;
    }
};