#include "Camera.h"



Camera::Camera()
{
	m_FOV = 75.0 * PI / 180.0;
	m_AspectRatio = Width / Height;
	m_NearPlane = 0.1f;
	m_FarPlane = 100.0f;
	m_Speed = 10.00;
	m_Instance = Matrix<float>(4, 4, 1.0f);
	m_CameraPosition = Vector3F<float>(4.0f, 3.0f, 4.0f);
	m_CameraTarget += Vector3F<float>(0.0f, 0.0f, -1.0f);
	m_CameraUp = Vector3F<float>(0.0f, 4.0f, 0.0f);
	
	
	
}

double Camera::getFov() const
{
	return m_FOV;
}

float Camera::getAspectRatio() const
{
	return m_AspectRatio;
}

float Camera::getNearPlane() const
{
	return m_NearPlane;
}

float Camera::getFarPlane() const
{
	return  m_FarPlane;
}

double Camera::getSpeed() const
{
	return m_Speed;
}

Vector3F<float>& Camera::getCameraPosition() 
{
	return m_CameraPosition;
}

Vector3F<float> Camera::getCameraTarget() const
{
	
	return m_CameraTarget;
}

Vector3F<float> Camera::getCameraUp() const
{
	return m_CameraUp;
}

Matrix<float> Camera::getLookat(const Vector3F<float>& CameraP, const Vector3F<float>& CameraT, const Vector3F<float>& CameraU) 
{
	
	return m_Instance.LookOfCamera(CameraP, CameraT, CameraU);
}

Matrix<float> Camera::getProjection(const double& fov,const float& aspectRatio, const float& nearplane, const float& farplane)
{
	return m_Instance.Projection(fov,aspectRatio,nearplane,farplane);
}

void Camera::InputValidation()
{
	//to process cameramovement in time
	float deltatime = 0.0f;
	float lastframe = 0.0f;
	float currentframe = glfwGetTime();
	deltatime = currentframe - lastframe;
	lastframe = currentframe;
	m_Speed = 0.005f* deltatime;
 
	if (Input::getKey(GLFW_KEY_W)) 
	{
		
		m_CameraPosition += m_CameraTarget * m_Speed;
		std::cout << "deltatime" << deltatime << "\n";
		std::cout << "CameraPosition: " << m_CameraPosition << "\n";
		std::cout << "W was pressed" << "\n";
	}
	if (Input::getKey(GLFW_KEY_S))
	{
		m_CameraPosition -= m_CameraTarget * m_Speed;
		std::cout << "deltatime" << deltatime << "\n";
		std::cout << "Cameraposition" << m_CameraPosition;
		std::cout << "S was pressed" << "\n";
	}
	if (Input::getKey(GLFW_KEY_A))
	{
		m_CameraPosition -= (m_CameraTarget.Crossproduct(m_CameraUp)).Normalize3d() * m_Speed;
		std::cout << "Cameraposition" << m_CameraPosition;
		std::cout << "A was pressed" << "\n";
	}
	if (Input::getKey(GLFW_KEY_D))
	{
		m_CameraPosition += (m_CameraTarget.Crossproduct(m_CameraUp)).Normalize3d() * m_Speed;
		std::cout << "Cameraposition" << m_CameraPosition;
		std::cout << "D was pressed" << "\n";
	}
}


