class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size() , m = image[0].size() , region[501][501][2] = {};
        for(int i = 0 ; i < n - 2 ; i++){    
            for(int j = 0 ; j < m - 2 ; j++){
                int sum = 0; bool ok = true;
                for(int k = i ; k < i + 3 ; k++){
                    for(int l = j ; l < j + 3 ; l++){
                        sum += image[k][l];
                        ok &= (k == i or abs(image[k][l] - image[k - 1][l]) <= threshold); // either start of the subgrid or inside. If inside compare with left and up as we are going down, eventually all cell will be covered.
                        ok &= (l == j or abs(image[k][l] - image[k][l - 1] ) <= threshold);
                    }
                }
                if(ok){
                    for(int k = i ; k < i + 3 ; k++) // all these cells are part of a region
                        for(int l = j ; l < j + 3 ; l++)
                            region[k][l][0] += sum / 9 , region[k][l][1]++;  // [1] represent [i][j] cell's participation in regions.
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(region[i][j][1])
                    image[i][j] = region[i][j][0] / region[i][j][1];
            }
        }
        return image;
    }
};