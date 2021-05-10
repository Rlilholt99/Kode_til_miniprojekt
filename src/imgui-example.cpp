#include "imgui.h" // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h

#include "imgui-SFML.h" // for ImGui::SFML::* functions and SFML-specific overloads
#include <iostream>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Plant_Stats.hpp"




int main() {
    
    Plant_stats Plant;
    sf::RenderWindow window(sf::VideoMode(800, 400), "ImGui + SFML = <3", sf::Style::Titlebar | sf::Style::Close);

    
    
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    static bool tomatotown = false;
    static bool checkbox1 = false;
    static bool checkbox2 = false;
    int condition = 0;

    static float value1 = 3;
    static float value2 = 22;

    sf::Texture texture;

    if (!texture.loadFromFile("res/smovs.jpg"))
    {
        std::cout << "Load Failed \n";
        system("pause");
    }
    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    

    


    // sf::CircleShape shape(40.f);
    // shape.setFillColor(sf::Color::Green);

    // shape.setTexture(&texture);
    
    sf::Clock deltaClock;
    while (window.isOpen()) {


        sf::Event event;


        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        // ImGui::ShowDemoWindow();

        ImGui::Begin("Waddup we buildin some cool ass stuf come see eksdee");
    
        if (ImGui::Button("Select a pre-build setting"))
        {
            bool setting_chosen = 1;
            if (setting_chosen == 1)
            {
             ImGui::OpenPopup("Vindue 1");


            }
        }
        

        
        
        if (ImGui::BeginPopupModal("Vindue 1"))
        {
            if (ImGui::Button("The tomato program"))
                {
                    std::cout << "You have set the settings to The tomato program";
                    Plant.GetPlant1();
                    Plant.Print();
                    

                ImGui::CloseCurrentPopup();
                }
                
                if (ImGui::Button("The mint program"))
                {
                    Plant.GetPlant2();
                    Plant.Print();
                    ImGui::CloseCurrentPopup();
                }
                if (ImGui::Button("The micro green program"))
                {
                    Plant.GetPlant3();
                    Plant.Print();
                    ImGui::CloseCurrentPopup();
                }
                if (ImGui::Button("Actually never mind"))
                {
                    ImGui::CloseCurrentPopup();
                }
            ImGui::EndPopup();
        }

        
        
        if (ImGui::Button("Show the parameters of the greenhouse"))
        {
            bool show_parameters = 1;
            if (show_parameters == 1)
            {
                ImGui::OpenPopup("Parameters");
            }
            
        }
        if (ImGui::BeginPopupModal("Parameters"))
        {
        ImGui::Text("The light level is set to: %.2f ",Plant.ReturnLight());
        ImGui::Text("The temperature is set to: %.2f ",Plant.ReturnTemperature());
        ImGui::Text("The vapor level is set to: %.2f ",Plant.ReturnVapor());
        ImGui::Text("The carbon level is set to: %.2f ",Plant.ReturnCarbon());    
        ImGui::Text("The water phd level is set to: %.2f ",Plant.ReturnWater_PHD());
        ImGui::Text("The water nutrition level is set to: %.2f ",Plant.ReturnWater_nut());
        ImGui::Text("The power level is set to: %.2f ",Plant.ReturnPower());
        
            
            if (ImGui::Button("Thank you"))
            {
                ImGui::CloseCurrentPopup();
                
            }
            ImGui::EndPopup();
        }
        
        if (ImGui::Button("Set your own parameters"))
        {
            bool set_custom_parameters = 1;
            if (set_custom_parameters == 1)
            {
                ImGui::OpenPopup("Custom Parameters");
            }
            
        }
        if (ImGui::BeginPopupModal("Custom Parameters"))
        {
                //Indsæt funktioner der ænderer værdierne i vores class

            static float f1 = Plant.ReturnLight();
            ImGui::SliderFloat("The light level", &f1 , 0.0f, 210.0f, "antallet af bananer = %.3f");

            static float f2 = Plant.ReturnTemperature();
            ImGui::SliderFloat("The Temperature level", &f2 , 0.0f, 210.0f, "antallet af bananer = %.3f");

            static float f3 = Plant.ReturnVapor();
            ImGui::SliderFloat("The Vapor level", &f3 , 0.0f, 210.0f, "antallet af bananer = %.3f");

            static float f4 = Plant.ReturnCarbon();
            ImGui::SliderFloat("The Carbon level", &f4 , 0.0f, 210.0f, "antallet af bananer = %.3f");

            static float f5 = Plant.ReturnWater_PHD();
            ImGui::SliderFloat("The Water PHD level", &f5 , 0.0f, 210.0f, "antallet af bananer = %.3f");

            static float f6 = Plant.ReturnWater_nut();
            ImGui::SliderFloat("The Water Nutrients level", &f6 , 0.0f, 210.0f, "antallet af bananer = %.3f");

            static float f7 = Plant.ReturnPower();
            ImGui::SliderFloat("The Power level", &f7 , 0.0f, 210.0f, "antallet af bananer = %.3f");

            
            if (ImGui::Button("Thank you"))
            {
                Plant.CustomParametersSettings(f1,f2,f3,f4,f5,f6,f7);
                ImGui::CloseCurrentPopup();
                
            }
            ImGui::EndPopup();
        }
        
        // ImGui::InputText("string", buf, IM_ARRAYSIZE(buf));
        // ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
        
        // ImGui::End();
        // ImGui::Begin("Parameters");
        
        // ImGui::Text("The light level is set to: %.2f ",Plant.ReturnLight());
         // ImGui::Text("The temperature is set to: %.2f ",Plant.ReturnTemperature());
         // ImGui::Text("The vapor level is set to: %.2f ",Plant.ReturnVapor());
         // ImGui::Text("The carbon level is set to: %.2f ",Plant.ReturnCarbon());    
         // ImGui::Text("The water phd level is set to: %.2f ",Plant.ReturnWater_PHD());
         // ImGui::Text("The water nutrition level is set to: %.2f ",Plant.ReturnWater_nut());
         // ImGui::Text("The power level is set to: %.2f ",Plant.ReturnPower());
        
        if (ImGui::Button("Wipe out tomato town"))
        {
            tomatotown = true;
        }
        

        
        ImGui::End();

       
        

        
        

        window.clear(sf::Color(255,255,255));
        if (tomatotown == true)
        {
            window.draw(sprite);
        }
        
        
        // window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}