#include "lineType.h"
#include "../../test.cpp"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    lineType line1(0, 1, 5);
    lineType line2(0, 1, 7);
    array<double, 2> intersection = line1.interSection(line2);
    suite("Intersection of horizontal lines:");
    assertEqual(std::isnan(intersection[0]), true, "parallel lines don't have an intersecting x value");
    assertEqual(std::isnan(intersection[1]), true, "parallel lines don't have an intersection y value");


    lineType line1a(1, 0, 5);
    lineType line2a(1, 0, 7);
    suite("Intersection of vertical lines:");
    array<double, 2> intersection1 = line1a.interSection(line2a);
    assertEqual(std::isnan(intersection1[0]), true, "parallel lines don't have an intersecting x value");
    assertEqual(std::isnan(intersection1[1]), true, "parallel lines don't have an intersection y value");

    lineType line1b(-2, 1, 3);
    lineType line2b(0, 1, 5);
    array<double, 2> intersection2 = line2b.interSection(line1b);
    suite("Intersection of  y = 5 and -2x + y = 3.");
    assertEqual(intersection2[0], 1.0, "the x-value should be 1");
    assertEqual(intersection2[1], 5.0, "the y-value should be same as the line");
    suite("Intersection of -2x + y = 3 and y = 5");
    array<double, 2> intersection5 = line1b.interSection(line2b);
    assertEqual(intersection5[0], 1.0, "the x-value should be 1");
    assertEqual(intersection5[1], 5.0, "the y-value should be same as the line");

    lineType line1f(-2, 1, 3);
    lineType line2f(0.5, 1, 7);
    array<double, 2> intersection6 = line1f.interSection(line2f);
    suite("Intersection of normal lines -2x + y = 3 and 0.5x + y = 7:");
    assertEqual(intersection6[0], 1.6, "the x-value should be 1.6");
    assertEqual(intersection6[1], 6.2, "the y-value should be 6.2");

    lineType line1e(-2, 1, 3);
    array<double, 2> intersection3 = line1e.interSection(line2a);
    suite("Intersection of -2x + y = 3 and x = 7:");
    assertEqual(intersection3[0], 7.0, "x should be 7");
    assertEqual(intersection3[1], 17.0, "y should be 17");
    suite("Intersection of x = 7 and -2x + y = 3");
    array<double, 2> intersection4 = line2a.interSection(line1e);
    assertEqual(intersection4[0], 7.0, "x should be 7");
    assertEqual(intersection4[1], 17.0, "y should be 17");

    lineType line1c(2, 4, 10);
    lineType line1d(-3, 1, 4);
    lineType line2d(-3, 1, -5);
    lineType line3d(3, 1, -5);
    //assertEqual(intersection3[0], -3.0, "");

    suite("#isParallel");
    assertEqual(line1.isParallel(line2), true, "horizontal lines are parallel");
    assertEqual(line1a.isParallel(line2a), true, "vertical lines are parallel");
    assertEqual(line1d.isParallel(line2d), true, "parallel lines that are not vertical or horizontal");

    suite("#slope");
    assertEqual(std::isnan(line1a.slope()), true, "vertical lines don't have a slope");
    assertEqual(0.0, line2b.slope(), "horizontal lines have zero slope");
    assertEqual(3.0, line2d.slope(), "normal lines can have positive slopes");
    assertEqual(-3.0, line3d.slope(), "normal lines can have negative slopes");
    assertEqual(line1c.slope(), -0.5, "line 2x + 4y = 10; the slope should be -0.5");

    suite("#equals");
    lineType line1g(2, 3, 5);
    lineType line2g(4, 6, 10);
    lineType line3g(20, 30, 50);
    assertEqual(line1g.equals(line2g), true, "2x + 3y = 5 equals 4x + 6y = 10");
    assertEqual(line1g.equals(line3g), true, "2x + 3y = 5 equals 20x + 30y = 50");

    suite("#isPerpendicular:");
    lineType line1i(-5, 3, 15);
    lineType line2i(3, 5, -10);
    assertEqual(line1i.isPerpendicular(line2i), true, "-5x + 3y = 15 is perpendicular to 3x + 5y = -10");
    lineType line1j(-3, 1, 4);
    lineType line2j(-5, 1, -5);
    assertEqual(line1j.isPerpendicular(line2j), false, "y = 3x + 4 is not perpendicular to y = 5x -5");
}

