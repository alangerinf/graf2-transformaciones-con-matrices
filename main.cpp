
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>


using namespace std;




GLfloat pibote[3] = {1,2,2};


GLfloat tra [3] = { 	0,
						0,
						0
};
GLfloat sca [3] = { 	1,
	1,
	1
};
GLfloat rot [3] = {
	0,
	0,
	0,
};

GLfloat v[8][3] = 	{
						{-1,-1,-1},
						{-1,-1, 1},
						{-1, 1, 1},
						{-1,1,-1},
						{1,-1,-1},
						{1,-1,1},
						{1,1,1},
						{1,1,-1}
					};  /* Will be filled in with X,Y,Z vertexes. */

GLfloat v2[8][3] = 	{
	{-1,-1,-1},
	{-1,-1, 1},
	{-1, 1, 1},
	{-1,1,-1},
	{1,-1,-1},
	{1,-1,1},
	{1,1,1},
	{1,1,-1}
};  /* Will be filled in with X,Y,Z vertexes. */



float** multiMatrix(float a[4][4], float b[4][4]){
	float *r[4];
	for (int i = 0; i < 4; i++) {		for (int j = 0; i < 4; j++) {			r[i][j] = 0;			for (int k = 0; k < 4; k++) {				r[i][j]	+= a[i][k] * b[k][j];			}		}	}
	return r;
}

float*  translate(float t[3],float v[3]){
	
	float r[3];
	float *p;
	float t1[4][4]=	{	{1,	0,	0,	t[0] },
						{0,	1,	0,	t[1] },
						{0,	0,	1,	t[2] },
						{0,	0,	0,	1	 }
	};
	float v1[4]={v[0],v[1],v[2],1};
	/*
	for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	cout<<t1[i][j]<<" ";
	}
	cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<4;i++){
	cout<<v1[i]<<" ";
	}
	
	cout<<endl<<endl;
	
	for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	cout<<t1[i][j]*v1[j]<<" ";
	}
	cout<<endl;
	}
	cout<<endl<<endl;
	*/
	float r1[4];
	for(int i=0;i<4;i++){
		r1[i]=0;
		for(int j=0;j<4;j++){
			r1[i] = r1[i] +t1[i][j]*v1[j];
		}
		/*cout<<r1[i];
		cout<<endl;*/
	}	
	
	for(int k=0;k<3;k++){
		r[k]=r1[k];		//pasando de los 4 parametros universales a solo 3
		//	cout << r[k];
	}
	p=r;
	return p;
	
}

float*  scalate(float t[3],float v[3]){
	
	float r[3];
	float *p;
	float t1[4][4]=	{	{t[0],	0   ,	0   ,	0 },
	{0   ,	t[1],	0   ,	0 },
	{0   ,	0   ,	t[2],	0 },
	{0   ,	0   ,	0   ,	1 }
	};
	float v1[4]={v[0],v[1],v[2],1};
	
	float r1[4];
	for(int i=0;i<4;i++){
		r1[i]=0;
		for(int j=0;j<4;j++){
			r1[i] = r1[i] +t1[i][j]*v1[j];
		}
		/*cout<<r1[i];
		cout<<endl;*/
	}	
	
	for(int k=0;k<3;k++){
		r[k]=r1[k];		//pasando de los 4 parametros universales a solo 3
		//	cout << r[k];
	}
	p=r;
	return p;
	
}

float*  rotateX(float a,float v[3]){
	
	float r[3];
	float *p;
	float t1[4][4]=	{	{1	, 0		,	0   ,	0 },
	{0	, cos(a),-sin(a),	0 },
	{0	, sin(a), cos(a),	0 },
	{0	, 0     ,	0   ,	1 }
	};
	float v1[4]={v[0],v[1],v[2],1};
	
	float r1[4];
	for(int i=0;i<4;i++){
		r1[i]=0;
		for(int j=0;j<4;j++){
			r1[i] = r1[i] +t1[i][j]*v1[j];
		}
		/*cout<<r1[i];
		cout<<endl;*/
	}	
	
	for(int k=0;k<3;k++){
		r[k]=r1[k];		//pasando de los 4 parametros universales a solo 3
		//	cout << r[k];
	}
	p=r;
	return p;
	
}


