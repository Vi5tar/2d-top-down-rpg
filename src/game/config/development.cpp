#include "development.h"

Development::Development()
{
    on = true;
    doorsOpen = false;
};

bool Development::enabled()
{
    return on;
}

bool Development::hasDoorsOpen()
{
    return doorsOpen;
}

void Development::toggleDoorsOpen()
{
    doorsOpen = !doorsOpen;
}