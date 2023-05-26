//
// Created by Artemis on 25/05/2023.
//

#ifndef APT3_COINSDATABASE_H
#define APT3_COINSDATABASE_H

#include "LinkedList.h"
#include "Utils.h"

namespace ppd{
    struct CoinDenom {
        unsigned denomination;
        unsigned amount;
    };

    class CoinsDatabase {
        DoublyLinkedList<CoinDenom>* db;
    public:
        std::string filePath;

        CoinsDatabase();
        ~CoinsDatabase();
        void addDenomination(CoinDenom denom);

        const DoublyLinkedList<ppd::CoinDenom>& getList();

        ReturnType saveData();
    };




}



#endif //APT3_COINSDATABASE_H