float*  rotateY(float a,float v[]){
	
	float r[3];
	float *p;
	float t1[4][4]=	{	{ cos(a), 0	, sin(a),	0 },
	{ 0		, 1 ,	0	,	0 },
	{-sin(a), 0	, cos(a),	0 },
	{ 0		, 0 ,	0   ,	1 }
	};
	float v1[4]={v[0],v[1],v[2],1};
	
	float r1[4];
	for(int i=0;i<4;i++){
		r1[i]=0;
		for(int j=0;j<4;j++){
			r1[i] = r1[i] +t1[i][j]*v1[j];
		}
		//cout<<r1[i];
		//cout<<endl;
	}	
	
	for(int k=0;k<3;k++){
		r[k]=r1[k];		//pasando de los 4 parametros universales a solo 3
		//	cout << r[k];
	}
	p=r;
	return p;
	
}


float*  rotateZ(float a,float v[3]){
	
	float r[3];
	float *p;
	float t1[4][4]=	{	{cos(a), -sin(a),	0   ,	0 },
	{sin(a), cos(a) ,	0   ,	0 },
	{0     , 0      ,	1	,	0 },
	{0     , 0      ,	0   ,	1 }
	};
	float v1[4]={v[0],v[1],v[2],1};
	
	float r1[4];
	for(int i=0;i<4;i++){
		r1[i]=0;
		for(int j=0;j<4;j++){
			r1[i] = r1[i] +t1[i][j]*v1[j];
		}
		//cout<<r1[i];
		//cout<<endl;
	}	
	
	for(int k=0;k<3;k++){
		r[k]=r1[k];		//pasando de los 4 parametros universales a solo 3
		//	cout << r[k];
	}
	p=r;
	return p;
	
}











void reiniciar(){
	tra[0]=0;
	tra[1]=0;
	tra[2]=0;
	rot[0]=0;
	rot[1]=0;
	rot[2]=0;
	sca[0]=1;
	sca[1]=1;
	sca[2]=1;
}

