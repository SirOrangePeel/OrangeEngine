#include <iostream>
#include <string>
#include <tuple>

using namespace std;


// Kind of a test position3d paramter for future objects
class Position3D 
{
    private:

        double x;
        double y;
        double z;

    public:

        // This is a default constructor. Assuming when an object is created with a position it starts at the origin.
        Position3D() {
            x = 0;
            y = 0;
            z = 0;
        }

        std::tuple<float, float, float> getPosition() {
            return std::make_tuple(x, y, z);
        }

        void setPosition(float newX, float newY, float newZ) {
            x = newX;
            y = newY;
            z = newZ;
        }

        void addPosition(float xVal, float yVal, float zVal) {
            x += xVal;
            y += yVal;
            z += zVal;
        }

        float getX() {return x;}
        void setX(float value) {x = value;}
        void addX(float value) {x += value;}
        float getY() {return y;}
        void setY(float value) {y = value;}
        void addY(float value) {y += value;}
        float getZ() {return z;}
        void setZ(float value) {z = value;}
        void addZ(float value) {z += value;}


};