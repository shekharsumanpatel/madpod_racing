#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
void printCommand(int next_checkpoint_x, int next_checkpoint_y, int thrust){
    cout<< next_checkpoint_x<<" "<<next_checkpoint_y<<" "<<thrust<<endl;

}

int angleToThrust(int next_checkpoint_angle, int max_angle, int power_val){
    int abs_angle = abs(next_checkpoint_angle);
    float fract = 1 - pow(abs_angle/max_angle, power_val);
    return (int)100*fract;

}
int main()
{
    int x;
    int y;
    int next_checkpoint_x; // x position of the next check point
    int next_checkpoint_y; // y position of the next check point
    int next_checkpoint_dist; // distance to the next checkpoint
    int next_checkpoint_angle; // angle between your pod orientation and the direction of the next checkpoint
    cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle; cin.ignore();
    int opponent_x;
    int opponent_y;
    cin >> opponent_x >> opponent_y; cin.ignore();
    int thrust = 100;

    printCommand(next_checkpoint_x,next_checkpoint_y,thrust);


    // game loop
    while (1) {
        cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle; cin.ignore();
        cin >> opponent_x >> opponent_y; cin.ignore();

        if(next_checkpoint_angle<90){
            
            thrust = angleToThrust(next_checkpoint_angle,90,3);
            cerr<<" thrust val = "<<thrust<<endl;
        }
        else{
            thrust = 0;
            cerr<<" thrust val = "<<thrust<<endl;
        }

        printCommand(next_checkpoint_x,next_checkpoint_y,thrust);
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // You have to output the target position
        // followed by the power (0 <= thrust <= 100) or "BOOST" or "SHIELD"
        // i.e.: "x y thrust"
        
    }
}