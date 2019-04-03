
# Header only C++17 benchmarking utilities

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

std::cout
<< "The approximation of ln(2) in " << ITERATIONS
<< " iterations is equal to " << sum
<< " [" << std::fixed << ms << " microseconds elapsed] "
<< std::endl;
```

## License

The project is licensed under the [MIT License](https://opensource.org/licenses/MIT)
