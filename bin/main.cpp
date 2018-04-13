#include "crow.h"
#include <string>

using namespace std;

int main()
{
    int count = 0;
    bool checkBox = 0;
    int slider = 75;
    string editBox = "Пустой текст.";
    string select = "Красный";

    cout << select;

    crow::SimpleApp app;
    crow::mustache::set_base(".");

    CROW_ROUTE(app, "/get/")
            ([&count, &checkBox, &editBox, &select, &slider](){
                crow::json::wvalue response;
                response["count"] = count;
                response["checkBox"] = int(checkBox);
                response["editBox"] = editBox;
                response["select"] = select;
                response["slider"] = slider;
                return response;
            });

    CROW_ROUTE(app, "/set/")
            ([&count, &checkBox, &editBox, &select, &slider](const crow::request& req){
                if(req.url_params.get("count") != nullptr) {
                    int tmp = boost::lexical_cast<int>(req.url_params.get("count"));
                    count = tmp;
                }
                if(req.url_params.get("checkBox") != nullptr) {
                    bool tmp = boost::lexical_cast<bool>(req.url_params.get("checkBox"));
                    checkBox = tmp;
                }
                if(req.url_params.get("editBox") != nullptr) {
                    string tmp = boost::lexical_cast<string>(req.url_params.get("editBox"));
                    editBox = tmp;
                }
                if(req.url_params.get("select") != nullptr) {
                    string tmp = boost::lexical_cast<string>(req.url_params.get("select"));
                    select = tmp;
                }
                if(req.url_params.get("slider") != nullptr) {
                    int tmp = boost::lexical_cast<int>(req.url_params.get("slider"));
                    slider = tmp;
                }
                return "OK";
            });

    CROW_ROUTE(app, "/")
            ([]{
                return crow::mustache::load("index.html").render();
            });

    CROW_ROUTE(app, "/count/")
            ([&count]{
                return std::to_string(++count);
            });

    CROW_ROUTE(app, "/checkBox/")
            ([&checkBox]{
                checkBox = !checkBox;
                return std::to_string(checkBox);
            });


    CROW_ROUTE(app, "/<path>")
            ([](string file){
                return crow::mustache::load(file).render();
            });



    app.port(8080).run();



}
