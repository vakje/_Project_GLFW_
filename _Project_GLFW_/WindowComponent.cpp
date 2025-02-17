#include "WindowComponent.h"
#include "Game.h"


GLFWwindow* Window::mywindow;

Game game;

void Window::SetWindow(int width, int height, const char* title)
{

	const int FramesPerSecond = 60;//cap for framerate
	const double FrameDelay = 1000.0 / FramesPerSecond;//making framedelay 


	if (!glfwInit())
		return;

	mywindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!mywindow)
	{
		glfwTerminate();
		return;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(mywindow);
	glfwSwapInterval(0);
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW initialization failed!" << std::endl;
		return;
	}
	int frames = 0;
	//before loop time 
	double lastTime = glfwGetTime() * 1000.0;//to make it in miliseconds

	//--------------------------------------------------------------
	game.Initilize();
	
	//--------------------------------------------------------------



	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(mywindow))
	{

		// putting seconds in milliseconds 
		// framestart before the loop
		double FrameStart = glfwGetTime() * 1000;
		/* Render here */

		
		game.Clear();

		/* Swap front and back buffers */


		game.MainCharacter();
		
       
		glfwSwapBuffers(mywindow);
		/* Poll for and process events */
		glfwPollEvents();
		//currenttime in the loop
		double currentTime = glfwGetTime() * 1000.0;
		//adding frames 
		frames++;

	
		

		//if the time in the loop - time before loop  is more than 1 miliseconds
		if (currentTime - lastTime >= 1000.0) // Print every second
		{
			//print out fps 
			std::cout << "FPS: " << frames << std::endl;
			//assigne to 0 to make it default again
			frames = 0;
			// and assingn to the timer before loop to update the value 
			lastTime = currentTime;
		}
		//end time in loop
		double FrameEndTime = glfwGetTime() * 1000.0;
		// elapsed time is the time which is subtraction of two times before and after window pops
		double elapsedTime = FrameEndTime - FrameStart;
		//if elapsedtime value is less than 16.67 re calculate it 
		while (elapsedTime < FrameDelay)
		{
			FrameEndTime = glfwGetTime() * 1000.0;//updating currenttime
			elapsedTime = FrameEndTime - FrameStart;//recalculate elapsed time
		}


	}

}
Window::~Window() {
	glfwDestroyWindow(mywindow);
	glfwTerminate();
}



