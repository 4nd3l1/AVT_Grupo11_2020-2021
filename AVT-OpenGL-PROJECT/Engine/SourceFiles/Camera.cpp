#include "../HeaderFiles/Camera.h"
# define PI atan(1)*4

Camera::Camera(Vector3D eye, Vector3D center, Vector3D up)
{
	Vector3D cent_eye = center - eye;
	cent_eye.normalize();
	cameraDirection = cent_eye;

	// Set initial pitch and yaw

	// cameraDirection.Y = sinPitch => pitch = aSin(cameraDirection.Y)
	pitch = asin(cameraDirection.getY());

	// cameraDirection.X = cosYaw * cosPitch => cosYaw = cameraDirection.X/cosPitch => Yaw = aCos(cameraDirection.X/cosPitch)
	yaw = acos(cameraDirection.getX() / cos(pitch));

	if (eye.getZ() < 0 && yaw > 0) {
		yaw = -yaw;
	}

	initialEye = eye;
	initialCenter = center;
	initialUp = up;

	setViewMatrix(eye, eye + cameraDirection, up);
}

Camera::~Camera()
{
}


void Camera::setViewMatrix(Vector3D eye, Vector3D center, Vector3D up)
{
	cameraEye = eye;
	cameraCenter = center;
	cameraUp = up;

	Vector3D cent_eye = center - eye;
	cent_eye.normalize();
	cameraDirection = cent_eye;

	Vector3D v = cent_eye; // CameraDirection

	Vector3D s = v.cross(up); // CameraRight
	s.normalize();

	Vector3D u = s.cross(v); // CameraUp

	Matrix4D axis(new float[4][4]{
			{  s.getX(),  s.getY(),	 s.getZ(), 0},
			{  u.getX(),  u.getY(),	 u.getZ(), 0},
			{ -v.getX(), -v.getY(), -v.getZ(), 0},
			{ 0,         0,		    0,        1}
		});

	Matrix4D trans(new float[4][4]{
			{ 1, 0, 0, -eye.getX()},
			{ 0, 1, 0, -eye.getY()},
			{ 0, 0, 1, -eye.getZ()},
			{ 0, 0, 0,	1		  }
		});

	view = axis * trans;
}

