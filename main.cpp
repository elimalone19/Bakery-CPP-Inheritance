#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"

using namespace std;

bool IsAlreadyInVector(vector<BakedGood*> allBakedGoods, vector<BakedGood*> holdVector, int j, int& newIndex) {
  bool alreadyInVector = false;
  for (unsigned int i = 0; i < holdVector.size(); i++) {
    if (allBakedGoods.at(j)->ToString(allBakedGoods, j) == holdVector.at(i)->ToString(holdVector, i)) {
      alreadyInVector = true;
      newIndex = i;
    }
  }
  return alreadyInVector;
}

void CreateTempVector(vector<BakedGood*> allBakedGoods, vector<BakedGood*>& holdVector, vector<int>& itemQuantities) {
  string checkString;
  int newIndex;

  for (unsigned int k = 0; k < allBakedGoods.size(); k++) {
    if (IsAlreadyInVector(allBakedGoods, holdVector, k, newIndex) == true) {
      itemQuantities.at(newIndex) = itemQuantities.at(newIndex) + 1;
    }

    else {
      holdVector.push_back(allBakedGoods.at(k));
      itemQuantities.push_back(1);

    }
  }
}

int main() {
  string bakedGood;
  string breadType;
  string cakeFlavor;
  string frostingType;
  string sprinklesType;
  int numBakedGoods;
  int numLayers;
  int totalQuantity = 0;
  double totalPrice = 0.0;
  double rowTotal;
  vector<BakedGood*> allBakedGoods;
  vector<BakedGood*> holdVector;
  vector<int> itemQuantities;

  cout << "**Bread and Cakes Bakery**" << endl << endl;
  cout << "Enter sub-order (enter \"done\" to finish)" << endl;

  while (bakedGood !="done") {

    cout << "Sub-order: ";
    cin >> bakedGood;

    if (bakedGood == "Bread") {
      cin >> breadType;
      cin >> numBakedGoods;

      for (int i = 0; i < numBakedGoods; i++) {
        allBakedGoods.push_back(new Bread(breadType));
      }
    }
 

    else if (bakedGood == "Cupcake") {
      cin >> cakeFlavor;
      cin >> frostingType;
      cin >> sprinklesType;
      cin >> numBakedGoods;
      for (int i = 0; i < numBakedGoods; i++) {
        allBakedGoods.push_back(new CupCake(sprinklesType, cakeFlavor, frostingType));
      }
    }

    else if (bakedGood == "Layer-cake") {
      cin >> cakeFlavor;
      cin >> frostingType;
      cin >> numLayers;
      cin >> numBakedGoods;
      for (int i = 0; i < numBakedGoods; i++) {
        allBakedGoods.push_back(new LayerCake(cakeFlavor, frostingType, numLayers));
      }
    }

  }

  cout << "Order Confirmations:" << endl;

  for (unsigned int i = 0; i < allBakedGoods.size(); i++) {
      
    cout << allBakedGoods.at(i)->ToString(allBakedGoods, i) << endl;

  }

  holdVector.push_back(allBakedGoods.at(0));
  itemQuantities.push_back(0);
  CreateTempVector(allBakedGoods, holdVector, itemQuantities);




  cout << "Invoice:" << endl;
  cout << left << setw(75) << "Baked Good" << setw(9) << "Quantity" << setw(9) << "Total" << endl;


  for (unsigned int i = 0; i < holdVector.size(); i++) {
  
    rowTotal = (itemQuantities.at(i) * holdVector.at(i)->GetBasePriceDouble()) - holdVector.at(i)->GetDiscount(itemQuantities, i);

    cout << left << setw(75) << holdVector.at(i)->ToString(holdVector, i) << setw(9) << itemQuantities.at(i) << setw(9) << fixed << setprecision(2) << rowTotal << endl;

    totalQuantity = totalQuantity + itemQuantities.at(i);
    totalPrice = totalPrice + rowTotal;

  }

  cout << left << setw(75) << "Totals" << setw(9) << totalQuantity << setw(9) << totalPrice << endl;

  cout << "Good Bye" << endl;


}