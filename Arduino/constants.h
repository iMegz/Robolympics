//Directions
#define FRONT 0
#define BACK 1
#define RIGHT 2
#define LEFT 3
#define FRONT_RIGHT 4
#define FRONT_LEFT 5
#define BACK_RIGHT 6
#define BACK_LEFT 7
#define TURN_LEFT 8
#define TURN_RIGHT 9

//MOTOR Numbers
#define FRM 0
#define BRM 1
#define FLM 2
#define BLM 3

//Movement
#define FORWARD 1
#define BACKWARD -1
#define STOP 0

//Arm ----------------------------------->>
#define UP 0
#define DOWN 1
#define OPEN 2
#define CLOSE 3

//Minimum distance before stopping
#define MIN_DISTANCE 10 ----------------------------->>

//--------------------------------------//
//---------------- PINS ----------------//
//--------------------------------------//

//Ultra sonic sensors pins
#define FRONT_TRIG 2
#define RIGHT_TRIG 3
#define LEFT_TRIG 4

#define FRONT_ECHO 5
#define RIGHT_ECHO 6
#define LEFT_ECHO 7


//Motors pins, F = Front, R = Right, M = Motor ... (i.e. FRM = Front right motor)
#define SPEED 11

#define FRM_IN1 12
#define FLM_IN1 13
#define BRM_IN1 A0
#define BLM_IN1 A1 

#define FRM_IN2 A2
#define FLM_IN2 A3
#define BRM_IN2 A4
#define BLM_IN2 A5

//Arm
#define JAW_SERVO 8
#define FIRE_MOTOR 9
#define MOVE_SERVO 10 
