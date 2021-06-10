#include <iostream>
#include <complex>

int main()
{
    std::complex<double> c1(4.0, 3.0);
    std::complex<float> c2(std::polar(6.0, 7.5));
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;

    std::cout << "c1:magnitude: " << std::abs(c1) << " (squared magnitude: )" << std::norm(c1) << " )"
              << " phase angle: " << std::arg(c1) << std::endl;
    std::cout << "c1:magnitude: " << std::abs(c2) << " (squared magnitude: )" << std::norm(c2) << " )"
              << " phase angle: " << std::arg(c2) << std::endl;

    std::cout << " c1 conjugated: " << std::conj(c1) << std::endl;
    std::cout << " c2 conjugated: " << std::conj(c2) << std::endl;

    std::cout << "4.4 +c1 * 1.8: " << 4.4 + c1 * 1.8 << std::endl;

    std::cout << "c1+c2: " << c1 + std::complex<double>(c2.real(), c2.imag()) << std::endl;

    return 0;
}