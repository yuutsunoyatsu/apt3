//
// Created by Artemis on 25/05/2023.
//

#ifndef APT3_STOCKITEM_H
#define APT3_STOCKITEM_H


#include <string>
#include <vector>

namespace ppd{
    struct Price
    {
    public:
        // The dollar value, and the cents value for some price
        unsigned dollars, cents;
        std::string getString() const;
        inline unsigned int getCentValue() const;
    };

    class StockItem {
    public:
        StockItem();

        explicit StockItem(const std::vector<std::string>& inputVector);
        bool operator==(const StockItem& other) const;
        std::string description;
        std::string id;
        std::string name;
        unsigned onHand;
        Price price{};
    };
}

#endif //APT3_STOCKITEM_H
