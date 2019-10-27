//
// Created by mauri on 27/10/2019.
//

#ifndef DESKCALCULATOR_DRIVER_H
#define DESKCALCULATOR_DRIVER_H

#include "Parser.h"
void calculate(){
    for (;;){
        ts.get();
        if (ts.current().kind==Kind::end)break;
        if (ts.current().kind==Kind::print)continue;
        cout<<expr(false)<<'\n';
    }
}

#endif //DESKCALCULATOR_DRIVER_H
