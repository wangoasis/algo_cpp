#include <iostream>
#include <stack>
#include <string>
using namespace std;

double evalPostFix() {
  stack<double> s;
  string token;
  double a, b, result;
  cin >> token;

  while(token[0] != '=') {
    result = atof(token.c_str());  // const char* c_str();  double atof(const char* nptr)
    cout << result << endl;

    if(result != 0.0)
      s.push(result);
    else if(token == "0.0")
      s.push(result);
    else 
      switch(token[0]) {
        case '+':
          a = s.top();
          s.pop();
          b = s.top();
          s.pop();
          s.push(a+b);
          break;
        case '-':
          a = s.top();
          s.pop();
          b = s.top();
          s.pop();
          s.push(a-b);
          break;
        case '*':
          a = s.top();
          s.pop();
          b = s.top();
          s.pop();
          s.push(a*b);
          break;
        case '/':
          a = s.top();
          s.pop();
          b = s.top();
          s.pop();
          s.push(a/b);
          break;
      }
    cin >> token;
  }

  return s.top();
}