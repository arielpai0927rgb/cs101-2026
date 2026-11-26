#include <stdio.h>

int main() {
    int var=30;
    int* ip;
    
    ip =&var;
    
    printf("Address of var: %p\n", &var);
    printf("Value of ip: %p\n", ip);
    printf("Address of ip: %p\n", &ip);
    printf("Value of *ip: %d\n", *ip);
    return 0;
}
