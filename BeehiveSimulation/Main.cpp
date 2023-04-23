#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Audio.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include "Hive.h"
#include <random>
#include "bee.h"
#include "map.h"
#include "WorkerBee.h"
#include "QueenBee.h"
#include "Drone.h"
#include <filesystem>
#include <vector>
#include "BeeHiveSimulationUtils.h"




float randomFloat(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return static_cast<float>(dis(gen));

}


float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

int main()
{
    float result = lerp(1.0f, 2.0f, 0.5f);
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    std::vector<Bee> bees;
    bool dragging = false;
    sf::Vector2i lastMousePosition;
    sf::Vector2f mapPosition(0.0f, 0.0f);

    float deltaTime = 0.1f;
    float targetX = 100.0f;
    float targetY = 200.0f;
    float newX = 0;
    float newY = 0;
    float timer = 0;



    bool simulation_stopped_message_printed = false;

    bool simulation_started = false;
    int minflowernectar = 0;
    int maxflowernectar = 5;
    int startflowercount = 1;
    int beeactivity = 1;
    int enemyactivity = 1;
    int enemyspeed = 1;
    float Beespeed = 0.1;
    int flowerpermin = 1;

    for (Bee& bee : bees) {
        bee.updatePosition(deltaTime, targetX, targetY);
    }


    //to render the window and everything
    ImGui::CreateContext();
    sf::RenderWindow window1(sf::VideoMode::getDesktopMode(), "Simulation", sf::Style::Fullscreen);
    ImGui::SFML::Init(window1);
    WorkerBee beeInstance(0.0f, 0.0f, 0.0f, 0.0f);

    beeInstance.updatePosition(deltaTime, targetX, targetY);

    sf::Texture beeTexture;

    if (!beeTexture.loadFromFile("Bee.png")) {
        std::cout << "Failed to load bee textures";
    };

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("BeeSimulationBackground.jpg")) {
        std::cout << "Failed to load background textures";
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    sf::Sprite BeeSprite;
    BeeSprite.setTexture(beeTexture);


    sf::CircleShape circle1(100, 20);
    sf::Vector2i mousePosition; // Add this line before the while loop
    sf::View view(window1.getDefaultView());
    void updateBeePositionRelativeToBackground(sf::Sprite & BeeSprite, const sf::Sprite & backgroundSprite, const WorkerBee & beeInstance);
    {
        sf::Vector2f backgroundPosition = backgroundSprite.getPosition();
        BeeSprite.setPosition(backgroundPosition.x + beeInstance.getX(), backgroundPosition.y + beeInstance.getY());
    }
    sf::Clock deltaClock;
    while (window1.isOpen())
    {
        // Process events
        sf::Event event;
        while (window1.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window1, event);
            {
                if (event.type == sf::Event::Closed) {
                    window1.close();
                }
                
                // Handle mouse events only if ImGui window is not hovered
                if (!ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow))
                {
                    // Handle mouse button press
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window1);
                        if (backgroundSprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                        {
                            dragging = true;
                            lastMousePosition = mousePosition;
                        }
                    }
                    // Handle mouse button release
                    else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                    {
                        dragging = false;
                    }
                    // Handle mouse movement
                    else if (event.type == sf::Event::MouseMoved && dragging)
                    {
                        sf::Vector2i currentMousePosition = sf::Mouse::getPosition(window1);
                        sf::Vector2i deltaMouse = currentMousePosition - lastMousePosition;
                        view.move(-deltaMouse.x, -deltaMouse.y);
                        window1.setView(view);
                        lastMousePosition = currentMousePosition;

                        // Move the background sprite
                        backgroundSprite.move(-deltaMouse.x, -deltaMouse.y);

                        // Update the bee's position relative to the background sprite
                        updateBeePositionRelativeToBackground(BeeSprite, backgroundSprite, beeInstance);
                    }
                }
            }

        }



        ImGui::SFML::Update(window1, deltaClock.restart());
        
        
        ImGui::NewFrame();



        

        //to make the actual gui
        ImGui::Begin("Hello, world");
        ImGui::Text("Hello, Select your paramaters,");
        ImGui::Text("then launch the simulation.");
        if (ImGui::Button("Exit")) {
            window1.close();
        }
        ImGui::End();


        ImGui::Begin("Simulation Panel");

        ImGui::Text("Starting Paramaters");

        ImGui::SliderInt("Starting bee activity ", &beeactivity, 1, 10);

        ImGui::SliderInt("Starting enemy activity", &enemyactivity, 1, 10);

        ImGui::SliderInt("Flower count on start", &startflowercount, 1, 10);

        ImGui::SliderInt("Min Flower Nectar", &minflowernectar, 0, 5);

        ImGui::SliderInt("Max Flower Nectar", &maxflowernectar, 10, 1000);

        ImGui::SliderInt("Flower nectar rate / min", &flowerpermin, 1, 100);

        int BeespeedInt = static_cast<int>(Beespeed * 100);
        ImGui::SliderInt("Bee speed", &BeespeedInt, 1, 300);

        Beespeed = static_cast<float>(BeespeedInt) / 100.0f;



        ImGui::SliderInt("Enemy speed", &enemyspeed, 1, 10);

        if (ImGui::Button("Start Simulation")) {
            simulation_started = true;
            simulation_stopped_message_printed = false;
            sf::Vector2u windowSize = window1.getSize();
            BeeSprite.setPosition(static_cast<float>(windowSize.x) / 2, static_cast<float>(windowSize.y) / 2);
            float deltaTime = deltaClock.restart().asSeconds(); // Calculate deltaTime
            beeInstance.updatePosition(deltaTime, targetX, targetY);
        }


        if (ImGui::Button("Stop Simulation")) {
            simulation_started = false;
        }
        ImGui::End();






        ImGui::Begin("Bee Console");
        ImGui::Text("Bee position: (%.2f, %.2f)", beeInstance.getX(), beeInstance.getY());
        ImGui::End();


        sf::FloatRect backgroundBounds = backgroundSprite.getGlobalBounds();

        if (simulation_started) {
            timer += deltaTime;
            const float targetUpdateTime = 1.0f; // Adjust this value for the desired update frequency

            if (timer >= targetUpdateTime) {
                newX = beeInstance.getX() + randomFloat(-50, 50);
                newY = beeInstance.getY() + randomFloat(-50, 50);
                timer = 0;
            }

            float t = deltaTime * Beespeed;
            float interpolatedX = lerp(beeInstance.getX(), newX, t);
            float interpolatedY = lerp(beeInstance.getY(), newY, t);
            beeInstance.updatePosition(deltaTime, interpolatedX, interpolatedY); // Updated function call
            BeeSprite.setPosition(interpolatedX, interpolatedY);

            // Print bee's position to the ImGui console window
            sf::Vector2f movementVector(interpolatedX - BeeSprite.getPosition().x, interpolatedY - BeeSprite.getPosition().y);
            sf::Vector2f newPosition = BeeSprite.getPosition() + movementVector;

            if (backgroundBounds.contains(newPosition.x, newPosition.y))
            {
                beeInstance.updatePosition(deltaTime, interpolatedX, interpolatedY);
                BeeSprite.setPosition(interpolatedX, interpolatedY);
            }

        }
    }




    if (!simulation_started && !simulation_stopped_message_printed) {
        std::cout << "Simulation stopped\n";
        std::cout << "To start it again click start simulation\n";
        simulation_stopped_message_printed = true;
    }


    {
        sf::View view = window1.getDefaultView();
        window1.setView(view);
        backgroundSprite.setPosition(mapPosition);
        sf::FloatRect backgroundBounds = backgroundSprite.getGlobalBounds();






        //render and display everything
        //window1.setVerticalSyncEnabled(true);
        window1.clear(sf::Color(135, 206, 235));

        window1.draw(backgroundSprite);
        window1.draw(BeeSprite);
        updateBeePositionRelativeToBackground(BeeSprite, backgroundSprite, beeInstance);
        
        ImGui::SFML::Render(window1);

        window1.display();


    }
     
    
        //exit when program closed



        ImGui::SFML::Shutdown();


        return EXIT_SUCCESS;

}



