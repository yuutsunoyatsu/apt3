//
// Created by Artemis on 26/05/2023.
//

#ifndef APT3_DISPLAYCOINSCOMMAND_H
#define APT3_DISPLAYCOINSCOMMAND_H

#include "../Command.h"

namespace ppd {

    class DisplayCoinsCommand : public Command{
    public:
        DisplayCoinsCommand();
    private:
        ReturnType runSubFunction(Invoker cmdInvoker) override;
    };

} // ppd

#endif //APT3_DISPLAYCOINSCOMMAND_H
