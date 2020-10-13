#ifndef LAYERCAKE_H
#define LAYERCAKE_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Cake.h"
using namespace std;

class LayerCake : public Cake { 
  public:
    LayerCake(string cakeFlavor, string frostingType, int numLayerCakes);
    string ToString(vector<BakedGood*> allBakedGoods, int i);
    string GetName();
    string GetBasePrice();
    string GetLayerQuantity();
    int GetNumBakedGoods();
    double GetDiscount(vector<int> itemQuantities, int i);
    double GetBasePriceDouble();
    void UpdateQuantity(int newNum);

    
  private:
    int layerQuantity;
    double extraLayerPrice = 3.00;
    double creamCheesePrice = 1.00;
};

#endif