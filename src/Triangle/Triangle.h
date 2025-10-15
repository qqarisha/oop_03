#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Figure/Figure.h"
#include <array>

class Triangle : public Figure {
private:
    std::array<std::pair<double, double>, 3> vertices; 
    
public:
    Triangle() = default;
    Triangle(const std::array<std::pair<double, double>, 3>& v);
    
    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);
    
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(Triangle&& other) noexcept;
    
    bool operator==(const Figure& other) const override;

    Figure* clone() const override;
};

#endif