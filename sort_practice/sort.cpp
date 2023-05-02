#include<bits/stdc++.h>
using namespace std;

bool g (int a, int b) {
    return a > b;
}

vector<int> v = { 1, 3, 2, 4, 6, 2, 3 };
int main () {
    // If the third parameter (also known as comparator) is not provided, the elements are sorted in ascending order.
    // sort(v.begin(), v.end());

    // To sort the elements in descending order, use the `greater()` function as the third parameter to `sort()`.
    // sort(v.begin(), v.end(), greater<int>());

    // If you want to specify custom sorting criteria, you can pass a function that defines the sorting order.
    sort(v.begin(), v.end(), g);
    // debugging
    // a: 3, b: 1, v: [1, 3, 2, 4, 6, 2, 3]
    // a: 2, b: 3, v: [3, 1, 2, 4, 6, 2, 3]
    
    // a: 2, b: 3, v: [3, 1, 1, 4, 6, 2, 3]
    // a: 4, b: 3, v: [3, 2, 1, 4, 6, 2, 3]
    // a: 6, b: 4, v: [4, 3, 2, 1, 6, 2, 3]
    // a: 2, b: 6, v: [6, 4, 3, 2, 1, 2, 3]
    // a: 2, b: 1, v: [6, 4, 3, 2, 1, 2, 3]
    // a: 2, b: 2, v: [6, 4, 3, 2, 1, 1, 3]
    // a: 3, b: 6, v: [6, 4, 3, 2, 2, 1, 3]
    // a: 3, b: 1, v: [6, 4, 3, 2, 2, 1, 3]
    // a: 3, b: 2, v: [6, 4, 3, 2, 2, 1, 1]
    // a: 3, b: 2, v: [6, 4, 3, 2, 2, 2, 1]
    // a: 3, b: 3, v: [6, 4, 3, 2, 2, 2, 1]

    // Documentation of Function `sort()`
    /**
     *  @brief Sort the elements of a sequence using a predicate for comparison.
     *  @ingroup sorting_algorithms
     *  @param  __first   An iterator.
     *  @param  __last    Another iterator.
     *  @param  __comp    A comparison functor.
     *  @return  Nothing.
     *
     *  Sorts the elements in the range @p [__first,__last) in ascending order,
     *  such that @p __comp(*(i+1),*i) is false for every iterator @e i in the
     *  range @p [__first,__last-1).
     *
     *  The relative ordering of equivalent elements is not preserved, use
     *  @p stable_sort() if this is needed.
     */

    // Documentation of Functor `less` and `greater`
    //   /// One of the @link comparison_functors comparison functors@endlink.
    //   template<typename _Tp>
    //     struct greater : public binary_function<_Tp, _Tp, bool>
    //     {
    //       _GLIBCXX14_CONSTEXPR
    //       bool
    //       operator()(const _Tp& __x, const _Tp& __y) const
    //       { return __x > __y; } // 💡 `>` is GREATER THAN sign
    //     };

    //   /// One of the @link comparison_functors comparison functors@endlink.
    //   template<typename _Tp>
    //     struct less : public binary_function<_Tp, _Tp, bool>
    //     {
    //       _GLIBCXX14_CONSTEXPR
    //       bool
    //       operator()(const _Tp& __x, const _Tp& __y) const
    //       { return __x < __y; } // 💡 `<` is LESS THAN sign
    //     };

    sort(v.begin(), v.end(), greater());


    // The functor is named 'greater', which refers to the symbol '>'. 
    // In general reading, 'A > B' is pronounced as 'A is greater than B'.
    // Therefore, the name 'greater' is chosen for this functor, and there is no other reason for it.

    vector<int> k = { 11, 33 }
    sort(k.begin(), k.end(), greater());
    // greater(33, 11) (referring to the element with the higher index as the first argument)
    // 33 > 11 :: true
    // The sort() function basically sorts the container in the direction of a falsy return of the functor.
    // So, when the returned value is true, it means that the elements are not in order.
    // Basically, calling the comparator functor means "Are these two arguments not in order?"
    // And when the comparator functor returns true, it means "Yes, swap their order."
    // While when the comparator functor returns false, it means "No, they don't need to be swapped."


    for (auto i : v) {
        cout << i << " ";
    }
    return 0;
}
