#ifndef __BOOKING_CLASS_H
#define __BOOKING_CLASS_H

#include<string>
#include<iostream>
using namespace std;


/**********ABSTRACT CLASS Declaration*******************/
class BookingClass{
public:
    virtual double GetLoadFactor() const = 0;
    virtual string GetName() const = 0;
    virtual bool isSitting() const = 0;
    virtual bool isAc() const = 0;
    virtual int GetNumberOfTiers() const = 0;
    virtual bool isLuxury() const = 0; 
    friend ostream& operator<<(ostream&,const BookingClass&);
};

/**********ABSTRACT CLASS Declaration*******************/
class Seat:public BookingClass{
    public:
    virtual bool isSitting() const;
    virtual int GetNumberOfTiers() const;
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth:public BookingClass{
    public:
    virtual bool isSitting() const;
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth2Tier:public Berth{
    public:
    virtual int GetNumberOfTiers() const;
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth3Tier:public Berth{
    public:
    virtual int GetNumberOfTiers() const;
};

/**********CLASS Declaration***************************/
class ACChairCar: public Seat{
    static const double sloadFactor;
    ACChairCar();
    static ACChairCar* sInstance;
    
    public:
    ~ACChairCar();
    const static ACChairCar& Type();
    double GetLoadFactor() const ;
    string GetName() const ;
    bool isAc() const ;
    bool isLuxury() const ;
};

/**********CLASS Declaration***************************/
class SecondSitting: public Seat{
    static const double sloadFactor;
    SecondSitting();
    static SecondSitting* sInstance;
    
    public:
    ~SecondSitting();
    const static SecondSitting& Type();
    double GetLoadFactor() const ;
    string GetName() const ;
    bool isAc() const ;
    bool isLuxury() const ;
};

/**********CLASS Declaration***************************/
class ACFirstClass:public Berth2Tier{
    static const double sloadFactor;
    ACFirstClass();
    static ACFirstClass* sInstance;
    
    public:
    ~ACFirstClass();
    const static ACFirstClass& Type();
    double GetLoadFactor() const ;
    string GetName() const ;
    bool isAc() const ;
    bool isLuxury() const ;
};

/**********CLASS Declaration***************************/
class AC2Tier:public Berth2Tier{
    static const double sloadFactor;
    AC2Tier();
    static AC2Tier* sInstance;
    public:
    ~AC2Tier();
    const static AC2Tier& Type();
    double GetLoadFactor() const ;
    string GetName() const ;
    bool isAc() const;
    bool isLuxury() const;
};

/**********CLASS Declaration***************************/
class FirstClass:public Berth2Tier{
    static const double sloadFactor;
    FirstClass();
    static FirstClass* sInstance;
    public:
    ~FirstClass();
    const static FirstClass& Type();
    double GetLoadFactor() const;
    string GetName() const;
    bool isAc() const;
    bool isLuxury() const;
};

/**********CLASS Declaration***************************/
class AC3Tier:public Berth3Tier{
    static const double sloadFactor;
    AC3Tier();
    static AC3Tier* sInstance;
    public:
    ~AC3Tier();
    const static AC3Tier& Type();
    double GetLoadFactor() const;
    string GetName() const;
    bool isAc() const;
    bool isLuxury() const;
};

/**********CLASS Declaration***************************/
class Sleeper:public Berth3Tier{
    static const double sloadFactor;
    Sleeper();
    static Sleeper* sInstance;
    public:
    ~Sleeper();
    const static Sleeper& Type();
    double GetLoadFactor() const;
    string GetName() const;
    bool isAc() const;
    bool isLuxury() const;
};



#endif // __BOOKING_CLASS_H
