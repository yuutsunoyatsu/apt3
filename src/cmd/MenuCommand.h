//
// Created by Artemis on 26/05/2023.
//

#ifndef APT3_MENUCOMMAND_H
#define APT3_MENUCOMMAND_H

#include "../Command.h"

namespace ppd {

    class MenuCommand : public Command{
    public:
        MenuCommand();
    private:
        ReturnType runSubFunction(Invoker cmdInvoker) override;
    };

} // ppd

#endif //APT3_MENUCOMMAND_H
