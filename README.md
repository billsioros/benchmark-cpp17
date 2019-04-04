
# Header only C++17 benchmarking

## Non void return type

```cpp
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


std::printf("{ %08.4lf ms } The partial sum of the first %lu terms is %.12lf\n", ms, ITERATIONS, sum);
```

    { 821.4230 ms } The partial sum of the first 100000000 terms is 0.693147185560

## Void return type

```cpp
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

std::printf("{ %08.4lf ms } Sorted %lu values in the range [%+.2lf, %+.2lf]\n", ms, SIZE, MIN, MAX);
```

    { 003.4680 ms } Sorted 10000 values in the range [+0.00, +1000.00]

## License

The project is licensed under the [MIT License](https://opensource.org/licenses/MIT)
