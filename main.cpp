#include <iostream>
#include <string>
#include <math.h>
#include <unordered_set>
#include <iomanip> 
#include <fstream>
using namespace std;

struct Calculator {
  unordered_set<char> validOp = {'+', '-', '*', '/', '^', 'r'};
  enum opname {ADD, SUB, MUL, DIV, POWER, SQRT};

  // allow nums from 0-9 and operator without spacing in between
  int checkValidValues(string input) {
    for (int i=0; i<input.length(); i++) {
      char c = input[i];
      if (!isdigit(c) && validOp.find(c) == validOp.end() && c != '.') {
        return 0;
      }
    }
    return 1;
  }

  double evaluate(double operand1, double operand2, char op) {
    switch (op) {
      case '+':
        return operand1 + operand2;
        break;
      case '-':
        return operand1 - operand2;
        break;
      case '*':
        return operand1 * operand2;
        break;
      case '/':
        if (int(operand2) == 0) throw "Division by zero error.";
        return operand1 / operand2;
        break;
      case '^':
        return pow(operand1,operand2);
        break;
      case 'r':
        return sqrt(operand1);
        break;
      default:
        throw "invalid operator";
    }
  }

  string findNum(string input, int& idx) {
    string num;
    while (isdigit(input[idx]) || input[idx] == '.') {
      num += input[idx];
      idx++;
    }
    return num;
  }

  double run(string input) {
    int idx = 0, size = input.length();
    string operand1, operand2;
    char op;
    // process special square root case which only has operator first then operand
    if (input[idx] == 'r') {
      if (size < 1)
        throw "square root operand not found";
      idx++;
      operand1 = findNum(input, idx);
      return evaluate(stod(operand1), -1.0, 'r');
    }

    if (!isdigit(input[idx])) 
      throw "1st operand not found";
    operand1 = findNum(input, idx);  
    
    if (idx >= size || validOp.find(input[idx])==validOp.end())
      throw "operator not found";
    op = input[idx];
    idx++;

    if (idx >= size || !isdigit(input[idx])) 
      throw "2nd operand not found";
    operand2 = findNum(input, idx); 

    return evaluate(stod(operand1), stod(operand2), op);
  }
};

int main() {
  Calculator calc;
  string s;

  // getting values from user
  cout << "Enter an expression in format: a+b, a-b, a*b, a/b, a^b, ra (sqrt of a)\n";
  cin >> s;
  while (!calc.checkValidValues(s)) { // throw invalid expression error
    cout << "Invalid syntax. Try again: \n";
    cin >> s;
  }
  string result;
  try {
    result = to_string(calc.run(s));
  } catch (const char* msg) {
    cout << "-> Error message: " << msg;
  }
  cout << fixed << setprecision(3) << result << endl;

  // processing values from input file
  ifstream inputFile;
  inputFile.open("./data/test_data.txt");
  ofstream outputFile;
  outputFile.open ("./report/result.txt");

  string line;
  while (getline(inputFile, line)) {
    try {
      if (!calc.checkValidValues(line)) 
        throw "Invalid syntax";
      string result = to_string(calc.run(line));
      outputFile << result << '\n';
    } catch (const char* msg) {
      outputFile << "-> error message: " << msg << "\n";
    }
  }
  inputFile.close();
  outputFile.close();

  return 0;
}