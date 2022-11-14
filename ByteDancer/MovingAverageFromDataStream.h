#pragma once

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        m_size = size;
        m_pContainer = new int[size];
    }

    double next(int val) {
        if (m_isFull) m_PreSum = m_PreSum - m_pContainer[m_TailIndex];
        m_pContainer[m_TailIndex] = val;
        if (m_TailIndex == m_size - 1 && !m_isFull) m_isFull = true;
        m_TailIndex = (m_TailIndex + 1) % m_size;
        m_PreSum += val;
        return m_isFull ? m_PreSum / m_size : m_PreSum / m_TailIndex;
    }
    ~MovingAverage() {
        delete[] m_pContainer;
    }
private:
    int* m_pContainer;
    int m_size;
    double m_PreSum = 0.0;
    int m_TailIndex = 0;
    bool m_isFull = false;
};
