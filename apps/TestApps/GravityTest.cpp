#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


void realtimeThrow(float timeWhole, float time, float initVelocity, float gravityConstant);

float applyGravity(float initVelocity) {

    const float gravityConstant = -9.81;
    float acceleration = 0;
    float time = (-1) * initVelocity / gravityConstant; // Time to reach peak.
    float maxHeight = initVelocity*initVelocity / (-2)*(gravityConstant);
    float timeWhole = floor(time);
    float timeDec = time - timeWhole;

    std::cout << "Starting velocity " << initVelocity << "m/s\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Simulating real-time throw... \n\n";

    if(time > 1) {
        realtimeThrow(timeWhole, time, initVelocity, gravityConstant);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\nTime to max height: " << time << "s\n";

    return maxHeight;

}

void realtimeThrow(float timeWhole, float time, float initVelocity, float gravityConstant) {

    for (int i = 0; i <= int(timeWhole); i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        float distance = initVelocity*i + (-1/2)*(gravityConstant)*(i*i); // this is a wrong calculation
        std::cout << "Height at " << i << "(s): " << distance << "m \n";
    }

}

int main() {

    float velocity, height;

    cout << "Enter a starting velocity in y-direction (m/s): ";
    cin >> velocity;

    height = applyGravity(velocity);
    std::cout << "Max height: " << height << "\n";



    return 0;

}