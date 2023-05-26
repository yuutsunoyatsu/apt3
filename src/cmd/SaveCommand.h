//
// Created by Artemis on 26/05/2023.
//

#ifndef APT3_SAVECOMMAND_H
#define APT3_SAVECOMMAND_H

#include "../Command.h"

namespace ppd {

    class SaveCommand :public Command{
    public:
        SaveCommand();
        ReturnType runSubFunction(ppd::Invoker cmdInvoker) override;
    };

} // ppd

#endif //APT3_SAVECOMMAND_H
