#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "CupCake.h"
using namespace std;

CupCake::CupCake(string sprinklesType, string cakeFlavor, string frostingType) {

  kindOfSprinkles = sprinklesType;
  basePrice = 1.95;
  flavorOfCake = cakeFlavor;
  kindOfFrosting = frostingType;

  if (kindOfFrosting == "cream-cheese") {
    basePrice = basePrice + creamCheesePrice;
  }
  
}

string CupCake::ToString(vector<BakedGood*> allBakedGoods, int i) {

  string cupCakeString;

  cupCakeString = allBakedGoods.at(i)->GetFlavor() + " cupcake with " + allBakedGoods.at(i)->GetFrosting() + " frosting" + " and " + allBakedGoods.at(i)->GetName() + " sprinkles" + " ($" + Cake::ToString(allBakedGoods, i) + ")";

  return cupCakeString;

}

string CupCake::GetName() {

  return kindOfSprinkles;

}

string CupCake::GetBasePrice() {

  return to_string(basePrice);
}

string CupCake::GetLayerQuantity() {
  string myString;
  return myString;
}

int CupCake::GetNumBakedGoods() {
  return numBakedGoods;
}

double CupCake::GetDiscount(vector<int> itemQuantities, int i) {

  if (itemQuantities.at(i) == 2 || itemQuantities.at(i) == 3) {
    discountPrice = .3;
  }
  else if (itemQuantities.at(i) >= 4) {
    discountPrice = .4;
  }
  return discountPrice * itemQuantities.at(i);
}

double CupCake::GetBasePriceDouble() {
  return basePrice;
}

void CupCake::UpdateQuantity(int newNum) {
  numBakedGoods = numBakedGoods + newNum;
}