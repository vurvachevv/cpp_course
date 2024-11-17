#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>
#include <vector>
#include <string>

using namespace std;

class Complex
{
public:
    double real, imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator*(const Complex& other) const
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    double modulus() const
    {
        return sqrt(real * real + imag * imag);
    }
};

class Image
{
public:
    int width, height;
    vector<vector<int>> pixels;

    Image(int w, int h) : width(w), height(h), pixels(h, vector<int>(w)) {}

    void setPixel(int x, int y, int color)
    {
        pixels[y][x] = color;
    }

    void save(const string& filename)
    {
        ofstream file(filename);
        file << "P3\n" << width << " " << height << "\n255\n";
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                int color = pixels[y][x];
                file << color << " " << color << " " << color << " ";
            }
            file << "\n";
        }
    }
};

bool isEscaping(const Complex& c, int max_iter)
{
    Complex z(0, 0);
    for (int i = 0; i < max_iter; ++i)
    {
        z = z * z + c;
        if (z.modulus() > 2)
        {
            return true;
        }
    }
    return false;
}

void generateMandelbrotSet(Image& img, int max_iter)
{
    for (int y = 0; y < img.height; ++y)
    {
        for (int x = 0; x < img.width; ++x)
        {
            Complex c((x - img.width / 2.0) * 4.0 / img.width, 
                      (y - img.height / 2.0) * 4.0 / img.height);
            if (isEscaping(c, max_iter))
            {
                img.setPixel(x, y, 255);
            }
            else
            {
                img.setPixel(x, y, 0);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc < 5)
    {
        cout << "Usage: " << argv[0] << " <max_iter> <set_type> <output_filename>\n";
        cout << "set_type: 'mandelbrot'\n";
        return 1;
    }

    int max_iter = atoi(argv[1]);
    string set_type = argv[2];
    string output_filename = argv[3];

    Image img(800, 800);

    if (set_type == "mandelbrot")
    {
        generateMandelbrotSet(img, max_iter);
    }
    else
    {
        cout << "Invalid set type. Use 'mandelbrot'.\n";
        return 1;
    }

    img.save(output_filename);
    cout << "Image saved to " << output_filename << "\n";

    return 0;
}
