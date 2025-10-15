#include "Square.h"
#include <cmath>

Square::Square(const std::array<std::pair<double, double>, 4>& v) : vertices(v) {}

std::pair<double, double> Square::center() const {
    double x = 0, y = 0;
    for (const auto& v: vertices) {
        x += v.first;
        y += v.second;
    }
    return {x / 4, y / 4};
}

double Square::area() const {
    double side = std::sqrt(std::pow(vertices[1].first - vertices[0].first, 2) + 
                           std::pow(vertices[1].second - vertices[0].second, 2));
    return side * side;
}

void Square::print(std::ostream& os) const {
    os << "Square: ";
    for (const auto& v: vertices) {
        os << "(" << v.first << ", " << v.second << ") ";
    }
}

void Square::read(std::istream& is) {
    for (int i = 0; i < 4; i = i + 1) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Error input for square");
        }
        vertices[i] = {x, y};
    }
}

Square::Square(const Square& other) : vertices(other.vertices) {}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Square::Square(Square&& other) noexcept : vertices(std::move(other.vertices)) {}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

bool Square::operator==(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (!otherSquare) return false;
    return vertices == otherSquare->vertices;
}

Figure* Square::clone() const {
    return new Square(*this);
}