#include "../include/Collision.h"
#include<algorithm>

bool CheckCollision(const Ball& ball, const Rectangle& rect
){
	Vec2 center{ ball.transform.position
	}; //the center of the ball because the position is top left and we add the radius to both x and y to get the center

	//findind the half of the rectangle's width and height to get the half extents
	Vec2 half_extents{ rect.transform.scale.x * 0.5f, rect.transform.scale.y * 0.5f };

	//finding the center of the rectangle by adding the half extents to the position of the rectangle
	Vec2 rectangle_center{ rect.transform.position };

	Vec2 difference = center - rectangle_center; //finding the difference between the center of the ball and the center of the rectangle

	//Vec2 clamped = { std::max(-half_extents.x, std::min(difference.x, half_extents.x)),
	//					std::max(-half_extents.y, std::min(difference.y, half_extents.y)) }; //clamping the difference to the half extents of the rectangle

	Vec2 clamped{
		std::clamp(difference.x,-half_extents.x,half_extents.x),
		std::clamp(difference.y,-half_extents.y,half_extents.y)
	};

	Vec2 closest =rectangle_center + clamped; //finding the closest point on the rectangle to the center of the ball

	Vec2 distance = closest - center; //finding the distance between the closest point and the center of the ball

	float distance_squared = 
	 distance.x * distance.x +
		distance.y * distance.y ; //finding the squared distance

	return distance_squared <= ball.radius * ball.radius; //checking if the squared distance is less than the squared radius of the ball, also touching is colliding
}