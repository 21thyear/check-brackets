
#include <iostream>
#include <stack>
#include <string>

bool checkBrackets(const std::string& expression)
{
    std::stack<char> brackets;

    int openedBracketsCount = 0;
    int closedBracketsCount = 0;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            openedBracketsCount++;
            brackets.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            closedBracketsCount++;
            if (brackets.empty()) {
                return false;
            }
            
            char top = brackets.top();
            brackets.pop();
            
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return brackets.empty();
}
int main()
{
    std::string brackets = "{}}}{[{{}{}{}{{{]}}}][";
    if (checkBrackets(brackets))
    {
        std::cout << "All brackets - good" << std::endl;
        return true;
    }
    std::cout << "Bad brackets :(" << std::endl;
    return false;
}
