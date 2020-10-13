#include "BakedGood.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

BakedGood::BakedGood() {

}

string BakedGood::ToString(vector<BakedGood*> allBakedGoods, int i) {

  return allBakedGoods.at(i)->GetBasePrice();

}

int BakedGood::GetNumBakedGoods() {
  return numBakedGoods;
}
