
#include "Token_stream.h"

Token Token_stream::get()
{
    char ch;
    do {//skip} whitespace expect /n;
        if (!ip->get(ch))return ct={Kind::end};
    }   while(ch!='\n'&& isspace(ch));
    switch (ch){
        case ';':
        case '\n':
            return ct={Kind::print};
        default:
            if (isalpha(ch)){
                ct.string_value=ch;
                while(ip->get(ch))
                    if (isalnum(ch))
                        ct.string_value+=ch;
                    else{
                        ip->putback(ch);
                        break;
                    }
                ct.kind=Kind::name;
                return ct;
            }
    }
}