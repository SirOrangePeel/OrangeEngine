#pragma once
#include <tuple>

// Kind of a test position3d paramter for future objects
class Position3D 
{
    private:

        double x;
        double y;
        double z;

    public:

        // This is a default constructor. Assuming when an object is created with a position it starts at the origin.
        Position3D();
        Position3D(float newX, float newY, float newZ);
        ~Position3D();
        std::tuple<float, float, float> getPosition();
        void setPosition(float newX, float newY, float newZ);
        void addPosition(float xVal, float yVal, float zVal);
        float getX();
        void setX(float value);
        void addX(float value);
        float getY();
        void setY(float value);
        void addY(float value);
        float getZ();
        void setZ(float value);
        void addZ(float value);


};