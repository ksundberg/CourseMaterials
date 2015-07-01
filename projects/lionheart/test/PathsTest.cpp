#include "catch.hpp"
#include "Plan.hpp"

SCENARIO("Path Vertex Objects behave in a sane way")
{
  GIVEN("PathVertex Objects")
  {
    lionheart::PathVertex n00({0, 0}, lionheart::Direction::NORTH);
    lionheart::PathVertex n10({1, 0}, lionheart::Direction::NORTH);
    lionheart::PathVertex n01({0, 1}, lionheart::Direction::NORTH);
    lionheart::PathVertex n11({1, 1}, lionheart::Direction::NORTH);

    lionheart::PathVertex s00({0, 0}, lionheart::Direction::SOUTH);
    lionheart::PathVertex s10({1, 0}, lionheart::Direction::SOUTH);
    lionheart::PathVertex s01({0, 1}, lionheart::Direction::SOUTH);
    lionheart::PathVertex s11({1, 1}, lionheart::Direction::SOUTH);

    lionheart::PathVertex e00({0, 0}, lionheart::Direction::EAST);
    lionheart::PathVertex e10({1, 0}, lionheart::Direction::EAST);
    lionheart::PathVertex e01({0, 1}, lionheart::Direction::EAST);
    lionheart::PathVertex e11({1, 1}, lionheart::Direction::EAST);

    lionheart::PathVertex w00({0, 0}, lionheart::Direction::WEST);
    lionheart::PathVertex w10({1, 0}, lionheart::Direction::WEST);
    lionheart::PathVertex w01({0, 1}, lionheart::Direction::WEST);
    lionheart::PathVertex w11({1, 1}, lionheart::Direction::WEST);

    WHEN("compared for less")
    {
      THEN("comparisons are correct")
      {
        REQUIRE(n00 < n01);
        REQUIRE(n00 < n10);
        REQUIRE(n00 < n11);
        REQUIRE(n01 < n10);
        REQUIRE(n01 < n11);
        REQUIRE(n10 < n11);

        REQUIRE(s00 < s01);
        REQUIRE(s00 < s10);
        REQUIRE(s00 < s11);
        REQUIRE(s01 < s10);
        REQUIRE(s01 < s11);
        REQUIRE(s10 < s11);

        REQUIRE(e00 < e01);
        REQUIRE(e00 < e10);
        REQUIRE(e00 < e11);
        REQUIRE(e01 < e10);
        REQUIRE(e01 < e11);
        REQUIRE(e10 < e11);

        REQUIRE(w00 < w01);
        REQUIRE(w00 < w10);
        REQUIRE(w00 < w11);
        REQUIRE(w01 < w10);
        REQUIRE(w01 < w11);
        REQUIRE(w10 < w11);

      }
    }
    WHEN("compared for equality")
    {
      THEN("comparisons are correct")
      {
        REQUIRE(n00 != n01);
        REQUIRE(n00 != n10);
        REQUIRE(n00 != n11);
        REQUIRE(n00 != s00);
        REQUIRE(n00 != s01);
        REQUIRE(n00 != s10);
        REQUIRE(n00 != s11);
        REQUIRE(n00 != e00);
        REQUIRE(n00 != e01);
        REQUIRE(n00 != e10);
        REQUIRE(n00 != e11);
        REQUIRE(n00 != w00);
        REQUIRE(n00 != w01);
        REQUIRE(n00 != w10);
        REQUIRE(n00 != w11);

        REQUIRE(n00 == n00);
        REQUIRE(n01 == n01);
        REQUIRE(n10 == n10);
        REQUIRE(n11 == n11);
        REQUIRE(s00 == s00);
        REQUIRE(s01 == s01);
        REQUIRE(s10 == s10);
        REQUIRE(s11 == s11);
        REQUIRE(e00 == e00);
        REQUIRE(e01 == e01);
        REQUIRE(e10 == e10);
        REQUIRE(e11 == e11);
        REQUIRE(w00 == w00);
        REQUIRE(w01 == w01);
        REQUIRE(w10 == w10);
        REQUIRE(w11 == w11);
      }
    }
  }
}

