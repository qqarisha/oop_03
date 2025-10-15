#include "FigureArray.h"

void FigureArray::addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
}

Figure* FigureArray::getFigure(size_t index) const {
    if (index >= figures.size()) {
        throw std::out_of_range("Incorrect index");
    }
    return figures[index].get();
}

void FigureArray::removeFigure(size_t index) {
    if (index >= figures.size()) {
        throw std::out_of_range("Incorrect index");
    }
    figures.erase(figures.begin() + index);
}

size_t FigureArray::size() const {
    return figures.size();
}

double FigureArray::totalArea() const {
    double res = 0;
    for (const auto& f: figures) {
        res += f->area();
    }
    return res;
}

void FigureArray::printAll(std::ostream& os) const {
    for (size_t i = 0; i < figures.size(); i = i + 1) {
        os << "Figure " << i << ": " << *figures[i] << std::endl;
    }
}

FigureArray::FigureArray(const FigureArray& other) {
    figures.reserve(other.figures.size());
    for (const auto& f: other.figures) {
        figures.push_back(std::unique_ptr<Figure>(f->clone()));
    }
}

FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this != &other) {
        figures.clear();
        figures.reserve(other.figures.size());
        for (const auto& f: other.figures) {
            figures.push_back(std::unique_ptr<Figure>(f->clone()));
        }
    }
    return *this;
}

FigureArray::FigureArray(FigureArray&& other) noexcept: figures(std::move(other.figures)) {}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        figures = std::move(other.figures);
    }
    return *this;
}