#ifndef __BOOKING_CLASS_H
#define __BOOKING_CLASS_H

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
    virtual int GetNumberOfTiers() const = 0; 
    
    friend std::ostream& operator<<(std::ostream&, const BookingClass&); 
};

/**********ABSTRACT CLASS Declaration*******************/
class Seat: public BookingClass {
protected:
    Seat(const std::string&, bool, bool);
    virtual ~Seat();
public:
    virtual bool isSitting() const;
    virtual int GetNumberOfTiers() const;
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth: public BookingClass {
protected:
    Berth(const std::string&, bool, bool);
    virtual ~Berth();
public:
    virtual bool isSitting() const;
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth2Tier: public Berth {
protected:
    Berth2Tier(const std::string&, bool, bool);
    virtual ~Berth2Tier();
public:
    virtual int GetNumberOfTiers() const;
};

/**********ABSTRACT CLASS Declaration*******************/
class Berth3Tier: public Berth {
protected:
    Berth3Tier(const std::string&, bool, bool);
    virtual ~Berth3Tier();
public:
    virtual int GetNumberOfTiers() const;
};

/**********CLASS Declaration***************************/
// AC Chair Car 
class ACChairCar: public Seat {

private:
    static const double sloadFactor;
    ACChairCar(const std::string&, bool, bool);
    ~ACChairCar();
public:
    double GetLoadFactor() const;
    static const ACChairCar& Type();
};

/**********CLASS Declaration***************************/
class SecondSitting: public Seat {
private:
    static const double sloadFactor;
    SecondSitting(const std::string&,bool,bool);
    ~SecondSitting();
public:
    double GetLoadFactor() const;
    static const SecondSitting& Type();
};

/**********CLASS Declaration***************************/
/*


*/
class ACFirstClass: public Berth2Tier {

private:
    static const double sloadFactor;
    ACFirstClass(const std::string&,bool,bool);
    ~ACFirstClass();
public:
    double GetLoadFactor() const;
    static const ACFirstClass& Type();
};

/**********CLASS Declaration***************************/
class AC2Tier: public Berth2Tier {
private:
    static const double sloadFactor;
    AC2Tier(const std::string&,bool,bool);
    ~AC2Tier();
public:
    double GetLoadFactor() const;
    static const AC2Tier& Type();
};

/**********CLASS Declaration***************************/
class FirstClass: public Berth2Tier {
private:
    static const double sloadFactor;
    FirstClass(const std::string&,bool,bool);
    ~FirstClass();
public:
    double GetLoadFactor() const;
    static const FirstClass& Type();
};

/**********CLASS Declaration***************************/
class AC3Tier: public Berth3Tier {
private:
    static const double sloadFactor;
    AC3Tier(const std::string&,bool,bool);
    ~AC3Tier();
public:
    double GetLoadFactor() const;
    static const AC3Tier& Type();
};

/**********CLASS Declaration***************************/
class Sleeper: public Berth3Tier {
private:
    static const double sloadFactor;
    Sleeper(const std::string&,bool,bool);
    ~Sleeper();
public:
    double GetLoadFactor() const;
    static const Sleeper& Type();
};


#endif // __BOOKING_CLASS_H
