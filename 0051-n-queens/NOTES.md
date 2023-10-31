vector<vector<string>> solveNQueens(int N) {
ans.clear();
board.resize(N, string(N, '.'));
place(0,0,0,0);
return ans;
}
​
private:
vector<vector<string>> ans;
vector<string> board;
​
void place(int i, int vert, int ldiag, int rdiag) {
int N = board.size();
if (i == N) {
vector<string> res;
for (auto row : board) res.push_back(row);
ans.push_back(res);
return;
}
for (int j = 0; j < N; j++) {
int vmask = 1 << j, lmask = 1 << (i+j), rmask = 1 << (N-i-1+j);
if (vert & vmask || ldiag & lmask || rdiag & rmask) continue;
board[i][j] = 'Q';
place(i+1, vert | vmask, ldiag | lmask, rdiag | rmask);
board[i][j] = '.';
}
}
};
Time Complexity : O(N!), Since we have N choices in the first row, then N-1 choices in the second row and so on so the overall complexity become O(N!)
Space Complexity: O(N*N), Just the board and recursive stack space