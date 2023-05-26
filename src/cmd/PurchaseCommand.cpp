//
// Created by Artemis on 26/05/2023.
//

#include <iomanip>
#include <map>
#include "PurchaseCommand.h"

namespace ppd {
    PurchaseCommand::PurchaseCommand() {
        introString = "Purchasing item...";
        helpString = "Input the ID of the item you would like to purchase "
                     "(e.g. I0001) and then pay using valid denominations until"
                     " you have paid enough and may receive change.";
    }

    ReturnType PurchaseCommand::runSubFunction(Invoker cmdInvoker) {
        std::cout << "Purchase Item\n"
                "-------------\n";


        bool valid_loop = true;
        while (valid_loop){
            std::cout << "Please enter the id of the item you wish to purchase: ";

            std::string userChoice;
            std::getline(std::cin, userChoice);
            StockItem stock;
            trim(userChoice);

            if (cmdInvoker.sdb->findById(userChoice, stock) == SUCCESS) {
                // Item found
                std::cout << "\nYou have selected \""
                          << stock.name << " - " << stock.description
                          << "\". This will cost you "
                          << stock.price.getString()
                          << ".\n";

                std::cout << "Please hand over the money - type in the value of each note/coin in cents.\n";
                std::cout << "Press enter or ctrl-d to cancel this purchase: ";
//                coinLoop(cmdInvoker.cdb, stock);
                valid_loop = false;
            }
            else {
                if (userChoice.empty() || std::cin.eof()) {
                    valid_loop = false;
                }
                else {
                    std::cout << "\nError: you did not enter a valid id. Please try again.\n";
                }
            }
        }

        return SUCCESS;
    }

//    bool PurchaseCommand::coinLoop(CoinsDatabase* cdb,
//                                 StockItem& stock) {
//        bool endLoop = false;
//        bool return_val = true;
//
//        while (stock.price.getCentValue() > 0 && !endLoop) {
//            std::cout << "\nYou still need to give us " <<
//            Price::getString(stock.price);
//            std::cout << ": " << std::setfill(' ') ;
//
//            std::string input;
//            if (std::cin.eof()) {
//                endLoop = true;
//            }
//            std::getline(std::cin, input);
//            trim(input);
//
//            if (input.find_first_not_of( "0123456789" ) == std::string::npos && !endLoop && !input.empty()){
//                unsigned userInput = std::stoul(input);
//                // Found denomination
//                if (cdb..count((int) userInput) > 0) {
//                    // Check if change can be returned
//                    int valAfterCoin = (int) costInCents - userInput;
//
//                    if (valAfterCoin < 0) {
//                        cout << "Here is your ";
//                        cout << stock.name;
//                        endLoop = !dispenseCoins(map, -valAfterCoin, false);
//                    }
//
//
//                    if (!endLoop){
//                        // Subtract from map if available
//                        map[userInput] += 1;
//
//                        if (valAfterCoin >= 0){
//                            costInCents -= userInput;
//                        }
//                        else {
//                            costInCents = 0;
//                        }
//                    }
//                }
//
//                else if (!endLoop){
//                    std::cout << "\nError: ";
//                    Coin::printPrice(costInCents);
//                    std::cout << " is not a valid denomination of money. Please try again.";
//                }
//
//            }
//            else {
//                if (input.empty() || std::cin.eof()) {
//                    endLoop = true;
//                }
//                else {
//                    cout << "Error: you did not enter a valid int. Please try again." << endl;
//                    return_val = false;
//                }
//            }
//
//        }
//
//        if (costInCents <= 0) {
//            std::cout << "Successful Purchase!" << std::endl;
//        }
//
//        return return_val;
//
//    }
//
//    bool StockDatabase::dispenseCoins(std::map<unsigned, unsigned>& coins, unsigned amount, bool checkOnly) {
//        std::cout << " and your change of ";
//        Coin::printPrice(amount);
//        std::cout << ":";
//        bool canBeDispensed;
//
//        std::map<unsigned, unsigned> changeCoins;
//
//        // Iterate over the denominations in descending order
//        bool stopLoop = false;
//        for (auto it = coins.rbegin(); it != coins.rend() && !stopLoop; ++it) {
//
//            unsigned denomination = it->first;
//            unsigned quantity = it->second;
//
//            // Calculate the number of coins required for the current denomination
//            unsigned numCoins = std::min(amount / denomination, quantity);
//
//            if (numCoins > 0){
//                changeCoins[denomination] = numCoins;
//            }
//
//            // Update the remaining amount
//            amount -= numCoins * denomination;
//
//            // Break the loop if the amount becomes zero
//            if (amount == 0) {
//                stopLoop = true;
//            }
//        }
//
//        // If the amount is still not zero, it cannot be dispensed with the available coins
//        if (amount != 0) {
//            canBeDispensed = false;
//            std::cout << "Change is not available for that amount of money. Please try again.";
//        }
//            // Print and dispense change
//        else {
//            canBeDispensed = true;
//            for (auto & changeCoin : changeCoins) {
//                unsigned denomination = changeCoin.first;
//                unsigned& quantity = changeCoin.second;
//                Coin::printPrice(denomination);
//                std::cout << " x " << quantity << " ";
//
//                if (!checkOnly) {
//                    coins[denomination] -= quantity;
//                }
//            }
//
//            std::cout << std::endl;
//        }
//
//        return canBeDispensed;
//    }
} // ppd