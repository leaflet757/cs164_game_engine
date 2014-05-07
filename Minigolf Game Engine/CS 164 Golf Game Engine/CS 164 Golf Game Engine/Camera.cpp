#include "Camera.h"


Camera::Camera(double eyex,
	double eyey,
	double eyez,
	double centerx,
	double centery,
	double centerz,
	double upx,
	double upy,
	double upz)
{
	position = glm::vec3(eyex, eyey, eyez);
	lookAt = glm::vec3(centerx, centery, centerz);
	up = glm::vec3(upx, upy, upz);
	directionF = glm::vec3();
	setDirectionF();
	directionS = glm::vec3();
	setDirectionS();
	directionU = glm::vec3();
	setDirectionU();

	velocity = glm::vec3(0.5);
}

Camera::~Camera()
{
}

void Camera::setDirectionF()
{
	directionF = position - lookAt;
	float length = sqrt(pow(directionF.x, 2) + pow(directionF.y, 2) + pow(directionF.z, 2));

	directionF = directionF / length;

	length = sqrt(pow(directionF.x, 2) + pow(directionF.y, 2) + pow(directionF.z, 2));
	std::cout << directionF.x << ", " << directionF.y << ", " << directionF.z << ", " << length << std::endl;
}

void Camera::setDirectionS()
{
	directionS.x = (directionF.y * up.z) - (directionF.z * up.y);
	directionS.y = -1 * ((directionF.x * up.z) - (directionF.z * up.x));
	directionS.z = (directionF.x - up.y) - (directionF.y * up.x);
	
	float length = sqrt(pow(directionS.x, 2) + pow(directionS.y, 2) + pow(directionS.z, 2));
	directionS = directionS / length;

	length = sqrt(pow(directionS.x, 2) + pow(directionS.y, 2) + pow(directionS.z, 2));
	std::cout << directionS.x << ", " << directionS.y << ", " << directionS.z << ", " << length << std::endl;
}

void Camera::setDirectionU()
{
	directionU.x = (directionS.y * directionF.z) - (directionS.z * directionF.y);
	directionU.y = -1 * ((directionS.x * directionF.z) - (directionS.z * directionF.x));
	directionU.z = (directionS.x * directionF.y) - (directionS.y * directionF.x);
	
	float length = sqrt(pow(directionU.x, 2) + pow(directionU.y, 2) + pow(directionU.z, 2));
	directionU = directionU / length;

	length = sqrt(pow(directionU.x, 2) + pow(directionU.y, 2) + pow(directionU.z, 2));
	std::cout << directionU.x << ", " << directionU.y << ", " << directionU.z << ", " << length << std::endl;
}

void Camera::update(float delta) const
{
	gluLookAt(position.x, position.y, position.z,
		lookAt.x, lookAt.y, lookAt.z,
		up.x, up.y, up.z);
}

void Camera::setLookAt(float x, float y, float z)
{
	lookAt.x = x;
	lookAt.y = y;
	lookAt.z = z;
}

void Camera::setUp(float x, float y, float z)
{
	up.x = x;
	up.y = y;
	up.z = z;
}

void Camera::setVelocity(float x, float y, float z)
{
	velocity.x = x;
	velocity.y = y;
	velocity.z = z;
}

void Camera::forward()
{
	setPosition(-directionF.x + position.x,
		-directionF.y + position.y,
		-directionF.z + position.z);

	setLookAt(-directionF.x + lookAt.x,
		-directionF.y + lookAt.y,
		-directionF.z + lookAt.z);
}
void Camera::backward()
{
	setPosition(directionF.x + position.x,
		directionF.y + position.y,
		directionF.z + position.z);

	setLookAt(directionF.x + lookAt.x,
		directionF.y + lookAt.y,
		directionF.z + lookAt.z);
}

void Camera::leftMove()
{
	setPosition(-directionS.x + position.x,
		-directionS.y + position.y,
		-directionS.z + position.z);

	setLookAt(-directionS.x + lookAt.x,
		-directionS.y + lookAt.y,
		-directionS.z + lookAt.z);
}

void Camera::rightMove()
{
	setPosition(directionS.x + position.x,
		directionS.y + position.y,
		directionS.z + position.z);

	setLookAt(directionS.x + lookAt.x,
		directionS.y + lookAt.y,
		directionS.z + lookAt.z);
}

void Camera::upMove()
{
	setPosition(directionU.x + position.x,
		directionU.y + position.y,
		directionU.z + position.z);

	setLookAt(directionU.x + lookAt.x,
		directionU.y + lookAt.y,
		directionU.z + lookAt.z);
}

void Camera::downMove()
{
	setPosition(directionU.x + position.x,
		directionU.y + position.y,
		directionU.z + position.z);

	setLookAt(directionU.x + lookAt.x,
		directionU.y + lookAt.y,
		directionU.z + lookAt.z);
}

void Camera::tilt(float angle, bool up, bool down, bool left, bool right)
{
	if (up)
	{
		rotateAboutCenter(lookAt.x, lookAt.y, lookAt.z, 
			position.x, position.y, position.z, 
			directionS.x, directionS.y, directionS.z, angle);
	}
	if (down)
	{
		rotateAboutCenter(lookAt.x, lookAt.y, lookAt.z, 
			position.x, position.y, position.z, 
			directionS.x, directionS.y, directionS.z, -angle);
	}
	if (left)
	{
		rotateAboutCenter(lookAt.x, lookAt.y, lookAt.z, 
			position.x, position.y, position.z, 
			directionU.x, directionU.y, directionU.z, -angle);
	}
	if (right)
	{
		rotateAboutCenter(lookAt.x, lookAt.y, lookAt.z, 
			position.x, position.y, position.z, 
			directionU.x, directionU.y, directionU.z, angle);
	}
	setDirectionF();
	setDirectionS();
	setDirectionU();
}

void Camera::rotateAboutCenter(float x, float y, float z, 
	float a, float b, float c, 
	float u, float v, float w, float theta)
{
	float cosT = cos(theta);
	float sinT = sin(theta);

	float u2 = pow(u, 2);
	float v2 = pow(v, 2);
	float w2 = pow(w, 2);

	float l2 = u2 + v2 + w2;
	float length = sqrt(l2);

	lookAt.x = a*(v2 + w2) + u*(-b*v - c*w + u*x + v*y + w*z)
		+ (-a*(v2 + w2) + u*(b*v + c*w - v*y - w*z) + (v2 + w2)*x)*cosT
		+ length*(-c*v + b*w - w*y + v*z)*sinT;
	lookAt.x = lookAt.x / l2;

	lookAt.y = b*(u2 + w2) + v*(-a*u - c*w + u*x + v*y + w*z)
		+ (-b*(u2 + w2) + v*(a*u + c*w - u*x - w*z) + (u2 + w2)*y)*cosT
		+ length*(c*u - a*w + w*x - u*z)*sinT;
	lookAt.y = lookAt.y / l2;

	lookAt.z = c*(u2 + v2) + w*(-a*u - b*v + u*x + v*y + w*z)
		+ (-c*(u2 + v2) + w*(a*u + b*v - u*x - v*y) + (u2 + v2)*z)*cosT
		+ length*(-b*u + a*v - v*x + u*y)*sinT;
	lookAt.z = lookAt.z / l2;

	// I DONT KNOW HOW TO MATH
}