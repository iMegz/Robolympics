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
#define OPEN 90
#define CLOSE 40

//Minimum distance before stopping
#define MIN_DISTANCE 15

//--------------------------------------//
//---------------- PINS ----------------//
//--------------------------------------//

//Ultra sonic sensors pins
#define FRONT_TRIG 33 //Orange
#define RIGHT_TRIG 31 //Yellow
#define LEFT_TRIG 35 //Brown

#define FRONT_ECHO 32 //Orange
#define RIGHT_ECHO 30 //Yellow
#define LEFT_ECHO 34 //Brown

//Motors pins, F = Front, R = Right, M = Motor ... (i.e. FRM = Front right motor)
#define FRM_SPEED 2
#define FRM_IN1 25
#define FRM_IN2 23

#define FLM_SPEED 3
#define FLM_IN1 27 
#define FLM_IN2 29

#define BRM_SPEED 4
#define BRM_IN1 28 
#define BRM_IN2 26

#define BLM_SPEED 5
#define BLM_IN1 22 
#define BLM_IN2 24

//Arm
#define SERVO_1 7 //-----------------------
#define SERVO_2 8
#define JAW 9

#define SERVO_1_INIT 0
#define SERVO_2_INIT 85
#define CLAMP_INIT 90
#define ANGLE_CHANGE 10

//Fire
#define FIRE_ENABLE 6
