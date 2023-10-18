#pragma once
#ifndef _COLLISION_DETECTION_H_
#define _COLLISION_DETECTION_H_

class CollisionDetection
{
public:
	CollisionDetection();
	~CollisionDetection();

	bool CheckCollision();
	bool CheckCollisionWithPlayer();
	bool CheckCollisionWithProjectile();

};
#endif // !_COLLISION_DETECTION_H_


