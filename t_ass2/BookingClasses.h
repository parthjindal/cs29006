// **** BookingClass class definition
// **** Author: Parth Jindal
// **** Date: 1 March 2021
// **** Roll no.: 19CS30033

#ifndef __BOOKING_CLASS_H //Control inclusion of header files
#define __BOOKING_CLASS_H


/*************C++ Headers **********************/
#include<string>
#include<iostream>


/**********ABSTRACT CLASS Declaration*******************/
class BookingClass {

protected:
    //CONSTRUCTOR
    //-----------
    BookingClass(const std::string&, bool, bool);
    
    //DESTRUCTOR
    //----------
    virtual ~BookingClass();

    const std::string name_;
    const bool isAC_;  
    const bool isLuxury_;

public:
    
    std::string GetName() const;              //returns name
    bool isAc() const;                        //returns true if has AC
    bool isLuxury() const;                    //returns true if luxury

    //PURE VIRTUAL FUNCTIONS
    //----------------------

    //returns true if Booking is 'Seat Type' else false
    virtual bool isSitting() const = 0;    

    /*returns loadFactor of BookingClass.
    loadFactor to be set in Application.*/ 
    virtual double GetLoadFactor() const = 0; //returns loadFactor
    virtual int GetNumberOfTiers() const = 0; //returns No. of tiers
    
    friend std::ostream& operator<<(std::ostream&, const BookingClass&);
};

/**********ABSTRACT CLASS Declaration*******************/
class Seat: public BookingClass {
protected:
    //CONSTRUCTOR
    //-----------
    Seat(const std::string&, bool, bool);

    //DESTRUCTOR
    //----------
    virtual ~Seat();
public:
    virtual bool isSitting() const;
    virtual int GetNumberOfTiers() const;
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth: public BookingClass {
protected:
    //CONSTRUCTOR
    //-----------
    Berth(const std::string&, bool, bool);

    //DESTRUCTOR
    //----------
    virtual ~Berth();
public:
    virtual bool isSitting() const;
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth2Tier: public Berth {
protected:
    //CONSTRUCTOR
    //-----------
    Berth2Tier(const std::string&, bool, bool);

    //DESTRUCTOR
    //-----------
    virtual ~Berth2Tier();
public:
    virtual int GetNumberOfTiers() const;
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth3Tier: public Berth {
protected:

//CONSTRUCTOR
//----------
    Berth3Tier(const std::string&, bool, bool);

//DESTRUCTOR
//----------
    virtual ~Berth3Tier();
public:
    virtual int GetNumberOfTiers() const;
};

/**********CLASS Declaration***************************/
// AC Chair Car 
class ACChairCar: public Seat {

private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    ACChairCar(const std::string&, bool, bool);
    
    //DESTRUCTOR
    //----------
    ~ACChairCar();
public:
    double GetLoadFactor() const;
    static const ACChairCar& Type();

    static void UnitTestACChairCar();
};

/**********CLASS Declaration***************************/
class SecondSitting: public Seat {
private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    SecondSitting(const std::string&,bool,bool);
    
    //DESTRUCTOR
    //----------
    ~SecondSitting();
public:
    double GetLoadFactor() const;
    static const SecondSitting& Type();

    static void UnitTestSecondSitting();
};

/**********CLASS Declaration***************************/
class ACFirstClass: public Berth2Tier {

private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    ACFirstClass(const std::string&,bool,bool);
    
    //DESTRUCTOR
    //----------
    ~ACFirstClass();
public:
    double GetLoadFactor() const;
    static const ACFirstClass& Type();

    static void UnitTestACFirstClass();
};

/**********CLASS Declaration***************************/
class AC2Tier: public Berth2Tier {
private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    AC2Tier(const std::string&,bool,bool);
    
    //DESTRUCTOR
    //----------
    ~AC2Tier();
public:
    double GetLoadFactor() const;
    static const AC2Tier& Type();

    static void UnitTestAC2Tier();
};

/**********CLASS Declaration***************************/
class FirstClass: public Berth2Tier {
private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    FirstClass(const std::string&,bool,bool);
    FirstClass(const FirstClass&);            //block cctor
    FirstClass& operator=(const FirstClass&); //block operator=
    
    //DESTRUCTOR
    //----------
    ~FirstClass();
public:
    double GetLoadFactor() const; //Local static const Instance
    static const FirstClass& Type();

    static void UnitTestFirstClass();
};

/**********CLASS Declaration***************************/
class AC3Tier: public Berth3Tier {
private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    AC3Tier(const std::string&,bool,bool);
    AC3Tier(const AC3Tier&); //block cctor
    AC3Tier& operator=(const AC3Tier&); //block operator=
    
    //DESTRUCTOR
    //----------
    ~AC3Tier();
public:
    double GetLoadFactor() const;
    static const AC3Tier& Type();

    static void UnitTestAC3Tier();
};

/**********CLASS Declaration***************************/
class Sleeper: public Berth3Tier {
private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    Sleeper(const std::string&,bool,bool);
    Sleeper(const Sleeper&); //block cctor
    Sleeper& operator=(const Sleeper&); //block operator=

    //DESTRUCTOR
    //----------
    ~Sleeper();

public:
    double GetLoadFactor() const;
    static const Sleeper& Type();

    static void UnitTestSleeper();
};


#endif // __BOOKING_CLASS_H
