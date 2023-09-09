// A pointer variable contains an address of a memory object
// Address operator & and indirection operator *

#include <stdio.h>

int main(void){
    int* intPtr;
    intPtr = NULL;
    int intVar = 5;

    intPtr = &intVar;
    printf("%d %d %d %d\n", intPtr, *intPtr, &intVar, intVar);

    *intPtr += 1;
    printf("%d %d\n",*intPtr,intVar);
    
    return 0;
}
