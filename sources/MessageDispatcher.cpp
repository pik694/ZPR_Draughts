//
// Created by Piotr Żelazko on 23.04.2017.
//

#include "MessageDispatcher.hpp"


void MessageDispatcher::visit(NickRequestSignal *message) {
	std::cout<<"message dispatcher working"<<std::endl;
}