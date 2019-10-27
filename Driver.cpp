//
// Created by mauri on 26/10/2019.
//
#include "Token_stream.h"
Token_stream ts{cin}; //input form cin
int no_of_errors;
double error(const string &s){
    no_of_errors++;
    cerr<<"error"<<s<<'\n';
    return 1;
}