#include <stdio.h>

void main(void){
    int arr[3][3] = {
        {100,200,300},
        {400,500,600},
        {700,800,900}
    };

    int (*ptr)[3] = arr;

    printf("%d\n",**ptr);
    printf("%d\n",*(*(ptr+2)+1)+3);
    
}