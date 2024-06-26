
#include <iostream>
 
class Icon
{
    public:
    Icon() {}
    float speed, glow, energy;
    int x, y;
    virtual void move() = 0;
    virtual void flair() = 0;
};
 
class SpinIcon : public Icon
{
    bool clockwise; // need for spinner
    bool expand; // need for spinner
    
    public:
    SpinIcon() {}
    void spin() {}
    void move() { std::cout <<"spinner move"<<std::endl;}
    void flair() {std::cout <<"spinner flair"<<std::endl; }
};
 
class SlideIcon : public Icon
{
    public:
    SlideIcon() {}
    bool vertical; // need for slider
    int distance; // need for slider
    
    public:
    void slide() {}
    void move() {std::cout <<"slider move"<<std::endl;}
    void flair() {std::cout <<"slider flair"<<std::endl;}
};
 
class HopIcon : public Icon
{
    public:
    HopIcon() {}
    bool visible; // need for hopper
    int xcoord, ycoord; // need for hopper
    
    public:
    void hop() {}
    void move() {std::cout <<"hopper move"<<std::endl;}
    void flair() {std::cout <<"hopper flair"<<std::endl;}
};
 
int main() {
    SpinIcon obj1;
    obj1.move();
    obj1.flair();
    return 0;
}
