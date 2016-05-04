#include <ctime>
#include <iostream>
#include <stdio.h>

//WORKS QUITE FAST
/*
Dump of assembler code for function _Z4Testv:
   0x0000000000403ff0 <+0>:	    xorps  %xmm1,%xmm1
   0x0000000000403ff3 <+3>:	    xor    %eax,%eax
   0x0000000000403ff5 <+5>:	    movaps 0x8374(%rip),%xmm0        # 0x40c370
   0x0000000000403ffc <+12>:	nopl   0x0(%rax)
   0x0000000000404000 <+16>:	add    $0x1,%eax
   0x0000000000404003 <+19>:	addps  %xmm1,%xmm0
   0x0000000000404006 <+22>:	cmp    $0x3b9aca00,%eax
   0x000000000040400b <+27>:	jne    0x404000 <_Z4Testv+16>
   0x000000000040400d <+29>:	repz retq 
End of assembler dump.
*/
//Prøv at lave denne med float4 istedet for __m128 og se om det er samme resultat (det skulle det jo være!)
//I såfald, så prøv da med Vector, og se om det også er samme der, hvis ikke debug det.
//Start med at forstå overstående asm

__m128 Test()
{
    __m128 a = {1,1,1,1};
    __m128 b = {0,0,0,0};
    for(int x=0; x<1000000000; x++)
        a = a+b;
    return a;
}

void ArithmeticTest()
{   
    clock_t timer;
    register OpenEngine::Math::Vector<3,float> VP((float)rand(),(float)rand(),(float)rand());
    register OpenEngine::Math::Vector<3,float> Clear;
    register float Scalar = rand();
    std::cout << "ArithmeticTest" << std::endl;
    
    //Test1
    std::cout << "Scalar Addition" << std::endl;
    timer = clock();
    for(register int x=0; x<1000000000; x++)
    {
        register volatile OpenEngine::Math::Vector<3,float> a = VP+Scalar;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;
    
    //Test2
    std::cout << "Vector Addition" << std::endl;
    timer = clock();
    /*
    for(register int x=0; x<1000000000; x++)
    {
        register volatile OpenEngine::Math::Vector<3,float> a = VP+Clear;
    }
    */
    volatile __m128 a = Test();
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;
    
    //Test3
    std::cout << "Scalar Subtraction" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        volatile OpenEngine::Math::Vector<3,float> a = VP-Scalar;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;
    
    //Test4
    std::cout << "Vector Subtraction" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        volatile OpenEngine::Math::Vector<3,float> a = VP-Clear;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;

    //Test5
    std::cout << "Scalar multiplication" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        volatile OpenEngine::Math::Vector<3,float> a = VP*Scalar;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;
    
    //Test6
    std::cout << "Scalar division" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        volatile OpenEngine::Math::Vector<3,float> a = VP/Scalar;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;

    //Test7
    std::cout << "Additive Inverse" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
        volatile OpenEngine::Math::Vector<3,float> a = -VP;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;

    //Test8
    std::cout << "Destructive Scalar addition" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
       VP += Scalar;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;

    //Test9
    std::cout << "Destructive Vector addition" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
       VP += Clear;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;

    //Test10
    std::cout << "Destructive Scalar multiplication" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
       VP *= Scalar;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;

    //Test11
    std::cout << "Destructive Scalar subtraction" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
       VP -= Scalar;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;

    //Test12
    std::cout << "Destructive Scalar Divison" << std::endl;
    timer = clock();
    for(int x=0; x<1000000000; x++)
    {
       VP /= Scalar;
    }
    std::cout << "Timed Elapsed:\t" << (float)(((float)clock()-(float)timer)/(float)CLOCKS_PER_SEC) << std::endl;
    VP = Clear;
}
