
#include <benchmark.hpp>
#include <random>
#include <functional>

#define ITERATIONS (100000000UL)

#define SIZE (10000UL)
#define MIN (0.0)
#define MAX (1000.0)

int main()
{
    auto [ms, sum] = massiva::benchmark
    (
        [](std::size_t iterations)
        {
            double sum = 0.0f;
            for (std::size_t i = 1UL; i < iterations; i++)
            {
                if (i % 2UL)
                    sum += 1.0f / static_cast<double>(i);
                else
                    sum -= 1.0f / static_cast<double>(i);
            }

            return sum;
        },
        ITERATIONS
    );


    std::printf("{ %010.6lf milliseconds } After %lu iterations ln(2) is approximately %.12lf\n", ms, ITERATIONS, sum);

    ms = massiva::benchmark
    (
        []()
        {
            auto engine = std::bind
            (
                std::uniform_real_distribution<double>(MIN, MAX),
                std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count())
            );

            double values[SIZE];
            for (std::size_t i = 0UL; i < SIZE; i++)
                values[i] = engine();

            std::sort(std::begin(values), std::end(values));
        }
    );

    std::printf("{ %010.6lf milliseconds } Sorted %lu values in the range [%+.2lf, %+.2lf]\n", ms, SIZE, MIN, MAX);

    return 0;
}
