#ifndef ROBOT_H
#define ROBOT_H

enum RobotState
{
    ATTENTION,
    ROAM,
    PET,
    SLEEP
};

void robotBegin();
void robotUpdate();

#endif