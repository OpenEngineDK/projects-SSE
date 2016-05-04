#include <ctime>
#include <iostream>

void DataAccessTest()
{   
    clock_t timer;
    OpenEngine::Math::Vector<3,float> VP;
    float *Array = new float[4];
    volatile float Temp;
    std::cout << "Vector 3 Constructor Test" << std::endl;
    
    //Test1
    std::cout << "[] Access" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        for(int y=0; y<3; y++)
            Temp = VP[y]; //To avoid the compiler optimizing it all away
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    
    //Test2
    std::cout << "Get Access" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        for(int y=0; y<3; y++)
            Temp = VP.Get(y); //To avoid the compiler optimizing it all away
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
        
    //Test3
    std::cout << "ToArray" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        Array = VP.ToArray();
        Array[0] -= 1; //To avoid the compiler optimizing it all away
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
        
    //Test4
    std::cout << "ToArray(*)" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        VP.ToArray(Array);
        Array[0] -= 1;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
        
    //Test5
    std::cout << "ToInt" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        volatile OpenEngine::Math::Vector<3,int> IP = VP.ToInt();
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;

    //Test6
    std::cout << "ToFloat" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        volatile OpenEngine::Math::Vector<3,float> FP = VP.ToFloat();
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;

    //Test7
    std::cout << "ToDouble" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        volatile OpenEngine::Math::Vector<3,double> DP = VP.ToDouble();
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    
    //delete[] Array;
}
