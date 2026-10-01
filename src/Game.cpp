
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window): window(game_window)
{
  srand(time(NULL)); //seeds random number generator with the current time
}

Game::~Game()
{

}

// We call this once after the game class is instantiated
bool Game::init()
{
  menu_title.setString("Whack-a-Mole");
  menu_option_play.setString("Play");
  menu_option_quit.setString("Quit");

  menu_title.setFillColor(sf::Color::Yellow);
  menu_option_play.setFillColor(sf::Color::Yellow);
  menu_option_quit.setFillColor(sf::Color::Yellow);

  menu_title.setPosition({ 10, 10 });
  menu_option_play.setPosition({ 10, 60 });
  menu_option_quit.setPosition({ 10, 110 });

  return true;
}

// Update runs after event polling and before rendering
// use it for everything that needs to update between frames
void Game::update(float dt)
{
	switch (current_gamestate)
	{
	case GameState::Menu:
		switch (selected_menu_option)
		{
			case MenuOption::Play:
				menu_option_play.setFillColor(sf::Color::Green);
				menu_option_quit.setFillColor(sf::Color::Yellow);
				break;
			case MenuOption::Quit:
				menu_option_play.setFillColor(sf::Color::Yellow);
				menu_option_quit.setFillColor(sf::Color::Green);
				break;
			default:
				menu_option_play.setFillColor(sf::Color::Yellow);
				menu_option_quit.setFillColor(sf::Color::Yellow);
				break;
		}
		break;
	case GameState::Playing:
		break;
	default:
		break;
	}
}

// Runs after update, use it to tell the window what to draw this frame
void Game::render()
{
	switch (current_gamestate)
	{
	case GameState::Menu:
		window.draw(menu_title);
		window.draw(menu_option_play);
		window.draw(menu_option_quit);
		break;
	case GameState::Playing:
		window.draw(background);
		break;
	default:
		break;
	}
}

//Called by event polling when a MouseButtonPressed event is found
void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	// Event contains mouse position and which button was clicked

	// Don't need to extract position to a variable like this, this is just to show you it's a Vector2i
	sf::Vector2i position = event->position;

	// You can tell which button was pressed by comparing it to SFML's definitions of mouse buttons
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was pressed
	}
}

//Called by event polling when a MouseButtonReleased event is found
void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	//Works the same as MouseButtonPressed
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was released
	}
}

// Called by event polling when a KeyPressed event is found
void Game::keyPressed(const sf::Event::KeyPressed* event)
{
	// You can tell which button was pressed by the scancode to SFML's definitions of keyboard keys
	switch (event->scancode)
	{
	case sf::Keyboard::Scancode::Q:
	case sf::Keyboard::Scancode::Backspace:
	case sf::Keyboard::Scancode::Escape:
		window.close();
		break;
	case sf::Keyboard::Scancode::Up:
	case sf::Keyboard::Scancode::W:
		if (current_gamestate == GameState::Menu)
		{
			selected_menu_option = MenuOption::Play;
		}
		break;
	case sf::Keyboard::Scancode::Down:
	case sf::Keyboard::Scancode::S:
		if (current_gamestate == GameState::Menu)
		{
			selected_menu_option = MenuOption::Quit;
		}
		break;
	case sf::Keyboard::Scancode::Enter:
	case sf::Keyboard::Scancode::Space:
		if (current_gamestate == GameState::Menu)
		{
			switch (selected_menu_option)
			{
			case MenuOption::Play:
				current_gamestate = GameState::Playing;
				break;
			case MenuOption::Quit:
				window.close();
				break;
			default:
				break;
			}
		}
		break;
	default:
		break;
	}

}

// Called by event polling when a KeyReleased event is found
void Game::keyReleased(const sf::Event::KeyReleased* event)
{
	// Works the same way as KeyPressed
	switch (event->scancode)
	{
	default:
		break;
	}

}


