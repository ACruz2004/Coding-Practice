// This is for using OpenGL on Mac
// THIS WAS DONE USING XCODE ON MAC
// Shoutout to this dude for the MAC help https://github.com/zamirmf/OpenGLOnMac
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>

// Like explained in class the best way to go about displaying both the solid and the wireframe bots would be a bool.
bool displayWireMesh = false;
// If the model is toggled or not
bool displayModel = true;
// If the moved model is toggled or not
bool displayMovedModel = false;
// If axis is toggled or not
bool displayAxis = true;
// For Perspevtive view
bool orthoDisplay = true;
// For color toggle
bool isColored = true;
// For emoting
bool isControlled = false;
// For Rotation XYZ shizz
GLfloat Xrot = 0.0f;
GLfloat Yrot = 0.0f;
GLfloat Zrot = 0.0f;
// For Bot Movement
GLfloat Xmove = 0.0f;
GLfloat Ymove = 0.0f;
GLfloat Zmove = 0.0f;
// For Camera zoom (Like shown in class)
GLfloat cameraOrth = 5.0f;

// Size of the window
static size_t windowWidth = 500;         // Width
static size_t windowHeight = 500;        // Height

// Array of colors so color of robot can easily be set
// Error I ran into: I tried to set it as an array of ints, XCode yelled at me, make it an array of floats...
float roboColor[3] = {0.0f, 0.0f, 1.0f}; // Sets the color to blue

// This array of floats will store the old color so that it doesn't just go back to plain blue (that's boring)
float oldColor[3] = {0.0f, 0.0f, 0.0f};

