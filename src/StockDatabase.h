//
// Created by Artemis on 25/05/2023.
//

#ifndef APT3_STOCKDATABASE_H
#define APT3_STOCKDATABASE_H

#include <string>
#include <vector>
#include "StockItem.h"
#include "LinkedList.h"
#include "Utils.h"

namespace ppd {
    class StockDatabase {
        DoublyLinkedList<StockItem>* db;

    public:
        std::string filePath;

        void addBack(const std::vector<std::string>& stockLine);

        ~StockDatabase();

        StockDatabase();

        size_t size();

        const DoublyLinkedList <ppd::StockItem>& getList();

        ReturnType findById(const std::string& id, StockItem& stock);

        void saveData();
    };
}

#endif //APT3_STOCKDATABASE_H
