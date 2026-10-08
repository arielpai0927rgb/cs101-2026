#include <stdio.h>

int main() {
    int n = 6;
    int spc = n - 1;
    
    for (int i = 1; i <= n; i++) {
      
        for (int k = spc; k >= 1; k--) {
            printf(" ");
        }
            printf("%d ", i);
        }
        
        printf("\n");
        spc--;
    }
    
    return 0;
}
