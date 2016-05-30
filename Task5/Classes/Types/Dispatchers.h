#pragma once
#include <iostream>

// example classes
class Shape
{
public:
    virtual void method()
    {

    }
};

class Rectangle : public Shape
{
public:
    void method() override
    {

    }
};

class Circle : public Shape
{
public:
    void method() override
    {

    }
};

// Dispatcher

class SymmetricTripleLinearDispatcher
{
public:
    static void dispatch(Shape* x, Shape* y, Shape* z)
    {
        if (Rectangle* rx = dynamic_cast<Rectangle*>(x))
        {
             if (Rectangle* ry = dynamic_cast<Rectangle*>(y))
             {
                 if (Rectangle* rz = dynamic_cast<Rectangle*>(z))
                 {
                     dispatch(rx, ry, rz);
                 }
                 else if (Circle* cz = dynamic_cast<Circle*>(z))
                 {
                     dispatch(rx, ry, cz);
                 }
             }
             else if (Circle* cy = dynamic_cast<Circle*>(y))
             {
                 if (Rectangle* rz = dynamic_cast<Rectangle*>(z))
                 {
                     dispatch(rx, rz, cy);
                 }
                 else if (Circle* cz = dynamic_cast<Circle*>(z))
                 {
                     dispatch(rx, cy, cz);
                 }
             }
        }
        else if (Circle* cx = dynamic_cast<Circle*>(x))
        {
            if (Rectangle* ry = dynamic_cast<Rectangle*>(y))
            {
                if (Rectangle* rz = dynamic_cast<Rectangle*>(z))
                {
                    dispatch(rz, ry, cx);
                }
                else if (Circle* cz = dynamic_cast<Circle*>(z))
                {
                    dispatch(ry, cx, cz);
                }
            }
            else if (Circle* cy = dynamic_cast<Circle*>(y))
            {
                if (Rectangle* rz = dynamic_cast<Rectangle*>(z))
                {
                    dispatch(rz, cy, cx);
                }
                else if (Circle* cz = dynamic_cast<Circle*>(z))
                {
                    dispatch(cx, cy, cz);
                }
            }
        }
        else
        {
            std::cout << "Error" << std::endl;
        }
    }

private:

    static void dispatch(Rectangle* x, Rectangle* y, Rectangle* z)
    {
        std::cout << "RRR" << std::endl;
    }

    static void dispatch(Rectangle* x, Rectangle* y, Circle* z)
    {
        std::cout << "RRC" << std::endl;
    }

    static void dispatch(Rectangle* x, Circle* y, Circle* z)
    {
        std::cout << "RCC" << std::endl;
    }

    static void dispatch(Circle* x, Circle* y, Circle* z)
    {
        std::cout << "CCC" << std::endl;
    }
};
