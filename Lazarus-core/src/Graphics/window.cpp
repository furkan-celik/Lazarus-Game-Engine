#include "window.h"

//Author: Furkan Celik Date: 20.12.2018

namespace Lazarus { namespace Graphics {
	Window::Window(const char* _windowName, int _width, int _height) {
		windowTitle = _windowName;
		height = _height;
		width = _width;
		if (!Init()) glfwTerminate(); //if initialization of window will fail for any cause, calling terminate function of glfw to terminate created window/s. Since there will be only one window runned at the same time, this will be anough

		for (int i = 0; i < MAX_KEYS; i++) { //initializing keys and mouseButtons arrays as well
			keys[i] = false;
		}
		for (int i = 0; i < MAX_MOUSEBUTTONS; i++) {
			mouseButtons[i] = false;
		}
	}

	Window::~Window() { //calling glfwTerminate function to terminate program since there will only be one window at the same time
		glfwTerminate();
	}

	void Window::Update() { //calling poolEvents and swapbuffers to keep frame updated
		glfwPollEvents(); //processes events on event queue, this will cause triggering callbacks since they are related with an event
		//glfwGetFramebufferSize(window, &width, &height);
		glfwSwapBuffers(window); //swaps front and back buffers, this method does not work with vulkan
	}

	bool Window::Init() {
		if (!glfwInit()) { //if there is some problem with glfw to run, error message will be logged and returning to false
			std::cout << "#Lazarus.Graphics.window Failed to Initialize window. glfwFail" << std::endl;
			return false;
		}
		window = glfwCreateWindow(width, height, windowTitle, nullptr, nullptr); //creating a glfw window with given width, height and title. Monitor and share filled with nullptr since scope of engine does not support multiple monitor and share stuff
		if (!window) { //if there is some problem with window creation, error message will be logged and returning to false
			std::cout << "#Lazarus.Graphics.window Failed to create GLFW window." << std::endl;
			return false;
		}

		glfwMakeContextCurrent(window); //makes window current context in running thread. Since our game will run single threaded making this is enough
		glfwSetWindowUserPointer(window, this); //setting this window element as a user pointer for window so we can reach this window class by reaching this user pointer
		glfwSetKeyCallback(window, key_callback); //subscribing key_callback function to keyCallback event
		glfwSetMouseButtonCallback(window, mouse_button_callback); //subscribing mouse_button_callback function to MouseButtonCallback event
		glfwSetCursorPosCallback(window, cursor_position_callback); //subscribing cursor_position_callback function to CursorPosCallback event
		glfwSetWindowSizeCallback(window, WindowResize); //subscribing WindowResize function to WindowSizeCallback event

		if (glewInit() != GLEW_OK) { //checking if glew initialized
			std::cout << "Could not initialize GLEW " << glewInit() << " Lazarus.Graphics" << std::endl;
			return false;
		}

		std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl; //printing opengl function as a log
		return true;
	}

	bool Window::Closed() const { //closing window by telling glfw
		return glfwWindowShouldClose(window) == 1;
	}

	void Window::Clear() const { //clearing buffer of glfw collor and depth buffer for clearing frame
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	//FREE FUNCTIONS
	void WindowResize(GLFWwindow *_window, int _width, int _height) { //changes viewport as new size variables of window
		glViewport(0, 0, _width, _height);
	}

	void key_callback(GLFWwindow * _window, int _key, int _scancode, int _action, int _mods) //changing pressed key's place in array to true if it is pressed
	{
		Window* win = (Window*)glfwGetWindowUserPointer(_window);
		win->keys[_key] = (_action != GLFW_RELEASE); //if action is not release, it must be pressed ot repeat, either way the key is pressed so instead of checking it is pressed checking it is not released will cover both press and repeat states
	}

	void mouse_button_callback(GLFWwindow * _window, int _button, int _action, int _mods) //same thing done for keyboard buttons to mouse buttons
	{
		Window* win = (Window*)glfwGetWindowUserPointer(_window);
		win->mouseButtons[_button] = (_action != GLFW_RELEASE);
	}

	void cursor_position_callback(GLFWwindow * _window, double _xpos, double _ypos) //changing mouseXPos and mouseYPos variables of window to new x and y pos of mouse
	{
		Window* win = (Window*)glfwGetWindowUserPointer(_window);
		win->mouseXPos = _xpos;
		win->mouseYPos = _ypos;
	}
} }