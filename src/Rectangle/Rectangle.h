#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Figure/Figure.h"
#include <array>

class Rectangle : public Figure {
private:
    std::array<std::pair<double, double>, 4> vertices; 
    
public:
    Rectangle() = default;
    Rectangle(const std::array<std::pair<double, double>, 4>& v);
    
    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;
    
    bool operator==(const Figure& other) const override;

    Figure* clone() const override;
};

#endif