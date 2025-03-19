// Online C++ compiler to run C++ program online
#include <iostream>
// you can use includes, for example:
#include <algorithm>

class Solution {
    static const int MAX_NUMBER_OF_COMBINATIONS = 24; // 4!=24
    static const int NUMBER_OF_DIGITS = 4; 
    constexpr static const int ALL_PERMUTATIONS[MAX_NUMBER_OF_COMBINATIONS][NUMBER_OF_DIGITS] = {
        {0,1,2,3},
        {0,1,3,2},
        {0,2,3,1},
        {0,2,1,3},
        {0,3,1,2},
        {0,3,2,1},

        {1,0,2,3},
        {1,0,3,2},
        {1,2,0,3},
        {1,2,3,0},
        {1,3,0,2},
        {1,3,2,0},       

        {2,0,1,3},
        {2,0,3,1},
        {2,1,0,3},
        {2,1,3,0},
        {2,3,0,1},
        {2,3,1,0},

        {3,0,1,2},
        {3,0,2,1},
        {3,1,2,0},
        {3,1,0,2},
        {3,2,0,1},
        {3,2,1,0}
    };
    
    int unique_combs[MAX_NUMBER_OF_COMBINATIONS]={0};
    int unique_combs_num = 0;
    bool isUnique(int hours, int minutes){
      int clock_value = hours*256 + minutes;
      for(int i=0; i<MAX_NUMBER_OF_COMBINATIONS; i++) {
          if(unique_combs[i] == clock_value)
            return false;
      }
      //add clock value to array
      unique_combs[unique_combs_num]=clock_value;
      unique_combs_num++;
      return true;
    };
    
    bool isValidClock(int (&comb_to_check)[NUMBER_OF_DIGITS]){
        int hours = comb_to_check[0] * 10 + comb_to_check[1];
        int minutes = comb_to_check[2] * 10 + comb_to_check[3];
        if((hours > 0) && (hours < 24) && (minutes >0) && (minutes < 60)){
            if(isUnique(hours, minutes)){
                std::cout << hours <<":"<<minutes <<std::endl;
                return true;
            }
        }
        return false;
    };
public:
    int solution(int A, int B, int C, int D){
        // Implement your solution here
        int number_of_combinations = 0;
        int combination[NUMBER_OF_DIGITS] = {A, B, C, D};
        for(int i = 0; i < MAX_NUMBER_OF_COMBINATIONS;i++){ // for all N! combinations
            // get combination
            combination[ALL_PERMUTATIONS[i][0]] = A;
            combination[ALL_PERMUTATIONS[i][1]] = B;
            combination[ALL_PERMUTATIONS[i][2]] = C;
            combination[ALL_PERMUTATIONS[i][3]] = D;
            // validate it,  if valid - increment counter
            if(isValidClock(combination)==true){
                number_of_combinations++;
            }
        }
        std::cout << number_of_combinations << std::endl;
        return number_of_combinations;
    };
};


int main() {
    // Write C++ code here
    Solution* sol  =  new Solution;
    sol->solution(1, 1, 1, 1);
    std::cout << "----------------------------"<< std::endl;
    sol->solution(7, 8, 9, 9);
    std::cout << "----------------------------"<< std::endl;

    sol->solution(1, 2, 3, 4);
    std::cout << "----------------------------"<< std::endl;

    return 0;
}