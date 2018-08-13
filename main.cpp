#include "main.h"
int i = 0;
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	
/*  //bresenham's algorithm working for all octants!!!!!11!
	DrawLine(Vector2D(0, 0), Vector2D(255, 255), Color(255, 0, 0));
	DrawLine(Vector2D(255, 255), Vector2D(511, 511), Color(255, 128, 0));
	DrawLine(Vector2D(255, 0), Vector2D(255, 255), Color(255, 128, 0));
	DrawLine(Vector2D(255, 255), Vector2D(255, 511), Color(255, 255, 0));
	DrawLine(Vector2D(255, 255), Vector2D(511, 0), Color(0, 255, 128));
	DrawLine(Vector2D(255, 255), Vector2D(0, 511), Color(128, 255, 128));
	DrawLine(Vector2D(255, 255), Vector2D(511, 255), Color(0, 0, 255));
	DrawLine(Vector2D(0, 255), Vector2D(255, 255), Color(0, 255, 255));
*/	

/*
	for (int i = 0; i < 350; i++)
	{
		DrawLine(Vector2D(100+i, 100+i), Vector2D(100+i, 450-i), Color(0, 0, 255), Color(0, 255, 0));
	}
*/

	Hexagrama();

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

