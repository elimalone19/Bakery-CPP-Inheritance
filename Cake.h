#ifndef CAKE_H
#define CAKE_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "BakedGood.h"
using namespace std;

class Cake : public BakedGood { 

  public: 
    Cake();
    virtual string ToString(vector<BakedGood*> allBakedGoods, int i);
    virtual string GetName() = 0;
    virtual string GetBasePrice() = 0;
    virtual string GetLayerQuantity() = 0;
    string GetFlavor();
    string GetFrosting();
    double GetDiscount(vector<int> itemQuantities, int i) = 0;
    double GetBasePriceDouble();
    void UpdateQuantity(int newNum);
  private:
   

  protected:
    int numBakedGoods;
    double basePrice;
    string kindOfFrosting;
    string flavorOfCake;
    
    
};


#endif