//#include "NickRequestSignal.hpp"
#include "SignalFactory.hpp"
#include "NickRequestSignal.hpp"
#include "../MessageDispatcher.hpp"

typedef std::map<std::string,Signal*(*)()> map_type;
map_type* SignalFactory::map = nullptr;

Register<NickRequestSignal> NickRequestSignal::reg("nickRequest");

