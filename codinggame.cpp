#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
void changeThrustVal(int &thrust, int next_checkpoint_dist, int minThreshVal){
    if( next_checkpoint_dist < 13 ){
        thrust = 0;
    }
}

void calcMinThreshVal( int total_dist_next_checkpoint, int &minThreshVal){
    minThreshVal = 0.05*total_dist_next_checkpoint;
}

void changeThrustValBasedOnAngle(int next_checkpoint_angle, int &thrust){
    float checkpoint_angle = (float)abs(next_checkpoint_angle);
    cerr<<" angle "<< checkpoint_angle<<endl;
    float fract = pow(((90-checkpoint_angle)/90),5);
    cerr<<"thrust cal val "<<100*fract;
    thrust = (int)100*fract;
}


int main()
{ int boost_number = 0;
  int minThreshVal = 5;
  int last_checkPoint_x = 0;
  int last_checkpoint_y = 0;
  int last_next_checkpoint_distnce = 0;
  int thrust = 80;

    // game loop
    while (1) {
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

        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        if(last_checkPoint_x != next_checkpoint_x || last_checkpoint_y != next_checkpoint_x){
            last_next_checkpoint_distnce = next_checkpoint_dist;
            calcMinThreshVal(last_next_checkpoint_distnce, minThreshVal);
        }
        
        if (next_checkpoint_angle > 90 || next_checkpoint_angle < -90){
            thrust = 0;
        }
        else{
            // changeThrustValBasedOnAngle(next_checkpoint_angle, thrust);
            thrust = 100;
        }

        changeThrustVal(thrust, next_checkpoint_dist, minThreshVal);

        if(boost_number != 0){
            cout << next_checkpoint_x << " " << next_checkpoint_y << " " <<thrust<< endl;
        }
        else{
            cout << next_checkpoint_x << " " << next_checkpoint_y << " BOOST"<< endl;
        }
        boost_number = 1;
        
        last_checkPoint_x = next_checkpoint_x;
        last_checkpoint_y = next_checkpoint_y;

    }
}