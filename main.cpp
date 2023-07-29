#include "crow.h"
#include <string>

std::string load_file(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return load_file("index.html");
    });

    CROW_ROUTE(app, "/home")([](){
        return "Hello world yo!";
    });

    app.port(8080).multithreaded().run();
}