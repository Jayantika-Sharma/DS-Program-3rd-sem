#include <iostream>
using namespace std;
char stackArr[100];
int top = -1;
void push(char ch) {
    if (top < 99)
        stackArr[++top] = ch;
    else
        cout << "Stack Overflow!" << endl;
}
char pop() {
    if (top == -1)
        return '\0';
    return stackArr[top--];
}
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}
bool isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'));}
int main() {
    char exp[100];
    cout << "Enter infix expression: ";
    cin >> exp;
    cout << "Postfix expression: ";
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (isOperand(ch)) {
            cout << ch;} 
        else if (ch == '(') {
            push(ch);} 
        else if (ch == ')') {
            while (top != -1 && stackArr[top] != '(')
                cout << pop();
            pop(); } 
        else { 
            while (top != -1 && precedence(stackArr[top]) >= precedence(ch))
                cout << pop();
            push(ch);   } }
    while (top != -1)
        cout << pop();
    cout << endl;
    return 0;
}
