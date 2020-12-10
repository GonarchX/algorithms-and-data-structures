#include "../lib/calc.hpp"

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

bool checkCountBracket(const string& str)
{
    string left = "(";
    string right = ")";
    size_t lcount = 0, rcount = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == left[0]) lcount++;
        if (str[i] == right[0]) rcount++;
    }
    return (lcount == rcount);
}

bool checkMatchingBracket(const string& str)
{
    int balance = 0;
    for (string::const_iterator it = str.begin(); it < str.end(); it++)
    {
        if (*it == '(') balance++;
        else if (*it == ')') balance--;
        if (balance < 0) return 0;
    }
    return 1;
}

bool checkEmptyBracket(const string& str)
{
    for (string::const_iterator it = str.begin(); it < str.end(); it++)
    {
        if (*it == '(')
        {
            it++;
            while (it != str.end() && ::isspace(*it)) it++;
            if (*it == ')') return 0;
        }
    }
    return 1;
}

void checkExpression(const string& str)
{
    if (!checkCountBracket(str))
        throw runtime_error("Recheck brackets in an expression!");

    if (!checkMatchingBracket(str))
        throw runtime_error("The closing bracket met before the opening bracket!");

    if (!checkEmptyBracket(str))
        throw runtime_error("Some brackets in an expression are empty!");
}

// Remove duplicated spaces in string
void remDupSpaces(string& str)
{
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1, str.size());
    for (string::iterator second = str.begin(); second != str.end(); second++)
    {
        string::iterator first = second;
        while (second != str.end() && ::isspace(*second)) second++;
        if (second - first > 1)
            second = str.erase(first + 1, second) - 1;
    }
}

List parse(string& str)
{
    remDupSpaces(str);
    List tokens;
    string temp;
    for (string::iterator it = str.begin(); it != str.end(); it++)
    {
        if (::isspace(*it))
        {
            tokens.push(temp);
            temp.clear();
        }
        else
        {
            temp.push_back(*it);
        }
    }
    if (temp.size()) tokens.push(temp);
    return tokens;
}

bool isDigit(const string& str)
{
    if (str.find(".") != string::npos)
    {
        // Check for the presence of only one point in the number
        if (str.find(".") != str.rfind(".")) return 0;
        // Check the position of the point (it must not be the first or last character)
        if ((str.find(".") == 0 || str.find(".") == str.size() - 1)) return 0;
    }
    if (str.find("-") != string::npos)
    {
        // If there is only a minus without a number
        if (str.size() == 1) return 0;
        // Check for the presence of only one minus in the number
        if (str.find("-") != str.rfind("-")) return 0;
        // Check the position of the minus (it can only be the first character in the number)
        if (str.find("-") != 0) return 0;
    }
    // Check for the presence of numbers and the absence of extraneous characters
    return (str.find_first_not_of("0123456789.-") == string::npos && str.find_first_of("0123456789.-") != string::npos);
}

bool isConst(const string& str)
{
    if (str == "pi") return 1;
    else if (str == "-pi") return 1;
    else if (str == "e") return 1;
    else if (str == "-e") return 1;
    return 0;
}

bool isFunc(const string& str)
{
    // Check for two parentheses: open and close
    if ((str.find("(") == string::npos) || !checkCountBracket(str)) return 0;

    string funcName[8] = { "cos", "sin", "ctg", "tg", "ln", "log", "sqrt", "cbrt" };
    size_t count = 0;
    string argument = str;

    if (str[0] == '-') argument.erase(argument.begin());
    for (auto i : funcName)
    {
        if (argument.find(i) != string::npos)
        {
            count++;
            // If we have more than one function in the token
            if (count != 1) return 0;
            // Leave only the argument inside the function to check for a number
            argument.erase(argument.find(i), i.size() + 1);
            argument.erase(argument.size() - 1);
        }
    }
    return (isDigit(argument) || isConst(argument));
}

bool isOperator(const string& str)
{
    if (str == "-" || str == "+" || str == "/" || str == "*" || str == "^") return 1;
    else return 0;
}

void checkTokens(const List& tokens)
{
    Iterator* listIter = tokens.create_iterator();

    while (listIter->has_next())
    {
        string token = listIter->getCurrent();
        if (isOperator(token) || token == "(" || token == ")")
        {
            // OK
            // cout << token << " - ";
            // cout << "Delim\n";
        }
        else if (isDigit(token))
        {
            // OK
            // cout << token << " - ";
            // cout << "Digit\n";
        }
        else if (isConst(token))
        {
            // OK
            // cout << token << " - ";
            // cout << "Const\n";
        }
        else if (isFunc(token))
        {
            // OK
            // cout << token << " - ";
            // cout << "Function\n";
        }
        else
        {
            // NOT OK
            cout << token << " - ";
            throw runtime_error("Incorrect input! Try again...");
        }
        listIter->next();
    }
}

size_t getPrioritet(const string& str)
{
    char op = str[0];
    switch (op)
    {
    case '(': return 0;
    case ')': return 0;
    case '+': return 1;
    case '-': return 1;
    case '/': return 2;
    case '*': return 2;
    case '^': return 3;
    }
    throw runtime_error("Can't get prioritet!");
}

