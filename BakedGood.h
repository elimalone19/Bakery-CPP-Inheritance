#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class BakedGood {

  public: 
    BakedGood();
    virtual string ToString(vector<BakedGood*> allBakedGoods, int i);
    virtual string GetName() = 0;
    virtual string GetBasePrice() = 0;
    virtual string GetFlavor() = 0;
    virtual string GetFrosting() = 0;
    virtual string GetLayerQuantity() = 0;
    virtual int GetNumBakedGoods();
    virtual double GetDiscount(vector<int> itemQuantities, int i) = 0;
    virtual double GetBasePriceDouble() = 0;
    virtual void UpdateQuantity(int newNum) = 0;


  private:
   

  protected:
    int numBakedGoods;
    double basePrice;
    double discountPrice = 0;

    
};


#endif