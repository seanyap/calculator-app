#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <stack>
using namespace std;

struct Calculator {
  unordered_set<string> validOp = {"+", "-", "*", "/", "^", "^^", "(", ")", "."};
  enum opname {ADD, SUB, MUL, DIV, POWER, SQRT};

  // allow nums from 0-9, operators, parenthesis  
  int checkValidValues(string input) {
    for (int i=0; i<input.length(); i++) {
      char c = input[i];
      string c_str = string(1, c);
      if (!isdigit(c) && validOp.find(c_str) == validOp.end()) {
        return 0;
      }
    }
    return 1;
  }

  double evaluate(double operand1, double operand2, opname op) {
    switch (op) {
      case ADD:
        return operand1 + operand2;
        break;
      case SUB:
        return operand1 - operand2;
        break;
      case MUL:
        return operand1 * operand2;
        break;
      case DIV:
        if (operand2 == 0)
          // throw division by zero error
        return operand1 / operand2;
        break;
      case POWER:
        return pow(operand1,operand2);
        break;
      case SQRT:
        return sqrt(operand1);
        break;
      default:
        // invalid precaution
    }
  }

  string run(string input) {
    stack<float> operands;
    stack<string> operators;
    for (int i=0; i<input.length(); i++) {
      if (input[i] == ' ') continue;
      // loop all values that belong to the same value 
    }

    return input;
  }
};

int main() {
  Calculator calc;
  string s;
  cout << "Enter a mathematical expression\n";
  cin >> s;
  while (!calc.checkValidValues(s)) { // throw invalid expression error
    cout << "Invalid syntax\n";
    cout << "Enter a valid mathematical expression\n";
    cin >> s;
  }
  cout << calc.run(s) << "\n";
}