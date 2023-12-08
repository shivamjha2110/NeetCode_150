We traverse the grid element by element.
When :
​
1. grid[i][j] == "0" -> Do nothing
2. grid[i][j] == "1" ->There is an island.
3. Increase the count of islands by one.
4. Now we need to remove the island from the grid. [ WHY : It is done to prevent counting
5. the rest of "1" that belong to same island ]
6. We can use DFS to traverse through the island, where :
7. If "1" is there, make it "0".
8. Break out if we reach out of boundaries or we encounter "0" -> water.
9. And to the same for neighbouring cells. [ i + 1 , i - 1 , j + 1 , j - 1 ]