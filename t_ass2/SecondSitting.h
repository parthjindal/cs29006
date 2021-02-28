#include "BookingClasses.h"

/**********CLASS Declaration***************************/
class SecondSitting: public Seat{
    static const double sloadFactor_;
    SecondSitting();
    static SecondSitting* sInstance;
    
    public:
    const static SecondSitting& Type();
    int GetNumberOfTiers() const ;
    double GetLoadFactor() const ;
    string GetName() const ;
    bool isAc() const ;
    bool isLuxury() const ;
};