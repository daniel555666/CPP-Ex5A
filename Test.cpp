#include"doctest.h"
#include"OrgChart.hpp"
#include <iostream>

#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace ariel;

TEST_CASE("check iterators"){
    OrgChart organization;
    organization.add_root("1")
      .add_sub("1", "2.1")         
      .add_sub("1", "2.2")         
      .add_sub("2.1", "3.1");

    OrgChart::Iterator it1=organization.begin_level_order();
    OrgChart::Iterator it2=organization.begin_reverse_order();
    OrgChart::Iterator it3=organization.begin_preorder();

//begin_level_order iterator
    CHECK(*it1=="1");
    ++it1;
    CHECK(*it1=="2.1");
    ++it1;
    CHECK(*it1=="2.2");
    ++it1;
    CHECK(*it1=="3.1");
    ++it1;

    CHECK(it1==organization.end_level_order());

//begin_reverse_order iterator
    CHECK(*it2=="3.1");
    ++it2;
    CHECK(*it2=="2.2");
    ++it2;
    CHECK(*it2=="2.1");
    ++it2;
    CHECK(*it2=="1");
    ++it2;

    CHECK(it2==organization.reverse_order());

//begin_preorder iterator
    CHECK(*it3=="1");
    ++it3;
    CHECK(*it3=="2.1");
    ++it3;
    CHECK(*it3=="3.1");
    ++it3;
    CHECK(*it3=="2.2");
    ++it3;

    CHECK(it3==organization.end_preorder());

}

TEST_CASE("check throws"){

    OrgChart organization;

    CHECK_THROWS(organization.add_sub("no root","not add"));
    CHECK_THROWS(organization.add_sub("not add","hghk"));

    organization.add_root("same name is ok");
    CHECK_NOTHROW(organization.add_sub("same name is ok","same name is ok"));
    CHECK_NOTHROW(organization.add_sub(" 2 same names is ok","can add me"));

    CHECK_THROWS(organization.add_sub("no such name","cant add"));
    CHECK_THROWS(organization.add_sub("no such name2","cant add"));





}