void drawBox()
{
	
	glBegin(GL_QUADS);        // Draw The Cube Using quads
	
		glColor3f(0.0f,0.0f,1.0f);    // Color Blue
		glVertex3fv(v2[3]);    // Top Right Of The Quad (Top)
		glVertex3fv(v2[2]);    // Top Left Of The Quad (Top)
		glVertex3fv(v2[6]);    // Bottom Left Of The Quad (Top)
		glVertex3fv(v2[7]);    // Bottom Right Of The Quad (Top)
		
		glColor3f(0.0f,1.0f,0.5f);    // Color Orange
		glVertex3fv(v2[4]);    // Top Right Of The Quad (Bottom)
		glVertex3fv(v2[5]);    // Top Left Of The Quad (Bottom)
		glVertex3fv(v2[6]);    // Bottom Left Of The Quad (Bottom)
		glVertex3fv(v2[7]);    // Bottom Right Of The Quad (Bottom)
		
		glColor3f(0.0f,0.5f,0.0f);    // Color Orange
		glVertex3fv(v2[0]);    // Top Right Of The Quad (Bottom)
		glVertex3fv(v2[4]);    // Top Left Of The Quad (Bottom)
		glVertex3fv(v2[7]);    // Bottom Left Of The Quad (Bottom)
		glVertex3fv(v2[3]);    // Bottom Right Of The Quad (Bottom)
		
		glColor3f(0.5f,0.0f,0.0f);    // Color Orange
		glVertex3fv(v2[0]);    // Top Right Of The Quad (Bottom)
		glVertex3fv(v2[1]);    // Top Left Of The Quad (Bottom)
		glVertex3fv(v2[5]);    // Bottom Left Of The Quad (Bottom)
		glVertex3fv(v2[4]);    // Bottom Right Of The Quad (Bottom)
		
		glColor3f(0.5f,0.5f,0.0f);    // Color Orange
		glVertex3fv(v2[0]);    // Top Right Of The Quad (Bottom)
		glVertex3fv(v2[1]);    // Top Left Of The Quad (Bottom)
		glVertex3fv(v2[2]);    // Bottom Left Of The Quad (Bottom)
		glVertex3fv(v2[3]);    // Bottom Right Of The Quad (Bottom)
		
		glColor3f(0.5f,0.0f,0.5f);    // Color Orange
		glVertex3fv(v2[2]);    // Top Right Of The Quad (Bottom)
		glVertex3fv(v2[1]);    // Top Left Of The Quad (Bottom)
		glVertex3fv(v2[5]);    // Bottom Left Of The Quad (Bottom)
		glVertex3fv(v2[6]);    // Bottom Right Of The Quad (Bottom)
	
	
	glEnd();            // End Drawing The Cube

	
	
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	glBegin(GL_LINES);
		glColor3f(0.0f,0.0f,1.0f); 
		glVertex3i(0,0,15);
		glVertex3i(0,0,-15);
		glColor3f(0.0f,1.0f,1.0f); 
		glVertex3i(0,15,0);
		glVertex3i(0,-15,0);
		glColor3f(1.0f,0.0f,1.0f); 
		glVertex3i(15,0,0);
		glVertex3i(-15,0,0);
	
	glEnd();
	
	
	glPushMatrix();
		glTranslatef(pibote[0],pibote[1],pibote[2]);
	
		glutSolidSphere(0.2,4,3);
	
	glPopMatrix();
	
	
	glPushMatrix();
		//glTranslatef(translate_x,translate_y,translate_z);
		/*glRotatef(rotate_x,1.0f,0,0);
		glRotatef(rotate_y,0,1.0f,0);
		glRotatef(rotate_z,0,0,1.0f);	
		glScalef(scale_x,scale_y,scale_z);
		*/
	/***dibujado de box
	
	*/																																					for(int i=0;i<8;i++){		float s[3]={sca[0],sca[1],sca[2]};float t[3]={tra[0],tra[1], tra[2]};float vv[3]={v[i][0] , v[i][1] , v[i][2]};float *point1 =	rotateX(	rot[0]	,	vv	);		vv[0]=point1[0];vv[1]=point1[1];		vv[2]=point1[2];		float *point2 =	rotateY(	rot[1]	,	vv	);		vv[0]=point2[0];		vv[1]=point2[1];		vv[2]=point2[2];		float *point3 =	rotateZ(	rot[2]	,	vv	);		vv[0]=point3[0];		vv[1]=point3[1];		vv[2]=point3[2];				float *point4 = scalate(s ,vv) ;		vv[0]=point4[0];		vv[1]=point4[1];		vv[2]=point4[2];				float *point5 = translate(t,vv);		v2[i][0] = point5[0];		v2[i][1] = point5[1];		v2[i][2] = point5[2];	}
		
	float mTra[4][4] = {
		{1	,0	,0	,tra[0]},
		{0	,1	,0	,tra[1]},
		{0	,0	,1	,tra[2]},
		{0	,0	,0	,1     }
	};
	float mSca[4][4] = {
		{sca[0]	,0		,0		,0},
		{0		,sca[1]	,0		,0},
		{0		,0		,sca[2]	,0},
		{0		,0		,0		,1}
	};
	float cosX=cos(rot[0]);
	float sinX=sin(rot[0]);
	float cosY=cos(rot[1]);
	float sinY=sin(rot[1]);
	float cosZ=cos(rot[2]);
	float sinZ=sin(rot[2]);
	float mRotX[4][4] = {
		{1		,0		,0		,0},
		{0		,cosX	,-sinX	,0},
		{0		,sinX	,cosX	,0},
		{0		,0		,0		,1}
	};
	float mRotY[4][4] = {
		{cosY	,0	,sinY	,0},
		{0		,1	,0		,0},
		{-sinY	,0	,cosY	,0},
		{0		,0	,0		,1}
	};
	float mRotZ[4][4] = {
		{cosZ	,sinZ	,0	,0},
		{-sinY	,cosZ	,0	,0},
		{0		,0		,1	,0},
		{0		,0		,0	,1}
	};
	
	//float **s = multiMatrix(mRotX,mRotY);
	//multiMatrix(multiMatrix(multiMatrix(,mSca),mTra);
	drawBox();
	
	glPopMatrix();
	
	glutSwapBuffers();
}

