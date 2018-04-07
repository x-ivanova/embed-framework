#include "crow.h"
#include <string>

using namespace std;

int main()
{
    int numClicks = 0;
    bool check = false;

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
            ([&numClicks](const crow::request& req){
                if(req.url_params.get("count") != nullptr) {
                    int count = boost::lexical_cast<int>(req.url_params.get("count"));
                    numClicks = numClicks + count;
                }
                return std::to_string(numClicks);
            });

    CROW_ROUTE(app, "/get/")
            ([&numClicks](){
                return std::to_string(numClicks);
            });

    CROW_ROUTE(app, "/check/")
            ([&check](){
                check = !check;
                return std::to_string(check);
            });

    app.port(8080).run();



}
