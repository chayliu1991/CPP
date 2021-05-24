#include <iostream>
#include <limits>

int main()
{
    cout << boolalpha;
    cout << std::numeric_limits<float>::is_specialized << endl;
    cout << std::numeric_limits<float>::is_signed << endl;
    cout << std::numeric_limits<float>::is_integer << endl;
    cout << std::numeric_limits<float>::is_exact << endl;
    cout << std::numeric_limits<float>::is_bounded << endl;
    cout << std::numeric_limits<float>::max() << endl;
    cout << std::numeric_limits<float>::min() << endl;
    cout << std::numeric_limits<float>::lowest() << endl;

    cout << std::numeric_limits<int>::is_specialized << endl;
    cout << std::numeric_limits<int>::is_signed << endl;
    cout << std::numeric_limits<int>::is_integer << endl;
    cout << std::numeric_limits<int>::is_exact << endl;
    cout << std::numeric_limits<int>::is_bounded << endl;
    cout << std::numeric_limits<int>::max() << endl;
    cout << std::numeric_limits<int>::min() << endl;
    cout << std::numeric_limits<int>::lowest() << endl;

    return 0;
}