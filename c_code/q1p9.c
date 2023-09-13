#include <stdio.h>

int quiz(int n);

int main(void){
    int number;
    int answer;
    printf("Input a number: ");
    scanf("%d",&number);
    answer = quiz(number);
    printf("The answer is %d\n", answer);
}

int quiz(int n){
    int result = 0;
    for(int i = 1; i<=n;i++){
        result += i;
    }
    return result;
}