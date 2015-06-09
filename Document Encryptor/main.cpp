
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

#include "TextEncryptor.h"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 600), "Color Synthesizer", sf::Style::Close);
    
    TextEncryptor textEncryptor(window);
    
    // Start the game loop
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            
            // Checks if the mouse was moved, and lets textEncryptor handle the movement if so.
            if (event.type == sf::Event::MouseMoved)
                textEncryptor.checkButtons(event.mouseMove.x, event.mouseMove.y);
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window->close();
            
            // Backspace is pressed. If the user was typing a file location, deletes the newest string.
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace)
                textEncryptor.backspace();
            
            // If text was entered, and its unicode code is readable (not enter, delete, etc), launches typing method.
            if (event.type == sf::Event::TextEntered && event.text.unicode > 10)
                textEncryptor.handleTyping((char) event.text.unicode);
            
            // Checks if the mouse was clicked, and lets textEncryptor handle the action if so.
            if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                textEncryptor.handleEvents(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
        }
        
        
        // Clear screen
        window->clear(sf::Color::White);
        
        // Draw the sprites
        textEncryptor.drawObjects();
        
        // Update the window
        window->display();
    }
    
    // Deletes the render window memory from the heap and exits the window.
    delete window;
    return EXIT_SUCCESS;
}