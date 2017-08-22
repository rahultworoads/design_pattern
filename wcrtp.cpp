// A simple C++ program to demonstrate run-time 
// polymorphism
#include <iostream>
#include <chrono>
using namespace std;
 
typedef std::chrono::high_resolution_clock Clock;
 
// To store dimensions of an image
class Dimension
{
public:
    Dimension(int _X, int _Y) {mX = _X;  mY = _Y; }
private:
    int mX, mY;
};
 
// Base class for all image types
class Image
{
public:
    virtual void Draw() = 0;
    virtual Dimension GetDimensionInPixels() = 0;
protected:
    int dimensionX;
    int dimensionY;
};
 
// For Tiff Images
class TiffImage : public Image
{
public:
    void Draw() { }
    Dimension GetDimensionInPixels() {
        return Dimension(dimensionX, dimensionY);
    }
};
 
// There can be more derived classes like PngImage, 
// BitmapImage, etc
 
// Driver code that calls virtual function
int main()
{
    // An image type  
    Image* pImage = new TiffImage;
 
    // Store time before virtual function calls
    auto then = Clock::now();
 
    // Call Draw 1000 times to make sure performance
    // is visible
    for (int i = 0; i < 1000; ++i)
        pImage->Draw();
 
    // Store time after virtual function calls
    auto now = Clock::now();
 
    cout << "Time taken: "
         << std::chrono::duration_cast
           <std::chrono::nanoseconds>(now - then).count()
         << " nanoseconds" << endl;
 
    return 0;
}