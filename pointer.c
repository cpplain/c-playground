#import <stdio.h>
#import <stdbool.h>
#import <stdlib.h>

struct employee_t {
    int id;
    int income;
    bool staff;
};

int initialize_employee(struct employee_t *e) {
    static int numEmployees = 0;
    numEmployees++;

    e->id = numEmployees;
    e->income = 0;
    e->staff = false;

    return numEmployees;
};

int main() {
    int n = 4;

    struct employee_t *employees = malloc(sizeof(struct employee_t) * n);
    if (employees == NULL) {
        printf("Allocation failed\n");
        return -1;
    }

    int i = 0;
    for (i = 0; i < n; i++) {
        initialize_employee(&employees[i]);
        printf("New employee ID is %d\n", employees[i].id);
    }

    free(employees);
    employees = NULL;

    return 0;
}
