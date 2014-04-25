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
	direction = glm::vec3();
	direction.x = (position.x - lookAt.x) / (position - lookAt).length();
	direction.y = (position.y - lookAt.y) / (position - lookAt).length();
	direction.z = (position.z - lookAt.z) / (position - lookAt).length();
	velocity = glm::vec3(0.1);
}

Camera::~Camera()
{
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
	setPosition(-velocity.x * direction.x + position.x,
		-velocity.y * direction.y + position.y,
		-velocity.z * direction.z + position.z);
	
	setLookAt(-velocity.x * direction.x + lookAt.x,
		-velocity.y * direction.y + lookAt.y,
		-velocity.z * direction.z + lookAt.z);
}
void Camera::backward()
{
	setPosition(velocity.x * direction.x + position.x,
		velocity.y * direction.y + position.y,
		velocity.z * direction.z + position.z);

	setLookAt(velocity.x * direction.x + lookAt.x,
		velocity.y * direction.y + lookAt.y,
		velocity.z * direction.z + lookAt.z);
}

void Camera::leftMove()
{
	setPosition(velocity.x * direction.x + position.x,
		velocity.y * direction.y + position.y,
		velocity.z * direction.z + position.z);

	setLookAt(velocity.x * direction.x + lookAt.x,
		velocity.y * direction.y + lookAt.y,
		velocity.z * direction.z + lookAt.z);
}

void Camera::rightMove()
{
	setPosition(velocity.x * direction.x + position.x,
		velocity.y * direction.y + position.y,
		velocity.z * direction.z + position.z);

	setLookAt(velocity.x * direction.x + lookAt.x,
		velocity.y * direction.y + lookAt.y,
		velocity.z * direction.z + lookAt.z);
}

void Camera::upMove()
{
	setPosition(position.x,
		velocity.y * 1.0 + position.y,
		position.z);

	setLookAt(lookAt.x,
		velocity.y * 1.0 + lookAt.y,
		lookAt.z);
}

void Camera::downMove()
{
	setPosition(position.x,
		velocity.y * -1.0 + position.y,
		position.z);

	setLookAt(lookAt.x,
		velocity.y * -1.0 + lookAt.y,
		lookAt.z);
}