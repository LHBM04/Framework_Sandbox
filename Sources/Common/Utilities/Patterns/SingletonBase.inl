template<typename TInstance>
inline TInstance& SingletonBase<TInstance>::GetInstance(void)
{
    static_assert(std::is_default_constructible_v<TInstance>,
        "TInstance must be default constructible");
    static TInstance instance;
    return instance;
}
