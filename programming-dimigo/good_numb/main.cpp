#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int* num_array;
int input_num = 0;

int validation(int change_depth) {
    int same_num;

    // validation check -> when each round , we confirm that num is in rule
    for (int size = 1; size <= (change_depth / 2); size++) {
        same_num = 0;
        // check one rule
        for (int k = 0; k < size; k++) {
            if (num_array[(change_depth -1) - k] == num_array[(change_depth - 1) - k - size])  same_num++;
        }
        // if check and rule is fined , end function
        if (same_num == size) return -1;
    }


    // if it is ANSWER ? -> print and exit program.
    if (change_depth == input_num){
        for (int i = 0; i < input_num; i++) {
            printf("%d",num_array[i]);
        }
        exit(0);
    }
    return 1;
}

// confirm data and push answer into vector
void confirm ( int change_depth) {
    if ( change_depth > input_num ) return;
    if ( validation(change_depth) == -1 ) return ;

    // check other numbers
    for (int i = 0; i < 3; i++) {
        num_array[change_depth] = i+1;
        confirm(change_depth + 1);
    }
}

int main() {
    scanf("%d", &input_num);
    num_array = (int*)malloc(sizeof(int)*input_num);

    // confirm array
    confirm(0);

    return 0;
}
