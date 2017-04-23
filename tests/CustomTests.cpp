//
// Created by Piotr Żelazko on 22.04.2017.
//

#include <boost/test/unit_test.hpp>
#include "Adder.h"

BOOST_AUTO_TEST_SUITE(customTestSuite)


    BOOST_AUTO_TEST_CASE(custom_test_case){

        Adder adder;

        BOOST_REQUIRE( adder.add(1 , 2) == 3 );


    }

BOOST_AUTO_TEST_SUITE_END()