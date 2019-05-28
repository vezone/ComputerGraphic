#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "src/all_my_code.h"


#define TEST 0

//WINDOW
static int8 g_is_cursor_position_visible = 0;
static int8 g_is_cursor_enabled = 1;
static int8 g_is_freqency_visible = 0;
static uint64 g_freqency;

//OPENGL FUNCTIONS
void vertex_buffer_bind(uint32 vertex_buffer_id);
void vertex_buffer_unbind();
uint32 vertex_buffer_create(float* buffer_data, int32 length);
void vertex_array_enable(int8 vertex_array_index);
void vertex_array_disable(int8 vertex_array_index);
int8 vertex_array_create(uint32 vertex_buffer_id, int32 size);

void window_key_callback(GLFWwindow* window, int32 key, int32 scancode, int32 action, int32 mods)
{
	if (action == GLFW_PRESS)
	{
		switch (key)
		{
		case GLFW_KEY_Q:
			printf("Q is pressed\n");
			glfwSetWindowShouldClose(window, 1);
			break;
		case GLFW_KEY_W:
			printf("W is pressed\n");
			break;
		case GLFW_KEY_E:
			printf("E is pressed\n");
			break;
		case GLFW_KEY_R:
			printf("R is pressed\n");
			break;
		case GLFW_KEY_T:
			printf("T is pressed\n");
			break;
		case GLFW_KEY_Y:
			printf("Y is pressed\n");
			break;
		case GLFW_KEY_U:
			printf("U is pressed\n");
			break;
		case GLFW_KEY_I:
			printf("I is pressed\n");
			break;
		case GLFW_KEY_O:
			printf("O is pressed\n");
			break;
		case GLFW_KEY_P:
			printf("P is pressed\n");
			break;
		case GLFW_KEY_A:
			printf("A is pressed\n");
			break;
		case GLFW_KEY_S:
			if (!g_is_cursor_position_visible)
			{
				g_is_cursor_position_visible = 1;
			}
			else
			{
				g_is_cursor_position_visible = 0;
			}
			printf("S is pressed\n");
			break;
		case GLFW_KEY_D:
			if (!g_is_cursor_enabled)
			{
				g_is_cursor_enabled = 1;
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			}
			else
			{
				g_is_cursor_enabled = 0;
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
			}
			printf("D is pressed\n");
			break;
		case GLFW_KEY_F:
			if (g_is_freqency_visible)
			{
				g_is_freqency_visible = 0;
			}
			else 
			{
				g_is_freqency_visible = 1;
			}
			printf("F is pressed\n");
			break;
		case GLFW_KEY_G:
			printf("G is pressed\n");
			break;
		case GLFW_KEY_H:
			printf("H is pressed\n");
			break;
		case GLFW_KEY_J:
			printf("J is pressed\n");
			break;
		case GLFW_KEY_K:
			printf("K is pressed\n");
			break;
		case GLFW_KEY_L:
			printf("L is pressed\n");
			break;
		case GLFW_KEY_Z:
			printf("Z is pressed\n");
			break;
		case GLFW_KEY_X:
			printf("X is pressed\n");
			break;
		case GLFW_KEY_C:
			printf("C is pressed\n");
			break;
		case GLFW_KEY_V:
			printf("V is pressed\n");
			break;
		case GLFW_KEY_B:
			printf("B is pressed\n");
			break;
		case GLFW_KEY_N:
			printf("N is pressed\n");
			break;
		case GLFW_KEY_M:
			printf("M is pressed\n");
			break;
		case GLFW_KEY_0:
			printf("0 is pressed\n");
			break;
		case GLFW_KEY_1:
			printf("1 is pressed\n");
			break;
		case GLFW_KEY_2:
			printf("2 is pressed\n");
			break;
		case GLFW_KEY_3:
			printf("3 is pressed\n");
			break;
		case GLFW_KEY_4:
			printf("4 is pressed\n");
			break;
		case GLFW_KEY_5:
			printf("5 is pressed\n");
			break;
		case GLFW_KEY_6:
			printf("6 is pressed\n");
			break;
		case GLFW_KEY_7:
			printf("7 is pressed\n");
			break;
		case GLFW_KEY_8:
			printf("8 is pressed\n");
			break;
		case GLFW_KEY_9:
			printf("9 is pressed\n");
			break;
		case GLFW_KEY_LEFT_SHIFT:
			printf("LShift is pressed\n");
			break;
		case GLFW_KEY_RIGHT_SHIFT:
			printf("RShift is pressed\n");
			break;
		case GLFW_KEY_UP:
			printf("Up is pressed\n");
			break;
		case GLFW_KEY_DOWN:
			printf("Down is pressed\n");
			break;
		case GLFW_KEY_LEFT:
			printf("Left is pressed\n");
			break;
		case GLFW_KEY_RIGHT:
			printf("Right is pressed\n");
			break;
		}
	}
}

