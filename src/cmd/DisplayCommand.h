#ifndef APT3_DISPLAYCOMMAND_H
#define APT3_DISPLAYCOMMAND_H

#include "../Command.h"

namespace ppd {

    class DisplayCommand : public Command {
    public:
        DisplayCommand();
    private:
        ReturnType runSubFunction(Invoker cmdInvoker) override;

    };

} // ppd

#endif //APT3_DISPLAYCOMMAND_H
