#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H

#include "../Figure/Figure.h"
#include <vector>
#include <memory>

class FigureArray {
private:
    std::vector<std::unique_ptr<Figure>> figures;
    
public:
    FigureArray() = default;
    
    void addFigure(std::unique_ptr<Figure> figure);
    Figure* getFigure(size_t index) const;
    void removeFigure(size_t index);
    size_t size() const;
    double totalArea() const;
    void printAll(std::ostream& os) const;
    
    FigureArray(const FigureArray& other);
    FigureArray& operator=(const FigureArray& other);
    
    FigureArray(FigureArray&& other) noexcept;
    FigureArray& operator=(FigureArray&& other) noexcept;
};

#endif