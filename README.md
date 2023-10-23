# cserve

An exercise in building a server in C++ on macos (silicon).

Step 1: install dependencies via homebrew

```sh
brew install cmake make jsoncpp git
```

Step 2: clone and build drogon folder

```sh
mkdir dependencies && cd dependencies

git clone https://github.com/drogonframework/drogon.git

cd drogon

git submodule update --init

mkdir build && cd build

cmake ..

make
```

Step 3: Go back to the root directory of your project
```sh
mkdir build && cd build

cmake ..

make

./cserve
```

## curl

1. **listTodos** - This is a GET request to the base URL.

```bash
curl http://127.0.0.1:8848/api/v1/Todos/
```

2. **createTodo** - This is a POST request to the base URL. You need to include the JSON data for the new todo in the body of the request.

```bash
curl -X POST -H "Content-Type: application/json" -d '{"title":"New Todo","body":"This is a new todo."}' http://127.0.0.1:8848/api/v1/Todos/
```

3. **getTodo** - This is a GET request to the URL for a specific todo. Replace `{id}` with the ID of the todo you want to get.

```bash
curl http://127.0.0.1:8848/api/v1/Todos/{id}
```

4. **updateTodo** - This is a PUT request to the URL for a specific todo. You need to include the updated JSON data for the todo in the body of the request. Replace `{id}` with the ID of the todo you want to update.

```bash
curl -X PUT -H "Content-Type: application/json" -d '{"title":"Updated Todo","body":"This is an updated todo."}' http://127.0.0.1:8848/api/v1/Todos/{id}
```

5. **deleteTodo** - This is a DELETE request to the URL for a specific todo. Replace `{id}` with the ID of the todo you want to delete.

```bash
curl -X DELETE http://127.0.0.1:8848/api/v1/Todos/{id}
```

Replace `{id}` with the actual ID of the todo you want to get, update, or delete.