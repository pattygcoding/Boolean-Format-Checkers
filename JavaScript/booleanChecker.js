let testRuns = 500;

function getRandomBoolean() {
    return Math.random() < 0.5;
}

function generateExpression() {
    const x = Array.from({ length: 5 }, getRandomBoolean);
    
    // Expression format 1
    const ex1 = `(${x[0]} && ${x[1]} && ${x[2]}) || (${x[3]} && ${x[4]})`;
    
    // Expression format 2
    const ex2 = `${x[0]} && ${x[1]} && ${x[2]} || ${x[3]} && ${x[4]}`;
    
    return eval(ex1) === eval(ex2);
}

let allTrue = true;
for (let i = 0; i < testRuns; i++) {
    if (!generateExpression()) {
        allTrue = false;
        break;
    }
}

console.log(allTrue);
