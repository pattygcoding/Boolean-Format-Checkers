import random

test_runs = 500

def get_random_boolean():
    return random.random() < 0.5

def generate_expression():
    x = [get_random_boolean() for _ in range(5)]

    # Expression format 1
    ex1 = ((x[0] and x[1] and x[2]) or (x[3] and x[4]))

    # Expression format 2
    ex2 = (x[0] and x[1] and x[2] or x[3] and x[4])

    return ex1 == ex2

all_true = all(generate_expression() for _ in range(test_runs))

print(all_true)