List convertToPostfix(List& tokens)
{
    List postFix;
    List list;
    Iterator* listIter = tokens.create_iterator();
    string temp;

    while (listIter->has_next())
    {
        string token = listIter->getCurrent();
        // If the token being viewed is an operand, then we put it into the output stream
        if (isDigit(token) || isFunc(token) || isConst(token)) postFix.push(token);

        else if (isOperator(token))
        {
            // If the priority of the operator, which is at the top of the list,
            // greater than or equal to the token priority.
            // Until we see an operator with a lower priority,
            // pop all operators from the list into the output stream
            // Then push the operator we are looking at onto the list.
            // Otherwise, push the operator being viewed onto the list immediately.
            if (list.getSize() && (getPrioritet(list.getTail()) >= getPrioritet(token)))
            {
                temp = list.getTail();
                while (list.getSize() && list.getTail() != "(" && getPrioritet(temp) >= getPrioritet(token))
                {
                    temp = list.pop();
                    postFix.push(temp);
                    if (list.getSize()) temp = list.getTail();
                }
                list.push(token);
            }
            else
            {
                list.push(token);
            }
        }
        else if (token == "(")
        {
            list.push(token);
        }
        else if (token == ")")
        {
            temp = list.pop();
            // pop all characters from the list until the left parenthesis appears
            // and add them to the output stream
            while (temp != "(")
            {
                postFix.push(temp);
                temp = list.pop();
            }
        }
        listIter->next();
    }
    while (list.getSize())
    {
        postFix.push(list.pop());
    }
    return postFix;
}

void convertConst(string& str)
{
    if (str == "pi") str = to_string(M_PI);
    if (str == "e") str = to_string(exp(1));
    if (str == "-pi") str = to_string(-M_PI);
    if (str == "-e") str = to_string(-exp(1));
}

// Converting func and constants to number
string convertFunc(string& str)
{
    string funcName[] = { "cos", "sin", "ctg", "tg", "ln", "log", "sqrt", "cbrt" };
    size_t count = sizeof(funcName) / sizeof(std::string);
    bool negativeSign = false;

    for (size_t i = 0; i < count; i++)
    {
        if (str.find(funcName[i]) != string::npos)
        {
            if (str[0] == '-')
            {
                str.erase(str.begin());
                negativeSign = true;
            }
            // Leave only the argument inside the function
            str.erase(str.find(funcName[i]), funcName[i].size() + 1);
            str.erase(str.size() - 1);

            if (isConst(str)) convertConst(str);

            switch (i)
            {
            case 0:
                str = to_string(cos(stod(str)));
                break;
            case 1:
                str = to_string(sin(stod(str)));
                break;
            case 2:
                if (str == "pi") throw logic_error("Incorrect argument in ctg!");
                str = to_string(cos(stod(str)) / sin(stod(str)));
                break;
            case 3:
                str = to_string(tan(stod(str)));
                break;
            case 4:
                if (str[0] == '-') throw logic_error("Negative argument in ln!");
                str = to_string(log(stod(str)));
                break;
            case 5:
                if (str[0] == '-') throw logic_error("Negative argument in log!");
                str = to_string(log2(stod(str)));
                break;
            case 6:
                if (str[0] == '-') throw logic_error("Negative argument in sqrt!");
                str = to_string(sqrt(stod(str)));
                break;
            case 7:
                if (str[0] == '-') throw logic_error("Negative argument in cbrt!");
                str = to_string(cbrt(stod(str)));
                break;
            }
            i = 8;
        }
    }
    if (negativeSign) str = to_string(-stod(str));
    return str;
}

double calculate(const List& postfix)
{
    Iterator* listIter = postfix.create_iterator();
    List list;
    while (listIter->has_next())
    {
        string current = listIter->getCurrent();
        double a;
        double b;
        if (isConst(current))
        {
            convertConst(current);
            list.push(current);
        }
        else if (isDigit(current)) list.push(current);
        else if (isFunc(current)) list.push(convertFunc(current));
        else if (isOperator(current))
        {
            if (list.getSize()) b = stod(list.pop());
            else throw logic_error("Not enough operands for such a large number of operators!");
            if (list.getSize()) a = stod(list.pop());
            else throw logic_error("Not enough operands for such a large number of operators!");
            if (current == "+")
            {
                list.push(to_string(a + b));
            }
            else if (current == "-")
            {
                list.push(to_string(a - b));
            }
            else if (current == "/")
            {
                if (b == 0) throw logic_error("The denominator of the fraction is zero!");
                list.push(to_string(a / b));
            }
            else if (current == "*")
            {
                list.push(to_string(a * b));
            }
            else if (current == "^")
            {
                list.push(to_string(pow(a, b)));
            }
        }
        listIter->next();
    }
    if (list.getSize() > 1) throw logic_error("Not enough operators for such a large number of operands!");
    return stod(list.pop());
}