#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;

struct Calculator {
  unordered_set<char> validOp = {'+', '-', '*', '/', '^', 'r'};
  enum opname {ADD, SUB, MUL, DIV, POWER, SQRT};

  // allow nums from 0-9, operators, parenthesis  
  int checkValidValues(string input) {
    for (int i=0; i<input.length(); i++) {
      char c = input[i];
      if (!isdigit(c) && validOp.find(c) == validOp.end() && c != '.') {
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
        if (operand2 == 0) throw "Division by zero error.";
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
        throw "Invalid values";
    }
  }

  double run(string input) {
    int size = input.length();

    for (int i=0; i<size; i++) {
    }
  }
};

int main() {
  Calculator calc;
  string s;
  cout << "Enter a mathematical expression:\n";
  cin >> s;
  while (!calc.checkValidValues(s)) { // throw invalid expression error
    cout << "Invalid syntax\n";
    cout << "Enter a valid mathematical expression:\n";
    cin >> s;
  }
  string result;
  try {
    result = to_string(calc.run(s));
  } catch (string error) {
    cout << error << "\n";
  }

  cout << result << "\n";
}