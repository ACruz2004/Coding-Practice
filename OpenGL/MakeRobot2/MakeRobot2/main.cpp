// This is for using OpenGL on Mac
// THIS WAS DONE USING XCODE ON MAC
// Shoutout to this dude for the MAC help https://github.com/zamirmf/OpenGLOnMac
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

// Like explained in class the best way to go about displaying both the solid and the wireframe bots would be a bool.
bool displayWireMesh = false;
// If axis is toggled or not
bool displayAxis = true;
// If the model is toggled or not
bool displayModel = true;

// Size of the window
static size_t windowWidth = 500;         // Width
static size_t windowHeight = 500;        // Height

// Array of colors so color of robot can easily be set
float roboColor[3] = {0.0f, 0.0f, 1.0f}; // Sets the color to blue
// This array of floats will store the old color so that it doesn't just go back to plain blue (that's boring)
float oldColor[3] = {0.0f, 0.0f, 0.0f};

// Camera stuff
// Actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;

// XZ position of the camera
float x = 0.0f, z = 15.0f;

// Angle for rotating triangle
float angle = 0.0f;

// Define the number of robots
const int numRobots = 16;

// The arrays with the random numbers being used by the random robots
int randomX[numRobots];
int randomZ[numRobots];

// NOW THE FUN PART, Le joints
static int shoulderAngle = 0, elbowAngle = 0;
static int legAngle = 0, kneeAngle = 0;

// FOR BOINUS ////////////////////////////////////////
bool isZombies = false;
int movedX[numRobots];
int movedZ[numRobots];

//Making the robot limbs a new way
void wireBox(GLdouble width, GLdouble height, GLdouble depth) {
    glPushMatrix();
    glScalef(width, height, depth);
    glutWireCube(1.0);
    glPopMatrix();
}

void solidBox(GLdouble width, GLdouble height, GLdouble depth) {
    glPushMatrix();
    glScalef(width, height, depth);
    glutSolidCube(1.0);
    glPopMatrix();
}

