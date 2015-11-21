#pragma once
typedef unsigned short ushort;

struct Point {
    Point(ushort x = 0, ushort y = 0) :
        x(x), y(y) {
    }

    ushort x,y;
};
