//
// Created by mauri on 26/10/2019.
//
#include "headers.h"
#ifndef DESKCALCULATOR_TOKEN_STREAM_H
#define DESKCALCULATOR_TOKEN_STREAM_H

enum class Kind: char {
    name, number,end,
    plus='+',minus='-',mul='*',div='/', print=';',
    assign ='=',lp='(',rp=')'
};
struct Token{
    Kind kind;
    string string_value;
    double numer_value;
};
class Token_stream {
private:
    void close(){
        if (owns) delete ip;}
        istream *ip;
        bool owns;
        Token ct{Kind::end};
public:
    explicit Token_stream(istream & s):ip{&s},owns{false}{}
    explicit Token_stream(istream *p):ip{p},owns{true}{}
    ~Token_stream(){close();}
    Token get();
    const Token& current(){return ct;}
    void set_input(istream &s){close(); ip=&s;owns=false;}
    void set_input(istream *p){close();ip=p;owns=true;}
};


#endif //DESKCALCULATOR_TOKEN_STREAM_H
