}
// Recursive Function (solve) - It basically tries all possible placement of queen for the current row & recurses for it's next row
void solve(vector<string>& board, int row) {
// Base condition.
// We reached the last row, so we have a solution so we add it to the solution vector
if(row == size(board)) {
sols.push_back(board);
return;
}
// Try placing a queen on each column for a given row.
// Explore next row by placing Q at each valid column for the current row
for(int col = 0; col < size(board); col++){
if(isSafe(board, row, col)) {
board[row][col] = 'Q';    // Queen placed on a valid cell
solve(board, row + 1);    // Exploring next row
board[row][col] = '.';    // Backtracking to get all possible solutions
}
}
}
};
Time Complexity : O(N!), Since we have N choices in the first row, then N-1 choices in the second row and so on so the overall complexity become O(N!)
Space Complexity: O(N*N), Just the board and recursive stack space
Time Complexity : O(N!), Since we have N choices in the first row, then N-1 choices in the second row and so on so the overall complexity become O(N!)
Space Complexity: O(N*N), Just the board and recursive stack space