
#include <iostream>
// This can be a class, any class, doesn't matter

class WithSingleton
{

    private:

        static WithSingleton *instance; // Static instance of class
        int x, y; // Some member variables, they are here for testing

    public:
        // Default constructor, sets x and y to 1
    WithSingleton()
    {
        x = y = 1;
    }
    // Destructor
    ~WithSingleton()
    {
        if (instance)
        {
            delete instance;
            instance = NULL;
        }
    }
    // This is the accesor of our class.
    static WithSingleton *GetInstance()
    {
        // If the instance is NULL, then allocate memory
        if (instance == NULL)
            instance = new WithSingleton;
        // And return the created instance
        return instance;
    }
    // Some very very simple member functions, I don't think they need
    // explanation
    void SetXY(const int x, const int y)
    {
      this->x = x;
      this->y = y;
    }

    void print() const

    {
      std::cout << "x = " << x << std::endl;
      std::cout << "y = " << y << std::endl;
  }

};

// Initialize static member variable to prevent linkage errors

WithSingleton *WithSingleton::instance = NULL;

// This is my method. I usually declare a macro, to get rid

// of writing ClassName::GetMyInstance()  ...

#define CSingleInstance WithSingleton::GetInstance()

int main()
{
    // Use CSingleInstance EVERYWHERE in your program, this
    // is the universal accesor.
    CSingleInstance->SetXY(11, 20);
    CSingleInstance->print();

    return 0;
}
