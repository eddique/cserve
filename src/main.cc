#include <drogon/drogon.h>
#include "todos.h"
using namespace drogon;
int main()
{
    auto ctrl = std::make_shared<api::v1::Todos>();
    LOG_INFO << "Server running on 127.0.0.1:8848";
    app()
        .addListener("127.0.0.1", 8848)
        .registerController<api::v1::Todos>(ctrl)
        .run();
    return 0;
}