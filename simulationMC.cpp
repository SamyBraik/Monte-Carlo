#include <iostream>
#include <random>
#include <cmath>
#include <numeric>

double period = 5;
double strike = 100;
double current = 100;
double vol = 0.15; 
double drift = 0.06;

std::default_random_engine generator;
std::normal_distribution<double> distribution(0.0, period);
std::vector<double> prices;

int main(){
    for (int i=0;i<= 10000; i++){
        double nombre = distribution(generator);
        double value = current* std::exp(drift*period - std::pow(vol,2)/(2*period)+vol*nombre);
        if ((value-strike) >0){
            prices.push_back(value-strike);
        }
        else{
            prices.push_back(0.0);
        };
    }

    double sum = 0;
    for(std::vector<double>::iterator i = prices.begin(); i != prices.end(); ++i){
        sum += *i;
    }
    std::cout<<sum/10000;
    
     

};