// Make Robot
// I know he still looks weird, be nice
void makeRobot() {
    if (displayModel) {
        // Head 1
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
        
        // Body 2
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
        
        // The limbs
        if (displayWireMesh == true) {
            // Right Arm (Wireframe)
            glPushMatrix();
            glTranslatef(1.0, 1.0, 0.0); // Position at the right shoulder
            glRotatef((GLfloat)shoulderAngle, 0.0, 0.0, 1.0); // Rotate the shoulder
            glTranslatef(1.0, 0.0, 0.0); // Move to the end of the upper arm
            wireBox(2.0, 0.8, 1.0); // Draw the upper arm

            glTranslatef(1.0, 0.0, 0.0); // Move to the end of the lower arm
            glRotatef((GLfloat)elbowAngle, 0.0, 0.0, 1.0); // Rotate the elbow
            glTranslatef(1.0, 0.0, 0.0); // Move to the end of the forearm
            wireBox(2.0, 0.8, 1.0); // Draw the lower arm
            glPopMatrix();

            // Left Arm (Wireframe)
            glPushMatrix();
            glTranslatef(-1.0, 1.0, 0.0); // Position at the left shoulder
            glRotatef((GLfloat)-shoulderAngle, 0.0, 0.0, 1.0); // Rotate the shoulder
            glTranslatef(-1.0, 0.0, 0.0); // Move to the end of the upper arm
            wireBox(2.0, 0.8, 1.0); // Draw the upper arm

            glTranslatef(-1.0, 0.0, 0.0); // Move to the end of the lower arm
            glRotatef((GLfloat)-elbowAngle, 0.0, 0.0, 1.0); // Rotate the elbow
            glTranslatef(-1.0, 0.0, 0.0); // Move to the end of the forearm
            wireBox(2.0, 0.8, 1.0); // Draw the lower arm
            glPopMatrix();
            
            // Right Leg (wireframe)
            glPushMatrix();
            glTranslatef(1.0, -1.0, 0.0); // Position at the left leg
            glRotatef((GLfloat)legAngle, 1.0, 0.0, 0.0); // Rotate the leg
            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the upper leg
            wireBox(0.8, 2.0, 1.0); // Draw the upper leg

            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the lower leg
            glRotatef((GLfloat)kneeAngle, 1.0, 0.0, 0.0); // Rotate the knee
            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the knee area?
            wireBox(0.8, 2.0, 1.0); // Draw the lower lrg
            glPopMatrix();

            // Left Leg (Wireframe)
            glPushMatrix();
            glTranslatef(-1.0, -1.0, 0.0); // Position at the left leg
            glRotatef((GLfloat)-legAngle, 1.0, 0.0, 0.0); // Rotate the leg
            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the upper leg
            wireBox(0.8, 2.0, 1.0); // Draw the upper leg

            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the lower leg
            glRotatef((GLfloat)-kneeAngle, 1.0, 0.0, 0.0); // Rotate the knee
            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the knee area?
            wireBox(0.8, 2.0, 1.0); // Draw the lower leg
            glPopMatrix();
        }
        else {
            // Right Arm (Solid)
            glPushMatrix();
            glTranslatef(1.0, 1.0, 0.0); // Position at the right shoulder
            glRotatef((GLfloat)shoulderAngle, 0.0, 0.0, 1.0); // Rotate the shoulder
            glTranslatef(1.0, 0.0, 0.0); // Move to the end of the upper arm
            solidBox(2.0, 0.8, 1.0); // Draw the upper arm

            glTranslatef(1.0, 0.0, 0.0); // Move to the end of the lower arm
            glRotatef((GLfloat)elbowAngle, 0.0, 0.0, 1.0); // Rotate the elbow
            glTranslatef(1.0, 0.0, 0.0); // Move to the end of the forearm
            solidBox(2.0, 0.8, 1.0); // Draw the lower arm
            glPopMatrix();

            // Left Arm (Solid)
            glPushMatrix();
            glTranslatef(-1.0, 1.0, 0.0); // Position at the left shoulder
            glRotatef((GLfloat)-shoulderAngle, 0.0, 0.0, 1.0); // Rotate the shoulder
            glTranslatef(-1.0, 0.0, 0.0); // Move to the end of the upper arm
            solidBox(2.0, 0.8, 1.0); // Draw the upper arm

            glTranslatef(-1.0, 0.0, 0.0); // Move to the end of the lower arm
            glRotatef((GLfloat)-elbowAngle, 0.0, 0.0, 1.0); // Rotate the elbow
            glTranslatef(-1.0, 0.0, 0.0); // Move to the end of the forearm
            solidBox(2.0, 0.8, 1.0); // Draw the lower arm
            glPopMatrix();
            
            // Right Leg (Solid)
            glPushMatrix();
            glTranslatef(1.0, -1.0, 0.0); // Position at the left leg
            glRotatef((GLfloat)legAngle, 1.0, 0.0, 0.0); // Rotate the leg
            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the upper leg
            solidBox(0.8, 2.0, 1.0); // Draw the upper leg

            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the lower leg
            glRotatef((GLfloat)kneeAngle, 1.0, 0.0, 0.0); // Rotate the knee
            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the knee area?
            solidBox(0.8, 2.0, 1.0); // Draw the lower lrg
            glPopMatrix();

            // Left Leg (Solid)
            glPushMatrix();
            glTranslatef(-1.0, -1.0, 0.0); // Position at the left leg
            glRotatef((GLfloat)-legAngle, 1.0, 0.0, 0.0); // Rotate the leg
            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the upper leg
            solidBox(0.8, 2.0, 1.0); // Draw the upper leg

            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the lower leg
            glRotatef((GLfloat)-kneeAngle, 1.0, 0.0, 0.0); // Rotate the knee
            glTranslatef(0.0, -1.0, 0.0); // Move to the end of the knee area?
            solidBox(0.8, 2.0, 1.0); // Draw the lower leg
            glPopMatrix();
        }
        glPopMatrix();
    }
}

void makeRandomNumbers() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < numRobots; ++i) {
        randomX[i] = (rand() % 101) - 50; // Random number between -50 and 50
        randomZ[i] = (rand() % 101) - 50; // Random number between -50 and 50
    }
    // Make moved coords for zombies
    for (int i = 0; i < numRobots; ++i) {
        movedX[i] = randomX[i];
        movedZ[i] = randomZ[i];
    }
}

