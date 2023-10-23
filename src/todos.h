#pragma once

#include <drogon/HttpController.h>

using namespace drogon;
namespace api 
{
  namespace v1 
  {

class Todos : public HttpController<Todos, false>
{
  public:
    METHOD_LIST_BEGIN
      METHOD_ADD(Todos::listTodos, "/", Get); 
      METHOD_ADD(Todos::createTodo, "/", Post);
      METHOD_ADD(Todos::getTodo, "/{id}", Get);
      METHOD_ADD(Todos::updateTodo, "/{id}", Put);
      METHOD_ADD(Todos::deleteTodo, "/{id}", Delete);
    METHOD_LIST_END

  void listTodos(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const;
  void createTodo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const;
  void getTodo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int todoId) const;
  void updateTodo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int todoId) const;
  void deleteTodo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int todoId) const;
  public:
    Todos()
    {
        LOG_DEBUG << "Todos contoller constructor!";
    }
};
  }
}
