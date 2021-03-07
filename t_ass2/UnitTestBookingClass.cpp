#include "BookingClasses.h"
#include<iostream>
#include<cassert>
#include<sstream>
#include<fstream>

using namespace std;

const double ACChairCar::sloadFactor = 1.25;
const double SecondSitting::sloadFactor = 0.5;
const double ACFirstClass::sloadFactor = 3.00;
const double AC2Tier::sloadFactor = 2.00;
const double FirstClass::sloadFactor = 2.00;
const double AC3Tier::sloadFactor = 1.75;
const double Sleeper::sloadFactor = 1.00;


void ACChairCar::UnitTest(){

    assert(true == ACChairCar::Type().isAc());
    assert("AC Chair Car" == ACChairCar::Type().GetName());
    assert(false == ACChairCar::Type().isLuxury());
    assert(true == ACChairCar::Type().isSitting());
    assert(1.25 == ACChairCar::Type().GetLoadFactor());
    assert(0 == ACChairCar::Type().GetNumberOfTiers());

    //TESTING WITH GOLDEN OUTPUTS
    ifstream log("logs/ACCHairCar.log");
    if(log){
        stringstream expectedOut,out;
        expectedOut << log.rdbuf();
        out << ACChairCar::Type();
        assert(out.str() == expectedOut.str());
    }else{
        cout << "LogFile Not Found";
        exit(1);
    }
}

void SecondSitting::UnitTest(){
    assert(false== SecondSitting::Type().isAc());
    assert("Second Sitting" == SecondSitting::Type().GetName());
    assert(false == SecondSitting::Type().isLuxury());
    assert(true == SecondSitting::Type().isSitting());
    assert(0.5 == SecondSitting::Type().GetLoadFactor());
    assert(0 == SecondSitting::Type().GetNumberOfTiers());

    //TESTING WITH GOLDEN OUTPUTS
    ifstream log("logs/SecondSitting.log");
    if(log){
        stringstream expectedOut,out;
        expectedOut << log.rdbuf();
        out << SecondSitting::Type();
        assert(out.str() == expectedOut.str());
    }else{
        cout << "LogFile: SecondSitting.log Not Found";
        exit(1);
    }
}

void ACFirstClass::UnitTest(){
    assert(true == ACFirstClass::Type().isAc());
    assert("AC First Class" == ACFirstClass::Type().GetName());
    assert(true == ACFirstClass::Type().isLuxury());
    assert(false == ACFirstClass::Type().isSitting());
    assert(3 == ACFirstClass::Type().GetLoadFactor());
    assert(2 == ACFirstClass::Type().GetNumberOfTiers());
    
    //TESTING WITH GOLDEN OUTPUTS
    ifstream log("logs/ACFirstClass.log");
    if(log){
        stringstream expectedOut,out;
        expectedOut << log.rdbuf();
        out << ACFirstClass::Type();
        assert(out.str() == expectedOut.str());
    }else{
        cout << "LogFile: ACFirstClass.log Not Found";
        exit(1);
    }
}

void AC2Tier::UnitTest(){
    assert(true== AC2Tier::Type().isAc());
    assert("AC 2 Tier" == AC2Tier::Type().GetName());
    assert(false == AC2Tier::Type().isLuxury());
    assert(false == AC2Tier::Type().isSitting());
    assert(2.00 == AC2Tier::Type().GetLoadFactor());
    assert(2 == AC2Tier::Type().GetNumberOfTiers());

    //TESTING WITH GOLDEN OUTPUTS
    ifstream log("logs/AC2Tier.log");
    if(log){
        stringstream expectedOut,out;
        expectedOut << log.rdbuf();
        out << AC2Tier::Type();
        assert(out.str() == expectedOut.str());
    }else{
        cout << "LogFile: AC2Tier.log Not Found";
        exit(1);
    }

}

void FirstClass::UnitTest(){
    assert(false== FirstClass::Type().isAc());
    assert("First Class" == FirstClass::Type().GetName());
    assert(true == FirstClass::Type().isLuxury());
    assert(false == FirstClass::Type().isSitting());
    assert(2.00 == FirstClass::Type().GetLoadFactor());
    assert(2 == FirstClass::Type().GetNumberOfTiers());

    //TESTING WITH GOLDEN OUTPUTS
    ifstream log("logs/FirstClass.log");
    if(log){
        stringstream expectedOut,out;
        expectedOut << log.rdbuf();
        out << FirstClass::Type();
        assert(out.str() == expectedOut.str());
    }else{
        cout << "LogFile: FirstClass.log Not Found";
        exit(1);
    }
}

void AC3Tier::UnitTest(){
    assert(true == AC3Tier::Type().isAc());
    assert("AC 3 Tier" == AC3Tier::Type().GetName());
    assert(false == AC3Tier::Type().isLuxury());
    assert(false == AC3Tier::Type().isSitting());
    assert(1.75 == AC3Tier::Type().GetLoadFactor());
    assert(3 == AC3Tier::Type().GetNumberOfTiers());

    //TESTING WITH GOLDEN OUTPUTS
    ifstream log("logs/AC3Tier.log");
    if(log){
        stringstream expectedOut,out;
        expectedOut << log.rdbuf();
        out << AC3Tier::Type();
        assert(out.str() == expectedOut.str());
    }else{
        cout << "LogFile: AC3Tier.log Not Found";
        exit(1);
    }
}
void Sleeper::UnitTest(){
    assert(false== Sleeper::Type().isAc());
    assert("Sleeper" == Sleeper::Type().GetName());
    assert(false == Sleeper::Type().isLuxury());
    assert(false == Sleeper::Type().isSitting());
    assert(1.00 == Sleeper::Type().GetLoadFactor());
    assert(3 == Sleeper::Type().GetNumberOfTiers());

    //TESTING WITH GOLDEN OUTPUTS
    ifstream log("logs/Sleeper.log");
    if(log){
        stringstream expectedOut,out;
        expectedOut << log.rdbuf();
        out << Sleeper::Type();
        assert(out.str() == expectedOut.str());
    }else{
        cout << "LogFile: Sleeper.log Not Found";
        exit(1);
    }
}


int main(){
    
    ACChairCar::UnitTest(); 
    SecondSitting::UnitTest();
    ACFirstClass::UnitTest();
    AC2Tier::UnitTest();
    FirstClass::UnitTest();
    AC3Tier::UnitTest();
    Sleeper::UnitTest();

    return 0;
}
