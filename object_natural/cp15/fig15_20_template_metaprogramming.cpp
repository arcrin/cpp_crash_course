// fig15_20
// Implementing customDistance using template metaprogramming
#include <array>
#include <iostream>
#include <iterator>
#include <list>
#include <ranges>
#include <type_traits>

// calculate the distance (number of items) between two iterators;
// requires at least input iterators