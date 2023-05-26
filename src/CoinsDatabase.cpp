#include "CoinsDatabase.h"
#include "Utils.h"
#include <fstream>

using namespace ppd;

CoinsDatabase::CoinsDatabase() {
    db = new DoublyLinkedList<CoinDenom>();
}

CoinsDatabase::~CoinsDatabase() {
    delete db;
}

void CoinsDatabase::addDenomination(CoinDenom denom) {
    db->push_back(denom);
}

const DoublyLinkedList<ppd::CoinDenom>& CoinsDatabase::getList() {
    return *db;
}

ReturnType CoinsDatabase::saveData() {
    // Open the file in write mode to clear all the content
    std::ofstream outFile(filePath, std::ios::out | std::ios::trunc);
    if (!outFile) {
        std::cerr << "can't open output file" << std::endl;
    }
    outFile.close();

    // Reopen the file in append mode to write new content
    outFile.open(filePath, std::ios::out | std::ios::app);

    // Write new content to the file
    for (const auto& item: *db) {
        outFile << item.denomination << "|" << item.amount << std::endl;
    }

    outFile.close();

    return SUCCESS;
}
