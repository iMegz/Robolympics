//Directions
#define FRONT 0
#define BACK 1
#define RIGHT 2
#define LEFT 3
#define ROTATE 4

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
#define FRONT_ECHO 34
#define FRONT_TRIG 32



#define BACK_ECHO 16
#define BACK_TRIG  2

#define RIGHT_ECHO 17
#define RIGHT_TRIG 4

#define LEFT_ECHO 35
#define LEFT_TRIG 33

//Motors pins, F = Front, R = Right, M = Motor ... (i.e. FRM = Front right motor)
#define FRM_SPEED 0
#define FRM_IN1 1 
#define FRM_IN2 2

#define FLM_SPEED 0
#define FLM_IN1 1 
#define FLM_IN2 2

#define BRM_SPEED 0
#define BRM_IN1 1 
#define BRM_IN2 2

#define BLM_SPEED 0
#define BLM_IN1 1 
#define BLM_IN2 2

//Arm
#define MOVE_SERVO 0 
#define JAW_SERVO 1
#define FIRE_MOTOR 2
