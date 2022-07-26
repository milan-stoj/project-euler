/****************************************
 * Author: milan-stoj
 * Problem: 2
 * Title: Even Fibonacci numbers
 * Description:
 * 
 * 	Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
 * 	1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * 	By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms. 
 *
 * Answer: 4613732
 ************************************/

#include <stdio.h>
int sum_of_even_fibonacci(int ul);

int main() {
    int sum = sum_of_even_fibonacci(4000000);
    printf("answer: %d", sum);
}

int sum_of_even_fibonacci(int ul) {
    int sum = 0;
    for (int i = 1, prev = i, next = i + prev; i <= ul; next = i + prev, prev = i, i = next) {
        if (i % 2 == 0) sum += i;
    }
    return sum;
}
