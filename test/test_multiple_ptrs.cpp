/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// test_archive_derivation.cpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// should pass compilation and execution

#include <fstream>

#include "test_tools.hpp"

#include "D.hpp"

int test_main( int /* argc */, char* /* argv */[] )
{
    char testfile[TMP_MAX];
    std::tmpnam(testfile);

    A a, a1;

    {   
        test_ostream os(testfile, TEST_STREAM_FLAGS);
        test_oarchive oa(os);
        oa << boost::serialization::make_nvp("a", a);
    }
    {
        test_istream is(testfile, TEST_STREAM_FLAGS);
        test_iarchive ia(is);
        ia >> boost::serialization::make_nvp("a", a1);
    }
    BOOST_CHECK(a == a1);
	std::remove(testfile);
    return boost::exit_success;
}

// EOF