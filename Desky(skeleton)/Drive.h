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
     * @brief Constructor for Drive class.
     * Assigns internal MotorData members to the values inputted
     * 
     * @param rm MotorData for the right motor
     * @param lm MotorData for the left motor
    */
    Drive(MotorData rm, MotorData lm);

    /**
     * @brief A function that calls the internal runMotors() function
     * 
     */
    void runDrive();

    /**
     * @brief Runs the motors forwards, backwards, or stops the motors depending on power.
     * If the power is positive, then the drive state is forwards.
     * If the power is negative, then the drive state is backwards and multiplies the power by -1.
     * If the power is 0, then the drive state is stopped.
     * After determining the drive state, the motor power values are assigned, and _runCount is set to 10.
     * 
     * @param power The new power at which to drive the motors
     */
    void driveMotors(int power);

    /**
     * @brief 
     * 
     * @param power
     * @param runCount 
     */
    void driveMotors(int power, int runCount);
    
    /**
     * @brief 
     * 
     * @param power
     */
    void turnMotors(int power);

    /**
     * @brief 
     * 
     * @param power
     * @param runCount
     */
    void turnMotors(int power, int runCount);

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