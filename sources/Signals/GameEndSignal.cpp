#include "GameEndSignal.hpp"
#include "MessageDispatcher.hpp"

Register<GameEndSignal> GameEndSignal::reg("GameEndSignal");

void GameEndSignal::acceptDispatcher(MessageDispatcher &dispatcher) {

}