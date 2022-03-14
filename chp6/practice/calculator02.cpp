#include "std_lib_facilities.h"

double expression();

class Token {
public:
	char kind;
	double value;
	Token(char ch) : kind(ch), value(0) {}
	Token(char ch, double val) : kind(ch), value(val) {}
};

class Token_stream
{
public:
    Token_stream();
    Token get();
    void put_back(Token t);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream(): full (false), buffer(0) {}

void Token_stream::put_back(Token t){
    if (full) error ("Token_stream buffer is full");
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

	switch (ch) {
        case 'q':   // exit char 
        case ';':    // end of expression
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '.':
		case '/':
		//case '%':
			return Token(ch);
			case '1': case '2': case '3': case '4': case '5':
			case '6': case '7': case '8': case '9': case '0':
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
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();
		Token t = ts.get();
		if (t.kind != ')') error(") expected!");
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
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
			left /= primary(); // primary == 0?
		/*
		case '%':
			left %= primary(); // module is not defined for doubles
			t = get_token();
			break; 
			*/
		default:
            ts.put_back(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
            ts.put_back(t);
			return left; // result;
		}
	}
}

int main()
try{
    double val = 0;

	while (cin)
		{
            Token t = ts.get();
            if(t.kind == 'q') break;
            if(t.kind == ';')
                cout << "=" << val << endl;
            else 
                ts.put_back(t);
            
            val = expression();
        }

	return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch(...)
{
    cerr << "some error\n";
    return 2;
}