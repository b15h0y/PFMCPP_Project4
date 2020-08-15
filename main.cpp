/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function
 
 6) clean up any forward declaration that you might have.
 
 7) make sure it compiles & runs without errors.
 
 8) use your knowledge of casting to remove any conversion warnings. 

 9) insert 'part3();' before the 'good to go' at the end of your main(); 
        move this part3 function to before main()

 10) click the [run] button.  Clear up any errors or warnings as best you can.

 */


/*
your program should generate the following output EXACTLY.
This includes the warnings.
The output should have zero warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 

FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^3 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
good to go!




*/

struct A {};
//=========================================
struct HeapA
{  
    A* ptr;
    HeapA() : ptr(new A())
    {

    }
    ~HeapA()
    {
        delete ptr;
        ptr = nullptr;
    }
};

#include <iostream>

struct IntType;
struct DoubleType;

struct FloatType
{
private:
    float* pt;
public:    
    FloatType(float fl):pt(new float(fl))
    {
    }
    ~FloatType()
    {
        delete pt;
        pt = nullptr;
    }

    FloatType& add( float val );
    FloatType& subtract( float val );
    FloatType& multiply( float val );
    FloatType& divide( float val );
    operator float() { return *pt; }
};

struct DoubleType
{
private:
    double* pt;
public:    
    DoubleType(double dbl):pt(new double(dbl))
    {
    }
    ~DoubleType()
    {
        delete pt;
        pt = nullptr;
    }
    
    DoubleType& add( double val );
    DoubleType& subtract( double val );
    DoubleType& multiply( double val );
    DoubleType& divide( double val );
    operator double() { return *pt; }
};

struct IntType
{
private:    
    int* pt;
public:    
    IntType(int val):pt(new int(val))
    {
    }
    ~IntType()
    {
        delete pt;
        pt = nullptr;
    }
    IntType& add( int val );
    IntType& subtract( int val );
    IntType& multiply( int val );
    IntType& divide( int val );
    operator int() { return *pt; }
};

FloatType& FloatType::add( float val )
{
    *pt += val;
    return *this;
}

FloatType& FloatType::subtract( float val)
{
    *pt -= val;
    return *this;
}

FloatType& FloatType::multiply( float val )
{
    *pt *= val;
    return *this;
}
FloatType& FloatType::divide( float val )
{
    if(val == 0.0f)
    {
        std::cout << "warning, floating point division by zero!" << "\n";
    }
    *pt /= val;
    return *this;
}

//=======================================================
//=======================================================
DoubleType& DoubleType::add( double val )
{
    *pt += val;
    return *this;
}

DoubleType& DoubleType::subtract( double val )
{
    *pt -= val;
    return *this;
}

DoubleType& DoubleType:: multiply( double val )
{
    *pt *= val;
    return*this;
}

DoubleType& DoubleType::divide( double val)
{
    if(val == 0.0)
    {
        std::cout << "warning, floating point division by zero!" << "\n";
    }
    *pt /= val;
    return *this;
}

//=======================================================
//=======================================================
IntType& IntType::add( int val )
{
    *pt += val;
    return *this;
}

IntType& IntType::subtract( int val )
{
    *pt -= val;
    return *this;
}

IntType& IntType::multiply( int val )
{
    *pt *= val;
    return *this;
}
IntType& IntType::divide( int val )
{
    if(val == 0)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" << "\n";
    }
    else
    {
        *pt /= val;
    }
    return *this;
}

//=======================================================
//=======================================================
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */



void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^3 divided by IntType is: " << ft.multiply( static_cast<float> (ft) ).multiply( static_cast<float> (ft) ).divide( static_cast<float> (it) ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply(static_cast<double> (3) ).add( static_cast<double> (it) ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( static_cast<int> (pi) ).multiply( static_cast<int> (dt) ).subtract( static_cast<int> (ft) ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide( static_cast<int> (0.0f) ).divide( static_cast<int> (0.0) ) << std::endl;
    
    std::cout << "FloatType x IntType  =  " << it.multiply( static_cast<int> (ft) ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( static_cast<int> (dt) ).add( static_cast<int> (ft) ).multiply( 24 ) << std::endl;
}

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ) << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ) << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ) << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f) << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0) << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0) << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0) << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(static_cast<double> (5.f) ) << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2) << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2) << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2) << std::endl;
    std::cout << "IntType divide result=" << it.divide(3) << std::endl << std::endl;
    std::cout << "Chain calculation = " << it.multiply(1000).divide(2).subtract(10).add(100) << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f) << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt << std::endl;
    std::cout << "Initial value of it: " << it << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (dt.multiply(static_cast<double>(it)).divide(static_cast<double>(5.0f)).add(static_cast<double>(ft))) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0) << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0) << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    part3();
    std::cout << "good to go!\n";

    return 0;
}

/*
your program should generate the following output.  
Use a service like https://www.diffchecker.com/diff to compare your output. 
you should have no errors or warnings.


clang++ -std=c++17 -Weverything -Wno-c++98-compat -Wno-missing-prototypes main.cpp && ./a.out
result of ft.add(): 555.556
result of ft.subtract(): -308.644
result of ft.multiply(): 53345.3
result of ft.divide(): 0.285712
result of ft.add(): 4444.56
result of ft.subtract(): 4444.56
result of ft.multiply(): 0
result of ft.divide(): 
warning, floating point division by zero returns 'inf' !
inf
result of db.add(): 555.556
result of db.subtract(): -308.644
result of db.multiply(): 53345.3
result of db.divide(): 0.285712
result of db.add(): 123.456
result of db.subtract(): 123.456
result of db.multiply(): 0
result of db.divide(): 
warning, floating point division by zero returns 'inf' !
inf
result of i.add(): 30
result of i.subtract(): -10
result of i.multiply(): 200
result of i.divide(): 0
result of i.add(): 10
result of i.subtract(): 10
result of i.multiply(): 0
result of i.divide(): error, integer division by zero will crash the program!
returning lhs
10
good to go!
*/
