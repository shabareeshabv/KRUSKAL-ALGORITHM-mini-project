

#include<iostream>
#include <GL/glut.h>
#include<math.h>

#include<string.h>
using namespace std;
void find_spanning_tree();
void bitmap_output(int x, int y, const char* string, void* font);

int pointer = 0, point = 0, line = 0, lpointer = 0, upointer = -1, undo_cost_stack_pointer = -1;
int costmatrix[100][100], undo_cost_stack[100], lineundostack[100][100];
int undone = 0, nf = 0, f = 0, found = 0, nodenum = 1, load = 0;
int t[100][2], totalcost;
bool paused = false;
bool start=false,enterpressed=false,resdisplay=false,show_algorithm=false,back=false,show_help=false,show_flowchart=true;
char undostack[100];
char num[2];
char text[16] = "Draw mode:NONE";
float sx = -1, sy = -1;
float oldx[100][100], linepoints[2][2], linex[100][4];
float fade = 0.1;
GLfloat width = 900, height = 600;


//This functions writes the integer into char array
void int_str(int rad, char r[])
{
	sprintf(r, "%d", rad);
}

//whenever undo function is called the cost is pushed into the stack
void push(int n) {
	undo_cost_stack[++undo_cost_stack_pointer] = n;
}

//when redo function is called the cost is popped out
int pop() {
	if (undo_cost_stack_pointer >= 0) {
		return undo_cost_stack[undo_cost_stack_pointer--];
	}
	return 999;
}

//this function creates nodes using location stored in oldx[][] array


//This function prints text in graphics window
void bitmap_output(int x, int y, const char* string, void* font)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

