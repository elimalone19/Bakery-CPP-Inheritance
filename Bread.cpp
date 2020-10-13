#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Bread.h"
using namespace std;

Bread::Bread(string breadType) {

  kindOfBread = breadType;
  basePrice = 4.50;
  
}

string Bread::ToString(vector<BakedGood*> allBakedGoods, int i) {

  string breadString;

  breadString = allBakedGoods.at(i)->GetName() + " Bread" + " ($" + BakedGood::ToString(allBakedGoods, i) + ")";

  return breadString;

}

string Bread::GetName() {

  return kindOfBread;

}

string Bread::GetBasePrice() {

  return to_string(basePrice);
}

string Bread::GetFlavor() {
  string myString;
  return myString;
}

string Bread::GetFrosting() {
  string myString;
  return myString;
}

string Bread::GetLayerQuantity() {
  string myString;
  return myString;
}

double Bread::GetDiscount(vector<int> itemQuantities, int i) {

  while (itemQuantities.at(i) >= 3) {
    discountPrice = discountPrice + 4.50;
    itemQuantities.at(i) = itemQuantities.at(i) - 3;
  }
  return discountPrice;
}

double Bread::GetBasePriceDouble() {
  return basePrice;
}

void Bread::UpdateQuantity(int newNum) {
  numBakedGoods = numBakedGoods + newNum;
}
