#ifndef __LIGHTSIGNALS__
#define __LIGHTSIGNALS___

/*Interface for the management of the ligth signals given to the users.
The instructions given to this component trough its methods are then 
converted as switch hon or switch off signals for the leds */

class LightSignals {
public:
    virtual void signalAvailability() = 0;
    virtual void signalSleep() = 0;   
    virtual void signalFull() = 0;   
private:
    Led greenLed;
    Led redLed;
};

#endif
