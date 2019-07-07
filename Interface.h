#ifndef Interface_Header
#define Interface_Header
#define GLFW_INCLUDE_GLU

// // #include <iostream>
// #include <cstdlib>
// #include <cstdio>
// #include <GLFW/glfw3.h>
// #include <string>
// #include <ctime>

#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

const char MAX(10); //or MAX = 10;

class RNG{
    private:
        struct Data1
	{char f_name[MAX]; //character array's
		char l_name[MAX];};
    
    int node_Counter;// counter if needed in the future..  

    public:
    Data1 Value[MAX]; //array of structures, saves session information for future features if needed..  
    void dMenu(); //display menu 
    void create_Rng(); //create rndom numbers
    void great(); //great user
    void cLs(); //custom clear screen
    void rngCheck(int check); // check-print number out 
};
#endif
