#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

class Development {
    bool on;
    bool doorsOpen;
    public:
        Development();
        bool enabled();
        bool hasDoorsOpen();
        void toggleDoorsOpen();
};

#endif