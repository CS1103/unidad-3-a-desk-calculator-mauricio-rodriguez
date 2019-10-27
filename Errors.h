//
// Created by mauri on 27/10/2019.
//

#ifndef DESKCALCULATOR_ERRORS_H
#define DESKCALCULATOR_ERRORS_H

#include "Token_stream.h"
Token_stream ts{cin}; //input form cin
int no_of_errors;
double error(const string &s){
    no_of_errors++;
    cerr<<"error"<<s<<'\n';
    return 1;
}

#endif //DESKCALCULATOR_ERRORS_H
