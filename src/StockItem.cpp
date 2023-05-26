//
// Created by Artemis on 25/05/2023.
//

#include "StockItem.h"
#include <sstream>
#include <iomanip>

using namespace ppd;

StockItem::StockItem(const std::vector<std::string>& dataVector) {
    id = dataVector[0];
    name = dataVector[1];
    description = dataVector[2];
    double priceValue = std::stod(dataVector[3]);
    price.dollars = (int) priceValue;
    price.cents = (int) (priceValue - price.dollars) * 100;
    onHand = (unsigned int) std::stoi(dataVector[4]);
}

bool StockItem::operator==(const StockItem& other) const {
    return this->id == other.id;
}

StockItem::StockItem() = default;

unsigned int Price::getCentValue() const {
    return dollars * 100 + cents;
}

std::string Price::getString() const {
    std::stringstream ss;
    ss << "$" << dollars << "."
       << std::setw(2) << std::setfill('0')
       << cents << std::setfill(' ');
    return ss.str();
}
