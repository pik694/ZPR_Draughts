//
// Created by Piotr Żelazko on 02.06.2017.
//

#ifndef ZPR_DRAUGHTS_SENDSIGNALDELEGATE_HPP
#define ZPR_DRAUGHTS_SENDSIGNALDELEGATE_HPP

/*!
 * @file
 * @brief SendSignalDelegate is a class to which send signal task can be delegated.
 *
 * Provided as it appeared that such a class is necessary to test program well.
 * This delegate just sends message further, but in test files there is a class which derives from this one.
 */

#include "Signal.hpp"


/*!
 * @brief SendSignalDelegate is a class to which send signal task can be delegated.
 *
 * Provided as it appeared that such a class is necessary to test program well.
 * This delegate just sends message further, but in test files there is a class which derives from this one.
 */
class SendSignalDelegate {

public:
    /*!
     * @brief Default constructor
     */
    SendSignalDelegate();

    /*!
     * @brief Receives a signal and sends it futher (to the server).
     *
     * @param signal
     */
    virtual void sendSignal(std::shared_ptr<Signal> signal);


    /*!
     *
     * @return number of messages sent to the client through this delegate
     */
    int getNumberOfSentSignals();

    /*!
     * @brief Default destructor
     */
    virtual ~SendSignalDelegate();

private:

    int signalsSent_;
};


#endif //ZPR_DRAUGHTS_SENDSIGNALDELEGATE_HPP
