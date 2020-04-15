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
            .addFather("Osnat", "Zigmond")
            .addFather("Balla", "Lucy");

            CHECK(T.relation("Shani") == "me");
            CHECK(T.relation("Idit") == "mother");
            CHECK(T.relation("Moshe") == "father");
            CHECK(T.relation("Osnat") == "grandmother");
            CHECK(T.relation("Ovi") == "grandfather");
            CHECK(T.relation("Balla") == "great-grandmother");
            CHECK(T.relation("Zigmond") == "great-grandfather");
            CHECK(T.relation("Lucy") == "great-great-grandfather");

    family::Tree T2 ("Miri");
    T2.addFather("Miri", "Roi")
            .addMother("Miri", "Danit")
            .addFather("Danit", "Shmulik")
            .addMother("Danit", "Shiri")
            .addMother("Shiri", "Miriam")
            .addFather("Shiri", "Muli");


            CHECK(T2.relation("Miri") == "me");
            CHECK(T2.relation("Danit") == "mother");
            CHECK(T2.relation("Roi") == "father");
            CHECK(T2.relation("Shiri") == "grandmother");
            CHECK(T2.relation("Shmulik") == "grandfather");
            CHECK(T2.relation("Miriam") == "great-grandmother");
            CHECK(T2.relation("Muli") == "great-grandfather");
            CHECK(T2.relation("Nir") == "unrealated");   //exception



    family::Tree T3 ("Nirit");
    T3.addFather("Nirit", "Shay")
            .addMother("Nirit", "Noa")
            .addFather("Noa", "Nahum")
            .addMother("Noa", "Mally")
            .addMother("Mally", "Yehudit")
            .addFather("Mally", "Lior")
            .addFather("Yehudit", "Shirly");

            CHECK(T3.relation("Nirit") == "me");
            CHECK(T3.relation("Noa") == "mother");
            CHECK(T3.relation("Shay") == "father");
            CHECK(T3.relation("Mally") == "grandmother");
            CHECK(T3.relation("Nahum") == "grandfather");
            CHECK(T3.relation("Yehudit") == "great-grandmother");
            CHECK(T3.relation("Lior") == "great-grandfather");
            CHECK(T3.relation("Shirly") == "great-great-grandfather");
            CHECK(T3.relation("Mor") == "unrealated");    //exception

}


TEST_CASE("Test Find and Remove") {
    family::Tree T ("Shani");
    T.addFather("Shani", "Moshe")
            .addMother("Shani", "Idit")
            .addFather("Idit", "Ovi")
            .addMother("Idit", "Osnat")
            .addMother("Osnat", "Balla")
            .addFather("Osnat", "Zigmond")
            .addMother("Balla", "Lucy");

            CHECK(T.find("me") == "Shani");
            CHECK(T.find("mother") == "Idit");
            CHECK(T.find("father") == "Moshe");
            CHECK(T.find("grandmother") == "Osnat");
            CHECK(T.find("grandfather") == "Ovi");
            CHECK(T.find("great-grandmother") == "Balla");
            CHECK(T.find("great-grandfather") == "Zigmond");
            CHECK(T.find("great-great-grandmother") == "Lucy");

    family::Tree T2 ("Miri");
    T2.addFather("Miri", "Roi")
            .addMother("Miri", "Danit")
            .addFather("Danit", "Shmulik")
            .addMother("Danit", "Shiri")
            .addMother("Shiri", "Miriam")
            .addFather("Shiri", "Muli")
            .addMother("Miriam", "Nelly");


            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");


    family::Tree T3 ("Nirit");
    T3.addFather("Nirit", "Shay")
            .addMother("Nirit", "Noa")
            .addFather("Noa", "Nahum")
            .addMother("Noa", "Mally")
            .addMother("Mally", "Yehudit")
            .addFather("Mally", "Lior")
            .addMother("Yehudit", "Shirly");

            CHECK(T3.find("me") == "Nirit");
            CHECK(T3.find("mother") == "Noa");
            CHECK(T3.find("father") == "Shay");
            CHECK(T3.find("grandmother") == "Mally");
            CHECK(T3.find("grandfather") == "Nahum");
            CHECK(T3.find("great-grandmother") == "Yehudit");
            CHECK(T3.find("great-grandfather") == "Lior");
            CHECK(T3.find("great-great-grandmother") == "Shirly");

//    family::Tree T4 ("yarden");
//    T4.addFather("yarden", "ilan")//best father ever
//            .addMother("yarden", "riki")//mother
//            .addFather("ilan", "refael")//grandfather
//            .addMother("ilan", "lusi")//grandMother
//            .addMother("lusi", "galit")//great-grandMother
//            .addFather("lusi", "moshe")//great-grandfather
//            .addFather("moshe","yossi")//great-great-grandfather
//            .addFather("yossi","avraham")//great-great-great-grandfather
//            .addMother("avraham","danit");//great-great-great-great-grandMother
//
//            CHECK(T4.find("me") == string("yarden"));
//            CHECK(T4.find("mother") == string("riki"));
//            CHECK(T4.find("father") == string("ilan"));
//            CHECK(T4.find("grandmother") == string("lusi"));
//            CHECK(T4.find("grandfather") == string("refael"));
//            CHECK(T4.find("great-grandmother") == string("galit"));
//            CHECK(T4.find("great-grandfather") == string("moshe"));
//            CHECK(T4.find("great-grandfather") == string("ofir"));//throw error
//           // CHECK(T4.find("uncle") == string("tamir"));//throw error
//            CHECK(T4.find("great-great-great-great-grandmother") == string("danit"));
//            CHECK(T4.find("great-great-great-grandfather") == string("avraham"));
//
//            T4.remove("avraham");//avraham and danit removed
//            //CHECK(T4.find("great-great-great-grandfather") == string("avraham"));//throw error
//            CHECK(T4.find("great-great-great-great-grandmother") == string("danit"));
//            T4.addFather("yossi","avraham").addMother("avraham","danit");
//            T4.remove("moshe");//moshe,yossi,avraham and danit removed
//            //CHECK(T4.find("great-grandfather") == string("moshe"));//trow error
//            T4.remove("yarden");
//            CHECK(T4.find("me") == string("yarden"));//error
}