void window_mouse_button_callback(GLFWwindow* window, int32 button, int32 action, int32 mods)
{
	if (action == GLFW_PRESS)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			printf("Left mouse button is pressed\n");
		}
		else if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			printf("Right mouse button is pressed\n");
		}
		else if (button == GLFW_MOUSE_BUTTON_MIDDLE)
		{
			printf("Middle mouse button is pressed\n");
		}
	}
}

void window_mouse_scroll_callback(GLFWwindow* window, int32 xoffset, int32 yoffset)
{
	printf("Scroll mouse {%d, %d}\n", xoffset, yoffset);
}

void window_cursor_callback(GLFWwindow* window, double xpos, double ypos)
{
	//empty for now
}

void handle_dropped_file(const char* path)
{
	printf("Path of file = %s\n", path);
}

void window_drop_callback(GLFWwindow* window, int32 count, const char** paths)
{
	int32 i;
	for (i = 0; i < count; i++)
	{
		handle_dropped_file(paths[i]);
	}
}

int main()
{
	float g_R, g_G, g_B, g_RI, g_GI, g_BI;
	g_RI = 0.01f;
	g_GI = 0.01f;
	g_BI = 0.01f;
	g_R = 0.01f;
	g_G = 0.01f;
	g_B = 0.01f;

#if TEST == 1

	dynamic_array_int32 darray32 = dynamic_array_int32_Allocate(30);
	for (int i = 0; i < darray32.Length; i++)
	{
		darray32.Data[i] = i;
	}
	dynamic_array_int32_Print(darray32);

	darray32 = dynamic_array_int32_Add(darray32, 5);
	dynamic_array_int32_Print(darray32);

	darray32 = dynamic_array_int32_Remove(darray32, 29);
	dynamic_array_int32_Print(darray32);


#elif TEST == 0

	GLFWwindow* window;

	if (!glfwInit())
	{
		printf("GLFW is not initialized!\n");
		return(-1);
	}
	
	int32 major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("GLFW version: %d.%d.%d\n", major, minor, revision);

	window = glfwCreateWindow(960, 640, "Demo", 0, 0);
	if (!window)
	{
		glfwTerminate();
		return(-1);
	}
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		printf("Glew is not initialized!\n");
		return(-1);
	}
	
	printf("OpenGL version %s\n", glGetString(GL_VERSION));

	glfwSetKeyCallback(window, window_key_callback);
	glfwSetMouseButtonCallback(window, window_mouse_button_callback);
	glfwSetScrollCallback(window, window_mouse_scroll_callback);
	glfwSetDropCallback(window, window_drop_callback);

	//opengl
	float buffer_data_1[] = {
		-0.5f, -0.5f,  //0
		 0.5f, -0.5f,  //1
		 0.5f,  0.5f,  //2
	
		 0.5f,  0.5f,  //3
		 -0.5f, 0.5f,  //4
		 -0.5f, -0.5f,  //5
	};
	uint32 vertex_buffer_id_rectangle;
	vertex_buffer_id_rectangle = vertex_buffer_create(buffer_data_1, 12);
	int8 vertex_array_id_rectangle = vertex_array_create(vertex_buffer_id_rectangle, 2);
	vertex_array_disable(vertex_array_id_rectangle);
	vertex_buffer_unbind();

	float buffer_data_2[] = {
		-0.9f, -0.5f,  //0
		-0.7f, -0.5f,  //1
		-0.7f,  0.7f,  //2
	};
	uint32 vertex_buffer_id_triangle;
	vertex_buffer_id_triangle = vertex_buffer_create(buffer_data_2, 6);
	int8 vertex_array_id_triangle;
	//vertex_array_id_triangle = vertex_array_create(vertex_buffer_id_triangle, 2);
	//vertex_array_disable(vertex_array_id_triangle);
	vertex_buffer_unbind();

	shader_source shaderSource = shader_loader_load(
		"resources/RotationVertexShader.txt",
		"resources/RotationFragmentShader.txt");
	uint32 shader = 
		shader_loader_compile_shader(shaderSource);
	int32 uniform_color_location = glGetUniformLocation(shader, "color");
	glUseProgram(shader);
	
	//GLM
	mat4 rotationMatrix = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	vec3 v3 = { 0.1f, 0.1f, 0.1f };
	

	double mouse_x_pos, mouse_y_pos;
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		glUniform4f(uniform_color_location, g_R, g_G, g_B, 1);
		glm_rotate(&rotationMatrix, 0.1f, &v3);
		uint32_t location = 
			glGetUniformLocation(shader, "RotationMatrix");
		if (location >= 0)
		{
			glUniformMatrix4fv(location, 
				1, 0, &rotationMatrix[0][0]);
		}
		//glUseProgram(shader);

		//bug here: bind, unbind, select vertex_array
		vertex_buffer_bind(vertex_buffer_id_rectangle);
		vertex_array_enable(vertex_array_id_rectangle);
		glDrawArrays(GL_TRIANGLES, 0, 12);
		vertex_buffer_unbind(vertex_buffer_id_rectangle);
		vertex_array_disable(vertex_array_id_rectangle);
		
		//bug here
		//vertex_buffer_bind(vertex_buffer_id_triangle);
		//vertex_array_enable(vertex_array_id_triangle);
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		//vertex_buffer_unbind(vertex_buffer_id_triangle);
		//vertex_array_disable(vertex_array_id_triangle);

		glfwSwapBuffers(window);
		glfwPollEvents();
		

		if (g_R <= 0)
			g_RI = 0.02f;
		else if (g_R >= 1)
			g_RI = -0.01f;
		
		if (g_G <= 0)
			g_GI = 0.01f;
		else if (g_G >= 1)
			g_GI = -0.02f;
		
		if (g_B <= 0)
			g_BI = 0.03f;
		else if (g_B >= 1)
			g_BI = -0.01f;


		g_R += g_RI;
		g_G += g_GI;
		g_B += g_BI;

		
		g_freqency = glfwGetTimerFrequency();

		if (g_is_freqency_visible)
		{
			printf("%lld hz\n", g_freqency);
		}

		if (g_is_cursor_position_visible)
		{
			glfwGetCursorPos(window, &mouse_x_pos, &mouse_y_pos);
			printf("Mouse position: {%f,%f}\n", mouse_x_pos, mouse_y_pos);
		}
	}
	vertex_array_disable(0);
	vertex_array_disable(1);

	glfwTerminate();
#endif
	
	return(0);
}

void vertex_buffer_bind(uint32 vertex_buffer_id)
{
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
}

void vertex_buffer_unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

uint32 vertex_buffer_create(float* buffer_data, int32 length)
{
	uint32 vertex_buffer_id;
	glGenBuffers(1, &vertex_buffer_id);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
	glBufferData(GL_ARRAY_BUFFER, length*sizeof(float), buffer_data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return(vertex_buffer_id);
}

void vertex_array_enable(int8 vertex_array_index)
{
	glEnableVertexAttribArray(vertex_array_index);
}

void vertex_array_disable(int8 vertex_array_index)
{
	glDisableVertexAttribArray(vertex_array_index);
}

int8 vertex_array_create(uint32 vertex_buffer_id, int32 size)
{
	static int8 vertex_array_index = -1;
	++vertex_array_index;
	glEnableVertexAttribArray(vertex_array_index);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
	glVertexAttribPointer(
		0, size,
		GL_FLOAT, GL_FALSE,
		0,
		(void*)0);
	glDisableVertexAttribArray(vertex_array_index);
	return (vertex_array_index);
}
