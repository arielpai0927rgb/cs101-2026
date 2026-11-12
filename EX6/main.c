#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
    int id;
    char name[32];
    int age;
    float salary;
} employee_t;

void emp_info(employee_t emp) {
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %f\n\n", emp.salary);
}

int emp_aveage_age(employee_t emp[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }
    return sum / n;
}

void emp_writefile(employee_t emp[], int n) {
    FILE *fp = fopen("employee.bin", "wb");
    if (fp == NULL) {
        return;
    }
    fwrite(emp, sizeof(employee_t), n, fp);
    fclose(fp);
}

void emp_readfile(employee_t emp[], int n) {
    FILE *fp = fopen("employee.bin", "rb");
    if (fp == NULL) {
        return;
    }
    fread(emp, sizeof(employee_t), n, fp);
    fclose(fp);
}

int main() {
    employee_t emp[3];
    
    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name, "Oreo");

    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0;
    strcpy(emp[1].name, "Sabrina");

    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0;
    strcpy(emp[2].name, "Carpenter");

    emp_writefile(emp, 3);

    employee_t read_emp[10];
    emp_readfile(read_emp, 3);


    for (int i = 0; i < 3; i++) {
        printf("[%d] %d %s\n", i, read_emp[i].id, read_emp[i].name);
    }

    for (int i = 0; i < 3; i++) {
        emp_info(read_emp[i]);
    }

    return 0;
}