void init(void)
{
	/* Use depth buffering for hidden surface elimination. */
	glEnable(GL_DEPTH_TEST);
	
	/* Setup the view of the cube. */
	glMatrixMode(GL_PROJECTION);
	gluPerspective( /* field of view in degree */ 80.0,
				   /* aspect ratio */ -1.0,
				   /* Z near */ 1.0, /* Z far */ 20.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(5.0, 5.0, 5.0,  /* eye is at (0,0,5) */
			  0.0, 0.0, 0.0,      /* center is at (0,0,0) */
			  0.0, 0.0, 1.0);      /* up is in positive Y direction */

	/* Adjust cube position to be asthetic angle. */
	//glTranslatef(0.0, 0.0, -1.0);
	//glRotatef(60, 1.0, 0.0, 0.0);
	//glRotatef(-20, 0.0, 0.0, 1.0);resi
}

/*
void antiTra(){
	for(int i=0;i<8;i++){
		
		float t1[3]={-tra[0],-tra[1],-tra[2]};
		float v1[3]={v[i][0] , v[i][1] , v[i][2]};
		
		
		float *point =	translate(	t1	,	v1	);
		float vec[3];
		v[i][0] = point[0];
		v[i][1] = point[1];
		v[i][2] = point[2];
	}
}

void proTra(){
	for(int i=0;i<8;i++){
		
		float t1[3]={tra[0],tra[1],tra[2]};
		float v1[3]={v[i][0] , v[i][1] , v[i][2]};
		
		
		float *point =	translate(	t1	,	v1	);
		float vec[3];
		v[i][0] = point[0];
		v[i][1] = point[1];
		v[i][2] = point[2];
	}
}
*/
/*
void antiRot(){
	for(int i=0;i<8;i++){
		
		float t1=-rot[0];
		float v1[3]={v[i][0] , v[i][1] , v[i][2]};
		
		float *point =	rotateX(	t1	,	v1	);
		float vec[3];
		v[i][0] = point[0];
		v[i][1] = point[1];
		v[i][2] = point[2];
	}
	for(int i=0;i<8;i++){
		
		float t1=-rot[1];
		float v1[3]={v[i][0] , v[i][1] , v[i][2]};
		
		float *point =	rotateY(	t1	,	v1	);
		float vec[3];
		v[i][0] = point[0];
		trav[i][1] = point[1];
		v[i][2] = point[2];
	}
	for(int i=0;i<8;i++){
		
		float t1=-rot[2];
		float v1[3]={v[i][0] , v[i][1] , v[i][2]};
		
		float *point =	rotateZ(	t1	,	v1	);
		float vec[3];
		v[i][0] = point[0];
		v[i][1] = point[1];
		v[i][2] = point[2];
	}
}
void proRot(){
	for(int i=0;i<8;i++){
		float t1=rot[0];
		float v1[3]={v[i][0] , v[i][1] , v[i][2]};
		float *point =	rotateX(	t1	,	v1	);
		float vec[3];
		v[i][0] = point[0];
		v[i][1] = point[1];
		v[i][2] = point[2];
	}
	for(int i=0;i<8;i++){
		
		float t1=rot[1];
		float v1[3]={v[i][0] , v[i][1] , v[i][2]};
		float *point =	rotateY(	t1	,	v1	);
		float vec[3];
		v[i][0] = point[0];
		v[i][1] = point[1];
		v[i][2] = point[2];
	}
	for(int i=0;i<8;i++){
		
		float t1=rot[2];
		float v1[3]={v[i][0] , v[i][1] , v[i][2]};
		float *point =	rotateZ(	t1	,	v1	);
		float vec[3];
		v[i][0] = point[0];
		v[i][1] = point[1];
		v[i][2] = point[2];
	}
}



*/

static void key(unsigned char key, int x, int y)
{
	
	
	switch (key)
	{
	case 27 :
	case 'q':
	case 'Q':
		tra[0]=tra[0]+0.5;
		/*for(int i=0;i<8;i++){
			float t1[3]={tra[0] , 0 , 0};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			float *point =	translate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
		}
		*/
		break;
	case 'w':
	case 'W':
		tra[0]=tra[0]-0.5;
		/*for(int i=0;i<8;i++){
			
			float t1[3]={tra[0] , 0 , 0};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			float *point =	translate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
		}
		*/
		break;
	case 'a':
	case 'A':
		tra[1]=tra[1]+0.5;
		/*for(int i=0;i<8;i++){
			float t1[3]={0,tra[1], 0};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			float *point =	translate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
		}
		*/
		break;
		
	case 's'://presiona p para pausar
	case 'S':
		tra[1]=tra[1]-0.5;
		/*for(int i=0;i<8;i++){
			
			float t1[3]={0,-0.5, 0};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			float *point =	translate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
		}
		*/
	
		break;
	case 'z'://presiona p para pausar
	case 'Z':
		tra[2]=tra[2]+0.5;
		/*for(int i=0;i<8;i++){
			
			float t1[3]={0,0,0.5};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			float *point =	translate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
		}*/
		break;
	case 'x'://presiona p para pausar
	case 'X':
		tra[2]=tra[2]-0.5;
		/*for(int i=0;i<8;i++){
			
			float t1[3]={0,0,-0.5};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			float *point =	translate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			

		}
		*/
		break;
	case 'e':
	case 'E':
		sca[0]=sca[0]*1.1;
		//destraslado
		//antiTra();
		/*for(int i=0;i<8;i++){
			float t1[3]={1.1,1,1};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
		}
		*/
		//proTra();
		
		
		break;
	case 'r':
	case 'R':
		
		sca[0]=sca[0]*0.9;
	/*
		
		//antiTra();
		//antiRot();
		for(int i=0;i<8;i++){
			
			float t1[3]={0.9,1,1};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
		}
		*/
		//proRot();
		//proTra();
		break;
	case 'd':
	case 'D':
		sca[1]=sca[1]*1.1;
		
		//antiTra();
		/*
		for(int i=0;i<8;i++){
			
			float t1[3]={1,1.1,1};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
		}
		*/
		//proTra();
		break;
	case 'f':
	case 'F':
		sca[1]=sca[1]*0.9;
		/*
		//antiTra();
		for(int i=0;i<8;i++){
			
			float t1[3]={1,0.9,1};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		}
		*/
		//proTra();
		break;
	case 'c':
	case 'C':
		sca[2]=sca[2]*1.1;
		/*
		//antiTra();
		for(int i=0;i<8;i++){
			
			float t1[3]={1,1,1.1};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		
		}
		*/
		//proTra();
		break;
	case 'v':
	case 'V':
		sca[2]=sca[2]*0.9;
		
		/*
		//antiTra();
		for(int i=0;i<8;i++){
			
			float t1[3]={1,1,0.9};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		}
		*/
		//proTra();
		break;
	case 't':
	case 'T':
		rot[0]=rot[0]+0.2;
		//antiTra();
		/*
		for(int i=0;i<8;i++){
			
			float t1=0.2;
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	rotateX(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
		}
		*/
		//proTra();
		break;
	case 'y':
	case 'Y':
		rot[0]=rot[0]-0.2;
		/*
		//antiTra();
		for(int i=0;i<8;i++){
			
			float t1=-0.2;
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	rotateX(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
		}
		*/
		//proTra();
		break;
	case 'g':
	case 'G':
		rot[1]=rot[1]+0.2;
		/*
		//antiTra();
		for(int i=0;i<8;i++){
			
			float t1=0.2;
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	rotateY(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
		}
		*/
		//proTra();
		break;
	case 'h':
	case 'H':
		rot[1]=rot[1]-0.2;
		
		/*
		//antiTra();
		for(int i=0;i<8;i++){
			
			float t1=-0.2;
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	rotateY(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		}
		*/
		//proTra();
		break;
	case 'b':
	case 'B':
		rot[2]=rot[2]+0.2;
		//antiTra();
		/*
		for(int i=0;i<8;i++){
			
			float t1=0.2;
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			float *point =	rotateZ(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		}
		*/
		//proTra();
		break;
	case 'n':
	case 'N':
		rot[2]=rot[2]-0.2;
		//antiTra();
		/*
		for(int i=0;i<8;i++){
			
			float t1=-0.2;
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	rotateZ(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		}
		*/
		//proTra();
		break;
	case 'm':
	case 'M':
		//reiniciar();
		break;
	case 'i':
	case 'I':
		/*
		for(int i=0;i<8;i++){
			
			float t1[3]={1,-1,-1};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v[i][0] = point[0];
			v[i][1] = point[1];
			v[i][2] = point[2];
			
			
		}
		*/
		break;
	case 'o':
	case 'O':
		for(int  i=0;i<8;i++){
			
			float t1[3]={-1,1,-1};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
		
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
		}
		
		
		break;
	case 'p':
	case 'P':
		for(int i=0;i<8;i++){
			
			float t1[3]={-1,-1,1};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
		}
		
		
		break;
		
	case '1':
		pibote[0] = pibote[0]+0.2;
		break;
	case '2':
		pibote[0] = pibote[0]-0.2;
		break;
	case '4':
		pibote[1] = pibote[1]+0.2;
		break;
	case '5':
		pibote[1] = pibote[1]-0.2;
		break;
	case '7':
		pibote[2] = pibote[2]+0.2;
		break;
	case '8':
		pibote[2] = pibote[2]-0.2;
		break;
	case '/':
		
		
		
		for(int i=0;i<8;i++){
				
		
			
			//float t1[3]={0,-0.5, 0};
			float t1[3]={-pibote[0] , -pibote[1] , -pibote[2]};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	translate(t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
		}
		
		//escalado
		for(int i=0;i<8;i++){
			
			float t1[3]={1.1,1.1,1.1};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		}
		
		for(int i=0;i<8;i++){
			
			
			
			float t1[3]={pibote[0] , pibote[1] , pibote[2]};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	translate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		}
		
		break;
	
		
	case '*':
		
		
		
		for(int i=0;i<8;i++){
			
			
			
			//float t1[3]={0,-0.5, 0};
			float t1[3]={-pibote[0] , -pibote[1] , -pibote[2]};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	translate(t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		}
		
		//escalado
		for(int i=0;i<8;i++){
			
			float t1[3]={0.9,0.9,0.9};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	scalate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		}
		
		for(int i=0;i<8;i++){
			
			
			
			float t1[3]={pibote[0] , pibote[1] , pibote[2]};
			float v1[3]={v[i][0] , v[i][1] , v[i][2]};
			
			
			float *point =	translate(	t1	,	v1	);
			float vec[3];
			v2[i][0] = point[0];
			v2[i][1] = point[1];
			v2[i][2] = point[2];
			
			
		}
		
		break;
		
	}
	
	glutPostRedisplay();
}


void girar(){
	
	const double t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
	GLfloat temp[8][3];
	/*for(int i=0;i<8;i++){
		temp[i][0]=v[i][0];
		temp[i][1]=cos(t)*(v[i][1])-sin(t)*v[i][2];
		temp[i][2]=sin(t)*v[i][0]+cos(t)*v[i][1]+v[i][2];
		v[i][0]=temp[i][0];
		v[i][1]=temp[i][1];
		v[i][2]=temp[i][2];
		system("clear");
		cout<<temp;
		
	}*/
		//v[1][0]=5;
//	cout<<"sd";
	
}

static void idle(void){
	cout<<tra[0]<<" "<<tra[1]<<" "<<tra[2]<<endl;
	girar();
	glutPostRedisplay();
}

int
	main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("red 3D lighted cube");
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	init();
	glutMainLoop();
	return 0;             /* ANSI C requires main to return int. */
}



