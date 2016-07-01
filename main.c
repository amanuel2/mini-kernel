#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "kernel/drivers/drivers.h"


int main(int argc, char *argv[])
{
    initalizeDrivers();
    destroyDrivers();
}