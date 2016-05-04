#include <ctime>
#include <iostream>

void VectorMathTest()
{   
    clock_t timer;
    OpenEngine::Math::Vector<3,float> VP((float)rand(),(float)rand(),(float)rand());
    OpenEngine::Math::Vector<3,float> VP2((float)rand(),(float)rand(),(float)rand());
    std::cout << "VectorMathTest" << std::endl;
    
    //Test1
    std::cout << "DotProduct" << std::endl;
    timer = clock();
    for(int x=0; x<100000000; x++)
    {
        volatile float a = VP*VP2;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    
    //Test2
    std::cout << "CrossProduct" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        volatile OpenEngine::Math::Vector<3,float> a = VP%VP2;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    
    //Test3
    std::cout << "GetLength" << std::endl;
    timer = clock();
    for(int x=0; x<100000000; x++)
    {
        volatile float a = VP.GetLength();
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    
    //Test4
    std::cout << "LengthSquared" << std::endl;
    timer = clock();
    for(int x=0; x<100000000; x++)
    {
        volatile float a = VP.GetLengthSquared();
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;

    //Test5
    std::cout << "GetNormalized" << std::endl;
    timer = clock();
    for(int x=0; x<100000000; x++)
    {
        volatile OpenEngine::Math::Vector<3,float> a = VP.GetNormalize();
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    
    //Test6
    std::cout << "Distance" << std::endl;
    timer = clock();
    for(int x=0; x<100000000; x++)
    {
        volatile float a = VP.Distance(VP2);
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;

    //Test7
    std::cout << "Max" << std::endl;
    timer = clock();
    for(int x=0; x<100000000; x++)
    {
        volatile float a = VP.Max();
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;

    //Test8
    std::cout << "Min" << std::endl;
    timer = clock();
    for(int x=0; x<100000000; x++)
    {
       volatile float a = VP.Max();
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;

    //Test9
    std::cout << "Sum" << std::endl;
    timer = clock();
    for(int x=0; x<100000000; x++)
    {
       volatile float a = VP.Sum();
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
}
