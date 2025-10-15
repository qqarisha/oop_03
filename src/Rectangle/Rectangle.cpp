#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(const std::array<std::pair<double, double>, 4>& v) : vertices(v) {}

std::pair<double, double> Rectangle::center() const {
    double x = 0, y = 0;
    for (const auto& v: vertices) {
        x += v.first;
        y += v.second;
    }
    return {x / 4, y / 4};
}

double Rectangle::area() const {
    double side1 = std::sqrt(std::pow(vertices[1].first - vertices[0].first, 2) + 
                            std::pow(vertices[1].second - vertices[0].second, 2));
    double side2 = std::sqrt(std::pow(vertices[2].first - vertices[1].first, 2) + 
                            std::pow(vertices[2].second - vertices[1].second, 2));
    return side1 * side2;
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle: ";
    for (const auto& v: vertices) {
        os << "(" << v.first << ", " << v.second << ") ";
    }
}

void Rectangle::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Error input for rectangle");
        }
        vertices[i] = {x, y};
    }
}

Rectangle::Rectangle(const Rectangle& other) : vertices(other.vertices) {}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Rectangle::Rectangle(Rectangle&& other) noexcept : vertices(std::move(other.vertices)) {}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (!otherRect) return false;
    return vertices == otherRect->vertices;
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}
