#ifndef SQUARE_H
#define SQUARE_H

#include "../Figure/Figure.h"
#include <array>

class Square : public Figure {
private:
    std::array<std::pair<double, double>, 4> vertices; 
    
public:
    Square() = default;
    Square(const std::array<std::pair<double, double>, 4>& v);
    
    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Square(const Square& other);
    Square& operator=(const Square& other);
    
    Square(Square&& other) noexcept;
    Square& operator=(Square&& other) noexcept;
    
    bool operator==(const Figure& other) const override;

    Figure* clone() const override;
};

#endif