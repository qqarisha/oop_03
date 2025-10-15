#include "Triangle.h"
#include <sstream>

Triangle::Triangle(const std::array<std::pair<double, double>, 3>& v) : vertices(v) {}

std::pair<double, double> Triangle::center() const {
    double x = 0, y = 0;
    for (const auto& v: vertices) {
        x += v.first;
        y += v.second;
    }
    return {x / 3, y / 3};
}

double Triangle::area() const {
    const auto& [x1, y1] = vertices[0];
    const auto& [x2, y2] = vertices[1];
    const auto& [x3, y3] = vertices[2];
    return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle: ";
    for (const auto& v: vertices) {
        os << "(" << v.first << ", " << v.second << ") ";
    }
}

void Triangle::read(std::istream& is) {
    for (int i = 0; i < 3; i = i + 1) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Error input for triangle");
        }
        vertices[i] = {x, y};
    }
}

Triangle::Triangle(const Triangle& other) : vertices(other.vertices) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Triangle::Triangle(Triangle&& other) noexcept : vertices(std::move(other.vertices)) {}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (!otherTriangle) return false;
    return vertices == otherTriangle->vertices;
}

Figure* Triangle::clone() const {
    return new Triangle(*this);
}