#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
namespace Collision {
	
	bool PixelPerfectTest(const Sprite& Object1, const Sprite& Object2, Uint8 AlphaLimit = 0);
	bool CreateTextureAndBitmask(Texture& LoadInto, const string& Filename);
	bool CircleTest(const Sprite& Object1, const Sprite& Object2);
	bool BoundingBoxTest(const Sprite& Object1, const Sprite& Object2);
}

#endif