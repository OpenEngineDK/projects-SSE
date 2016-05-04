//Math
#include <Math/Vector.h>

// Logging
#include <Logging/Logger.h>
#include <Logging/StreamLogger.h>

// Test Modules
#include "ConstructorTest.h"
#include "DataAccessTest.h"
#include "ArithmeticTest.h"
#include "VectorMathTest.h"

int main(int argc, char** argv)
{    
    //ConstructorTest();
    //DataAccessTest();
    ArithmeticTest();
    VectorMathTest();
      
    // Return when the engine stops.
    return EXIT_SUCCESS;
}


