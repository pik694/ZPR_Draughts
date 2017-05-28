#ifndef ZPR_DRAUGHTS_SIGNAL_FACTORY_HPP
#define ZPR_DRAUGHTS_SIGNAL_FACTORY_HPP
#include <string>
#include <map>
#include "Signal.hpp"

class Signal;

template<typename T> Signal* createT() {
	return new T;	
}

class SignalFactory {
public:
	typedef std::map<std::string,Signal*(*)()> map_type;

	static Signal* createInstance(std::string const&s) {
		auto it = getMap()->find(s);
		if(it == getMap()->end())
			return nullptr;
		return it->second();
	}
protected:
	static map_type *getMap() {
		if(!map) {
			map = new map_type;
		}
		return map;
	}
private:
	static map_type *map;
};

template<typename T>
class Register : SignalFactory {
public:
	Register(std::string const &s) {
		getMap()->insert(std::make_pair(s,&createT<T>));
	}
};

#endif