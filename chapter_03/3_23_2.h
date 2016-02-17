#include <stack>
#include <iostream>
#include <string>
using namespace std;

void postToInFix() {
  stack<string> s;
  string token;
  string s1, s2;
  cin >> token;

  while(token[0] != '=') {
    if(token[0] >= 'a' && token[0] <= 'z')
      s.push(token);
    else
      switch(token[0]) {
        case '+':
          s1 = s.top();
          s.pop();
          s2 = s.top();
          s.pop();
          s.push("("+s1+"+"+s2+")");
          break; 
        case '-':
          s1 = s.top();
          s.pop();
          s2 = s.top();
          s.pop();
          s.push("("+s1+"-"+s2+")");
          break; 
        case '*':
          s1 = s.top();
          s.pop();
          s2 = s.top();
          s.pop();
          s.push("("+s1+"*"+s2+")");
          break; 
        case '/':
          s1 = s.top();
          s.pop();
          s2 = s.top();
          s.pop();
          s.push("("+s1+"/"+s2+")");
          break; 
        case '^':
          s1 = s.top();
          s.pop();
          s2 = s.top();
          s.pop();
          s.push("("+s1+"^"+s2+")");
          break; 
      }
    cin >> token;
  }

  std::cout << s.top() << endl;
}