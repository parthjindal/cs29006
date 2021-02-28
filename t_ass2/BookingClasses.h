#ifndef __BOOKING_CLASS_H
#define __BOOKING_CLASS_H



#include<string>
using namespace std;


/**********ABSTRACT CLASS Declaration*******************/
class BookingClass{
public:
    BookingClass();
    virtual ~BookingClass() = 0;
    virtual double GetLoadFactor() const = 0;
    virtual string GetName() const = 0;
    virtual bool isSitting() const = 0;
    virtual bool isAc() const = 0;
    virtual int GetNumberOfTiers() const = 0;
    virtual bool isLuxury() const = 0;
};

/**********ABSTRACT CLASS Declaration*******************/
class Seat:public BookingClass{
    public:
    virtual bool isSitting() const;
    virtual ~Seat();
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth:public BookingClass{
    public:
    virtual bool isSitting() const;
    virtual ~Berth();
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth2Tier:public Berth{
    public:
    virtual int GetNumberOfTiers() const;
    virtual ~Berth2Tier();

};

/**********ABSTRACT CLASS Declaration*******************/
class Berth3Tier:public Berth{
    public:
    virtual int GetNumberOfTiers() const;
    virtual ~Berth3Tier();
};

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

/**********CLASS Declaration***************************/
class ACFirstClass:public Berth2Tier{
    static const double sloadFactor_;
    ACFirstClass();
    static ACFirstClass* sInstance;
    
    public:
    const static ACFirstClass& Type();
    double GetLoadFactor() const ;
    string GetName() const ;
    bool isAc() const ;
    bool isLuxury() const ;
};

/**********CLASS Declaration***************************/
class AC2Tier:public Berth2Tier{
    static const double sloadFactor_;
    AC2Tier();
    static AC2Tier* sInstance;
    public:
    const static AC2Tier& Type();
    double GetLoadFactor() const ;
    string GetName() const ;
    bool isAc() const;
    bool isLuxury() const;
};

/**********CLASS Declaration***************************/
class FirstClass:public Berth2Tier{
    static const double sloadFactor_;
    FirstClass();
    static FirstClass* sInstance;
    public:
    const static FirstClass& GetInstance();
    double GetLoadFactor() const;
    string GetName() const;
    bool isAc() const;
    bool isLuxury() const;
};

/**********CLASS Declaration***************************/
class AC3Tier:public Berth3Tier{
    static const double sloadFactor_;
    AC3Tier();
    static AC3Tier* sInstance;
    public:
    const static AC3Tier& Type();
    double GetLoadFactor() const;
    string GetName() const;
    bool isAc() const;
    bool isLuxury() const;
};

/**********CLASS Declaration***************************/
class Sleeper:public Berth3Tier{
    static const double sloadFactor_;
    Sleeper();
    static Sleeper* sInstance;
    public:
    const static Sleeper& Type();
    double GetLoadFactor() const;
    string GetName() const;
    bool isAc() const;
    bool isLuxury() const;
};



#endif // __BOOKING_CLASS_H