//TEST_CASE("Test all functions") {
//    family::Tree T ("yarden");
//    T.addFather("yarden", "ilan")//best father ever
//            .addMother("yarden", "riki")//mother
//            .addFather("ilan", "refael")//grandfather
//            .addMother("ilan", "lusi")//grandMother
//            .addMother("lusi", "galit")//great-grandMother
//            .addFather("lusi", "moshe")//great-grandfather
//            .addFather("moshe","yossi")//great-great-grandfather
//            .addFather("yossi","avraham")//great-great-great-grandfather
//            .addMother("avraham","danit")//great-great-great-great-grandMother
//            .addMother("danit","tami");
//
//            CHECK(T.find("great-great-great-great-great-grandMother") == string("tami"));
//            CHECK(T.relation("yarden") == string("me"));
//            CHECK(T.relation("ofir") == string("unrelated"));
//            CHECK(T.find("great-grandmother") == string("galit"));
//            CHECK(T.relation("ilan") == "father");
//            CHECK(T.find("great-grandfather") == string("moshe"));
//            CHECK(T.relation("riki") == "mother");
//            CHECK(T.relation("ilan") == "futher");//error
//            CHECK(T.find("great-grandmother") == string("galit"));
//            CHECK(T.find("great-grandfather") == string("moshe"));
//            CHECK(T.find("great-great-great-great-grandMother") == string("danit"));
//
//            T.remove("tami");
//            CHECK(T.relation("tami") == string("unrelated"));
//            T.addMother("danit", "tami")
//            .addMother("tami", "shani")
//            .addFather("danit", "roni");
//            CHECK(T.find("great-great-great-great-great-grandFather") == string("roni"));
//            CHECK(T.find("great-great-great-great-great-great-grandMother") == string("shani"));
//            CHECK(T.find("father") == string("ilan"));
//            CHECK(T.find("grandmother") == string("lusi"));
//            CHECK(T.find("grandfather") == string("refael"));
//            CHECK(T.find("great-grandmother") == string("galit"));
//            CHECK(T.find("great-grandfather") == string("moshe"));
//            CHECK(T.find("great-grandFuther") == string("ilan"));//throw error
//            CHECK(T.find("brother") == string("tamir"));//throw error
//            CHECK(T.find("great-great-great-great-grandfMother") == string("danit"));
//            CHECK(T.find("great-great-great-grandfather") == string("avraham"));
//            T.remove("avraham");//avraham and danit removed
//            CHECK(T.relation("avraham") == string("unrelated"));
//            CHECK(T.relation("danit") == string("unrelated"));
//            T.remove("refael");
//            CHECK(T.relation("lusi") == string("grandfMother"));
//            CHECK(T.relation("refael") == string("unrelated"));
//            T.addFather("ilan","refael");
//            CHECK(T.relation("refael") == string("grandFather"));
//
//}

