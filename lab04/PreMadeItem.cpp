#include "PreMadeItem.h"
#include <string>

PreMadeItem::PreMadeItem(std::string name, std::string size) : IceCreamItem(size) {
    this->name = name;

    if(size == "small") {
        this->price += 4.00;
    }
    else if (size == "medium") {
        this->price += 6.00;
    }
    else {
        this->price += 7.50;
    }
}

PreMadeItem::~PreMadeItem(){

}

std::string PreMadeItem::composeItem() {
    std::string ret = "";
    ret += "Pre-made Size: " + this->size + "\n";
    ret += "Pre-made Item: " + this->name + "\n"; 
    std::string num_text = std::to_string(getPrice());
    std::string rounded = num_text.substr(0, num_text.find(".")+3);
    ret += "Price: $" + rounded + "\n";

    return ret;
}

double PreMadeItem::getPrice() {
    return this->price;
}