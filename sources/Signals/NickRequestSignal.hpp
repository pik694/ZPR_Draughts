//
// Created by Piotr Żelazko on 27.05.2017.
//

#ifndef ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP

#include "Signal.hpp"

class NickRequestSignal : public Signal {
public:
	NickRequestSignal(std::string nick) : nick_(nick) {}
	std::string nick_;
};


#endif //ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
