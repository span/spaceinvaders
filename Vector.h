/**
 *
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

struct Vector {
    int x, y, dy;
    Vector(int x, int y, int dy) : x(x), y(y), dy(dy) {}
};

#endif VECTOR_HPP_
