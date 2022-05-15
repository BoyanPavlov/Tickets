// #include "../catch.hpp"
// #include <iostream>
// #include <string>

// #include "ticket.h"
// #include "date.h"
// using std::string;

// //====================DATE=====================
// TEST_CASE("date")
// {
//     SECTION("Invalid days", "[input zero]")
//     {
//         int day = 0;
//         int month = 11;
//         int year = 1999;
//         bool flag = false;
//         string error = "Invalid date\n";
//         try
//         {
//             Date(year, month, day);
//         }
//         catch (std::invalid_argument &e)
//         {
//             flag = (error == e.what());
//         }
//         REQUIRE(flag == true);
//     }

//     SECTION("Invalid days", "[negative]")
//     {
//         int day = -1;
//         int month = 11;
//         int year = 1999;
//         bool flag = false;
//         string error = "Invalid date\n";
//         try
//         {
//             Date(year, month, day);
//         }
//         catch (std::invalid_argument &e)
//         {
//             flag = (error == e.what());
//         }
//         REQUIRE(flag == true);
//     }

//     SECTION("Invalid days", "[greater than 31]")
//     {
//         int day = 32;
//         int month = 11;
//         int year = 1999;
//         bool flag = false;
//         string error = "Invalid date\n";
//         try
//         {
//             Date(year, month, day);
//         }
//         catch (std::invalid_argument &e)
//         {
//             flag = (error == e.what());
//         }
//         REQUIRE(flag == true);
//     }

//     SECTION("Invalid months", "[zero]")
//     {
//         int day = 2;
//         int month = 0;
//         int year = 1999;
//         bool flag = false;
//         string error = "Invalid date\n";
//         try
//         {
//             Date(year, month, day);
//         }
//         catch (std::invalid_argument &e)
//         {
//             flag = (error == e.what());
//         }
//         REQUIRE(flag == true);
//     }
//     SECTION("Invalid months", "[greater than 12]")
//     {
//         int day = 12;
//         int month = 13;
//         int year = 1999;
//         bool flag = false;
//         string error = "Invalid date\n";
//         try
//         {
//             Date(year, month, day);
//         }
//         catch (std::invalid_argument &e)
//         {
//             flag = (error == e.what());
//         }
//         REQUIRE(flag == true);
//     }

//     SECTION("Invalid year and date February")
//     {
//         int day = 30;
//         int month = 2;
//         int year = 1999;
//         bool flag = false;
//         string error = "Invalid date\n";
//         try
//         {
//             Date(year, month, day);
//         }
//         catch (std::invalid_argument &e)
//         {
//             flag = (error == e.what());
//         }
//         REQUIRE(flag == true);
//     }

//     SECTION("Invalid day and month ")
//     {
//         int day = 31;
//         int month = 4;
//         int year = 2000;
//         bool flag = false;
//         string error = "Invalid date\n";
//         try
//         {
//             Date(year, month, day);
//         }
//         catch (std::invalid_argument &e)
//         {
//             flag = (error == e.what());
//         }
//         REQUIRE(flag == true);
//     }

//     SECTION("Valid year and date")
//     {
//         int day = 29;
//         int month = 2;
//         int year = 2000;
//         bool flag = false;
//         string error = "Invalid date\n";
//         try
//         {
//             Date(year, month, day);
//         }
//         catch (std::invalid_argument &e)
//         {
//             flag = (error == e.what());
//         }
//         REQUIRE(flag == false);
//     }

//     SECTION("Valid year and month")
//     {
//         int day = 31;
//         int month = 1;
//         int year = 1999;
//         bool flag = false;
//         string error = "Invalid date\n";
//         try
//         {
//             Date(year, month, day);
//         }
//         catch (std::invalid_argument &e)
//         {
//             flag = (error == e.what());
//         }
//         REQUIRE(flag == false);
//     }
// }
// //====================TODO=====================
