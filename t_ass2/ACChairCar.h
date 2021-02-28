#include "BookingClasses.h"

/**********CLASS Declaration***************************/
class ACChairCar: public Seat{
    static const double sloadFactor_;
    ACChairCar();
    static ACChairCar* sInstance;
    
    public:
    const static ACChairCar& Type();
    int GetNumberOfTiers() const ;
    double GetLoadFactor() const ;
    string GetName() const ;
    bool isAc() const ;
    bool isLuxury() const ;
};