// Draw ground plane
void drawGround() {
    glColor3f(0.8f, 0.8f, 0.9f);
    glBegin(GL_QUADS);
    glVertex3f(-1000.0f, -5.0f, -1000.0f);
    glVertex3f(-1000.0f, -5.0f, 1000.0f);
    glVertex3f(1000.0f, -5.0f, 1000.0f);
    glVertex3f(1000.0f, -5.0f, -1000.0f);
    glEnd();
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

// Keys for project
void reqKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
        case '1': // 1 Wire Mesh
            displayWireMesh = true;
            break;
            
        case '2': // 2 Solid Mesh
            displayWireMesh = false;
            break;
            
        case '3': // 3 Display the Axis
            if (displayAxis) {
                displayAxis = false;
            } else {
                displayAxis = true;
            }
            break;
            
        case '4': // 4 Increasing the elbow angle
            (elbowAngle += 5) %= 360; break;
            
        case '5': // 5 Increasing the shoulder angle
            (shoulderAngle += 5) %= 360; break;
            
        case '6': // 5 Increasing the leg angle
            (legAngle += 5) %= 360; break;
            
        case '7': // 5 Increasing the knee angle
            (kneeAngle += 5) %= 360; break;

        case 27: // escape
            exit(0);

    }
    // Resets Display After Each Key Input
    glutPostRedisplay();
}

// Special Keys
void specialKeys(int key, int xx, int yy)
{
    float fraction = 0.15f;
    switch (key)
    {
        // F4 Decreasing the elbow angle
        case GLUT_KEY_F4:
            (elbowAngle -= 5) %= 360; break;
            
        // F5 Decreasing the shoulder angle
        case GLUT_KEY_F5:
            (shoulderAngle -= 5) %= 360; break;
            
        // F5 Decreasing the leg angle
        case GLUT_KEY_F6:
            (legAngle -= 5) %= 360; break;
            
        // F5 Decreasing the knee angle
        case GLUT_KEY_F7:
            (kneeAngle -= 5) %= 360; break;
            
        case GLUT_KEY_LEFT:
            angle -= 0.1f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT:
            angle += 0.1f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP:
            x = x += lx * fraction;
            z = z += lz * fraction;
            break;
        case GLUT_KEY_DOWN:
            x = x -= lx * fraction;
            z = z -= lz * fraction;
            break;
        
    }
    // THE BELOW CODE IS FOR THE BONUS
    // Trying to figure out a decent way to reset the positions was a pain so I'm doing it when it refreshes the key presses
    // Update moved positions for zombies
        if (isZombies) {
            for (int i = 0; i < numRobots; i++) {
                // Move the robots towards the camera
                // If the bot is right and above it
                if (movedX[i] >= x && movedZ[i] >= z) {
                    movedX[i] = movedX[i] -= 0.01f; // Move left
                    movedZ[i] = movedZ[i] -= 0.01f; // Move down
                }
                // If the bot is right and below it
                if (movedX[i] >= x && movedZ[i] <= z) {
                    movedX[i] = movedX[i] -= 0.01f; // Move left
                    movedZ[i] = movedZ[i] += 0.01f; // Move up
                }
                // If the bot is left and above it
                if (movedX[i] <= x && movedZ[i] >= z) {
                    movedX[i] = movedX[i] += 0.01f; // Move right
                    movedZ[i] = movedZ[i] -= 0.01f; // Move down
                }
                // If the bot is left and below it
                if (movedX[i] <= x && movedZ[i] <= z) {
                    movedX[i] = movedX[i] += 0.01f; // Move right
                    movedZ[i] = movedZ[i] += 0.01f; // Move up
                }
            }
            shoulderAngle = shoulderAngle + 5;
            elbowAngle = elbowAngle + 5;
            legAngle = legAngle + 5;
            kneeAngle = kneeAngle + 5;
        }

    // Resets Display After Each Key Input
    glutPostRedisplay();
}

