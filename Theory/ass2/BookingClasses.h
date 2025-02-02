// **** BookingClass class definition
// **** Author: Parth Jindal
// **** Date: 1 March 2021
// **** Roll no.: 19CS30033

#ifndef __BOOKING_CLASS_H //Control inclusion of header files
#define __BOOKING_CLASS_H


/*************C++ Standard Library Headers **********************/
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

    //ATTRIBUTES
    //----------
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
    virtual bool isSitting() const; // = True
    virtual int GetNumberOfTiers() const; // = 0
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

    //BLOCKED CONSTRUCTOR
    //-------------------
    ACChairCar(const ACChairCar&) = delete; //block cctor
    ACChairCar& operator=(const ACChairCar&) = delete; //block operator=

    //DESTRUCTOR
    //----------
    ~ACChairCar();
public:
    double GetLoadFactor() const;
    static const ACChairCar& Type();

    static void UnitTest();
};

/**********CLASS Declaration***************************/
class SecondSitting: public Seat {
private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    SecondSitting(const std::string&,bool,bool);
    SecondSitting(const SecondSitting&) = delete; //block cctor
    SecondSitting& operator=(const SecondSitting&) = delete; //block operator=
    //DESTRUCTOR
    //----------
    ~SecondSitting();
public:
    double GetLoadFactor() const;
    static const SecondSitting& Type();

    static void UnitTest();
};

/**********CLASS Declaration***************************/
class ACFirstClass: public Berth2Tier {

private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    ACFirstClass(const std::string&,bool,bool);
    ACFirstClass(const ACFirstClass&) = delete; //block cctor
    ACFirstClass& operator=(const ACFirstClass&) = delete; //block operator=
    
    //DESTRUCTOR
    //----------
    ~ACFirstClass();
public:
    double GetLoadFactor() const;
    static const ACFirstClass& Type();

    static void UnitTest();
};

/**********CLASS Declaration***************************/
class AC2Tier: public Berth2Tier {
private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    AC2Tier(const std::string&,bool,bool);
    AC2Tier(const AC2Tier&) = delete; //block cctor
    AC2Tier& operator=(const AC2Tier&) = delete; //block operator=
    
    //DESTRUCTOR
    //----------
    ~AC2Tier();
public:
    double GetLoadFactor() const;
    static const AC2Tier& Type();

    static void UnitTest();
};

/**********CLASS Declaration***************************/
class FirstClass: public Berth2Tier {
private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    FirstClass(const std::string&,bool,bool);
    FirstClass(const FirstClass&) = delete;            //block cctor
    FirstClass& operator=(const FirstClass&) = delete; //block operator=
    
    //DESTRUCTOR
    //----------
    ~FirstClass();
public:
    double GetLoadFactor() const; //Local static const Instance
    static const FirstClass& Type();

    static void UnitTest();
};

/**********CLASS Declaration***************************/
class AC3Tier: public Berth3Tier {
private:
    static const double sloadFactor;
    
    //CONSTRUCTOR
    //----------
    AC3Tier(const std::string&,bool,bool);
    AC3Tier(const AC3Tier&) = delete; //block cctor
    AC3Tier& operator=(const AC3Tier&) = delete; //block operator=
    
    //DESTRUCTOR
    //----------
    ~AC3Tier();
public:
    double GetLoadFactor() const;
    static const AC3Tier& Type();

    static void UnitTest();
};

/**********CLASS Declaration***************************/
class Sleeper: public Berth3Tier {
private:
    static const double sloadFactor; 
    
    //CONSTRUCTOR
    //----------
    Sleeper(const std::string&,bool,bool);
    Sleeper(const Sleeper&) = delete; //block cctor
    Sleeper& operator=(const Sleeper&) = delete; //block operator=

    //DESTRUCTOR
    //----------
    ~Sleeper();

public:
    double GetLoadFactor() const;
    static const Sleeper& Type();

    static void UnitTest();
};


#endif // __BOOKING_CLASS_H
