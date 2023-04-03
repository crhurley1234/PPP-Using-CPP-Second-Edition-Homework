
//
// This is example code from Chapter 6.5.2.2 "Expressions: Second try" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

Token get_token();    // read a token from cin

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double expression()
{
    double left = term();              // read and evaluate a Term
    Token t = get_token();             // get the next token
    switch (t.kind) {                  // see which kind of token that is
    case '+':
        return left + expression();    // read and evaluate an Expression,
                                       // then do an add
    case '-':
        return left - expression();    // read and evaluate an Expression,
                                       // then do a subtraction
    default:
        return left;                   // return the value of the Term
    }
}

//------------------------------------------------------------------------------
