#pragma once
#include <iostream>
#include <string>

class Plant_stats
{
    
public:
   void GetPlant1();
   void GetPlant2();
   void GetPlant3();
   void GetPlant4();
   void Print();

   float ReturnTemperature(){return Temperature; };
   float ReturnVapor(){return Vapor; };
    float ReturnCarbon(){return Carbon; };
    float ReturnWater_PHD(){return Water_PHD; };
    float ReturnWater_nut(){return Water_nut; };
    float ReturnPower(){return power; };
    float ReturnLight(){return Light; };
    void CustomParametersSettings(float x, float y, float z, float a, float b, float c, float d);
    
private:
    
    std::string Name = "unknown";
    float Temperature = 0;
    float Vapor = 0;
    float Carbon = 0;
    float Water_PHD = 0;
    float Water_nut = 0;
    float power = 0;
    float Light = 0;

};

void Plant_stats::GetPlant1(){

    Name = "Tomato";
    Light = 1;
    Temperature = 1;
    Vapor = 1;
    Carbon = 1;
    Water_PHD = 1;
    Water_nut = 1;
    power = 1;

    return;

};

void Plant_stats::GetPlant2()
{
    Name = "Mint";
    Light = 2;
    Temperature = 2;
    Vapor = 2;
    Carbon = 2;
    Water_PHD = 2;
    Water_nut = 2;
    power = 2;

    return;

};

void Plant_stats::GetPlant3(){

    Name = "micro greens";
    Light = 3;
    Temperature = 3;
    Vapor = 3;
    Carbon = 3;
    Water_PHD = 3;
    Water_nut = 3;
    power = 3;

    return;
};

void Plant_stats::GetPlant4(){
    
    Name = "dadi whanted 4 options";
    Light = 4;
    Temperature = 4;
    Vapor = 4;
    Carbon = 4;
    Water_PHD = 4;
    Water_nut = 4;
    power = 4;

    return;
};

void Plant_stats::Print(){
    
    std::cout << Name << std::endl;
    std::cout << Light << std::endl;
    std::cout << Temperature << std::endl;
    std::cout << Vapor << std::endl;
    std::cout << Carbon << std::endl;
    std::cout << Water_PHD << std::endl;
    std::cout << Water_nut << std::endl;
    std::cout << power << std::endl;

    return;



}
void Plant_stats::CustomParametersSettings(float x,float y,float z, float a, float b,float c,float d)
{
    Light = x;
    Temperature = y;
    Vapor = z;
    Carbon = a;
    Water_PHD = b;
    Water_nut = c;
    power = d;

    return;

}