#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string input = "A*(B+C)/D";
    string output = "";
    stack s;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z')
            output.push_back(input[i]);
        else if (input[i] == '(')
        {
        }
        else if (input[i] == '^' || input[i] == '*' || input[i])
    }
    return 0;
}