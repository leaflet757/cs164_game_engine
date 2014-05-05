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
	this->up = glm::vec3(upx, upy, upz);
	directionF = glm::vec3();
	directionF.x = (position.x - lookAt.x) / (position - lookAt).length();
	directionF.y = (position.y - lookAt.y) / (position - lookAt).length();
	directionF.z = (position.z - lookAt.z) / (position - lookAt).length();
	directionS = glm::vec3();
	setDirectionS(directionS);
	directionU = glm::vec3();
	setDirectionU(directionU);

	velocity = glm::vec3(0.1);
	velocity.z = 0.3;
	velocity.y = 0.3;
}

Camera::~Camera()
{
}

void Camera::setDirectionS(glm::vec3& s)
{
	s.x = (directionF.y * up.z) - (directionF.z * up.y);
	s.y = -1 * (directionF.x * up.z) - (directionF.z * up.x);
	s.z = (directionF.x - up.y) - (directionF.y * up.x);
	s.x = s.x / s.length();
	s.y = s.y / s.length();
	s.z = s.z / s.length();
}

void Camera::setDirectionU(glm::vec3& u)
{
	u.x = (directionS.y * directionF.z) - (directionS.z * directionF.y);
	u.y = -1 * ((directionS.x * directionF.z) - (directionS.z * directionF.x));
	u.z = (directionS.x * directionF.y) - (directionS.y * directionF.x);
	u.x = u.x / u.length();
	u.y = u.y / u.length();
	u.z = u.z / u.length();
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
	setPosition(-velocity.x * directionF.x + position.x,
		-velocity.y * directionF.y + position.y,
		-velocity.z * directionF.z + position.z);
	
	setLookAt(-velocity.x * directionF.x + lookAt.x,
		-velocity.y * directionF.y + lookAt.y,
		-velocity.z * directionF.z + lookAt.z);
}
void Camera::backward()
{
	setPosition(velocity.x * directionF.x + position.x,
		velocity.y * directionF.y + position.y,
		velocity.z * directionF.z + position.z);

	setLookAt(velocity.x * directionF.x + lookAt.x,
		velocity.y * directionF.y + lookAt.y,
		velocity.z * directionF.z + lookAt.z);
}

void Camera::leftMove()
{
	setPosition(velocity.x * directionS.x + position.x,
		velocity.y * directionS.y + position.y,
		velocity.z * directionS.z + position.z);

	setLookAt(velocity.x * directionS.x + lookAt.x,
		velocity.y * directionS.y + lookAt.y,
		velocity.z * directionS.z + lookAt.z);
}

void Camera::rightMove()
{
	setPosition(-velocity.x * directionS.x + position.x,
		-velocity.y * directionS.y + position.y,
		-velocity.z * directionS.z + position.z);

	setLookAt(-velocity.x * directionS.x + lookAt.x,
		-velocity.y * directionS.y + lookAt.y,
		-velocity.z * directionS.z + lookAt.z);
}

void Camera::upMove()
{
	setPosition(-velocity.x * directionU.x + position.x,
		-velocity.y * directionU.y + position.y,
		-velocity.z * directionU.z + position.z);

	setLookAt(-velocity.x * directionU.x + lookAt.x,
		-velocity.y * directionU.y + lookAt.y,
		-velocity.z * directionU.z + lookAt.z);
}

void Camera::downMove()
{
	setPosition(velocity.x * directionU.x + position.x,
		velocity.y * directionU.y + position.y,
		velocity.z * directionU.z + position.z);

	setLookAt(velocity.x * directionU.x + lookAt.x,
		velocity.y * directionU.y + lookAt.y,
		velocity.z * directionU.z + lookAt.z);
}

void Camera::tilt(float amount, bool up, bool down, bool left, bool right)
{
	if (up)
	{
		setLookAt(lookAt.x - amount * directionU.x, lookAt.y - amount * directionU.y, lookAt.z - amount * directionU.z);
	}
	if (down)
	{
		setLookAt(lookAt.x + amount * directionU.x, lookAt.y + amount * directionU.y, lookAt.z + amount * directionU.z);
	}
	if (left)
	{
		setLookAt(lookAt.x - amount * directionS.x, lookAt.y - amount * directionS.y, lookAt.z - amount * directionS.z);
	}
	if (right)
	{
		setLookAt(lookAt.x + amount * directionS.x, lookAt.y + amount * directionS.y, lookAt.z + amount * directionS.z);
	}
}