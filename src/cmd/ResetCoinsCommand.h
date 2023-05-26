//
// Created by Artemis on 26/05/2023.
//

#ifndef APT3_RESETCOINSCOMMAND_H
#define APT3_RESETCOINSCOMMAND_H

#include "../Command.h"

#define DEFAULT_COIN_COUNT 20

namespace ppd {

    class ResetCoinsCommand : public Command{
    public:
        ResetCoinsCommand();
        ReturnType runSubFunction(Invoker cmdInvoker) override;
    };

} // ppd

#endif //APT3_RESETCOINSCOMMAND_H
