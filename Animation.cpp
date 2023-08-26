#include "Animation.h"
using namespace sf;
Animation::Animation(Texture* texture, Vector2u imagecount, float switchtime) {
	this->imageCount = imagecount;
	this->switchtime = switchtime;
	totaltime = 0.0f;
	currentimage.x = 0;

	uvRect.width = texture->getSize().x / float(imagecount.x);
	uvRect.height = texture->getSize().x / float(imagecount.y);


}

Animation::~Animation() {}
void Animation::Update(int row, float deltatime, bool faceright) {
	currentimage.y = row;
	totaltime += deltatime;
	if (totaltime > switchtime) {
		totaltime -= switchtime;
		currentimage.x++;
		if (currentimage.x >= imageCount.x) { currentimage.x = 0; }

	}
	uvRect.left = currentimage.x * uvRect.width;
	uvRect.top = currentimage.y * uvRect.height;

	if (faceright) {
		uvRect.left = currentimage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}

	else { uvRect.left = (currentimage.x + 1) * abs(uvRect.width);
	uvRect.width = -abs(uvRect.width);
	}

}