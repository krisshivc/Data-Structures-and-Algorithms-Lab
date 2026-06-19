#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }

    stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
        return '\0';
    }

    return stack[top--];
}

bool isEmpty()
{
    return top == -1;
}

bool isOpening(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool isMatch(char open, char close)
{
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}

bool isBalanced(const string& s)
{
    top = -1;

    for (int i = 0; i < (int)s.length(); i++)
    {
        char c = s[i];

        if (isOpening(c))
        {
            push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (isEmpty())
            {
                cout << "No matching opening bracket for '" << c << "'\n";
                return false;
            }

            char t = pop();

            if (!isMatch(t, c))
            {
                cout << "Mismatched brackets: '" << t << "' and '" << c << "'\n";
                return false;
            }
        }
    }

    if (!isEmpty())
    {
        cout << "Unclosed opening brackets remain\n";
        return false;
    }

    return true;
}

int main()
{
    string tests[] = {"{[()]}", "{[(])}", "((())", ""};

    for (int i = 0; i < 3; i++)
    {
        cout << "\"" << tests[i] << "\" -> ";
        cout << (isBalanced(tests[i]) ? "Balanced" : "Not Balanced") << "\n";
    }

    return 0;
}
