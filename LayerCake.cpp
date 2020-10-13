#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "LayerCake.h"
using namespace std;

LayerCake::LayerCake(string cakeFlavor, string frostingType, int numLayers) {

  basePrice = 9.00;
  flavorOfCake = cakeFlavor;
  kindOfFrosting = frostingType;
  layerQuantity = numLayers;

  for (int i = 0; i < layerQuantity - 1; i++) {

    basePrice = basePrice + extraLayerPrice;

  }

  if (kindOfFrosting == "cream-cheese") {

    for (int i = 0; i < layerQuantity; i++) {

      basePrice = basePrice + creamCheesePrice;

    }
  }
  
}

string LayerCake::ToString(vector<BakedGood*> allBakedGoods, int i) {

  string cupCakeString;

  cupCakeString = allBakedGoods.at(i)->GetLayerQuantity() + "-Layer " + allBakedGoods.at(i)->GetFlavor() + " cake with " + allBakedGoods.at(i)->GetFrosting() + " frosting" + " ($" + Cake::ToString(allBakedGoods, i) + ")";

  return cupCakeString;

}

string LayerCake::GetName() {
  string myString;
  return myString;
}

string LayerCake::GetBasePrice() {
  return to_string(basePrice);
}

string LayerCake::GetLayerQuantity() {
  return to_string(layerQuantity);
}

int LayerCake::GetNumBakedGoods() {
  return numBakedGoods;
}

double LayerCake::GetDiscount(vector<int> itemQuantities, int i) {
  if (itemQuantities.at(i) >= 3) {
    discountPrice = 2.00;
  }
  return discountPrice * itemQuantities.at(i);
}

double LayerCake::GetBasePriceDouble() {
  return basePrice;
}

void LayerCake::UpdateQuantity(int newNum) {
  numBakedGoods = numBakedGoods + newNum;
}