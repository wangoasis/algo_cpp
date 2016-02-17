#include <stack>
#include <iostream>
using namespace std;

void inToPostFix() {
  stack<char> s;
  char token;
  cin >> token;
  while(token != '=') {
    if(token >= 'a' && token <= 'z')
      cout << token << ' ';
    else 
      switch(token) {
        case ')':
          while(!s.empty() && s.top() != '(') {
            cout << s.top() << ' ';
            s.pop();
          }
          s.pop();  // pop '('
          break;
        case '(':
          s.push(token);
          break;
        case '^':
          /*while(!s.empty() && !(s.top() == '(' || s.top() == '^')) {
            cout << s.top() << ' ';
            s.pop();
          }*/
          s.push(token);
          break;
        case '*':
        case '/':
          while(!s.empty() && s.top() != '+' && s.top() != '-' && s.top() != '(') {
            cout << s.top() << ' ';
            s.pop();
          }
          s.push(token);
          break;
        case '+':
        case '-':
          while(!s.empty() && s.top() != '(') {
            cout << s.top() << ' ';
            s.pop();
          }
          s.push(token);
          break;
      }
      cin >> token;
  }

  while(!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
  cout << "=" << endl;
}