/*
374. Guess Number Higher or Lower  QuestionEditorial Solution  My Submissions
Total Accepted: 5617
Total Submissions: 17714
Difficulty: Easy
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
*/

#include"leetcode.h"





class solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        int test = (high-low)/2 + low;
        while(guess(test) && (high > low)){
            if(guess(test) < 0) high = test-1;
            if(guess(test) > 0) low = test+1;
            test = (high - low)/2 + low;
        }
        return test;
    }

	int guess(int num){
		int target = 6;
		return (num > target) ? -1 : ( (num < target) ? 1 : 0 );
	}

};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	solution slt;
//	slt.guessNumber(10);
// 	//system("pause");
//}
