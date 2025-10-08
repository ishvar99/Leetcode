class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cost = 5;
        int fiveChange =0;
        int tenChange = 0;
        for(auto i : bills){
            if(i == 5){
                fiveChange++;
            }
            else if(i == 10){
                if(fiveChange >= 1){
                    fiveChange--;
                    tenChange++;
                }
                else {
                    return false;
                }
            }
            else if(i == 20){
                if(tenChange >=1 && fiveChange >=1){
                    fiveChange--;
                    tenChange--;
                }
                else if(fiveChange >= 3){
                    fiveChange-=3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
