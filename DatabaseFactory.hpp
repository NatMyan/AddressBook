#ifndef DATABASE_FACTORY_HPP
#define DATABASE_FACTORY_HPP

#include <memory>

template <typename TDatabase>
class DatabaseFactory {
    public:
        std::shared_ptr<TDatabase> createConnection();
};

#endif // DATABASE_FACTORY_HPP