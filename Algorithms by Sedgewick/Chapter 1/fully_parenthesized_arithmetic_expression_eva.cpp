#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<string> stk_operator;
stack<float> stk_operand;

vector<float> get_operands(stack<float> stk)
{
    vector<float> res;
    for ( int i = 0; i < 2; i ++ )
    {
        res.push_back(stk.top());
        stk.pop();       
    }
    return res;
}

int main()
{
    string x, op;
    float res;
    while ( cin >> x )
    {
        if ( x == "-"|| x == "+" || x == "*" || x == "/" ) stk_operator.push(x);
        else if ( x == ")")
        {
            vector<float> operands = get_operands(stk_operand);
            op = stk_operator.top();
            stk_operator.pop();
            if ( op == "-") res = operands[1] - operands[0];
            else if ( op == "+" ) res = operands[0] + operands[1];
            else if ( op == "*") res = operands[0] * operands[1];
            else res = operands[1] / operands[0];
            stk_operand.push(res);
        }
        else if ( x != "(" ) stk_operand.push(stoi(x));
    }
    cout << stk_operand.top() << endl;
    return 0;
}

