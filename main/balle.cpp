#include <fstream>
#include <jsoncpp/json/json.h>
#include "Ball.h"
using namespace std;



struct InitInfo
{
    double height;
    double speed;
    double angle;
    bool airResistance;
    double timestep;
};



InitInfo readInput(const char* filename)
{
    Json::Reader reader;
    Json::Value root;
    ifstream ifile;
    InitInfo result;


    // Check the file is open correctly.
    ifile.open(filename, ifstream::in);
    if(!ifile.is_open())
        cerr << "File open failed!" << endl;

    // Parse json string from file.
    if(reader.parse(ifile, root))
    {
        result.height = root["height"].asDouble();
        result.speed = root["speed"].asDouble();
        result.angle = root["angle"].asDouble();
        result.airResistance = root["airResistance"].asBool();
        result.timestep = root["timestep"].asDouble();
    }
    else
    {
        cerr << "Parse json failed!" << endl;
    }

    ifile.close();
    return result;
}



int main()
{
    InitInfo input = readInput("input.json");
    cout << "Initial height (meters): " << input.height << endl;
    cout << "Initial speed (m/s): " << input.speed << endl;
    cout << "Initial angle (degrees): " << input.angle << endl;
    cout << "Air resistance (Yes:1, No:0): " << input.airResistance << endl;
    cout << "Timestep: " << input.timestep << endl;


    /// Theory
    cout << "Theory" << endl;
    Ball ball = Ball( input.height, input.speed, input.angle );
    ball.run(input.timestep, "theory");

    /// Euler Method
    cout << "Euler method" << endl;
    ball.reset();
    ball.run(input.timestep, "euler");

    /// Euler Cromer Method
    cout << "Euler-Cromer Method" << endl;
    ball.reset();
    ball.run(input.timestep, "euler_cromer");

    /// Midpoint Method
    cout << "Midpoint Method" << endl;
    ball.reset();
    ball.run(input.timestep, "midpoint");

    return 0;
}




