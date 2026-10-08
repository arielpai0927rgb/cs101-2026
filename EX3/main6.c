#include <stdio.h>

int main() {
    int i=119;
    if (i<=30) {
        printf("free");
    }
    else if (i >=240){
        printf("240 dollars");
        
    }
   
    else {
        if (i%30){
            int h = ((i/30)+1)*30;
            printf("%d dollars", h);
        }
        else {
        printf("%d dollars", i);
    }
}

    return 0;
    }
