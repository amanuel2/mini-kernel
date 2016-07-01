#ifndef _network_h_
#define _network_h_
#pragma once

#include <stdbool.h>
#include<stdint.h>

typedef struct
{
    char *name;
    bool initalized;
    int32_t status;
    int (*initalize)(void);
}NetworkDriver;

NetworkDriver* createNetworkDriver(const char* name_param);
bool destroyNetworkDriver(NetworkDriver *self);
#endif