//change the character used as exit command from q to x
//change the character used as print command from ; to =

#include "std_lib_facilities.h"

double expression();

class Token {
public:
	char kind;
	double value;
	Token (char ch): kind(ch), value(0) {}
	Token (char ch, double val): kind(ch), value(val) {}
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream(): full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full) error("Token_stream buffer full");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{	
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch(ch) {
		case 'x':           //here q is changed to x        //x is the case when user want to quit
		case '=':           //here ; is changed to =        //= is the when user wants to get the output from an expressions
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		//case '%':
			return Token(ch);
		case '.':
		case '0': case '1': case '2': case '3':
		case '4': case '5': case '6': case '7':
		case '8': case '9':
		{
			cin.putback(ch);
			double val = 0;
			cin >> val;
			return Token('8', val);
		}
		default:
			error("Bad token");
			return 0;
	}
}

Token_stream ts;

double primary()
{
	Token t = ts.get();
	switch(t.kind)
	{
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case '8':
			return t.value;
		default:
			error("primary expected");
			return 0;
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while(true){
		switch(t.kind){
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if ( d == 0 ) error("divide by zero");
				left /= d;
				t = ts.get();
				break;
			}
			/*
			case '%':
				left %= primary();
				t = get_token();
				break;
				*/
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression() 
{
	double left = term();
	Token t = ts.get();
	while(true){
		switch(t.kind){
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

int main()
try {
	//adding greeting line in the main()
    cout << "welcome to our simple calculator\n";
    cout << "Please enter expressions using floating numbers\n";
	double val = 0;

	while(cin)
	{
		Token t = ts.get();

		if (t.kind == 'x') break;           //q has been changed to x      // ts.get() loop will break when the input is x
		if (t.kind == '=')                  //; has been changed to =      // expression result would be first executed 
			cout << "=" << val << endl;
		else
			ts.putback(t);

		val = expression();
	}

	return 0;

} catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}