// Making the displays
void MyDisplay() {
    // Clears the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Reset transforms
    glLoadIdentity();
    // Set the camera (like the class example)
    gluLookAt(x, 1.0f, z, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
    
    // Make the Ground
    drawGround();
    // Display the main bot
    makeRobot();
    // Draw 16 Robots
    // If it's project view, the robots should be drawn normally, if not, they should increase/decrease their x/z cordinates to follow the camera
    if (isZombies == false) {
        for (int i = 0; i < 15; i++) {
            glPushMatrix();
            glTranslatef(randomX[i], 0,randomZ[i]);
            makeRobot();
            glPopMatrix();
        }
    }
    // This is genuinely the dumbest way possible to do this buuuuuuuuut
    if (isZombies == true) {
        for (int i = 0; i < 15; i++) {
            glPushMatrix();
            glTranslatef(movedX[i], 0,movedZ[i]);
            makeRobot();
            glPopMatrix();
        }
    }
    // Display the Axis
    makeAxis();
    glutSwapBuffers();
}

// Init
void init(void) {
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)windowWidth / (double)windowHeight, 1.0, 100.0); // Use perspective projection
    glMatrixMode(GL_MODELVIEW);
}

// Functions for the menus to follow
void myMenu(int value) {
    // IsZombiesFalse
    if (value == 1) {
        isZombies = false;
        roboColor[0] = 0.0f;
        roboColor[1] = 0.0f;
        roboColor[2] = 1.0f;
    }
    // IsZombiesFalse
    if (value == 2) {
        isZombies = true;
        roboColor[0] = 1.0f;
        roboColor[1] = 0.0f;
        roboColor[2] = 0.0f;
    }
    // Reset (Resets Everything)
    if (value == 3) {
        int movedX[numRobots];
        int movedZ[numRobots];
        shoulderAngle = 0;
        elbowAngle = 0;
        legAngle = 0;
        kneeAngle = 0;
    }
    
    // Makes it update after every selection
    glutPostRedisplay();
}

// Creating extra menus for testing and bonus
void menus() {
    // Create the submenus for view
    //./////////////////////////////////////////
    int modeMenu = glutCreateMenu(myMenu);
    glutAddMenuEntry("Project", 1);
    glutAddMenuEntry("Zombies", 2);
    //./////////////////////////////////////////

    // Main Menu
    // This IS NOT AN ERROR, ITS A WARNING BUT REMOVING IT CRASHES EVERYTHING!!!!
    int mainMenu = glutCreateMenu(myMenu);
    glutAddSubMenu("Modes", modeMenu);
    glutAddMenuEntry("Reset", 3);
    
    // Menus will display on right click
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc,char* argv[]){
    // Printing the jawn
    printf("\n\
    ----------------------------------------------------------------------------\n\
    OpenGL Assignment 2:\n\
      IF YOU SPAWN INSIDE OF A BLUE MESS WALK FORWARD \n\
    - '1': Display the wireframe model \n\
    - '2': Display the solid model\n\
    - '3': Toggle on/off the axes \n\
    - '4': Increase the elbow angle by 5 deg (Left and Right)\n\
    - '5': Increase the shoulder angle by 5 deg (Left and Right)\n\
    - '6': Increase the leg angle by 5 deg (Left and Right)\n\
    - '7': Increase the knee angle by 5 deg (Left and Right)\n\
    Special Keys\n\
    - 'F4': Decrease the elbow angle by 5 deg (Left and Right)\n\
    - 'F5': Decrease the shoulder angle by 5 deg (Left and Right)\n\
    - 'F6': Decrease the leg angle by 5 deg (Left and Right)\n\
    - 'F7': Decrease the knee angle by 5 deg (Left and Right)\n\
    - 'Up Arrow': Move the camera forward\n\
    - 'Down Arrow': Move the camera backward\n\
    - 'Left Arrow': Roatate the camera left\n\
    - 'Right Arrow': Rotate the camera right\n\
    Menu\n\
    - 'Modes': Either the Project mode or Zombies (In Zombies the meshes basically swarm you when you move) \n\
    - 'Reset': Resets the angles and the positions (if in zombies)\n\
    - ESC to quit \n\
    ----------------------------------------------------------------------------\n");
    
    // Displaying the Window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    // Shows my full name and Flashline
    glutCreateWindow("Anthony Cruz | 811190499");
    glutDisplayFunc(MyDisplay);
    glutIdleFunc(MyDisplay);
    
    init();
    makeRandomNumbers();
    
    // Keys
    glutKeyboardFunc(reqKeys);
    glutSpecialFunc(specialKeys);

    menus();
    glutMainLoop();
    
    return 0;
}
