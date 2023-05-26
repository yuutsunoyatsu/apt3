#ifndef APT3_VENDINGMACHINE_H
#define APT3_VENDINGMACHINE_H

#include <string>
#include "Utils.h"
#include "StockDatabase.h"
#include "CoinsDatabase.h"
#include "Command.h"

namespace ppd {

    class VendingMachine {
    StockDatabase* sdb;
    CoinsDatabase* cdb;

    public:
        // Reading files
        ReturnType tryParseStock(const std::string& filePath);
        ReturnType tryParseCoins(const std::string& filePath);

        // Main
        VendingMachine();
        ~VendingMachine();
        void start();
    };

}

#endif //APT3_VENDINGMACHINE_H
