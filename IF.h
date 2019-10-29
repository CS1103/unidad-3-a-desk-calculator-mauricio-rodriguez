//
// Created by mauri on 27/10/2019.
//

#ifndef DESKCALCULATOR_IF_H
#define DESKCALCULATOR_IF_H

#include "Errors.h"
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
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return ct={static_cast<Kind>(ch)};
        case '0': case '1': case'2': case '3': case '4': case'5':case '6':case '7': case '8': case '9':
        case '.':
            ip->putback(ch);
            *ip>>ct.numer_value;
            ct.kind=Kind::number;
            return ct;
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
            error("bad token");
            return ct={Kind::print};
    }
}

#endif //DESKCALCULATOR_IF_H
