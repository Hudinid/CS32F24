#include "CustomItem.h"
#include "string.h"
#include <map>
#include <iterator>
#include <iostream>
using namespace std;

CustomItem::CustomItem(std::string size) : IceCreamItem(size) {
    if(size == "small") {
        price += 3.00;
    }
    else if (size == "medium") {
        price += 5.00;
    }
    else {
        price += 6.50;
    }
    this->order = "";
}

CustomItem::~CustomItem() {
    toppings.clear();
}

double CustomItem::getPrice() {
    return this->price;
}

void CustomItem::addTopping(std::string topping) {
    this->price += 0.40;
    if(toppings.count(topping) > 0) {
        // cout << "wasd";
        int newVal = toppings.at(topping) + 1;
        toppings.erase(topping);
        toppings.insert( { topping , newVal } );
    }
    else {
        toppings.insert ({ topping, 1 });
    }
}

std::string CustomItem::composeItem() { 
    std::string ret = "";
    ret += "Custom Size: " + this->size + "\n";
    ret += "Toppings:\n";

    map<std::string, int>::iterator it;
    
    for(it = toppings.begin(); it != toppings.end(); it++) {
        ret += it->first + ": ";
        ret += std::to_string(it->second) + " oz\n"; 
    }
    std::string num_text = std::to_string(getPrice());
    std::string rounded = num_text.substr(0, num_text.find(".")+3);
    ret += "Price: $" + rounded + "\n";
    return ret;
}
