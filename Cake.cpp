#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Cake.h"
using namespace std;

Cake::Cake() {


}

string Cake::ToString(vector<BakedGood*> allBakedGoods, int i) {

  return allBakedGoods.at(i)->GetBasePrice();

}

string Cake::GetFlavor(){
  return flavorOfCake;
}

string Cake::GetFrosting() {

  return kindOfFrosting;
}

double Cake::GetBasePriceDouble() {
  int myInt = 0;
  return myInt;
}

void Cake::UpdateQuantity(int newNum) {
  numBakedGoods = numBakedGoods + newNum;
}
