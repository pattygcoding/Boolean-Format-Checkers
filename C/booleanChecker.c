#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_RUNS 500

int getRandomBoolean() {
    return rand() % 2;
}

int generateExpression() {
    int x[5];
    for (int i = 0; i < 5; i++) {
        x[i] = getRandomBoolean();
    }

    // Expression format 1
    int ex1 = ((x[0] && x[1] && x[2]) || (x[3] && x[4]));

    // Expression format 2
    int ex2 = (x[0] && x[1] && x[2] || x[3] && x[4]);

    return ex1 == ex2;
}

int main() {
    srand(time(NULL));

    int allTrue = 1;
    for (int i = 0; i < TEST_RUNS; i++) {
        if (!generateExpression()) {
            allTrue = 0;
            break;
        }
    }

    printf("%s\n", allTrue ? "true" : "false");

    return 0;
}
