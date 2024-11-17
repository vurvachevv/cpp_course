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

void generateJuliaSet(Image& img, const Complex& c, int max_iter)
{
    for (int y = 0; y < img.height; ++y)
    {
        for (int x = 0; x < img.width; ++x)
        {
            Complex z((x - img.width / 2.0) * 4.0 / img.width, 
                      (y - img.height / 2.0) * 4.0 / img.height);
            if (isEscaping(z, max_iter))
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
    if (argc < 6)
    {
        cout << "Usage: " << argv[0] << " <c_real> <c_imag> <max_iter> <set_type> <output_filename>\n";
        cout << "set_type: 'julia'\n";
        return 1;
    }

    double c_real = atof(argv[1]);
    double c_imag = atof(argv[2]);
    int max_iter = atoi(argv[3]);
    string set_type = argv[4];
    string output_filename = argv[5];

    Complex c(c_real, c_imag);
    Image img(800, 800);

    if (set_type == "julia")
    {
        generateJuliaSet(img, c, max_iter);
    }
    else
    {
        cout << "Invalid set type. Use 'julia'.\n";
        return 1;
    }

    img.save(output_filename);
    cout << "Image saved to " << output_filename << "\n";

    return 0;
}
