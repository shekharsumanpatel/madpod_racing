#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>

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
    else{
        cout<< next_checkpoint_x<<" "<<next_checkpoint_y<<" SHIELD"<<endl;
        cerr<<" ATTACK !!!"<<endl;
    }
}

int angleToThrust(int next_checkpoint_angle, int max_angle, int power_val){
    if(next_checkpoint_angle < 45){
        return 100;
    }
    else{
        float fract = 1 - pow(next_checkpoint_angle/max_angle, power_val);
        return (int)100*fract;
    }
}

int distToThrust(int dist_next_checkpoint, int dist_thresh, int power_val, int checkpoint_radius){
    float fract = pow(((dist_next_checkpoint - checkpoint_radius)/(dist_thresh - checkpoint_radius)), power_val);
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
    int num_of_iter_max_dist = 7;
    int max_checkpoint_dist = pow(10,5);
    float fract_max_dist_boost_act = 0.75;
    int angle_thresh_boost_act = 15;
    map<int,int> map_val_angle_to_thrust;
    map<int,int> map_val_dist_to_thrust;
    int max_angle_for_angle_thrust_calc = 90;
    int power_val_angle_thrust_calc = 3;
    int min_dist_for_speed_up = 650;
    int checkpoint_radius = 500;
    int abs_angle;
    int dist_to_oppon = 0;

    for(int i = 0; i < max_angle_for_angle_thrust_calc; i++){
        map_val_angle_to_thrust[i] = angleToThrust(i,max_angle_for_angle_thrust_calc,power_val_angle_thrust_calc);
    }

    // for(int i = checkpoint_radius - 10; i < min_dist_for_speed_up; i++){
    //     map_val_dist_to_thrust[i] = distToThrust(i, min_dist_for_speed_up, power_val_angle_thrust_calc, checkpoint_radius - 10);
    // }

    // game loop
    while (1) {
        cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle; cin.ignore();
        cin >> opponent_x >> opponent_y; cin.ignore();
        dist_to_oppon = calculateEuclideanDistance(x, y, opponent_x, opponent_y);
        if(dist_to_oppon < 802){
            thrust = -2;
            printCommand(next_checkpoint_x,next_checkpoint_y,thrust);
            break;
        }

        abs_angle = abs(next_checkpoint_angle);

        if(abs_angle < max_angle_for_angle_thrust_calc ){
            thrust = map_val_angle_to_thrust[abs_angle];
        }
        else{
            thrust = 0;
        }


        if(boost == false){
            if(last_checkpoint_x != next_checkpoint_x || last_checkpoint_y != next_checkpoint_y){
                dist_bw_checkpoint.insert(next_checkpoint_dist);
                count_of_iter++;
            }
            if(count_of_iter>num_of_iter_max_dist){
                max_checkpoint_dist = *dist_bw_checkpoint.rbegin();
            }
            if(next_checkpoint_dist >= fract_max_dist_boost_act*max_checkpoint_dist && abs_angle <angle_thresh_boost_act){
                thrust = -1;
                boost = true;
            }
        }

        printCommand(next_checkpoint_x,next_checkpoint_y,thrust);

        last_checkpoint_x = next_checkpoint_x;
        last_checkpoint_y = next_checkpoint_y;
        
    }
}