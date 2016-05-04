#include <ctime>
#include <iostream>

#include <Math/RandomGenerator.h>

void ConstructorTest()
{   
    OpenEngine::Math::RandomGenerator r;
    clock_t timer;
    OpenEngine::Math::Vector<3,float> *VP;
    OpenEngine::Math::Vector<3,float> Copy;
    float Array[4] = {r.UniformFloat(-rand(),rand()), r.UniformFloat(-rand(),rand()), r.UniformFloat(-rand(),rand()), r.UniformFloat(-rand(),rand())};
    std::cout << "Vector 3 Constructor Test" << std::endl;
    
    //Test1
    std::cout << "Default Constructor" << std::endl;
    timer = clock();
    for(int x=0; x<10000000; x++)
    {
        VP = new OpenEngine::Math::Vector<3,float>();
        delete VP;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    
    //Test2
    std::cout << "Scalar Constructor" << std::endl;
    timer = clock();
    for(int x=0; x<10000000; x++)
    {
        VP = new OpenEngine::Math::Vector<3,float>(r.UniformFloat(-rand(),rand()));
        delete VP;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    
    //Test3
    std::cout << "Copy Constructor" << std::endl;
    timer = clock();
    for(int x=0; x<10000000; x++)
    {
        VP = new OpenEngine::Math::Vector<3,float>(Copy);
        delete VP;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    
    //Test4
    std::cout << "Equal" << std::endl;
    timer = clock();
    VP = new OpenEngine::Math::Vector<3,float>;
    for(int x=0; x<10000000; x++)
        *VP = Copy;
    delete VP;
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;

    //Test5
    std::cout << "Array Constructor" << std::endl;
    timer = clock();
    for(int x=0; x<10000000; x++)
    {
        VP = new OpenEngine::Math::Vector<3,float>(Array);
        delete VP;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;

    //Test6
        std::cout << "3Element Constructor" << std::endl;
    timer = clock();
    for(int x=0; x<10000000; x++)
    {
        VP = new OpenEngine::Math::Vector<3,float>(r.UniformFloat(-rand(),rand()), r.UniformFloat(-rand(),rand()), r.UniformFloat(-rand(),rand()));
        delete VP;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
}
