#include <vector>
#include <sstream>
#include <iostream>
#include "VendingMachine.h"
#include "cmd/MenuCommand.h"
#include "Invoker.h"
#include "Utils.h"

namespace ppd {
    VendingMachine::VendingMachine() {
        sdb = new StockDatabase;
        cdb = new CoinsDatabase;
    }

    VendingMachine::~VendingMachine() {
        delete sdb;
        delete cdb;
    }

    void VendingMachine::start() {
        Invoker cmd(sdb, cdb);
        MenuCommand menu;
        ReturnType response = SUCCESS;

        while (response != EOFILE) {
            response = menu.execute(cmd);
        }

    }

    ReturnType VendingMachine::tryParseStock(const std::string& filePath) {
        ReturnType response;
        std::ifstream file(filePath);
        std::string line;
        sdb->filePath = filePath;

        if (validateFileExistence(filePath)) {
            // Read lines from file and tokenize
            while (std::getline(file, line)) {
                trim(line);
                std::vector<std::string> tokens;
                std::istringstream lineStream(line);
                std::string token;

                while (std::getline(lineStream, token, '|')) {
                    trim(token);
                    tokens.push_back(token);
                }

                if (tokens.size() == 5) {
                    sdb->addBack(tokens);
                }
            }

            response = SUCCESS;
        }
        else {
            response = ReturnType::INVALID;
        }

        file.close();
        return response;
    }

    ReturnType VendingMachine::tryParseCoins(const std::string& filePath) {
        std::ifstream file(filePath);
        std::string line;
        ReturnType response;
        cdb->filePath = filePath;

        if (validateFileExistence(filePath)) {
            while (std::getline(file, line)) {
                CoinDenom cd{};
                std::stringstream ss(line);
                std::string token;

                std::getline(ss, token, ',');
                cd.denomination = std::stoul(token);

                std::getline(ss, token, ',');
                cd.amount = std::stoul(token);

                cdb->addDenomination(cd);
            }
            response = SUCCESS;
        }
        else {
            response = ReturnType::INVALID;
        }

        file.close();
        return response;
    }
}