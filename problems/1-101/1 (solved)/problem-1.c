/****************************************
 * Author: milan-stoj
 * Problem: 1
 * Title: Multiples of 3 or 5
 * Description:
 * 
 * 	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * 	Find the sum of all the multiples of 3 or 5 below 1000. 
 *
 * Answer: 233168
 ************************************/
#include <stdio.h>
int sum_of_multiples(int upper, int multiple_1, int multiple_2);

int main() {
    int answer = sum_of_multiples(1000, 3, 5);
    printf("Answer: %d", answer);
    return 0;
}

int sum_of_multiples(int upper, int multiple1, int multiple2) {
    int sum = 0;
    for (int i = 0; i < upper; i++) {
        if (i % multiple1 == 0 || i % multiple2 ==0) sum += i;
    }
    return sum;
}

