#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation {
public:
	Animation(Texture* texture,Vector2u imagecount,float switchtime);
	~Animation();

	IntRect uvRect;
	Vector2u imageCount;
	Vector2u currentimage;
	float totaltime;
	float switchtime;
	void Update(int row, float deltatime,bool faceright);
	
	

};