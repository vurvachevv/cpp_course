void generateMandelbrotSet(int maxIterations, const std::string& filename) {
    int width = 800;
    int height = 800;
    double minX = -2.0, maxX = 2.0, minY = -2.0, maxY = 2.0;
    Image img(width, height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double real = minX + (maxX - minX) * x / width;
            double imag = minY + (maxY - minY) * y / height;
            std::complex<double> c(real, imag);
            int iter = mandelbrotIterations(std::complex<double>(0, 0), c, maxIterations);
            int color = (iter == maxIterations) ? 0 : (iter * 255 / maxIterations);
            img.setPixel(x, y, color, color, color);
        }
    }
    img.save(filename);
}

int main() {
    generateMandelbrotSet(1000, "mandelbrot.ppm");
    return 0;
}
