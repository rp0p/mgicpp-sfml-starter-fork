#pragma once

#include <SFML/Graphics.hpp>

#include "enums/GameState.h"
#include "enums/MenuOption.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
  void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
  void keyPressed(const sf::Event::KeyPressed* event);
  void keyReleased(const sf::Event::KeyReleased* event);

 private:
  sf::RenderWindow& window;
  
  sf::Font font{ "./Data/Fonts/MxPlus_IBM_VGA_8x16.ttf" };
  sf::Text menu_title{ font };
  sf::Text menu_option_play{ font };
  sf::Text menu_option_quit{ font };

  sf::Texture background_texture{ "./Data/Images/WhackaMole Worksheet/background.png" };
  sf::Sprite background{ background_texture };

  sf::Texture bird_texture{ "./Data/Images/WhackaMole Worksheet/bird.png" };
  sf::Sprite bird{ bird_texture };

  GameState current_gamestate{ GameState::Menu };
  MenuOption selected_menu_option{ MenuOption::Play };
};
