/**
 * @file Drive.h
 * @author Michael Denissov
 * @author your name
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DRIVE_H
#define DRIVE_H
/**
 * @brief Holds the pin numbers that are required to drive the motor.
 *      Also holds the current speed that the motor should be running at
 * 
 */
struct MotorData {
    int PWMpin;
    int Fpin;
    int Bpin;
    int power = 0;
};

/**
 * @brief Possible state that the Drive class can be in
 * 
 */
enum DriveState {
  DRIVE_FORWARDS,
  DRIVE_BACKWARDS,
  DRIVE_FORWARDS_RIGHT,
  DRIVE_FORWARDS_LEFT,
  DRIVE_BACKWARDS_RIGHT,
  DRIVE_BACKWARDS_LEFT,
  DRIVE_LEFT,
  DRIVE_RIGHT,
  DRIVE_STOPPED
};

/**
 * @brief 
 * 
 */
class Drive {
    public:
    /**
     * @brief Constructor for Drive class
     * Has MotorData structs as params for the right and left motors
     * 
     * @param rm MotorData for the right motor
     * @param lm MotorData for the left motor
    */
    Drive(MotorData rm, MotorData lm);
    /**
     * @brief 
     * 
     */
    void runDrive();
    /**
     * @brief 
     * 
     */
    void driveMotors(int power);
    /**
     * @brief 
     * 
     */
    void driveMotors(int power, int runCount);
    /**
     * @brief 
     * 
     */
    void turnMotors();
    /**
     * @brief 
     * 
     */
    void turnMotors();
    /**
     * @brief 
     * 
     */
    void stopMotors();
    /**
     * @brief 
     * 
     */
    void jitterMotors();
    /**
     * @brief 
     * 
     */
    void runRoutine();
    /**
     * @brief 
     * 
     */
    void stopRoutine();
    /**
     * @brief 
     * 
     */
    bool getRoutine();
    /**
     * @brief 
     * 
     */
    bool readLightSensors();
    private:
    MotorData _rm;
    MotorData _lm;
    DriveState _state = DRIVE_STOPPED;
    DriveState _prevState = DRIVE_FORWARDS;
    int _runCount = 0;
    bool _jitter = false;
    bool _routine = false;
    bool _routineTurn = false;
    bool _routineBackup = false;
    /**
     * @brief 
     * 
     */
    void runMotors();
    /**
     * @brief 
     * 
     */
    void setLeftForwards();
    /**
     * @brief 
     * 
     */
    void setRightForwards();
    /**
     * @brief 
     * 
     */
    void setLeftBackwards();
    /**
     * @brief 
     * 
     */
    void setRightBackwards();

}; 
#endif