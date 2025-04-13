#include "Braces.h"


std::string EnterStr()
{

	std::string Str;
	while (true)
	{
	std::cout << "[Enter String]: "; std::cin >> Str;
	
	if (Str.length() < 0) std::cout << "\n[Enter More Symbols Than 0]\n";
	
	else
		{
			break;
			return Str;
		}
	}

}

int MatchingPair(char a, char b)
{
	if (a == '{' && b == '}') return 1;
	else if (a == '(' && b == ')') return 1;
	else if (a == '[' && b == ']') return 1;
	return 0; 
}

void LoopOverStr(std::string str)
{
	std::stack<char> st;
	bool errorFound = false;

	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];

		if (ch != '{' && ch != '}' && ch != '(' && ch != ')' && ch != '[' && ch != ']')
			continue;

		if (ch == '{' || ch == '(' || ch == '[')
		{
			st.push(ch);
		}
		else
		{
			if (st.empty() || !MatchingPair(st.top(), ch))
			{
				std::cout << "\n[Not A Matching Pair]\n";
				errorFound = true;
				break;
			}
			else
			{
				st.pop();
			}
		}
	}

	if (!errorFound)
	{
		if (st.empty())
			std::cout << "\n[Matching & Balanced Brackets]\n";
		else
			std::cout << "\n[Not A Matching Pair]\n";
	}
}