void Camera::setOrthoProjectionMatrix(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
{
	orthoProj = Matrix4D(new float[4][4]{
		{2 / (right - left), 0                 , 0               , (left + right) / (left - right)},
		{0                 , 2 / (top - bottom), 0               , (bottom + top) / (bottom - top)},
		{0                 , 0                 , 2 / (near - far), (near + far) / (near - far)},
		{0                 , 0                 , 0               , 1},
		}
	);
}

void Camera::setPrespProjectionMatrix(GLfloat fovy, GLfloat aspect, GLfloat nearZ, GLfloat farZ)
{
	GLfloat ang_rad = (fovy / 2.0f) * (float)PI / 180.0f;
	GLfloat d = 1 / tan(ang_rad);

	perspProj = Matrix4D(new float[4][4]{
			{(d / aspect), 0,  0                                , 0                                  },
			{0           , d,  0                                , 0                                  },
			{0           , 0,  ((nearZ + farZ) / (nearZ - farZ)), 2 * (nearZ * farZ) / (nearZ - farZ)},
			{0           , 0, -1                                , 0                                  }
		}
	);
}

void Camera::setDirection(float xOffset, float yOffset)
{
	// Convert degrees to radians
	xOffset = xOffset * (float)PI / 180.0f;
	yOffset = yOffset * (float)PI / 180.0f;

	yaw -= xOffset;
	pitch += yOffset;
	 
	float cosYaw = cos(yaw);
	float cosPitch = cos(pitch);
	float sinPitch = sin(pitch);
	float sinYaw = sin(yaw);

	cameraDirection.setX(cosYaw * cosPitch);
	cameraDirection.setY(sinPitch);
	cameraDirection.setZ(-sinYaw * cosPitch);

	cameraDirection.normalize();
}


 Matrix4D Camera::getViewMatrix() {
	return view;
}

 Matrix4D Camera::getOrthProj() {
	return orthoProj;
}

Matrix4D Camera::getPerspProj() {
	return perspProj;
}

void Camera::moveCameraForward(float speed) {
	cameraEye += speed * cameraDirection;
	setViewMatrix(cameraEye, cameraEye + cameraDirection, cameraUp);
}

void Camera::moveCameraBackward(float speed) {
	cameraEye -= speed * cameraDirection;
	setViewMatrix(cameraEye, cameraEye + cameraDirection, cameraUp);
}

void Camera::moveCameraLeft(float speed) {
	Vector3D vec2 = cameraDirection.cross(cameraUp);
	vec2.normalize();
	cameraEye -= vec2 * speed;
	setViewMatrix(cameraEye, cameraEye + cameraDirection, cameraUp);
}

void Camera::moveCameraRight(float speed) {
	Vector3D vec3 = cameraDirection.cross(cameraUp);
	vec3.normalize();
	cameraEye += vec3 * speed;
	setViewMatrix(cameraEye, cameraEye + cameraDirection, cameraUp);
}

void Camera::moveCameraUp(float speed) {
	cameraEye += speed * cameraUp;
	setViewMatrix(cameraEye, cameraEye + cameraDirection, cameraUp);
}

void Camera::moveCameraDown(float speed) {
	cameraEye -= speed * cameraUp;
	setViewMatrix(cameraEye, cameraEye + cameraDirection, cameraUp);
}


void Camera::rotateCamera(float xOffset, float yOffset, float sensitivity)
{
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	setDirection(xOffset, yOffset);
	setViewMatrix(cameraEye, cameraEye + cameraDirection, cameraUp);
}

void Camera::invertCamera()
{
	cameraEye = -cameraEye;

	cameraDirection = -cameraDirection;

	// Set initial pitch and yaw

	// cameraDirection.Y = sinPitch => pitch = aSin(cameraDirection.Y)
	pitch = asin(cameraDirection.getY());

	// cameraDirection.X = cosYaw * cosPitch => cosYaw = cameraDirection.X/cosPitch => Yaw = aCos(cameraDirection.X/cosPitch)
	yaw = acos(cameraDirection.getX() / cos(pitch));

	if (cameraEye.getZ() < 0 && yaw > 0) {
		yaw = -yaw;
	}

	setViewMatrix(cameraEye, cameraEye + cameraDirection, cameraUp);
}

void Camera::resetCamera()
{
	Vector3D vec = initialCenter - initialEye;
	vec.normalize();
	cameraDirection = vec;

	// Set initial pitch and yaw

	// cameraDirection.Y = sinPitch => pitch = aSin(cameraDirection.Y)
	pitch = asin(cameraDirection.getY());

	// cameraDirection.X = cosYaw * cosPitch => cosYaw = cameraDirection.X/cosPitch => Yaw = aCos(cameraDirection.X/cosPitch)
	yaw = acos(cameraDirection.getX() / cos(pitch));

	if (initialEye.getZ() < 0 && yaw > 0) {
		yaw = -yaw;
	}

	setViewMatrix(initialEye, initialEye + cameraDirection, initialUp);
}

void Camera::rotateCameraAround(float rotationDegree, Vector4D axis_i, Vector3D point)
{
	
	float rotationRads = rotationDegree * PI / 180.0f;

	Vector3D neg = -point;
	Vector4D standIn = Vector4D(cameraEye.getX(), cameraEye.getY(), cameraEye.getZ(), 0.0f);;
	standIn = Matrix4D::translation(neg) * standIn;
	if (axis_i == Vector4D(1.0f, 0.0f, 0.0f, 1.0f)) {
		standIn = Matrix4D::rotationX(rotationRads) * standIn;
	}
	else if (axis_i == Vector4D(0.0f, 1.0f, 0.0f, 1.0f)) {
		standIn = Matrix4D::rotationY(rotationRads) * standIn;
	}
	else if (axis_i == Vector4D(0.0f, 0.0f, 0.0f, 1.0f)) {
		standIn = Matrix4D::rotationZ(rotationRads) * standIn;
	}
	standIn = Matrix4D::translation(point) * standIn;

	cameraEye = Vector3D(standIn.getX(), standIn.getY(), standIn.getZ());

	// Set direction to look at point
	Vector3D dir = point - cameraEye;
	dir.normalize();
	cameraDirection = dir;


	// cameraDirection.Y = sinPitch => pitch = aSin(cameraDirection.Y)
	pitch = asin(cameraDirection.getY());

	// cameraDirection.X = cosYaw * cosPitch => cosYaw = cameraDirection.X/cosPitch => Yaw = aCos(cameraDirection.X/cosPitch)
	yaw = acos(cameraDirection.getX() / cos(pitch));

	if (cameraEye.getZ() < 0 && yaw > 0) {
		yaw = -yaw;
	}


	setViewMatrix(cameraEye, cameraEye + cameraDirection, cameraUp);
}

void Camera::rotateCameraAroundQuaternion(float rotationDegree, Vector4D axis_i, Vector3D point)
{
	float thetai = 45.0f;
	Quaternion qtr(rotationDegree, axis_i);

	Vector4D vec4(cameraEye.getX(), cameraEye.getY(), cameraEye.getZ(), 1.0f);
	Vector4D rot = qtr.GLRotationMatrix() * vec4;
	Vector3D eye_rot(rot.getX(), rot.getY(), rot.getZ());

	cameraEye = eye_rot;

	// Set direction to look at point
	Vector3D dir = point - cameraEye;
	dir.normalize();
	cameraDirection = dir;


	// cameraDirection.Y = sinPitch => pitch = aSin(cameraDirection.Y)
	pitch = asin(cameraDirection.getY());

	// cameraDirection.X = cosYaw * cosPitch => cosYaw = cameraDirection.X/cosPitch => Yaw = aCos(cameraDirection.X/cosPitch)
	yaw = acos(cameraDirection.getX() / cos(pitch));

	if (cameraEye.getZ() < 0 && yaw > 0) {
		yaw = -yaw;
	}

	setViewMatrix(cameraEye, cameraEye + cameraDirection, cameraUp);
}


