/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// test_recurrsion.cpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// should pass compilation and execution

#include <fstream>

#include "test_tools.hpp"

#include "J.hpp"

int test_main( int /* argc */, char* /* argv */[] )
{
    const char * testfile = tmpnam(NULL);
    BOOST_REQUIRE(NULL != testfile);

    // test recursive structure
    J j, j1;
    j.j = &j;

    {   
        test_ostream os(testfile, TEST_STREAM_FLAGS);
        test_oarchive oa(os);
        oa << BOOST_SERIALIZATION_NVP(j);
    }
    {
        test_istream is(testfile, TEST_STREAM_FLAGS);
        test_iarchive ia(is);
        ia >> BOOST_SERIALIZATION_NVP(j1);
    }
    BOOST_CHECK(j == j1);
	std::remove(testfile);
    return boost::exit_success;
}

// EOF