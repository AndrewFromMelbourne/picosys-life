#pragma once

//-------------------------------------------------------------------------
//
// The MIT License (MIT)
//
// Copyright (c) 2022 Andrew Duncan
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------

#include <array>
#include <cstdint>
#include <vector>

#include "picosystem.hpp"

//-------------------------------------------------------------------------

using namespace picosystem;

//-------------------------------------------------------------------------

class Life
{
public:

    static constexpr size_t WIDTH{240};
    static constexpr size_t HEIGHT{240};
    static constexpr size_t aliveCellShift{4};
    static constexpr uint8_t aliveCellMask{1 << aliveCellShift};

    enum DisplayOption
    {
        DISPLAY_CELLS,
        DISPLAY_POPULATION
    };

    enum CellState
    {
        CELL_DEAD,
        CELL_ALIVE
    };

    Life();

    void init();
    void update(uint32_t tick);
    void draw(uint32_t tick);

private:

    void updateCell(int col, int row, int value);
    void setCell( int col, int row);
    void clearCell(int col, int row);
    void createGosperGliderGun();
    void createSimkinGliderGun();
    void iterate();

    DisplayOption m_display;
    std::array<color_t, 9> m_populationColours;
    std::array<color_t, 2> m_cellColours;
    std::array<uint8_t, WIDTH * HEIGHT> m_cells;
    std::array<uint8_t, WIDTH * HEIGHT> m_cellsNext;
};

