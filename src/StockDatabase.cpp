#include <iomanip>
#include "StockDatabase.h"
#include "Utils.h"

using namespace ppd;

StockDatabase::StockDatabase() {
    db = new DoublyLinkedList<StockItem>();
}

StockDatabase::~StockDatabase() {
    delete db;
}

void StockDatabase::addBack(const std::vector<std::string>& stockLine) {
    StockItem stock(stockLine);
    db->push_back(stock);
}

size_t StockDatabase::size() {
    return db->size();
}

const DoublyLinkedList<ppd::StockItem>& StockDatabase::getList() {
    return *db;
}

ReturnType StockDatabase::findById(const std::string& id, StockItem& stock) {
    ReturnType response = FAILURE;

    for (const auto& item : *db) {
        if (item.id == id) {
            stock = item;
            response = SUCCESS;
        }
    }

    return response;
}

void StockDatabase::saveData() {
    // Open the file in write mode to clear all the content
    std::ofstream outFile(filePath, std::ios::out | std::ios::trunc);
    if (!outFile) {
        std::cerr << "can't open output file" << std::endl;
    }
    outFile.close();

    // Reopen the file in append mode to write new content
    outFile.open(filePath, std::ios::out | std::ios::app);

    // Write new content to .
    for (const auto& item: *db) {
        outFile << item.id << "|"
        << item.name << "|"
        << item.description << "|"
        << item.price.dollars << "."
        << std::setw(2)
        << std::setfill('0')
        << item.price.cents << "|"
        << std::setfill(' ')
        << item.onHand
        << std::endl;

    }

    outFile.close();
}


