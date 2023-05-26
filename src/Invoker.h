//
// Created by Artemis on 26/05/2023.
//

#ifndef APT3_INVOKER_H
#define APT3_INVOKER_H

#include "StockDatabase.h"
#include "CoinsDatabase.h"

namespace ppd {

    class Invoker {
    public:
        Invoker(StockDatabase* sdb, CoinsDatabase* cdb): sdb(sdb), cdb(cdb) {};
        ReturnType doCommand(int cmd);

        StockDatabase* sdb;
        CoinsDatabase* cdb;
    };

} // ppd

#endif //APT3_INVOKER_H
