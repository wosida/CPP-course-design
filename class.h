//
// Created by ¿Ó∂¨—Ù on 2023/5/25.
//

#ifndef CPPKESHE_CLASS_H
#define CPPKESHE_CLASS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>
#include "windows.h"
using namespace std;
class Epidemic{
    string country;
    string city;
    int Newcases[30];
    int Existcases[30];
    int Acumulatedcases[30];
    int Curedcases[30];
    int Deathcases[30];
    int Forecastcases;
public:
    Epidemic();
    void Forecast();
    int getForecastcases();
    int getNewcases(int k);
    int getExistcases(int k);
    int getAcumulatedcases(int k);
    int getCuredcases(int k);
    int getDeathcases(int k);
    string getcity();
    string getcountry();
    void show(int n) const;
   void setdates(int n,string country,string city,int Newcases,int Existcases,int Acumulatedcases,int Curedcases,int Deathcases);

};

#endif //CPPKESHE_CLASS_H
