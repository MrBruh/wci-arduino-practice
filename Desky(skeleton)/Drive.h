/**
 * @file Drive.h
 * @author Michael Denissov
 * @author your name
 * @brief 
 * @version 0.3
 * @date 2021-02-01
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
 * @brief Possible states that the Drive class can be in
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
     * If the power is positive, then the drive state is set to DRIVE_FORWARDS.
     * If the power is negative, then the drive state is set to DRIVE_BACKWARDS and multiply the power by -1.
     * If the power is 0, then the drive state is set to DRIVE_STOPPED.
     * After determining the drive state, the motor power values are assigned to the MotorData structs,
     * and _runCount is set to 10.
     * 
     * @param power The new power at which to drive the motors
     */
    void driveMotors(int power);

    /**
     * @brief This calls the method above, and after calling the method,
     * _runCount and _routineBackup are set to the parameter values.
     * This method returns when either _routineTurn or _routineBackup are true.
     * 
     * @param power The new power at which to drive the motors
     * @param runCount The value for how long to run the motors
     * @param routineBackup Whether or not this is a part of a backup routine
     */
    void driveMotors(int power, int runCount, bool routineBackup = false);
    
    /**
     * @brief Runs the motors forwards, backwards, or stops the motors depending on power.
     * If the power is positive, then the drive state is set to DRIVE_RIGHT.
     * If the power is negative, then the drive state is set to DRIVE_LEFT and multiply the power by -1.
     * If the power is 0, then the drive state is set to DRIVE_STOPPED.
     * After determining the drive state, the motor power values are assigned to the MotorData structs,
     * and _runCount is set to 5.
     * 
     * @param power The new power at which to drive the motors
     */
    void turnMotors(int power);

    /**
     * @brief This calls the method above, and after calling the method,
     * _runCount is set to the parameter value.
     * This method returns when either _routineTurn or _routineBackup are true.
     * 
     * @param power The new power at which to drive the motors
     * @param runCount The value for how long to run the motors
     */
    void turnMotors(int power, int runCount);

    /**
     * @brief This method immediately stops the motors of the robot 
     * This sets the drive state to DRIVE_STOPPED and calls runMotors()
     * 
     */
    void stopMotors();

    /**
     * @brief This method jitters the robot left and right
     * _jitter is set to true, the MotorData power values are set to 150,
     * and _runCount is set to 100
     * 
     */
    void jitterMotors();

    /**
     * @brief This activates the general movement routine
     * _routine is set to true
     * 
     */
    void runRoutine();

    /**
     * @brief This stops all routines
     * _routine, _turnRoutine, and _routineBackup are set to false
     * 
     */
    void stopRoutine();

    /**
     * @brief This gets whether or not the general movement routine is running
     * 
     * @return _routine
     */
    bool getRoutine();

    
    /**
     * @brief This is used to detect if the robot is going to fall off
     * 
     * @return true If all three digitalReads are false 
     * @return false If at least one of the three digitalReads are true
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
     * @brief The most complicated method of the class, which decides how to run the motors
     * based on the all the values and states, and has many complicated sections to it.
     * 
     * The first section runs if both _runCount is greater than 0 and _jitter is true.
     * Here, if the tens digit of _runCount is odd, set _state to DRIVE_LEFT, else DRIVE_RIGHT
     * 
     * This section alternates running the motors left and right to make the robot jitter
     * 
     * 
     * else if _runCount is 0 and drive state is not DRIVE_STOPPED,
     * then _jitter and _routineTurn are set to false, and the drive state is set to DRIVE_STOPPED
     * if _routineBackup is true, then set it to false and call turnMotors at 200 power and 70 run count
     * 
     * This section is not ideal, but it's good enough for the task. This is here so that when
     * _runCount runs out, everything is set to stop, except for _routineBackup, in which case
     * the robot is supposed to turn around.
     * 
     * 
     * The next section runs if the drive state has changed(i.e. _state is not equal to _prevState),
     * which has a switch statement depending on _state
     * If the drive state is stopped, set the MotorData powers to 0
     * If the drive state is backwards, set both sides to backwards
     * If the drive state is forwards, set both sides to forwards
     * If the drive state is left, set the right side to backwards and the left side to forwards
     * If the drive state is right, set the right side to forwards and the left side to backwards
     * A default state to do nothing
     * After the switch statement, set _prevState to _state
     * 
     * This section determines what direction to run the motors depending on the drive state
     * 
     * 
     * Finally, analogWrite to the PWM pin of both motors their repective powers 
     * (Using the MotorData structs)
     */
    void runMotors();

    /**
     * @brief Sets the left side of the drive to forwards
     * Set the left B pin to low and F pin to high
     * 
     */
    void setLeftForwards();

    /**
     * @brief Sets the right side of the drive to forwards
     * Set the right B pin to low and F pin to high
     * 
     */
    void setRightForwards();

    /**
     * @brief Sets the left side of the drive to backwards
     * Set the left F pin to low and B pin to high
     * 
     */
    void setLeftBackwards();

    /**
     * @brief Sets the right side of the drive to backwards
     * Set the right F pin to low and B pin to high
     * 
     */
    void setRightBackwards();

}; 
#endif