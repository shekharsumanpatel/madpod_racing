#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
void printCommand(int next_checkpoint_x, int next_checkpoint_y, int thrust){
    if(thrust >= 0){
        cout<< next_checkpoint_x<<" "<<next_checkpoint_y<<" "<<thrust<<endl;
    }
    else if(thrust == -1){
        cout<< next_checkpoint_x<<" "<<next_checkpoint_y<<" BOOST"<<endl;
        cerr<<" We are full on boosting"<<endl;
    }
}

int angleToThrust(int next_checkpoint_angle, int max_angle, int power_val){
    int abs_angle = abs(next_checkpoint_angle);
    float fract = 1 - pow(abs_angle/max_angle, power_val);
    return (int)100*fract;

}

int calculateEuclideanDistance(int x_1, int y_1, int x_2, int y_2 ){
    float dist = pow( (pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2) ), 0.5);
    return (int)dist;
}

int main()
{
    int x;
    int y;
    int next_checkpoint_x; // x position of the next check point
    int next_checkpoint_y; // y position of the next check point
    int next_checkpoint_dist; // distance to the next checkpoint
    int next_checkpoint_angle; // angle between your pod orientation and the direction of the next checkpoint
    int opponent_x;
    int opponent_y;
    int thrust = 100;
    int last_checkpoint_x;
    int last_checkpoint_y;
    bool boost = false;
    set<int> dist_bw_checkpoint;
    int count_of_iter = 0;
    int max_checkpoint_dist = 0;

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

        
        if(boost == false){
            if(last_checkpoint_x != next_checkpoint_x || last_checkpoint_y != next_checkpoint_y){
                dist_bw_checkpoint.insert(next_checkpoint_dist);
                count_of_iter++;
            }
            if(count_of_iter>10){
                max_checkpoint_dist = *dist_bw_checkpoint.rbegin();
            }
            if(next_checkpoint_dist == max_checkpoint_dist){
                thrust = -1;
                boost = true;
            }
        }

        printCommand(next_checkpoint_x,next_checkpoint_y,thrust);

        last_checkpoint_x = next_checkpoint_x;
        last_checkpoint_y = next_checkpoint_y;


        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // You have to output the target position
        // followed by the power (0 <= thrust <= 100) or "BOOST" or "SHIELD"
        // i.e.: "x y thrust"
        
    }
}