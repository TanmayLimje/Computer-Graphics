#include <GL/glut.h>
#include <stdio.h>

int x1,y1,x2,y2;



void putpixel(int x, int y)
{
	glColor3f(1.0,0.0,0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}



void BresenhamLine (int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
  int dy = y2 - y1;
	int slope = dx / dy;

	if(slope < 1)
	{
      int para = 2 * dy - dx;
      int x = x1;
		  int y = y1;
    
		  if(dx < 0)
		  {
		    	x = x2;
			    y = y2;
			    x2 = x1;
		  }
		
		  putpixel(x,y);
		
		  while(x < x2)

		  {
		    	if (para >= 0)
			    {
				      x = x + 1;
				      y = y + 1;
				      para = para + 2 * dy - 2 * dx;			
			    }
          else
			    {
				      x = x + 1;
				      y = y;
				      para = para + 2 * dy;
			    }

  			  putpixel(x,y);	

		  }

	  }

};


void init()
{
	glClearColor(1,1,1,1);
	gluOrtho2D(0.0,500.0,0.0,500.0);
};

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	BresenhamLine(x1,y1,x2,y2);
	glFlush();
}

int main(int argc, char** argv)
{
	printf("Enter start points (x1,y1)\n:");
	scanf("%d %d", &x1, &y1);
	
	printf("Enter end points (x2,y2):\n");
	scanf("%d %d", &x2, &y2);

  glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(250,250);
	glutCreateWindow("Bresenham LINE");
	init();
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}
