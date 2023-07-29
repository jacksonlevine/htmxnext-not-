#include "crow.h"
#include <string>
#include <soci/soci.h>

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
        return load_file("./views/home.html");
    });

    CROW_ROUTE(app, "/downloads")([](){
        return load_file("./views/downloads.html");
    });

    app.port(8080).multithreaded().run();
}