SCENARIO("Shortest Paths are calculated correctly")
{
  
  GIVEN( "A trivial map")
  {
    std::string filename="test.in";
    auto map = lionheart::makeMap(filename);
    WHEN("paths are built for infantry")
    {
      lionheart::Paths p(map,1);
      THEN("all distances are correct")
      {
        lionheart::PathVertex n00({0,0},lionheart::Direction::NORTH);
        lionheart::PathVertex n10({1,0},lionheart::Direction::NORTH);
        lionheart::PathVertex n01({0,1},lionheart::Direction::NORTH);
        lionheart::PathVertex n11({1,1},lionheart::Direction::NORTH);

        lionheart::PathVertex s00({0,0},lionheart::Direction::SOUTH);
        lionheart::PathVertex s10({1,0},lionheart::Direction::SOUTH);
        lionheart::PathVertex s01({0,1},lionheart::Direction::SOUTH);
        lionheart::PathVertex s11({1,1},lionheart::Direction::SOUTH);

        lionheart::PathVertex e00({0,0},lionheart::Direction::EAST);
        lionheart::PathVertex e10({1,0},lionheart::Direction::EAST);
        lionheart::PathVertex e01({0,1},lionheart::Direction::EAST);
        lionheart::PathVertex e11({1,1},lionheart::Direction::EAST);

        lionheart::PathVertex w00({0,0},lionheart::Direction::WEST);
        lionheart::PathVertex w10({1,0},lionheart::Direction::WEST);
        lionheart::PathVertex w01({0,1},lionheart::Direction::WEST);
        lionheart::PathVertex w11({1,1},lionheart::Direction::WEST);

        CHECK(p.distance(n00,n00) == 0);
        CHECK(p.distance(n00,n01) == 3);
        CHECK(p.distance(n00,n10) == 3);
        CHECK(p.distance(n00,n11) == 5);
        CHECK(p.distance(n00,s00) == 1);
        CHECK(p.distance(n00,s01) == 3);
        CHECK(p.distance(n00,s10) == 2);
        CHECK(p.distance(n00,s11) == 4);
        CHECK(p.distance(n00,e00) == 1);
        CHECK(p.distance(n00,e01) == 2);
        CHECK(p.distance(n00,e10) == 3);
        CHECK(p.distance(n00,e11) == 4);
        CHECK(p.distance(n00,w00) == 1);
        CHECK(p.distance(n00,w01) == 3);
        CHECK(p.distance(n00,w10) == 3);
        CHECK(p.distance(n00,w11) == 5);
      }
    }
  }

  GIVEN( "A map loaded from a filename")
  {
    std::string filename="tiny.in";
    auto map = lionheart::makeMap(filename);
    WHEN("paths are built for infantry")
    {
      lionheart::Paths p(map,1);
      THEN("distances are correct")
      {
        lionheart::PathVertex a({0,0},lionheart::Direction::SOUTH);
        lionheart::PathVertex b({0,7},lionheart::Direction::NORTH);
        lionheart::PathVertex c({7,7},lionheart::Direction::WEST);
        lionheart::PathVertex d({6,2},lionheart::Direction::EAST);
        lionheart::PathVertex e({3,3},lionheart::Direction::EAST);

        CHECK(p.distance(a,a) == 0);
        CHECK(p.distance(a,b) == 19);
        CHECK(p.distance(a,c) == 16);
        CHECK(p.distance(a,d) == 9);
        CHECK(p.distance(a,e) == 9);

        CHECK(p.distance(b,a) == 19);
        CHECK(p.distance(b,b) == 0);
        CHECK(p.distance(b,c) == 9);
        CHECK(p.distance(b,d) == 16);
        CHECK(p.distance(b,e) == 11);

        CHECK(p.distance(c,a) == 16);
        CHECK(p.distance(c,b) == 8);
        CHECK(p.distance(c,c) == 0);
        CHECK(p.distance(c,d) == 8);
        CHECK(p.distance(c,e) == 11);

        CHECK(p.distance(d,a) == 11);
        CHECK(p.distance(d,b) == 16);
        CHECK(p.distance(d,c) == 9);
        CHECK(p.distance(d,d) == 0);
        CHECK(p.distance(d,e) == 6);

        CHECK(p.distance(e,a) == 9);
        CHECK(p.distance(e,b) == 10);
        CHECK(p.distance(e,c) == 11);
        CHECK(p.distance(e,d) == 7);
        CHECK(p.distance(e,e) == 0);
      }
      THEN("actions are correct")
      {
      }
    }
    WHEN("paths are built for mounted")
    {
    lionheart::Paths p(map,5);
      THEN("distances are correct")
      {
        lionheart::PathVertex a({0,0},lionheart::Direction::SOUTH);
        lionheart::PathVertex b({0,7},lionheart::Direction::NORTH);
        lionheart::PathVertex c({7,7},lionheart::Direction::WEST);
        lionheart::PathVertex d({6,2},lionheart::Direction::EAST);
        lionheart::PathVertex e({3,3},lionheart::Direction::EAST);

        CHECK(p.distance(a, a) == 0);
        CHECK(p.distance(a, b) == 8);
        CHECK(p.distance(a, c) == 6);
        CHECK(p.distance(a, d) == 4);
        CHECK(p.distance(a, e) == 5);

        CHECK(p.distance(b, a) == 10);
        CHECK(p.distance(b, b) == 0);
        CHECK(p.distance(b, c) == 4);
        CHECK(p.distance(b, d) == 8);
        CHECK(p.distance(b, e) == 7);

        CHECK(p.distance(c, a) == 6);
        CHECK(p.distance(c, b) == 3);
        CHECK(p.distance(c, c) == 0);
        CHECK(p.distance(c, d) == 4);
        CHECK(p.distance(c, e) == 5);

        CHECK(p.distance(d, a) == 6);
        CHECK(p.distance(d, b) == 7);
        CHECK(p.distance(d, c) == 5);
        CHECK(p.distance(d, d) == 0);
        CHECK(p.distance(d, e) == 4);

        CHECK(p.distance(e, a) == 5);
        CHECK(p.distance(e, b) == 6);
        CHECK(p.distance(e, c) == 6);
        CHECK(p.distance(e, d) == 5);
        CHECK(p.distance(e, e) == 0);
      }
      THEN("actions are correct")
      {
      }
    }
  }
}