//this delays out execution of next instruction
void delay() {
	int i = 190000000;
	while (i--);
}
void drawSquare()
{
	for (int i = 0; i < pointer; i++) {
		glBegin(GL_POINTS);
		if (i == 0)
		{
			glColor3f(1, 1, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 1)
		{
			glColor3f(1, 0, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 2)
		{
			glColor3f(1, 1, 1);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 3)
		{
			glColor3f(1, 0, 1);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 4)
		{
			glColor3f(1, 1, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 5)
		{
			glColor3f(1, 0, 2);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}if (i == 6)
		{
			glColor3f(2, 0, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 7)
		{
			glColor3f(1, 2, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 8)
		{
			glColor3f(1, 2, 2);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		glEnd();
	}
	for (int i = 0; i < pointer; i++) {
		glColor3f(0, 0, 0);
		int_str(nodenum, num);
		nodenum++;
		bitmap_output(oldx[i][0] - 5, oldx[i][1] - 6, num, GLUT_BITMAP_TIMES_ROMAN_24);
	}

		bitmap_output(500, height-570, "Press 'A' to go to INTRODUCTION PAGE",GLUT_BITMAP_HELVETICA_18);


}


//this function displays staring window
void introduction_page()
{
for (int i = 0; i < pointer; i++) {
		glBegin(GL_POINTS);
		if (i == 0)
		{
			glColor3f(1, 1, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 1)
		{
			glColor3f(1, 0, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 2)
		{
			glColor3f(1, 1, 1);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 3)
		{
			glColor3f(1, 0, 1);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 4)
		{
			glColor3f(1, 1, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 5)
		{
			glColor3f(1, 0, 2);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}if (i == 6)
		{
			glColor3f(2, 0, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 7)
		{
			glColor3f(1, 2, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 8)
		{
			glColor3f(1, 2, 2);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		glEnd();
	}
	for (int i = 0; i < pointer; i++) {
		glColor3f(0, 0, 0);
		int_str(nodenum, num);
		nodenum++;
		bitmap_output(oldx[i][0] - 5, oldx[i][1] - 6, num, GLUT_BITMAP_TIMES_ROMAN_24);
	}


	
glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2d(315,30);
glVertex2d(620,30);
glVertex2d(620,80);
glVertex2d(315,80);
glEnd();



	glLineWidth(2);
	
	glColor3f(0.0,0.0,0.69);
	bitmap_output(width/3, height-height/10, "SDM Institute of Technology, Ujire",GLUT_BITMAP_HELVETICA_18);


	
	bitmap_output(width/4+50, height-height/6, "Computer Graphics Lab with Mini Project",GLUT_BITMAP_HELVETICA_18);

	bitmap_output(width/4+55, height-height/4, "****KRUSHKAL'S ALGORITHM****",GLUT_BITMAP_TIMES_ROMAN_24);

	
	glColor3f(0.82,0.0,0.64);
	bitmap_output(width/15+55,height-height/2.2,"---Made by---",GLUT_BITMAP_HELVETICA_18);

	glColor3f(1.0,1.0,1.0);
	bitmap_output(width/15+10,height-height/1.9,"Avinash Bhat (4SU19CS012)",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(width/15+10,height-height/1.7,"B V Shabareesha (4SU19CS013)",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(width/15+10,height-height/1.55,"Basavaraj N (4SU19CS014)",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(width/15+10,height-height/1.42,"Darshan D Sutar (4SU19CS021)",GLUT_BITMAP_HELVETICA_18);

	glColor3f(0.82,0.0,0.64);
	bitmap_output(width/15+580,height-height/1.8,"---Guided by---",GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	bitmap_output(width/15+595,height-height/1.6,"Mr.Pradeep G S.",GLUT_BITMAP_TIMES_ROMAN_24);
	glFlush();
	delay();
	glColor3f(1.0,1.0,0.9);
	bitmap_output(width/5+135, 46, "Press 'ENTER' to continue",GLUT_BITMAP_TIMES_ROMAN_24);

	glFlush();
	delay();
}


void instruction_page()
{

for (int i = 0; i < pointer; i++) {
		glBegin(GL_POINTS);
		if (i == 0)
		{
			glColor3f(1, 1, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 1)
		{
			glColor3f(1, 0, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 2)
		{
			glColor3f(1, 1, 1);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 3)
		{
			glColor3f(1, 0, 1);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 4)
		{
			glColor3f(1, 1, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 5)
		{
			glColor3f(1, 0, 2);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}if (i == 6)
		{
			glColor3f(2, 0, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 7)
		{
			glColor3f(1, 2, 0);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		if (i == 8)
		{
			glColor3f(1, 2, 2);
			glVertex2i(oldx[i][0], oldx[i][1]);
		}
		glEnd();
	}
	for (int i = 0; i < pointer; i++) {
		glColor3f(0, 0, 0);
		int_str(nodenum, num);
		nodenum++;
		bitmap_output(oldx[i][0] - 5, oldx[i][1] - 6, num, GLUT_BITMAP_TIMES_ROMAN_24);
	}


	glColor3f(1.0,1.0,1.0);
	bitmap_output(300, height-100, "****KRUSHKALS ALGORITHM****",GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(330, height-200, "---INSTRUCTIONS---",GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(370, height-300, "Press 'S' (To START) ",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(330, height-350, "Press 'I' (About Krushakl algorithm) ",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(375, height-400, "Press 'H' (For HELP)  ",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(365, height-450, "Press 'ESC' (To QUIT)",GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,0.0,0.0);
	bitmap_output(500, height-570, "Press 'A' to go to INTRODUCTION PAGE",GLUT_BITMAP_HELVETICA_18);
}


void algorithm()
{ 
glBegin(GL_POLYGON);
glColor3f(0.9,0.3,0.1);
glVertex2d(0,0);
glColor3f(0.9,0.3,0.1);
glVertex2d(0,height);
glColor3f(0.9,0.3,0.1);
glVertex2d(width,height);
glColor3f(0.9,0.3,0.1);
glVertex2d(width,0);
glEnd();

	
glColor3f(1.0,1.0,1.0);
bitmap_output(width/6+25, height-50, "***KRUSHKAL'S ALGORITHM WORKING STEPS***",GLUT_BITMAP_TIMES_ROMAN_24);
bitmap_output(width/15+25, height-150, "1.  Initially Create nodes in a specific position. ",GLUT_BITMAP_HELVETICA_18);
bitmap_output(width/15+25, height-190, "2.  Select the Edge key and start drawing edges among nodes by entering the link cost ",GLUT_BITMAP_HELVETICA_18);
bitmap_output(width/15+45, height-230, "  make sure that all the edges should be connected",GLUT_BITMAP_HELVETICA_18);
bitmap_output(width/15+25, height-270, "3.  It will sort the edges from low weight to high  ",GLUT_BITMAP_HELVETICA_18);
bitmap_output(width/15+45, height-310, " Take the edge with the lowest and add it to the spanning tree. If adding the egde creating a cycle then rejet this edge ",GLUT_BITMAP_HELVETICA_18);
bitmap_output(width/15+45, height-350, "Keep adding edges untill we reach all vertices",GLUT_BITMAP_HELVETICA_18);

bitmap_output(width/15+600, height-570, "Press 'B' to go back",GLUT_BITMAP_HELVETICA_18);
}


void flowchart(){
glBegin(GL_POLYGON);
glColor3f(1.0,0.6,0.2);
glVertex2d(0,0);
glColor3f(1.0,0.6,0.2);
glVertex2d(0,height);
glColor3f(1.0,0.6,0.2);
glVertex2d(width,height);
glColor3f(1.0,0.6,0.2);
glVertex2d(width,0);
glEnd();


//heading
glColor3f(1.0,1.0,1.0);
bitmap_output(width/6+130, height-50, "***WORKING FLOW CHART***",GLUT_BITMAP_TIMES_ROMAN_24);
//introduction polygon
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(350,500);
glVertex2i(555,500);
glVertex2i(555,460);
glVertex2i(350,460);
glEnd();
glColor3f(0.0,0.0,0.0);
bitmap_output(380, 475, "Introduction page",GLUT_BITMAP_HELVETICA_18);
//intro-instruction
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(450,460);
glVertex2i(450,425);
glEnd();

//instruction polygon
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(350,425);
glVertex2i(555,425);
glVertex2i(555,385);
glVertex2i(350,385);
glEnd();
glColor3f(0.0,0.0,0.0);
bitmap_output(387, 400, "Instruction page",GLUT_BITMAP_HELVETICA_18);
//horizontal
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(190,365);
glVertex2i(690,365);
glEnd();
//instruction-horizontal
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(450,385);
glVertex2i(450,365);
glEnd();

//instruction-algo
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(190,365);
glVertex2i(190,350);
glEnd();
//instruction-end
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(690,365);
glVertex2i(690,350);
glEnd();
//instruction-help
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(360,365);
glVertex2i(360,350);
glEnd();
//instruction-simulation start
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(540,365);
glVertex2i(540,350);
glEnd();

//algorithm polygon
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(110,350);
glVertex2i(270,350);
glVertex2i(270,310);
glVertex2i(110,310);
glEnd();
glColor3f(0.0,0.0,0.0);
bitmap_output(125, 325, "Algorithm page",GLUT_BITMAP_HELVETICA_18);


//help polygon
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(290,350);
glVertex2i(430,350);
glVertex2i(430,310);
glVertex2i(290,310);
glEnd();
glColor3f(0.0,0.0,0.0);
bitmap_output(315, 325, "Help page",GLUT_BITMAP_HELVETICA_18);

//start simulation polygon
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(450,350);
glVertex2i(630,350);
glVertex2i(630,310);
glVertex2i(450,310);
glEnd();
glColor3f(0.0,0.0,0.0);
bitmap_output(470, 325, "Start Simulation",GLUT_BITMAP_HELVETICA_18);
//simulation start-draw graph
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(540,310);
glVertex2i(540,275);
glEnd();

//End polygon
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(650,350);
glVertex2i(730,350);
glVertex2i(730,310);
glVertex2i(650,310);
glEnd();
glColor3f(0.0,0.0,0.0);
bitmap_output(670, 325, "End",GLUT_BITMAP_HELVETICA_18);
// end-exit
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(690,310);
glVertex2i(690,55);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(690,55);
glVertex2i(450,55);
glEnd();

//simulation polygon
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(450,275);
glVertex2i(630,275);
glVertex2i(630,175);
glVertex2i(450,175);
glEnd();
glColor3f(0.0,0.0,0.0);
bitmap_output(490, 250, "Draw Node",GLUT_BITMAP_HELVETICA_18);
bitmap_output(490, 220, "Draw Edge",GLUT_BITMAP_HELVETICA_18);
bitmap_output(490, 190, "Draw Graph",GLUT_BITMAP_HELVETICA_18);
//draw graph-output
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(540,175);
glVertex2i(540,145);
glEnd();

//start simulation polygon
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(450,145);
glVertex2i(630,145);
glVertex2i(630,105);
glVertex2i(450,105);
glEnd();
glColor3f(0.0,0.0,0.0);
bitmap_output(510, 120, "Output",GLUT_BITMAP_HELVETICA_18);

//draw graph-output
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(540,105);
glVertex2i(540,75);
glEnd();

//Exit polygon
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2i(450,75);
glVertex2i(630,75);
glVertex2i(630,35);
glVertex2i(450,35);
glEnd();
glColor3f(0.0,0.0,0.0);
bitmap_output(520,50, "Exit",GLUT_BITMAP_HELVETICA_18);




//back button text
glColor3f(0.0,0.0,0.0);
bitmap_output(50, height-570, "Press 'B' to go Back",GLUT_BITMAP_HELVETICA_18);

}


//this function draws edges using location stored in linex array
void drawline(){
	glColor3f(0.9f,1.0f,0.8f);
	glLineWidth(4.0);
	char* cst = new char[5];
	int temp;
	glBegin(GL_LINES);
	for(int i=0;i<lpointer;i++){
	glVertex2i(linex[i][0],linex[i][1]);
	glVertex2i(linex[i][2],linex[i][3]);
	}
	glEnd();
	glColor3f(0.0,1.0,0.0);
	for(int i=0;i<lpointer;i++){
		temp=costmatrix[lineundostack[i][0]][lineundostack[i][1]];
		sprintf(cst, "%d", temp);
		bitmap_output((linex[i][0]+linex[i][2])/2-15,(linex[i][1]+linex[i][3])/2+15,cst,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	glFlush();//glutSwapBuffers();
}


//this displays a point when mouse clicked for first time in draw edge mode
void drawPointAt(float x,float y){
	glPointSize(15);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();

}

//this function displays text instructions in grpahics windwow
void Instructions()
{
	glColor3f(1.0, 1.0, 0.0);
	bitmap_output(10, height - height / 10, "Instructions", GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(10, height - height / 9);
	glVertex2f(130, height - height / 9);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	bitmap_output(10, height - height / 7, "->Press N to Create Nodes", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(10, height - height / 5.8, "->Press E to draw Edges", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(10, height - height / 4.9, "->Press D to draw spanning tree", GLUT_BITMAP_TIMES_ROMAN_24);
}


void help_page()
{
	glBegin(GL_POLYGON);
glColor3f(0.9,0.3,0.1);
glVertex2d(0,0);
glColor3f(0.9,0.3,0.1);
glVertex2d(0,height);
glColor3f(0.9,0.3,0.1);
glVertex2d(width,height);
glColor3f(0.9,0.3,0.1);
glVertex2d(width,0);
glEnd();
	glColor3f(0.0,1.0,0.0);
	bitmap_output(290, height-70, "****KRUSHKALS ALGORITHM****",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0,1.0,1.0);
	bitmap_output(370, height-150, "---HELP---",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0,0.0,0.0);
	bitmap_output(345, height-210, "Keys              Functions",GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,0.0,0.61);
	bitmap_output(345, height-250, "Enter    -    Instruction page",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(345, height-280, "S or s   -    To start the Prims Simulation",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(345, height-310, "I or i     -    To see the algorithm of Krushkals",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(345, height-340, "H or h   -    For Help ",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(345, height-370, "A or a   -    To go back to Introduction Page",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(345, height-400, "B or b   -    To go back to Instruction Page",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(345, height-430, "Z or z    -   To Undo",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(345, height-460, "Y or y    -   To Redo",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(345, height-490, "ESC      -    To Quit",GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,0.0,0.0);
bitmap_output(width/15+600, height-570, "Press 'B' to go back",GLUT_BITMAP_HELVETICA_18);
}



//this function does animation of lines connecting after calculating spanning tree
void blinking_lines() {
	delay();
	glLineWidth(7.0);
	for (int i = 0; i < pointer - 1; i++) {
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		glVertex2i(oldx[t[i][0]][0], oldx[t[i][0]][1]);
		glVertex2i(oldx[t[i][1]][0], oldx[t[i][1]][1]);
		glEnd();
		delay();
		glutSwapBuffers();
		glutPostRedisplay();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2i(oldx[t[i][0]][0], oldx[t[i][0]][1]);
		glVertex2i(oldx[t[i][1]][0], oldx[t[i][1]][1]);
		delay();
		glEnd();
		
		glFlush();
	}
}


//this function mimics loading animation
void loadpage() {
	delay();
	glLineWidth(100);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2d(100, 300);
	glVertex2d(100 + load, 300);
	glEnd();
	load += 100;
	glFlush();
	glutPostRedisplay();
}

//this function displays text output after calculating spanning tree
void output() {
	glColor3f(0.0, 1.0, 1.0);
	int xaxis = 10, yaxis = 550;
	bitmap_output(xaxis, yaxis, "Spanning tree exist and minimum spanning tree is", GLUT_BITMAP_HELVETICA_18);
	char* buffer = new char[50];
	char* cst = new char[50];
	char* a = new char[50];
	char* b = new char[50];
	for (int i = 0; i < pointer - 1; i++) {
		sprintf(a, "%d", t[i][0]);
		strcat(a, "->");
		sprintf(b, "%d", t[i][1]);
		strcat(a, b);
		sprintf(cst, "%d", costmatrix[t[i][0]][t[i][1]]);
		strcat(a, " cost=");
		strcat(a, cst);
		yaxis -= 20;
		bitmap_output(xaxis, yaxis, a, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	char sumchar[50];
	sprintf(buffer, "%d", totalcost);
	strcat(sumchar, "spanning tree cost=");
	strcat(sumchar, buffer);
	bitmap_output(xaxis, yaxis - 20, sumchar, GLUT_BITMAP_TIMES_ROMAN_24);
}

//This is callback function called by OpenGL 
void display() {
	nodenum = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.5, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (load < 800 && found == 0) {
		
		loadpage();
	}
	else if (load < 800 && found == 1) {
		
		loadpage();
	}
	else if(!start) {
		if (enterpressed)
		{
			instruction_page();
			 if(show_algorithm){
		     algorithm();		   
		 }
		   else if(show_help){
			 help_page();
		} 
		   else if(show_flowchart){
			 flowchart();
		}
		}
		else{
		//glLineWidth(25);
		introduction_page();
		}	
	}
		
		 if(start) {
			if (!found) {
				Instructions();
				glColor3f(0.1, 1, 0.0);
				bitmap_output(width - width / 2 + 200, height - height / 9, text, GLUT_BITMAP_TIMES_ROMAN_24);
			}
			glPointSize(40);
			drawSquare();
			if (sx != -1 && sy != -1) {
				drawPointAt(sx, sy);
			}
			if (!found){
				drawline();
			}
			if (found) {
				output();
				blinking_lines();
			}
		}
	
	glFlush();
}
	
	


//this is reshape callback function called by OpenGL whenever window is resized


void reshape(int w, int h)
{
	width = w;
	height = h;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w, 2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.0 * (GLfloat)w / (GLfloat)h, 2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
}

//this function takes cost input from user during edge drawing
void input() {
	int posi = -1, posj = -1;
	int cost;
	int center_difference_error = 4;
	for (int i = 0; i < pointer; i++) {
		if (oldx[i][0] >= (linepoints[0][0] - center_difference_error) && oldx[i][0] <= (linepoints[0][0] + center_difference_error)) {
			if (oldx[i][1] >= (linepoints[0][1] - center_difference_error) && oldx[i][1] <= (linepoints[0][1] + center_difference_error)) {
				posi = i;
				break;
			}
		}
	}
	for (int i = 0; i < pointer; i++) {
		if (oldx[i][0] >= (linepoints[1][0] - center_difference_error) && oldx[i][0] <= (linepoints[1][0] + center_difference_error)) {
			if (oldx[i][1] >= (linepoints[1][1] - center_difference_error) && oldx[i][1] <= (linepoints[1][1] + center_difference_error)) {
				posj = i;
				break;
			}
		}
	}
	if ((posi == posj) || posi == -1 || posj == -1) {
		glColor3f(1.0, 0.0, 0.0);
		bitmap_output(20, 50, "Invalid node", GLUT_BITMAP_TIMES_ROMAN_24);
		glFlush();
		delay();
		delay();
		lpointer--;
	}
	else {
		cout << "Enter the cost:";
		cin >> cost;
		lineundostack[lpointer][0] = posi;
		lineundostack[lpointer][1] = posj;
		costmatrix[posi][posj] = costmatrix[posj][posi] = cost;
	}
}

void mousebutton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (enterpressed) {

		}
	}
}
//this is mouse callback function called by OpenGL whenever mouse event occurs
void mousefun(int button, int state, int x, int y) {
	found = 0;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (enterpressed) {
			glLoadIdentity();
			float xp = (float)x;
			float yp = height - (float)y;

			if (point) {
				oldx[pointer][0] = xp;
				oldx[pointer++][1] = yp;
				undostack[++upointer] = 'p';
			}

			if (line) {
				if (f == 0) {
					linex[lpointer][0] = xp;
					linex[lpointer][1] = yp;
					f = 1;
					linepoints[0][0] = sx = xp;
					linepoints[0][1] = sy = yp;
				}
				else {
					linex[lpointer][2] = linepoints[1][0] = xp;
					linex[lpointer][3] = linepoints[1][1] = yp;
					input();
					lpointer++;
					f = 0;
					sx = sy = -1;
					undostack[++upointer] = 'l';
				}
			}
			glutPostRedisplay();
		}
	}
}

//this function will print matrix constructed
void printmatrix() {
	for (int i = 0; i < pointer; i++) {
		for (int j = 0; j < pointer; j++) {
			cout << costmatrix[i][j] << "  ";
		}
		cout << endl;
	}
}

//this checks if the graph is connected or not
bool isconnected() {
	int count;
	for (int i = 0; i < pointer; i++) {
		count = 0;
		for (int j = 0; j < pointer; j++) {
			if (costmatrix[i][j] == 999)count++;
		}
		if (count >= pointer - 1) {
			return false;
		}
	}
	return true;
}

//this undo the drawing in the order the graph was drawn
void undo() {
	if (pointer > 0 && undostack[upointer--] == 'p') {
		pointer--;
		undone++;
	}
	else if (lpointer > 0) {
		lpointer--;
		push(costmatrix[lineundostack[lpointer][0]][lineundostack[lpointer][1]]);
		costmatrix[lineundostack[lpointer][0]][lineundostack[lpointer][1]] = 999;
		costmatrix[lineundostack[lpointer][1]][lineundostack[lpointer][0]] = 999;
		undone++;
	}
}

//this redo the drawing in the order the graph was drawn
void redo() {
	if (undone) {
		if (undostack[++upointer] == 'p') {
			pointer++;
			undone--;
		}
		else {
			int  cost = pop();
			costmatrix[lineundostack[lpointer][0]][lineundostack[lpointer][1]] = cost;
			costmatrix[lineundostack[lpointer][1]][lineundostack[lpointer][0]] = cost;
			lpointer++;
			undone--;
		}
	}
}

//this will call find_spanning_tree function if graph is connected
void find() {
	if (isconnected()) {
		load = 0;
		find_spanning_tree();
	}
	else
	{
		glColor3f(1.0, 0.0, 0.0);
		bitmap_output(30, 20, "Graph is not connected", GLUT_BITMAP_TIMES_ROMAN_24);
		glFlush();
		delay();
		delay();
		//	cout<<"spanning tree doesn't exist"<<endl;
	}
}

//this will select edge draw mode 
void selectedge() {
	strcpy(text, "Draw mode: Edge");
	line = 1;
	point = 0;
}

//this will select node draw mode 
void selectnode() {
	strcpy(text, "Draw mode: Node");
	point = 1;
	line = 0;
}

//this is keyboard callback function called by OpenGL whenever keyboard event occurs
void keyboardfun(unsigned char key, int x, int y) {
	sx = -1; sy = -1;
	switch (key) {
	case 13:found = 0;
		enterpressed = true;
		break;

	    case 's' :
		case 'S' :found=0;
			       start=true;
			       break;

	     case 'a' :
		 case 'A' :enterpressed=false;
					start=false;
			       show_help=false;
			      show_algorithm=false;
			       break;

				    case 'b' :
		 case 'B' :start=false;
			       show_help=false;
			       show_algorithm=false;
				    show_flowchart=false;
			       back=true;
				   break;


	 case 'e':
	 case 'E':found = 0;
		selectedge();
		break;
	 case 'N':
	 case 'n':found = 0;
		selectnode();
		break;

	case 'Z':
	case 'z':found = 0;
		undo();
		break;

	case 'Y':
	case 'y':found = 0;
		redo();
		break;

	case 'D':
	case 'd':found = 0;
		find();
		break;
		 case 'i':
		 case 'I':
			      show_algorithm=true;
				  show_help=false;
				  show_flowchart=false;
			      break;
		 case 'h':
		 case 'H':show_algorithm=false;
			      show_help=true;
			      break;
		 case 'f':
		 case 'F':show_algorithm=false;
			      show_help=false;
				  show_flowchart=true;
			      break;
		 case ' ':paused=!paused;
			      break;
	
	case 27:exit(0);
	}
	glutPostRedisplay();
}

//this is menu callback function called by OpenGL as menu function
void menu(int id) {
	switch (id) {
	case 0:find();
		break;
	case 1:undo();
		break;
	case 2:redo();
		break;
	case 3:printmatrix();
		break;
	case 4:point = 1;
		line = 0;
		strcpy(text, "Draw Mode: Node");
		break;
	case 5:point = 0;
		line = 1;
		strcpy(text, "Draw Mode: Edge");
		break;
	}
	glutPostRedisplay();

}

//this function calculates spanning tree using Prim's algorithm
void find_spanning_tree() {
	int k, u, v;
	int sum, min, source;
	int* p = new int[100];
	int* d = new int[100];
	int* s = new int[100];
	min = 999;
	source = 0;
	for (int i = 0; i < pointer; i++) {
		for (int j = 0; j < pointer; j++) {
			if (costmatrix[i][j] != 0 && costmatrix[i][j] <= min) {
				min = costmatrix[i][j];
				source = i;
			}
		}
	}

	for (int i = 0; i < pointer; i++) {
		d[i] = costmatrix[source][i];
		p[i] = source;
		s[i] = 0;
	}
	s[source] = 1;
	sum = 0;
	k = 0;
	for (int i = 1; i < pointer; i++) {
		min = 999;
		u = -1;
		for (int j = 0; j < pointer; j++) {
			if (s[j] == 0) {
				if (d[j] < min) {
					min = d[j];
					u = j;
				}
			}
		}
		if (u == -1)return;
		t[k][0] = u;
		t[k++][1] = p[u];
		sum = sum + costmatrix[u][p[u]];
		s[u] = 1;
		for (v = 0; v < pointer; v++) {
			if (s[v] == 0 && costmatrix[u][v] < d[v]) {
				d[v] = costmatrix[u][v];
				p[v] = u;
			}
		}
	}
	if (sum >= 999) {
		cout << "spanning tree doesn't exist\n";
	}
	else {
		totalcost = sum;
		found = 1;
	}
}

//Program execution starts from here
int main(int argc, char** argv) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			if (i == j) {
				costmatrix[i][j] = 0;
			}
			else costmatrix[i][j] = 999;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(250, 250);
	glutInitWindowSize(width, height);
	glutCreateWindow("KRUSHKAL'S");
	glutDisplayFunc(display);
	glutMouseFunc(mousefun);
	glutKeyboardFunc(keyboardfun);
	glutReshapeFunc(reshape);
	glutCreateMenu(menu);
	glutAddMenuEntry("Run", 0);
	glutAddMenuEntry("Undo", 1);
	glutAddMenuEntry("redo", 2);
	glutAddMenuEntry("Draw node", 4);
	glutAddMenuEntry("Draw Edge", 5);
	glutAddMenuEntry("Print matrix", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
