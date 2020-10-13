#ifndef CUPCAKE_H
#define CUPCAKE_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Cake.h"
using namespace std;

class CupCake : public Cake { 
  public:
    CupCake(string sprinklesType, string cakeFlavor, string frostingType);
    string ToString(vector<BakedGood*> allBakedGoods, int i);
    string GetName();
    string GetBasePrice();
    string GetLayerQuantity();
    int GetNumBakedGoods();
    double GetDiscount(vector<int> itemQuantities, int i);
    double GetBasePriceDouble();
    void UpdateQuantity(int newNum);

  private:
    string kindOfSprinkles;
    double creamCheesePrice = .20;
};

#endif