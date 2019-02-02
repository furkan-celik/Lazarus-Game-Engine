#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Math/Vectors.h"
#include <iostream>

#define MAX_KEYS 1024 //maximum keyboard keys avaliable
#define MAX_MOUSEBUTTONS 32 //maximum mouse buttons avaliable

//Author: Furkan Celik Date: 20.12.2018

namespace Lazarus { namespace Graphics {
	class Window { //class window will handle events of a window can do. This class designed like game always runs single window
	public:
		//Functions
		Window(const char* _windowTitle, int _width, int _height);
		~Window();
		void Update(); //updates frame in window
		bool Closed() const; //for handling closing window by pressing X button on right up
		void Clear() const; //for clearing buffer
		inline int			GetWidth() const { return width; } //used inline to save from overheads. Simply returns width private variable. There is no set method for width
		inline int			GetHeight() const { return height; } //used inline to save from overheads. Simply returns height private variable. There is no set method for height
		inline bool			isKeyPressed(unsigned int _keyCode) const { return _keyCode < MAX_KEYS && keys[_keyCode]; } //returns if given keyCode of keyboard button is pressed or not
		inline bool			isMouseButtonPressed(unsigned int _keyCode) const { return _keyCode < MAX_MOUSEBUTTONS && mouseButtons[_keyCode]; } //returns if given keycode of mouse button is pressed or not
		inline double		GetMouseXPos() const { return mouseXPos; } //returns x position of mouse in case of keeping older versions of functions on run
		inline double		GetMouseYPos() const { return mouseYPos; } //returns y position of mouse in case of keeping older versions of functions on run
		inline void			GetMousePosVec(double &x, double &y) const { x = mouseXPos, y = mouseYPos; } //returns mouse position with referencing x and y
		inline Math::Vec2d  GetMousePosVec2d() const { return Math::Vec2d(mouseXPos, mouseYPos); } //returns mouse position as a Vec2d. Can cause using more memory, so not recommended to use.

		//Variables
	private:
		//functions
		bool Init(); //for initializing window properties and required callbacks

		//statics

		//variables
		int width, height;
		const char* windowTitle;
		GLFWwindow *window;

		//statics
		bool keys[MAX_KEYS]; //keeping track of pressed keyboard buttons. On press, index of keyCode will be true
		bool mouseButtons[MAX_MOUSEBUTTONS]; //keeping track of pressed mouse buttons. On press, index of keyCode will be true
		double mouseXPos, mouseYPos;

		friend static void key_callback(GLFWwindow * _window, int _key, int _scancode, int _action, int _mods); //friend function to handle key pressed event. Not member because glfw will call function directly, without pointing to window object
		friend static void mouse_button_callback(GLFWwindow* _window, int _button, int _action, int _mods); //friend function to handle mouse button pressed event. Not member because glfw will call function directly, without pointing to window object
		friend static void cursor_position_callback(GLFWwindow * _window, double _xpos, double _ypos); //friend function to handle cursor position changed event. Not member because glfw will call function directly, without pointing to window object
	};

	void WindowResize(GLFWwindow *_window, int _width, int _height); //for allowing resizing valid. With using resize callback, scaling up and down will affect frame as well
} }