#include "DatabaseFactory.hpp"

template <typename TDatabase>
std::shared_ptr<TDatabase> DatabaseFactory<TDatabase>::createConnection() {
    return std::make_shared<TDatabase>();
}

