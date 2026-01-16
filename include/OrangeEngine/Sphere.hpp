#pragma once
#include "Position3D.hpp"

class Sphere {
    public:
        Position3D position;
        float radius;
        Sphere();
        Sphere(float r);
        ~Sphere();
        int checkCollision(); // wip
};