#include "CppUnitTest.h"
#include <exception>

#include "../CourseWork/functions/lib/calc.hpp"
#include "../CourseWork/functions/lib/stack.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace CourseWorkTest
{
	TEST_CLASS(CourseWorkTest)
	{
	public:
		TEST_METHOD(INPUT_Correct_Number_Of_Brackets)
		{
			// If the quantity "(" match ")"
			try
			{
				string str = "5 * ( 3 - 2 )";

				//Check correct input
				checkExpression(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreNotEqual(message.what(), "Recheck brackets in an expression!");
			}
		}
		TEST_METHOD(INPUT_Incorrect_Number_Of_Brackets)
		{			
			// If the quantity "(" does not match ")"
			try
			{
				string str = "5 * ( 3 - 2 (";

				//Check correct input
				checkExpression(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Recheck brackets in an expression!");
			}
		}
		TEST_METHOD(INPUT_Close_Bracket_Met_After_Closing_Bracket)
		{
			// If close bracket met after closing bracket
			try
			{
				string str = "ln(e) - 4 + ( 6 - 2 )";

				//Check correct input
				checkExpression(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreNotEqual(message.what(), "The closing bracket met before the opening bracket!");
			}
		}
		TEST_METHOD(INPUT_Close_Bracket_Met_Before_Closing_Bracket)
		{
			// If close bracket met before closing bracket
			try
			{
				string str = "ln(e) - 4 + ) 6 - 2 (";

				//Check correct input
				checkExpression(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "The closing bracket met before the opening bracket!");
			}
		}
		TEST_METHOD(INPUT_Full_Bracket)
		{
			// If the expression doesn't contains empty parentheses
			try
			{
				string str = "cos(pi) + 3";

				//Check correct input
				checkExpression(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreNotEqual(message.what(), "Some brackets in an expression are empty!");
			}
		}
		TEST_METHOD(INPUT_Empty_Bracket)
		{
			// If the expression contains empty parentheses
			try
			{
				string str = "cos() + 3";

				//Check correct input
				checkExpression(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Some brackets in an expression are empty!");
			}
		}
		TEST_METHOD(INPUT_Empty_Bracket_SecondTry)
		{
			// If the expression contains empty parentheses
			try
			{
				string str = "pi + e + cos()";

				//Check correct input
				checkExpression(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Some brackets in an expression are empty!");
			}
		}		
		TEST_METHOD(getPrioritet_IncorrectValue_Const)
		{
			try
			{
				string str = "pi";
				getPrioritet(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Can't get prioritet!");
			}
		}		
		TEST_METHOD(getPrioritet_IncorrectValue_Func)
		{
			try
			{
				string str = "ln(e)";
				getPrioritet(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Can't get prioritet!");
			}
		}
		TEST_METHOD(getPrioritet_IncorrectValue_Digit)
		{
			try
			{
				string str = "999";
				getPrioritet(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Can't get prioritet!");
			}
		}
		TEST_METHOD(getPrioritet_IncorrectValue_Operand)
		{
			try
			{
				string str = "+";
				getPrioritet(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreNotEqual(message.what(), "Can't get prioritet!");
			}
		}
		TEST_METHOD(getPrioritet_CorrectValue_Operand)
		{
			string str = "+";
			size_t prioritet = getPrioritet(str);
			Assert::AreEqual(double(prioritet), double(1));
		}
		TEST_METHOD(getPrioritet_IncorrectValue_Bracket)
		{
			try
			{
				string str = "(";
				getPrioritet(str);

			}
			catch (const std::exception& message)
			{
				Assert::AreNotEqual(message.what(), "Can't get prioritet!");
			}
		}
		TEST_METHOD(getPrioritet_CorrectValue_Bracket)
		{
			string str = "(";
			size_t prioritet = getPrioritet(str);
			Assert::AreEqual(double(prioritet), double(0));
		}
		TEST_METHOD(getPrioritet_CorrectValue_Exponentiation)
		{
			string str = "^";
			size_t prioritet = getPrioritet(str);
			Assert::AreEqual(double(prioritet), double(3));
		}
		TEST_METHOD(isDigit_IncorrectPoints)
		{
			string str = ".5.";
			Assert::IsFalse(isDigit(str));
			str = ".5";
			Assert::IsFalse(isDigit(str));
			str = "5.";
			Assert::IsFalse(isDigit(str));
			str = ".";
			Assert::IsFalse(isDigit(str));
		}
		TEST_METHOD(isDigit_IncorrectMinus)
		{
			string str = "5-";
			Assert::IsFalse(isDigit(str));
			str = "-5-";
			Assert::IsFalse(isDigit(str));
			str = "-";
			Assert::IsFalse(isDigit(str));
		}
		TEST_METHOD(isDigit_IncorrectInput)
		{
			string str = "pi";
			Assert::IsFalse(isDigit(str));
			str = "cos(pi)";
			Assert::IsFalse(isDigit(str));
			str = "+";
			Assert::IsFalse(isDigit(str));
			str = ")";
			Assert::IsFalse(isDigit(str));
		}
		TEST_METHOD(isDigit_CorrectInput)
		{
			string str = "5";
			Assert::IsTrue(isDigit(str));
			str = "5.5";
			Assert::IsTrue(isDigit(str));
			str = "-5";
			Assert::IsTrue(isDigit(str));
			str = "-5.5";
			Assert::IsTrue(isDigit(str));			
		}
		TEST_METHOD(isFunc_IncorrectBrackets)
		{
			string str = "ln(e(";
			Assert::IsFalse(isFunc(str));
			str = "ln)e)";
			Assert::IsFalse(isFunc(str));
			str = "lne";
			Assert::IsFalse(isFunc(str));

			str = "-ln(e(";
			Assert::IsFalse(isFunc(str));
			str = "-ln)e)";
			Assert::IsFalse(isFunc(str));
			str = "-lne";
			Assert::IsFalse(isFunc(str));
		}
		TEST_METHOD(isFunc_Many_Functions_In_Token)
		{
			string str = "lntgcos(e)";
			Assert::IsFalse(isFunc(str));
		}
		TEST_METHOD(isFunc_CorrectInput)
		{
			string str = "ln(e)";
			Assert::IsTrue(isFunc(str));
			str = "-ln(e)";
			Assert::IsTrue(isFunc(str));

			str = "sqrt(9)";
			Assert::IsTrue(isFunc(str));
			str = "sqrt(6.25)";
			Assert::IsTrue(isFunc(str));
			str = "cbrt(225)";
			Assert::IsTrue(isFunc(str));
			str = "log(16)";
			Assert::IsTrue(isFunc(str));
		}
		TEST_METHOD(isFunc_IncorrectArgument_ctg)
		{
			try
			{
				string str = "ctg(pi)";
				convertFunc(str);

			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Incorrect argument in ctg!");
			}
		}
		TEST_METHOD(isFunc_IncorrectArgument_ln)
		{
			try
			{
				string str = "ln(-e)";
				convertFunc(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Negative argument in ln!");
			}
		}
		TEST_METHOD(isFunc_IncorrectArgument_log)
		{
			try
			{
				string str = "log(-16)";
				convertFunc(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Negative argument in log!");
			}
		}
		TEST_METHOD(isFunc_IncorrectArgument_sqrt)
		{
			try
			{
				string str = "sqrt(-9)";
				convertFunc(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Negative argument in sqrt!");
			}
		}
		TEST_METHOD(isFunc_IncorrectArgument_cbrt)
		{
			try
			{
				string str = "cbrt(-225)";
				convertFunc(str);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Negative argument in cbrt!");
			}
		}
		TEST_METHOD(Calculate_NotEnoughOperands)
		{
			try
			{
				string str = "cos(0) + sin(90) - +";
				Stack tokens = parse(str);
				Stack postfix = convertToPostfix(tokens);
				double result = calculate(postfix);
			}
			catch (const std::exception& message)
			{
				Assert::AreEqual(message.what(), "Not enough operands for such a large number of operators");
			}
		}
		TEST_METHOD(Calculate_CorrectInput)
		{			
			string str = "cos(0) + ln(e)";
			Stack tokens = parse(str);
			Stack postfix = convertToPostfix(tokens);
			double result = calculate(postfix);
			Assert::AreEqual(result, double(2));
		}
		TEST_METHOD(Calculate_CorrectInputSecond)
		{
			string str = "sin(0) / cos(pi) + ctg(999) + ( tg(pi) - ctg(999) + ln(e) ) + log(16) * ( sqrt(9) + cbrt(64) ) - 5 ^ ( 3 - ln(e) )";
			Stack tokens = parse(str);
			Stack postfix = convertToPostfix(tokens);
			double result = calculate(postfix);
			Assert::AreEqual(result, double(4));			
		}
	};
}
