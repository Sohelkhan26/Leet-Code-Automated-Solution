/*
প্রতি রো এর লাস্ট থেকে ট্রাভার্স করা শুরু করতে হবে। আমরা ধরে নিবো লাস্টের সেল খালি। ঐ সেলে যদি * থাকে তাহলে তো ঐখানে পাথর রাখা যাবে না , তাই তার বামের সেল খালি হিসেবে মার্ক করে রাখতে হবে যাতে ভবিষ্যতে পাথড় পাওয়া গেলে ঐখানে রাখা যায়। লাস্টের সেল যদি খালি নাও হয় তাহলে পাথরের সাথে পাথরের সেলই swap হবে। আউটপুট সেম থাকবে। এবং তার বামের টা খালি হিসেবে মার্ক হয়ে থাকবে। 
লাস্ট থেকে ট্রাভার্স করতে হবে কারণ * এর পরে পাথর এবং খালি সেল থাকতে পারে। বাম থেকে ট্রাভার্স করলে সেটা আগে থেকে জানার সুযোগ নাই। 
*/
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size() , cols = box[0].size();
        for(int i = 0 ; i < rows ; i++){
            for(int j = cols - 1 , empty = cols - 1 ; j >= 0 ; j--){
                if(box[i][j] == '*')
                    empty = j - 1;
                else if(box[i][j] == '#'){
                    swap(box[i][empty] , box[i][j]);
                    empty--;
                }
            }
        }
        vector<vector<char>> ans;
        for(int i = 0 ; i < cols ; i++){
            vector<char> temp;
            for(int j = rows - 1 ; j >= 0 ; j--) // rows - 1
                temp.push_back(box[j][i]);
            ans.push_back(temp);
        }
        return ans;
    }
};