// Make Robot
// I know he looks weird, be nice
void makeRobot() {
    if (displayModel) {
        // Head
        if (displayWireMesh == true) {
            glPushMatrix();
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(0, 0 + 2.0f, 0);
            glutWireSphere(1.0f, 10, 10);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glTranslatef(0, 0 + 2.0f, 0);
            glutSolidSphere(1.0f, 10, 10);
            glPopMatrix();
        }
        
        // Body
        if (displayWireMesh == true) {
            glPushMatrix();
            glTranslatef(0, 0, 0);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glTranslatef(0, 0, 0);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
        }
        
        // Arms
        // Right
        if (displayWireMesh == true) {
            glPushMatrix();
            glTranslatef(1.75, -.5 + .75, 0);
            glScaled(.4, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(1.75, -1.5 + .75, 0);
            glScaled(.4, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glTranslatef(1.75, -.5 + .75, 0);
            glScaled(.4, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(1.75, -1.5 + .75, 0);
            glScaled(.4, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
        }
        // Left
        if (displayWireMesh == true) {
            glPushMatrix();
            glTranslatef(-1.75, -.5 + .75, 0);
            glScaled(.4, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(-1.75, -1.5 + .75, 0);
            glScaled(.4, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glTranslatef(-1.75, -.5 + .75, 0);
            glScaled(.4, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(-1.75, -1.5 + .75, 0);
            glScaled(.4, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
        }
            
        // Legs
        // Right
        if (displayWireMesh == true) {
            glPushMatrix();
            glTranslatef(0.5, -2.95 + .75, 0);
            glScaled(.3, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
                
            // Bottom Half
            glPushMatrix();
            glTranslatef(0.5, -3.95 + .75, 0);
            glScaled(.3, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glTranslatef(0.5, -2.9 + .75, 0);
            glScaled(.3, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
                
            // Bottom Half
            glPushMatrix();
            glTranslatef(0.5, -3.95 + .75, 0);
            glScaled(.3, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
        }
        // Left
        if (displayWireMesh == true) {
            glPushMatrix();
            glTranslatef(-0.5, -2.95 + .75, 0);
            glScaled(.3, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
                
            // Bottom Half
            glPushMatrix();
            glTranslatef(-0.5, -3.95 + .75, 0);
            glScaled(.3, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glTranslatef(-0.5, -2.9 + .75, 0);
            glScaled(.3, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
                
            // Bottom Half
            glPushMatrix();
            glTranslatef(-0.5, -3.95 + .75, 0);
            glScaled(.3, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
        }
    }
}

// BONUS
// THIS WILL DISPLAY THE MOVED MODEL
// TOGGLED OFF AT FIRST
// MOVE MODEL WITH ARROW KEYS
void makeMovedModel() {
    if (displayMovedModel) {
        // The ground
        glPushMatrix();
        glTranslatef(0, -4.15, 0);
        glScaled(250, .1, 250);
        glColor3f(128, 128, 128);
        glutSolidCube(.5);
        glPopMatrix();
        
        // THIS WILL BE THE CONTROLLED MODEL CUZ I WANNA BE ABLE TO TOGGLE SMOOTHLY
        // Head
        if (displayWireMesh == true) {
            glPushMatrix();
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(0 + Xmove, 0 + 2.0f + Ymove, 0 + Zmove);
            glutWireSphere(1.0f, 10, 10);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glTranslatef(0 + Xmove, 0 + 2.0f + Ymove, 0 + Zmove);
            glutSolidSphere(1.0f, 10, 10);
            glPopMatrix();
        }
        
        // Body
        if (displayWireMesh == true) {
            glPushMatrix();
            glTranslatef(0 + Xmove, 0 + Ymove, 0 + Zmove);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glTranslatef(0 + Xmove, 0 + Ymove, 0 + Zmove);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
        }
        
        // Arms
        // Right
        if (displayWireMesh == true) {
            glPushMatrix();
            glTranslatef(1.75 + Xmove, -.5 + .75 + Ymove, 0 + Zmove);
            glScaled(.4, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(1.75 + Xmove, -1.5 + .75 + Ymove, 0 + Zmove);
            glScaled(.4, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glTranslatef(1.75 + Xmove, -.5 + .75 + Ymove, 0 + Zmove);
            glScaled(.4, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(1.75 + Xmove, -1.5 + .75 + Ymove, 0 + Zmove);
            glScaled(.4, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
        }
        // Left
        if (displayWireMesh == true) {
            glPushMatrix();
            glTranslatef(-1.75 + Xmove, -.5 + .75 + Ymove, 0 + Zmove);
            glScaled(.4, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(-1.75 + Xmove, -1.5 + .75 + Ymove, 0 + Zmove);
            glScaled(.4, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glTranslatef(-1.75 + Xmove, -.5 + .75 + Ymove, 0 + Zmove);
            glScaled(.4, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(-1.75 + Xmove, -1.5 + .75 + Ymove, 0 + Zmove);
            glScaled(.4, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
        }
        
        // Legs
        // Right
        if (displayWireMesh == true) {
            glPushMatrix();
            glTranslatef(0.5 + Xmove, -2.95 + .75 + Ymove, 0 + Zmove);
            glScaled(.3, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(0.5 + Xmove, -3.95 + .75 + Ymove, 0 + Zmove);
            glScaled(.3, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glTranslatef(0.5 + Xmove, -2.9 + .75 + Ymove, 0 + Zmove);
            glScaled(.3, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(0.5 + Xmove, -3.95 + .75 + Ymove, 0 + Zmove);
            glScaled(.3, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
        }
        // Left
        if (displayWireMesh == true) {
            glPushMatrix();
            glTranslatef(-0.5 + Xmove, -2.95 + .75 + Ymove, 0 + Zmove);
            glScaled(.3, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(-0.5 + Xmove, -3.95 + .75 + Ymove, 0 + Zmove);
            glScaled(.3, .75, .5);
            glColor3f(1, 1, 1);
            glutWireCube(2.5f);
            glPopMatrix();
        }
        else {
            glPushMatrix();
            glTranslatef(-0.5 + Xmove, -2.9 + .75 + Ymove, 0 + Zmove);
            glScaled(.3, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
            
            // Bottom Half
            glPushMatrix();
            glTranslatef(-0.5 + Xmove, -3.95 + .75 + Ymove, 0 + Zmove);
            glScaled(.3, .75, .5);
            glColor3f(roboColor[0], roboColor[1], roboColor[2]);
            glutSolidCube(2.5f);
            glPopMatrix();
        }
    }
}

// Make Axis
void makeAxis() {
    if (displayAxis == true) {
        // X
        glBegin(GL_LINES);
        glColor3f(GL_RED, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(3.5, 0, 0);
        glEnd();
        
        // Y
        glBegin(GL_LINES);
        glColor3f(0, GL_GREEN, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 3.5, 0);
        glEnd();
        
        // Z
        glBegin(GL_LINES);
        glColor3f(0, 0, GL_BLUE);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 3.5);
        glEnd();
        
    }
}

//actual bane of my exsistance
void MyDisplay() {
    // Clears the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(0, 0, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // I SWEAR TO GOD if I EVER run into a problem like this EVER AGAIN I'm DONE CODING FOR GOOD
    // had to set up the camera (took me two hours to figure out) but it was breaking my perspective view
    gluLookAt(0.0, 0.0, cameraOrth,0.0, 0.0, 0.0,0.0, 1.0, 0.0);

    
    // For the rotation
    glRotatef(Xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(Yrot, 0.0f, 1.0f, 0.0f);
    glRotatef(Zrot, 0.0f, 0.0f, 1.0f);
    
    // Display the robot
    makeRobot();
    
    // Display the moved robot
    makeMovedModel();
    
    // Display the Axis
    makeAxis();
    
    glFlush();
    glutSwapBuffers();
}

// Init
void init(void) {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (orthoDisplay == true && isControlled == false) {
        // Ortho
        glOrtho(-cameraOrth, cameraOrth, -cameraOrth, cameraOrth, -100, 100);
    } else if (orthoDisplay == false && isControlled == false){
        // Perspective (using frustrum like lecture 7 (shoutout Meldon thanks Meldon))
        // Changed this later to be the non controlled perspective cam
        glFrustum(-1.5, 1.5, -1.5, 1.5, 1, 100);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(2, 2, cameraOrth, 0, 0, 0, 0, 1, 0);
    } else if (isControlled == true){
        // This is the controlled perspective cam
        glFrustum(-1.5, 1.5, -1.5, 1.5, 1, 100);
        // left right bottom top
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(2, 2, cameraOrth, 0, 0, 0, 0, 1, 0);
    } else {
        orthoDisplay = true;
    }
    
}

// For Key Presses
void reqKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w':
            displayWireMesh = true;
            break;
        case 's':
            displayWireMesh = false;
            break;
        case 'c':
            displayModel = false;
            displayAxis =  false;
            break;
        case 'm':
            if (isControlled == false) {
                displayModel = true;
            }
            break;
        case 'a':
            if (displayAxis == true) {
                displayAxis = false;
            }
            else {
                displayAxis = true;
            }
            break;
        case 27: // escape
            exit(0);
    }
    // Resets Display After Each Key Input
    glutPostRedisplay();
}

// For Movement Key Presses
// This is a mix of the lecture notes and this site for the keypresses (arrow keys)
// https://faraznaqvi.wordpress.com/2017/08/19/how-to-move-an-object-in-opengl-with-keyboard-arrow-key-controlling/
void specialKeys(int key, int x, int y)
{
    switch (key)
    {
        // Left
        case GLUT_KEY_LEFT:
            if (isControlled == true) {
                Xmove = Xmove - .5;
            }
        break;
        //Right
        case GLUT_KEY_RIGHT:
            if (isControlled == true) {
                Xmove = Xmove + .5;
            }
        break;
        // Forward
        case GLUT_KEY_DOWN:
            if (isControlled == true) {
                Zmove = Zmove + .5;
            }
        break;
        // Backward
        case GLUT_KEY_UP:
            if (isControlled == true) {
                Zmove = Zmove - .5;
            }
        break;
        
    }
    // Resets Display After Each Key Input
    glutPostRedisplay();
}

// Mouse Function For Menus
void reqMouse(int button, int state, int x, int y) {
    // Left click function for changing colors from black to white
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (isColored == true) {
            // Store the old colors into a new array
            oldColor[0] = roboColor[0];
            oldColor[1] = roboColor[1];
            oldColor[2] = roboColor[2];
            // Change the current color to white
            roboColor[0] = 255.0f;
            roboColor[1] = 255.0f;
            roboColor[2] = 255.0f;
            // Set isColored to dalse
            isColored = false;
        }
        else {
            roboColor[0] = oldColor[0];
            roboColor[1] = oldColor[1];
            roboColor[2] = oldColor[2];
            // Set isColored to true
            isColored = true;
        }
    }
    // For scrolling (also like shown in class)
    if (button == 3) {
        if (state != GLUT_UP) {
            cameraOrth += 0.5;
            init();
        }
    }
    else if (button == 4) {
        if (state != GLUT_UP) {
            cameraOrth -= 0.5;
            init();
        }
    }
    // In case it bugs out on you, this will zoom him out
    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
        cameraOrth += 0.5;
        init();
    }
    glutPostRedisplay();
}


// The code for waht the menus will do
// I know it's long and kind of a silly goofy way to go about it, but it makes sense to me
void myMenu(int value) {
    // Rotations on X (1-5)
    if (value == 1) {
        Xrot += 30.0f;
    }
    if (value == 2) {
        Xrot += 60.0f;
    }
    if (value == 3) {
        Xrot += 90.0f;
    }
    if (value == 4) {
        Xrot += 120.0f;
    }
    if (value == 5) {
        Xrot += 180.0f;
    }
    
    // Rotations on Y (6-10)
    if (value == 6) {
        Yrot += 30.0f;
    }
    if (value == 7) {
        Yrot += 60.0f;
    }
    if (value == 8) {
        Yrot += 90.0f;
    }
    if (value == 9) {
        Yrot += 120.0f;
    }
    if (value == 10) {
        Yrot += 180.0f;
    }
    
    // Rotations on Z (11-15)
    if (value == 11) {
        Zrot += 30.0f;
    }
    if (value == 12) {
        Zrot += 60.0f;
    }
    if (value == 13) {
        Zrot += 90.0f;
    }
    if (value == 14) {
        Zrot += 120.0f;
    }
    if (value == 15) {
        Zrot += 180.0f;
    }
    
    // Views (16 & 17)
    if (value == 16) {
        orthoDisplay = true;
        init();
    }
    if (value == 17) {
        orthoDisplay = false;
        init();
    }
    
    // Colors (18-22)
    // Red
    if (value == 18) {
        roboColor[0] = 1.0f;
        roboColor[1] = 0.0f;
        roboColor[2] = 0.0f;
        isColored = true;
    }
    // Blue
    if (value == 19) {
        roboColor[0] = 0.0f;
        roboColor[1] = 0.0f;
        roboColor[2] = 1.0f;
        isColored = true;
    }
    // Green
    if (value == 20) {
        roboColor[0] = 0.0f;
        roboColor[1] = 1.0f;
        roboColor[2] = 0.0f;
        isColored = true;
    }
    // Yellow (had to look up past here cuz idk rgb codes like that (shoutout google))
    if (value == 21) {
        roboColor[0] = 255.0f;
        roboColor[1] = 255.0f;
        roboColor[2] = 0.0f;
        isColored = true;
    }
    // Pink
    if (value == 22) {
        roboColor[0] = 255.0f;
        roboColor[1] = 0.0f;
        roboColor[2] = 255.0f;
        isColored = true;
    }
    // Cyan
    if (value == 23) {
        roboColor[0] = 0.0f;
        roboColor[1] = 255.0;
        roboColor[2] = 255.0f;
        isColored = true;
    }
    
    // Movements
    // Off
    if (value == 24) {
        displayModel = true;
        displayMovedModel = false;
        isControlled = false;
        init();
    }
    // On
    if (value == 25) {
        // Turn off the OG model
        displayModel = false;
        displayMovedModel = true;
        Xrot += 30;
        Yrot -= 5;
        isControlled = true;
        init();
        
    }
    
    // A reset cuz I got tired of having the mesh spin everywhere
    if (value == 26) {
        if (isControlled == false) {
            Xrot = 0.0f;
            Yrot = 0.0f;
            Zrot = 0.0f;
        }
        else {
            Xrot = 30.0f;
            Yrot = -5.0f;
            Zrot = 0.0f;
        }
    }
    
    // Makes it update after every selection
    glutPostRedisplay();
}


void menus() {
    // Shoutout to the random no nammed person on google that showed how to do submenus
    //https://www.openglprojects.in/2013/03/adding-menu-to-opengl-projects.html#gsc.tab=0
    // Create the submenus for X, Y, Z rotations
    //./////////////////////////////////////////
    int xMenu = glutCreateMenu(myMenu);
    glutAddMenuEntry("30", 1);
    glutAddMenuEntry("60", 2);
    glutAddMenuEntry("90", 3);
    glutAddMenuEntry("120", 4);
    glutAddMenuEntry("180", 5);

    int yMenu = glutCreateMenu(myMenu);
    glutAddMenuEntry("30", 6);
    glutAddMenuEntry("60", 7);
    glutAddMenuEntry("90", 8);
    glutAddMenuEntry("120", 9);
    glutAddMenuEntry("180", 10);

    int zMenu = glutCreateMenu(myMenu);
    glutAddMenuEntry("30", 11);
    glutAddMenuEntry("60", 12);
    glutAddMenuEntry("90", 13);
    glutAddMenuEntry("120", 14);
    glutAddMenuEntry("180", 15);

    // Rotation Menu
    int rotationMenu = glutCreateMenu(myMenu);
    glutAddSubMenu("X", xMenu);
    glutAddSubMenu("Y", yMenu);
    glutAddSubMenu("Z", zMenu);
    glutAddMenuEntry("Reset", 26);
    //./////////////////////////////////////////
    
    
    
    // Create the submenus for view
    //./////////////////////////////////////////
    int viewMenu = glutCreateMenu(myMenu);
    glutAddMenuEntry("Orthographic", 16);
    glutAddMenuEntry("Perspective", 17);
    //./////////////////////////////////////////

    // Create the submenus for view
    //./////////////////////////////////////////
    int colorMenu = glutCreateMenu(myMenu);
    glutAddMenuEntry("Red", 18);
    glutAddMenuEntry("Blue", 19);
    glutAddMenuEntry("Green", 20);
    glutAddMenuEntry("Yellow", 21);
    glutAddMenuEntry("Pink", 22);
    glutAddMenuEntry("Cyan", 23);
    //./////////////////////////////////////////
    
    // EXTRA CREDIT ////////////////////////////
    int emoteMenu = glutCreateMenu(myMenu);
    glutAddMenuEntry("Off", 24);
    glutAddMenuEntry("On", 25);
    //./////////////////////////////////////////
    
    // Main Menu
    // This IS NOT AN ERROR, ITS A WARNING BUT REMOVING IT CRASHES EVERYTHING!!!!
    int mainMenu = glutCreateMenu(myMenu);
    //
    glutAddSubMenu("Rotations", rotationMenu);
    glutAddSubMenu("View", viewMenu);
    glutAddSubMenu("Color", colorMenu);
    glutAddSubMenu("Controller", emoteMenu);
    
    // Menus will display on right click
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc,char* argv[]){
    
    // Displaying the Window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(50, 50);
    // Shows my full name and Flashline
    glutCreateWindow("Anthony Cruz | 811190499");
    
    init();
    
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(reqKeys);
    glutMouseFunc(reqMouse);
    // For Movement
    glutSpecialFunc(specialKeys);
    
    menus();
    glutMainLoop();
    
    return 0;
}
