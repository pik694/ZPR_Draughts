#include "GameEndSignal.hpp"

Register<GameEndSignal> GameEndSignal::reg("GameEndSignal");

void GameEndSignal::acceptDispatcher(MessageDispatcher &dispatcher) {

}

Json::Value GameEndSignal::serialize() {
    Json::Value answer;
    answer["type"] = "GameEndSignal";
    answer["value"] = won_;
    return answer;
}
