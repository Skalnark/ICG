#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"


//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

// For easier handling of function arguments
class Color
{
	public:
		float r, g, b, a;

		Color(float r, float g, float b, float a)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

		Color(float r, float g, float b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			a = 255;
		}
};

class Vector2D
{
	public:
		int x, y;

		Vector2D(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
};

// Draw a pixel on the screen
void PutPixel(Vector2D v, Color c)
{
	FBptr[4*v.x + (4*v.y*IMAGE_WIDTH) + 0] = c.r;
	FBptr[4*v.x + (4*v.y*IMAGE_WIDTH) + 1] = c.g;
	FBptr[4*v.x + (4*v.y*IMAGE_WIDTH) + 2] = c.b;
	FBptr[4*v.x + (4*v.y*IMAGE_WIDTH) + 3] = c.a;
}

void DrawLine(Vector2D v1, Vector2D v2, Color c1, Color c2)
{	
	int octant;
	int dx0 = v2.x - v1.x;
	int dy0 = v2.y - v1.y;
	int x1, x2, y1, y2;

	// All of those if statements below are to Determine in which octant the line is
	if (dx0 < 0)
	{
		if (dy0 < 0)
		{
			if (dy0 > dx0)
			{
				octant = 4; //-1*(x,y)
				x1 = -v1.x;
				x2 = -v2.x;
				y1 = -v1.y;
				y2 = -v2.y;
			}
			else
			{
				octant = 5; // -1*(y, x)
				x1 = -v1.y;
				x2 = -v2.y;
				y1 = -v1.x;
				y2 = -v2.x;
			}
		}
		else
		{
			
			if (dy0 < -dx0)
			{
				octant = 3; //multiply the x by -1
				x1 = -v1.x;
				x2 = -v2.x;
				y1 = v1.y;
				y2 = v2.y;
			}
			else
			{
				octant = 2; //x = y0, y = -x0
				x1 = v1.y;
				x2 = v2.y;
				y1 = -v1.x;
				y2 = -v2.x;
			}
		}
	}
	else
	{
		
		if (0 < dy0)
		{
			if (dy0 < dx0)//1st octant
			{
				x1 = v1.x;
				x2 = v2.x;
				y1 = v1.y;
				y2 = v2.y;
				octant = 0;
			}
			else //we must invert x and y for the 2nd
			{
				octant = 1;
				x1 = v1.y;
				x2 = v2.y;
				y1 = v1.x;
				y2 = v2.x;
			}
		}
		else
		{
			if (dy0 > -dx0)
			{
				octant = 7; //negative y here on the last one
				x1 = v1.x;
				x2 = v2.x;
				y1 = -v1.y;
				y2 = -v2.y;
			}
			else
			{
				octant = 6; // x = -y0, y = x0
				x1 = -v1.y;
				x2 = -v2.y;
				y1 = v1.x;
				y2 = v2.x;
			}
		}
	}

	// The Bresenham's algorithm
	float dx = x2 - x1;
	float dy = y2 - y1;
	float dm = dy / dx;
	float m = 0;
	int y =  y1;

	// to interpolate the colors
	Color c = c1;

	// Dividing the color values by dx to get the same ammount of color for each pixel
	float red = (c2.r - c1.r) / dx;
	float green = (c2.g - c1.g) / dx;
	float blue = (c2.b - c1.b) / dx;
	float alpha = (c2.a - c1.a) / dx;

	for (int x = x1; x < x2; ++x)
	{
		// Interpolating the colors
		c.r += red;
		c.g += green;
		c.b += blue;
		c.a += alpha;

		

		if (m >= 0.5)
		{
			y++;
			m--;
		}

		// To move the cordinates back to the original octant
		switch (octant)
		{
			case 0: 
				PutPixel(Vector2D(x, y), c);
				break;
			case 1: 
				PutPixel(Vector2D(y, x), c);
				break;
			case 6: 
				PutPixel(Vector2D(y, -x), c);
				break;
			case 3: 
				PutPixel(Vector2D(-x, y), c);
				break;
			case 4: 
				PutPixel(Vector2D(-x, -y), c);
				break;
			case 5: 
				PutPixel(Vector2D(-y, -x), c);
				break;
			case 2: 
				PutPixel(Vector2D(-y, x), c);
				break;
			case 7: 
				PutPixel(Vector2D(x, -y), c);
				break;
		}

		m += dm;
	}
}

void DrawTriangle(Vector2D v1, Color c1, Vector2D v2, Color c2, Vector2D v3, Color c3)
{
	DrawLine(v1, v2, c1, c2);
	DrawLine(v2, v3, c2, c3);
	DrawLine(v3, v1, c3, c1);
}

void Hexagrama()
{
	
	for(int i = 0; i < 255; i++)
	{
		
		DrawTriangle(Vector2D(256, 88+i), Color(0, 255, i),
					 Vector2D(128+i, 346), Color(i, 0, 255),
					 Vector2D(384-i, 346), Color(255, i, 0)); 
		
		DrawTriangle(Vector2D(256, 424-i), Color(255, i, 0),
					 Vector2D(128+i, 168), Color(i/2, i/2, 255),
					 Vector2D(384-i, 168), Color(0, 255, i)); 
	}
}


#endif // _MYGL_H_
