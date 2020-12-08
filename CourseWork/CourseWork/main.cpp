#include "functions/lib/calc.hpp"
#include "functions/lib/stack.hpp"
#include "functions/lib/iterator.hpp"

using namespace std;

int main()
{
    try
    {
        string str;
        cout << "Use a space between operands, operators and brackets when entering an expression\n"
            << "Example: ( ( cos(60) + 1.5 ) - 5 + sin(50) )\n\n\n";
        cout << "Expression: ";
        getline(cin, str);

        checkExpression(str);
        Stack tokens = parse(str);
        checkTokens(tokens);
        Stack postfix = convertToPostfix(tokens);
        double result = calculate(postfix);

        cout << "Postfix notation: ";
        postfix.print();
        cout << "\nCalculated value: " << result;
    }
    catch (const std::exception& message)
    {
        std::cerr << message.what() << '\n';
    }
}