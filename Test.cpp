//
// Created by shani and Yarden on 14/04/2020.
//


#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#include "doctest.h"
using namespace std;
using std::string;


TEST_CASE("Test Relation") {   
    family::Tree T ("Shani");
    T.addFather("Shani", "Moshe")
            .addMother("Shani", "Idit")
            .addFather("Idit", "Ovi")
            .addMother("Idit", "Osnat")
            .addMother("Osnat", "Balla")
            .addFather("Osnat", "Zigmond");

            CHECK(T.relation("Shani") == "me");
            CHECK(T.relation("Idit") == "mother");
            CHECK(T.relation("Moshe") == "father");
            CHECK(T.relation("Osnat") == "grandmother");
            CHECK(T.relation("Ovi") == "grandfather");
            CHECK(T.relation("Balla") == "great-grandmother");
            CHECK(T.relation("Zigmond") == "great-grandfather");


    family::Tree T2 ("Miri");
    T2.addFather("Miri", "Roi")
            .addMother("Miri", "Danit")
            .addFather("Danit", "Shmulik")
            .addMother("Danit", "Shiri")
            .addMother("Shiri", "Miriam")
            .addFather("Miriam", "Nirit");


            CHECK(T.relation("Shani") == "me");
            CHECK(T.relation("Idit") == "mother");
            CHECK(T.relation("Moshe") == "father");
            CHECK(T.relation("Osnat") == "grandmother");
            CHECK(T.relation("Ovi") == "grandfather");
            CHECK(T.relation("Balla") == "great-grandmother");
            CHECK(T.relation("Zigmond") == "great-grandfather");


}

