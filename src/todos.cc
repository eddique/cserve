#include "todos.h"

using namespace api::v1;


void Todos::listTodos(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
    const
{
    Json::Value todos;
    for (int i = 0; i < 10; i++)
    {
        Json::Value todo;
        todo["id"] = i + 1;
        todo["title"] = "hello, world!";
        todo["body"] = "A todo from C++!";
        todos.append(todo);
    }
    auto resp = HttpResponse::newHttpJsonResponse(todos);
    callback(resp);
}
void Todos::createTodo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
    const
{
    auto jsonBody = req->getJsonObject();

    if (jsonBody)
    {
        std::string title = (*jsonBody)["title"].asString();
        std::string body = (*jsonBody)["body"].asString();

        Json::Value jsonResponse;
        jsonResponse["ok"] = true;
        jsonResponse["title"] = title;
        jsonResponse["body"] = body;
        auto resp = HttpResponse::newHttpJsonResponse(jsonResponse);

        callback(resp);
    }
    else
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        resp->setBody("Bad Request: Could not parse JSON body");
        callback(resp);
    }
}
void Todos::getTodo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int todoId) 
    const
{
    Json::Value todo;
    todo["id"] = todoId;
    todo["title"] = "A todo detail view";
    todo["body"] = "Hello, World from C++!";
    auto resp = HttpResponse::newHttpJsonResponse(todo);

    callback(resp);
}
void Todos::updateTodo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int todoId) 
    const
{
    auto jsonBody = req->getJsonObject();

    if (jsonBody)
    {
        std::string title = (*jsonBody)["title"].asString();
        std::string body = (*jsonBody)["body"].asString();

        Json::Value jsonResponse;
        jsonResponse["ok"] = true;
        jsonResponse["id"] = todoId;
        jsonResponse["title"] = title;
        jsonResponse["body"] = body;
        auto resp = HttpResponse::newHttpJsonResponse(jsonResponse);

        callback(resp);
    }
    else
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        resp->setBody("Bad Request: Could not parse JSON body");
        callback(resp);
    }
}
void Todos::deleteTodo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int todoId) 
    const
{
    Json::Value todo;
    todo["id"] = todoId;
    todo["title"] = "A deleted todo!";
    todo["body"] = "Hello, World from C++!";
    auto resp = HttpResponse::newHttpJsonResponse(todo);
    
    callback(resp);
}