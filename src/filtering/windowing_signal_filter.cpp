#include "windowing_signal_filter.hpp"

WindowingSignalFilter::WindowingSignalFilter(int windowSize)
    : m_windowSize(windowSize) 
{
    if (m_windowSize % 2 == 0)
        m_windowSize += 1;
}

std::vector<double> WindowingSignalFilter::filteredSequence(const std::vector<double> &sequence)
{
    int N = sequence.size();
    // Can't use method if window is too big for this sequence
    if (m_windowSize > N) {
        return sequence;
    }

    std::vector<double> filtered(N);
    // First and last values are unchanged
    filtered[0] = sequence[0];
    filtered[N - 1] = sequence[N - 1];

    int halfWindow = m_windowSize / 2;
    double sum = 0;

    // For the beginning of the vector (where window doesn't fit)
    for(int i = 1; i < halfWindow; i ++) {
        sum = 0;
        for(int j = 0; j < 2 * i + 1; j ++) {
            sum += sequence[j];
        }
        filtered[i] = sum / (2 * i + 1);
    }

    // For the last elements of the vector (where window doesn't fit)
    for(int i = N - halfWindow; i < N - 1; i ++) {
        sum = 0;
        // j starts from 'i - (N - i)' == '<index of element> - <distance to vector's end>'
        for(int j = 2*i - N; j < N; j ++) {
            sum += sequence[j];
        }
        filtered[i] = sum / (2*(N - i));
    }
    
    // For indexes where window does fit
    sum = 0;
    for(int i = halfWindow; i < N - halfWindow; i ++) {

        if (i == halfWindow) {
            // On first iteration
            for(int j = 0; j < m_windowSize; j ++) {
                sum += sequence[j];
            }
        } else {
            sum = sum - sequence[i - halfWindow - 1] + sequence[i + halfWindow];
        }
        filtered[i] = sum / m_windowSize;
    }

    return filtered;
}