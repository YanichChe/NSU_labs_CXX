#ifndef MODE_FACTORY_H
#define MODE_FACTORY_H

#include <memory>
#include <string>

#include "mode.h"
#include "gameData.h"
#include "detailed.h"
#include "fast.h"
#include "tournament.h"
#include <exception>

namespace modeFactory {
    const std::string DETAILED = "detailed";
    const std::string FAST = "fast";
    const std::string TOURNAMENT = "tournament";

    class NotFoundMode : public std::invalid_argument {
    public:
        explicit NotFoundMode(const std::string &modeName);
    };

    using ModePointer = std::unique_ptr<mode::Mode>;

    class ModeFactory {
    public:
        ModePointer create(const std::string mode, gameData::GameData *data);
    };
}
#endif