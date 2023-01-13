#pragma once
#include<iostream>
#include<vector>
#include<list>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Animator
{

public:
	
	struct Animation
	{
		std::string m_Name;
		std::string m_TextureName;
		std::vector<sf::IntRect> m_Frames;
		sf::Time m_Duration;
		bool m_Looping;

		Animation(std::string const& name, std::string const& textureName,
			sf::Time const& duration, bool looping) :m_Name(name), m_TextureName(textureName),
			m_Duration(duration), m_Looping(looping)
		{}

		// Добавляем кадры по горизонтали
		void AddFrames(sf::Vector2i const& startFrom,
			sf::Vector2i const& frameSize, unsigned int frames, unsigned int traccia)
		{
			sf::Vector2i  current = startFrom;
			for (unsigned int t = 0; t < traccia; t++) {

            
			for (unsigned int i = 0; i < frames; i++)
			{
				// добавить положение и размер текущего кадра
				m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
				// двигать текущий кадр по горизонтали 
				current.x += frameSize.x;
			}
			current.y += frameSize.y;
			current.x = startFrom.x;
			}
		}
	};

	Animator(sf::Sprite & sprite);

	Animator::Animation& CreateAnimation(std::string const& name,
		std::string const& textureName, sf::Time const& duration, bool loop = false
	);

	void Update(sf::Time const& dt);

	// вернуть истина, если переключение прошло успешно
	bool SwitchAnimation(std::string const& name);

	std::string GetCurrentAnimationName() const;

private:

	// введите имя анимации
	// возвращает nullptr, если такая анимация не найдена
	Animator::Animation* FindAnimation(std::string const& name);

	void SwitchAnimation(Animator::Animation* animation);

	//ссылка на спрайт
	sf::Sprite& m_Sprite;
	AssetManager manager;
	sf::Time m_CurrentTime;
	std::list<Animator::Animation> m_Animations;
	Animator::Animation* m_CurrentAnimation;

};

