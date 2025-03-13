#include <iostream>
#include <cstdlib>
#include <ctime>

#define TEST_RUNS 500

bool getRandomBoolean() {
    return rand() % 2;
}

bool generateExpression() {
    bool x[5];
    for (int i = 0; i < 5; i++) {
        x[i] = getRandomBoolean();
    }

    // Expression format 1
    bool ex1 = ((x[0] && x[1] && x[2]) || (x[3] && x[4]));

    // Expression format 2
    bool ex2 = (x[0] && x[1] && x[2] || x[3] && x[4]);

    return ex1 == ex2;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    bool allTrue = true;
    for (int i = 0; i < TEST_RUNS; i++) {
        if (!generateExpression()) {
            allTrue = false;
            break;
        }
    }

    std::cout << (allTrue ? "true" : "false") << std::endl;

    return 0;
}
