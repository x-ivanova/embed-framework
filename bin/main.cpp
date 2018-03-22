#include "crow.h"
#include <string>

using namespace std;

int main()
{
    int numClicks = 0;

    crow::SimpleApp app;
    crow::mustache::set_base(".");

    CROW_ROUTE(app, "/")
            ([]{
                return crow::mustache::load("index.html").render();
            });

    CROW_ROUTE(app, "/<string>")
            ([](string file){
                return crow::mustache::load(file).render();
            });

    CROW_ROUTE(app, "/make/")
            ([&numClicks](){
                return std::to_string(++numClicks);
            });

    CROW_ROUTE(app, "/get/")
            ([&numClicks](){
                return std::to_string(numClicks);
            });

    app.port(8080).run();



}
