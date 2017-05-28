//
// Created by Piotr Żelazko on 27.05.2017.
//

#ifndef ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP

#include "Signal.hpp"
#include "SignalFactory.hpp"
class NickRequestSignal : public Signal {
public:
	NickRequestSignal() {}
	//NickRequestSignal(std::string nick) : nick_(nick) {}
	std::string nick_;
	void acceptDispatcher(MessageDispatcher& dispatcher);
private:
	static Register<NickRequestSignal> reg;

};


#endif //ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
