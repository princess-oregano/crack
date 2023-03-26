#include "video.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

void
video()
{
        sf::RenderWindow window(sf::VideoMode(600, 475), "Cracked");

        sf::SoundBuffer buffer;
        buffer.loadFromFile("sans.wav");

        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.play();

        float progress_bar_length = 0;
        float progress_bar_y = 25;

        sf::Image Image;
        int n_frames = 179;
        int frame_counter = 0;
        char frame_name[30] = {};

        while (window.isOpen() && progress_bar_length < 4200) {
                sf::Event event;
                while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                                window.close();
                }

                sf::sleep(sf::seconds(0.1f));
                sf::RectangleShape progress_bar(sf::Vector2f(progress_bar_length / 7, progress_bar_y));

                progress_bar.setFillColor(sf::Color(0, 255, 38));
                window.draw(progress_bar);
                window.display();

                progress_bar_length += 10;

                sf::Texture texture;
                sprintf(frame_name, "gif/frame_%03d.gif", frame_counter);
                texture.loadFromFile(frame_name);

                sf::Sprite sprite(texture);
                sf::Vector2u size = texture.getSize();
                sprite.setOrigin(0, 0);
                sf::Vector2f increment(20.f, 20.f);
                window.draw(sprite);

                if (frame_counter < n_frames)
                        frame_counter++;
                else
                        frame_counter = 0;
        }
}
