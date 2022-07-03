//Directions
#define FRONT 0
#define BACK 1
#define RIGHT 2
#define LEFT 3
#define ROTATE 4
#define FRONT_RIGHT 5
#define FRONT_LEFT 6
#define BACK_RIGHT 7
#define BACK_LEFT 8
#define TURNLEFT 9
#define TURNRIGHT 10
//MOTOR Numbers
#define FRM 0
#define BRM 1
#define FLM 2
#define BLM 3
//movement
#define FORWARD 1
#define BACKWARD -1
#define STOP 0

//Arm 
#define UP 0
#define DOWN 1
#define OPEN 2
#define CLOSE 3

//Minimum distance before stopping
#define MIN_DISTANCE 10

//--------------------------------------//
//---------------- PINS ----------------//
//--------------------------------------//

//Ultra sonic sensors pins
#define FRONT_ECHO 0
#define FRONT_TRIG 1 

#define BACK_ECHO 0
#define BACK_TRIG 1 

#define RIGHT_ECHO 0
#define RIGHT_TRIG 1

#define LEFT_ECHO 0
#define LEFT_TRIG 1

//Motors pins, F = Front, R = Right, M = Motor ... (i.e. FRM = Front right motor)
#define FRM_SPEED 19
#define FRM_IN1 23
#define FRM_IN2 22

#define FLM_SPEED 5
#define FLM_IN1 26 
#define FLM_IN2 25

#define BRM_SPEED 18
#define BRM_IN1 1 
#define BRM_IN2 3

#define BLM_SPEED 15
#define BLM_IN1 13 
#define BLM_IN2 14

//Arm
#define MOVE_SERVO 0 
#define JAW_SERVO 1
#define FIRE_MOTOR 2
