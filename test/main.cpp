
#include <benchmark.hpp>
#include <random>
#include <functional>

#define ITERATIONS (100000000UL)

double alternating_harmonic_series();

int main()
{
    auto [ms, sum] = massiva::benchmark(alternating_harmonic_series);

    std::printf("{ %9.4lf ms } The partial sum of the first %lu terms is %7.6lf\n", ms, ITERATIONS, sum);

    auto madhava_leibniz_series = [](double& sum) -> void
    {
        sum = 0.0;

        for (std::size_t i = 0UL; i < ITERATIONS; i++)
        {
            if (i % 2UL)
                sum -= 4.0 / (2.0 * static_cast<double>(i) + 1.0);
            else
                sum += 4.0 / (2.0 * static_cast<double>(i) + 1.0);
        }
    };

    ms = massiva::benchmark(madhava_leibniz_series, sum);

    std::printf("{ %9.4lf ms } The partial sum of the first %lu terms is %7.6lf\n", ms, ITERATIONS, sum);

    return 0;
}

double alternating_harmonic_series()
{
    double sum = 0.0;

    for (std::size_t i = 1UL; i < ITERATIONS; i++)
    {
        if (i % 2UL)
            sum += 1.0 / static_cast<double>(i);
        else
            sum -= 1.0 / static_cast<double>(i);
    }

    return sum;
}
