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
void changeThrustVal(int &thrust, int next_checkpoint_dist){
    if( next_checkpoint_dist < 100 ){
        thrust = 0;}
}

void calcMinThreshVal( int total_dist_next_checkpoint, int &minThreshVal){
    minThreshVal = 0.05*total_dist_next_checkpoint;
}

void changeThrustValBasedOnAngle(int next_checkpoint_angle, int &thrust){
    float fract = 1 - pow((next_checkpoint_angle/90),3) ;
    thrust = (int)100*fract;
}

float calcEuclideanDistance(int x_1, int y_1, int x_2, int y_2){
    float EuclidDist = pow(pow(x_1-x_2,2) + pow(y_1-y_2,2),0.5);
    return EuclidDist;

}

void attackOtherPod(int x, int y, int opponent_x, int opponent_y, int &thrust ){
    float dist = calcEuclideanDistance(x,y,opponent_x,opponent_y);
    if(dist<810){
        thrust = 100;
    }
}

void circleOfAttack(int x, int y, int opponent_x, int opponent_y, int next_checkpoint_x, int next_checkpoint_y, int next_checkpoint_dist, int &thrust ){
    float opponent_circle_radius = calcEuclideanDistance(opponent_x,opponent_y, next_checkpoint_x, next_checkpoint_y);
    if(opponent_circle_radius > next_checkpoint_dist && next_checkpoint_dist <600){
        thrust = 0;
    }
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
        // if(last_checkPoint_x != next_checkpoint_x || last_checkpoint_y != next_checkpoint_x){
        //     last_next_checkpoint_distnce = next_checkpoint_dist;
        //     calcMinThreshVal(last_next_checkpoint_distnce, minThreshVal);
        // }
        int angle_abs = abs(next_checkpoint_angle);
        if(angle_abs < 90 && next_checkpoint_dist > 650){
            changeThrustValBasedOnAngle(angle_abs, thrust);
        }
        else if(angle_abs >= 90 && next_checkpoint_dist < 650){
            thrust = 0;
        }
        else{
            thrust = 0;
        }
        cerr<<"angle abs = "<<angle_abs<<endl;

        changeThrustVal(thrust, next_checkpoint_dist);
        
        attackOtherPod(x,y,opponent_x,opponent_y,thrust);

        circleOfAttack(x,y,opponent_x, opponent_y, next_checkpoint_x, next_checkpoint_y,next_checkpoint_dist,thrust);
        
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