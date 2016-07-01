#include "network.h"

extern void die(const char *message);

NetworkDriver* createNetworkDriver(const char* name_param)
{
    NetworkDriver *nd = malloc(sizeof(NetworkDriver));
    nd->name = name_param;
    initalize(nd);
    return nd;
}

bool destroyNetworkDriver(NetworkDriver *self)
{
    if(self->initalized == true)
    {
        free(self);
        return true;
    }
    else
        return false;
}

int initalize(NetworkDriver *self){
    //Check all the initalzation stuff...
    self->initalized = true;
    self->status = 0;
    return 0;
}