#ifndef BREAD_H
#define BREAD_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "BakedGood.h"
using namespace std;

class Bread : public BakedGood { 
  public:
    Bread(string breadType);
    string ToString(vector<BakedGood*> allBakedGoods, int i);
    string GetName();
    string GetBasePrice();
    string GetFlavor();
    string GetFrosting();
    string GetLayerQuantity();
    double GetDiscount(vector<int> itemQuantities, int i);
    double GetBasePriceDouble();
    void UpdateQuantity(int newNum);
  private:
    string kindOfBread;
};

#endif