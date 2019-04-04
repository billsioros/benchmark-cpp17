
# Header only C++17 benchmarking

## Quick Example

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


std::printf("{ %08.4lf ms } Sorted %lu values in the range [%+.2lf, %+.2lf]\n", ms, SIZE, MIN, MAX);
```

    { 827.9960 ms } After 100000000 iterations ln(2) is approximately 0.693147185560

## License

The project is licensed under the [MIT License](https://opensource.org/licenses/MIT)
