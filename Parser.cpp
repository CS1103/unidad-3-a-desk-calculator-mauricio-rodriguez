//
// Created by mauri on 26/10/2019.
//
#include "Token_stream.h"
double prim(bool get){
    
}
double term(bool get){
    double left=prim(get);
    for (;;){
        switch (ts.current().kind){
            case Kind::mul:
                left*=prim(true);
                break;
            case Kind::div:
                if(auto d=prim(true)){
                    left /=d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
    }
}
double expr(bool get){
    double left= term(get);
    for (;;){
        switch (ts.current().kind){
            case Kind::plus:
                left +=term(true);
                break;
            case Kind::minus:
                left-=term(true);
                break;
            default:
                return left;
        }
    }
}
