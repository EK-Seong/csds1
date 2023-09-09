#include <stdio.h>
int Factorial(int n);   // Declaration(function prototype)
                        // Informs the compiler about relevant properties: name, data type of return value,
                        // type of input arguments, and semicolon!!

int main(void){
    int number;
    int answer;
    printf("Input a number:");
    scanf("%d", &number);
    answer = Factorial(number);     // The caller must transmit proper arguments to the callee
                                    // And Calling is possible only when the callee is declared before
    printf("The factorial of %d is %d\n",number,answer);
}

int Factorial(int n){   // Header : function name('Factorial'), parameter list including data type('int n'), 
    int result = 1;     // and return value's data type('int Factorial')
    for(int i=1;i<=n;i++){
        result *= i;    // any variable declared in the body is local to the function! ('result' is local to Factorial()')
    }
    return result;      // Return value goes back to the caller
}