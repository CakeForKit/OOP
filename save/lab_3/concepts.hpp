# include <memory>

using namespace std;


template <typename Derived, typename Base>
concept Derivative = is_abstract_v<Base> && is_base_of_v<Base, Derived>;

template <typename Type>
concept NotAbstract = !is_abstract_v<Type>;

template <typename Type>
concept DefaultConstructible = is_default_constructible_v<Type>;

template<typename Type, typename... Args>
concept Constructible = is_constructible_v<Type, Args...>;
