/* My approach is First we eliminate all the values that are greater and then for the smaller ones we store the positions in which we find values that are equal.*/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        set<int>st;
        
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2]){
                continue;
            }
            else {
                for(int j=0;j<3;j++){
                    if(triplets[i][j]==target[j]){
                        st.insert(j);
                    }
                }
            }
        }
        return (st.size()==3)?true:false;
    }
};