#include "stdio.h"

typedef struct{
    void (*Start)(int gpio);
    void (*Stop)(int gpio);
    void (*ChangeSpeed)(int gpio, int speed);
} MotorController;

typedef int Pin;

void startmotor(Pin pin)
{
    printf("Start motor at PIN %d\n", pin);
}

void stopmotor(Pin pin)
{
    printf("Stop motor at PIN %d\n", pin);
}

void changespeedmotor(Pin pin , int speed)
{
    printf("Change speed at PIN %d: %d\n", pin, speed);
}


#define INIT_MOTOR(motorname,pinnumber) \
Pin PIN_##motorname = pinnumber;\
MotorController motorname = {.Start=startmotor,.Stop=stopmotor,.ChangeSpeed=changespeedmotor};



int main(int argc, char const *argv[])
{
    /* code */
    INIT_MOTOR(motorA,1);
    INIT_MOTOR(motorB,2);
    

    motorA.Start(PIN_motorA);
    motorA.Stop(PIN_motorA);
    motorA.ChangeSpeed(PIN_motorA,75);


    motorB.Start(PIN_motorB);
    motorB.Stop(PIN_motorB);
    motorB.ChangeSpeed(PIN_motorB,50);
    return 0;
}
