//
// Created by Piotr Żelazko on 22.04.2017.
//

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(customTestSuite)


    BOOST_AUTO_TEST_CASE(custom_test_case){

        BOOST_CHECK( 1==1 );


    }

BOOST_AUTO_TEST_SUITE_END()