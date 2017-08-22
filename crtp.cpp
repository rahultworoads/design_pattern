// Image program (similar to above) to demonstrate
// working of CRTP
//Curiously recurring template pattern (CRTP)

#include <iostream>
#include <chrono>
using namespace std;
 
typedef std::chrono::high_resolution_clock Clock;
 
// To store dimensions of an image
class Dimension
{
public:
    Dimension(int _X, int _Y)
    {
        mX = _X;
        mY = _Y;
    }
private:
    int mX, mY;
};
 
// Base class for all image types. The template
// parameter T is used to know type of derived
// class pointed by pointer.
template <class T>
class Image
{
public:
    void Draw()
    {
        // Dispatch call to exact type
        static_cast<T*> (this)->Draw();
    }
    Dimension GetDimensionInPixels()
    {
        // Dispatch call to exact type
        static_cast<T*> (this)->GetDimensionInPixels();
    }
 
protected:
    int dimensionX, dimensionY;
};
 
 
// For Tiff Images
class TiffImage : public Image<TiffImage>
{
public:
    void Draw()
    {
        // Uncomment this to check method dispatch
        // cout << "TiffImage::Draw() called" << endl;
    }
    Dimension GetDimensionInPixels()
    {
        return Dimension(dimensionX, dimensionY);
    }
};
 
// There can be more derived classes like PngImage,
// BitmapImage, etc
 
// Driver code
int main()
{
    // An Image type pointer pointing to Tiffimage
    Image<TiffImage>* pImage = new TiffImage;
 
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