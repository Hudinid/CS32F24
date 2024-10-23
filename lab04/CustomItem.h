#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H
#include "IceCreamItem.h"
#include <string.h>
#include <map>

class CustomItem : public IceCreamItem {
    public:
        CustomItem(std::string size);
        virtual ~CustomItem();
        virtual std::string composeItem();
        virtual double getPrice();
        void addTopping(std::string topping);
        
    private: 
        std::string order;
        std::map<std::string, int> toppings;
};

#endif